#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "view/viewer.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //viewer_ = new Viewer(this);
    //ui->tabWidget->insertTab(0, viewer_, "tab1");

  //  ui->tabWidget->setContentsMargins(0,0,0,0);
    mw_cont_ = new MWController;
    connect(ui->load_btn, SIGNAL(clicked()), this, SLOT(LoadButtonClicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadButtonClicked(){
    //сначала загрузка данных в модель
   ui->viewer->SetFasets(mw_cont_->GetFasets());
    ui->viewer->InitModel(mw_cont_->GetVertexCount(), mw_cont_->GetVertexes(), mw_cont_->GetFasets());

    ui->viewer->update();
//    qDebug() << " sfasf";
}

