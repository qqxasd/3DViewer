#ifndef CPP4_3DVIEWER_V2_0_1_MAINWINDOW_H_
#define CPP4_3DVIEWER_V2_0_1_MAINWINDOW_H_

#include <QMainWindow>
#include "controller/mwcontroller.h"
#include <QTimer>
#include "view/settings_widget.h"
#include "qgifimage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using namespace s21;
/**
 * @brief Mainwindow class, includes everything that needs for work
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MWController* mw_cont_; ///< Создание экземпляра контроллера
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SettingsWidget* sw_ = nullptr;
    void SaveJPEG();
    void SaveBMP();
    QGifImage* gif_ = NULL;
    QTimer tmr_;
    QString GetFileName(QString path);


private slots:
    void LoadButtonClicked();
    void SlotSettngsBtnClicked();
    void SlotRecordButtonClicked();
    void SlotTransformButtonClicked();
    void SlotAddImgToGif();
};
#endif // CPP4_3DVIEWER_V2_0_1_MAINWINDOW_H_
