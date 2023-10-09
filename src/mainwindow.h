#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller/mwcontroller.h"
#include "view/viewer.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using namespace s21;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MWController* mw_cont_; ///< Создание экземпляра контроллера
    Viewer* viewer_; ///< Создание экземпляра вьювера
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void LoadButtonClicked();
};
#endif // MAINWINDOW_H
