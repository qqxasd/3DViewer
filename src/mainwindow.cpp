#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "view/viewer.h"
#include <QValidator>
#include <QFileDialog>
#include "model/command.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mw_cont_ = new MWController;
    connect(ui->load_btn, SIGNAL(clicked()), this, SLOT(LoadButtonClicked()));
    connect(ui->set_btn, SIGNAL(clicked()), this, SLOT(SlotSettngsBtnClicked()));
    connect(ui->record_btn, SIGNAL(clicked()), this, SLOT(SlotRecordButtonClicked()));
    connect(ui->transform_btn, SIGNAL(clicked()), this, SLOT(SlotTransformButtonClicked()));
    connect(&tmr_, SIGNAL(timeout()), this, SLOT(SlotAddImgToGif()));
    QDoubleValidator* doub_vall = new QDoubleValidator(-360.0, 360.0, 2, this);
    doub_vall->setLocale(QLocale::C);
    ui->rot_x_le->setValidator(doub_vall);
    ui->rot_y_le->setValidator(doub_vall);
    ui->rot_z_le->setValidator(doub_vall);
    ui->move_x_le->setValidator(doub_vall);
    ui->move_y_le->setValidator(doub_vall);
    ui->move_z_le->setValidator(doub_vall);
    QDoubleValidator* sc_vall = new QDoubleValidator(0.01, 10.0, 2, this);
    sc_vall->setLocale(QLocale::C);
    ui->scale_le->setValidator(sc_vall);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SaveJPEG() {
    QString path = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                 "~/untitled.jpg",
                                                 tr("Images (*.jpg)"));
    QImage img = ui->viewer->grabFramebuffer();
    img.save(path);

}

void MainWindow::SaveBMP() {
    QString path = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                 "~/untitled.bmp",
                                                 tr("Images (*.bmp)"));
    QImage img = ui->viewer->grabFramebuffer();
    img.save(path);

}

QString MainWindow::GetFileName(QString path) {
    QStringList sl = path.split('/');
    return sl.back();
}

void MainWindow::LoadButtonClicked(){
   QString path = QFileDialog::getOpenFileName(this, tr("Open File"),
                                               "~/", tr("Models (*.obj)"));

    if (!path.isEmpty()) {
    mw_cont_->PerformParse(path.toStdString());

    ui->viewer->InitModel(mw_cont_->GetVertexCount(), mw_cont_->GetVertexes(), mw_cont_->GetFasets());
    ui->viewer->update();
    QString mes = GetFileName(path) + ", v = " + QString::number(mw_cont_->GetVertexCount()) +
            ", f = " +  QString::number(mw_cont_->GetFasetsCount());
    statusBar()->showMessage(mes);
    }
}

void MainWindow::SlotSettngsBtnClicked() {
    if (sw_)
        delete sw_;
  sw_ = new SettingsWidget(this);  //
  sw_->setModal(true);

  if (sw_->exec() == QDialog::Accepted) {
    ui->viewer->LoadSettings();
    ui->viewer->update();
  }
}

void MainWindow::SlotRecordButtonClicked() {
    if (ui->comboBox->currentIndex() == 0)
        SaveJPEG();
    else if (ui->comboBox->currentIndex() == 1)
        SaveBMP();
    else if (ui->comboBox->currentIndex() == 2) {
        tmr_.start(100);
        ui->record_btn->setEnabled(false);
    }
}

void MainWindow::SlotAddImgToGif() {
  if (gif_ == NULL) {
    gif_ = new QGifImage(QSize(640, 480));
    gif_->setDefaultTransparentColor(Qt::black);
    gif_->setDefaultDelay(100);
  }
  QImage img = ui->viewer->grabFramebuffer();
  gif_->addFrame(img);
  if (gif_->frameCount() == 50) {
    QString file_name = QFileDialog::getSaveFileName(this, tr("save"), "~/",
                                                     tr("Images (*.gif)"));
    gif_->save(file_name);
    // GifFreeSavedImages(gif);
    //        GifFreeSavedImages(gif);
    delete gif_;
    gif_ = NULL;
    tmr_.stop();
    ui->record_btn->setEnabled(true);
  }
}

void MainWindow::SlotTransformButtonClicked() {
    if (mw_cont_->ContainsModel()) {
    if (!ui->move_x_le->text().isEmpty()) {
        double move = ui->move_x_le->text().toDouble();
        mw_cont_->PerformMove('x', move);
    }
    if (!ui->move_y_le->text().isEmpty()) {
        double move = ui->move_y_le->text().toDouble();
        mw_cont_->PerformMove('y', move);
    }
    if (!ui->move_z_le->text().isEmpty()) {
        double move = ui->move_z_le->text().toDouble();
        mw_cont_->PerformMove('z', move);
    }
    if (!ui->rot_x_le->text().isEmpty()) {
        double rot = ui->rot_x_le->text().toDouble();
        mw_cont_->PerformRotate('x', rot);
    }
    if (!ui->rot_y_le->text().isEmpty()) {
        double rot = ui->rot_y_le->text().toDouble();
        mw_cont_->PerformRotate('y', rot);
    }
    if (!ui->rot_z_le->text().isEmpty()) {
        double rot = ui->rot_z_le->text().toDouble();
        mw_cont_->PerformRotate('z', rot);
    }
    if (!ui->scale_le->text().isEmpty()) {
        double scale = ui->scale_le->text().toDouble();
        if (scale == 0)
            scale = 1e-7;
        mw_cont_->PerformScale(scale);
    }
    ui->viewer->InitVertexBuffer(mw_cont_->GetVertexCount(), mw_cont_->GetVertexes());
     ui->viewer->update();
    }
}
