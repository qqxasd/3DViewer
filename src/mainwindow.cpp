#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "view/viewer.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mw_cont_ = new MWController;
    connect(ui->load_btn, SIGNAL(clicked()), this, SLOT(LoadButtonClicked()));
    connect(ui->set_btn, SIGNAL(clicked()), this, SLOT(SlotSettngsBtnClicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
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
