#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "view/viewer.h"
#include <QValidator>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mw_cont_ = new MWController;
    connect(ui->load_btn, SIGNAL(clicked()), this, SLOT(LoadButtonClicked()));
    connect(ui->set_btn, SIGNAL(clicked()), this, SLOT(SlotSettngsBtnClicked()));
    connect(ui->record_btn, SIGNAL(clicked()), this, SLOT(SlotRecordButtonClicked()));
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

void MainWindow::LoadButtonClicked(){
    //сначала загрузка данных в модель

    ui->viewer->InitModel(mw_cont_->GetVertexCount(), mw_cont_->GetVertexes(), mw_cont_->GetFasets());

    ui->viewer->update();

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
}
