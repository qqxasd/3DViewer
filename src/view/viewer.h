#ifndef VIEWER_H
#define VIEWER_H
#include <QMatrix4x4>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShader>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWidget>



// #include "../../model/model.h"
namespace  s21 {


/**
 * \brief Отрисовка окна внутри главной формы для отображения модели
 */
class Viewer : public QOpenGLWidget, protected QOpenGLFunctions {
 public:
  Viewer(QWidget* parent = nullptr);
  ~Viewer();

 public:
  /**
   * Инициализация окна и установка первичных настроек
   */
  void initializeGL() override;
  /**
   * Установка размера области просмотра
   */
  void resizeGL(int w, int h) override;
  /**
   * Отрисовка модели
   */
  void paintGL() override;
  /**
   * Инициализация шейдеров
   */
  void InitShaders();
  /**
   * Выделение памяти под модель
   */
  void InitModel(GLuint size, GLfloat* data,  std::vector<std::vector<GLuint>> fasets);

  /**
   * Обработка нажатия пкм
   */
//  void mousePressEvent(QMouseEvent* mo) override;
//  /**
//   * Обработка перемещения мыши с нажатой пкм
//   */
//  void mouseMoveEvent(QMouseEvent* mo) override;
//  /**
//   * Обработка вращения колесика мыши
//   */
//  void wheelEvent(QWheelEvent* event) override;

 private:
  QMatrix4x4 projection_matrix_;  ///< Матрица проекции перспективы
  QOpenGLShaderProgram* program_;  ///< Шейдерная программа
  QOpenGLBuffer vertex_buffer_;    ///< Буфер точек
  QOpenGLBuffer index_buffer_;
 /* QPoint pos_;  ///< Позиция нажатия пкм в окне отображения модели
  float x_rot_,
      y_rot_; */ ///< Смещение модели на координатах окна отображения модели
  //QVector4D bckgrnd_color_={70,20,20,255};;  ///< Цвет фона
//  QSettings* settings;  ///< Экземпляр настроек отображения моделей

  QVector4D background_color_ ={0.2,0.4,0.4,0.5};  ///< Цвет фона
  QVector4D line_color_ = {0.0, 0.0, 0.0, 0.5};        ///< Цвет линий
  QVector4D vertex_color_= {0, 0, 0, 0};      ///< Цвет точек
  int vertex_type_;             ///< Тип точек
  int line_type_;               ///< Тип линии
  float vertex_size_;           ///< Размер точек
  float line_width_;            ///< Ширина линий
  int projection_type_ = 1;         ///< Тип проекции
 std::vector<std::vector<GLuint>> fasets_;
 public:
  /**
   *Загрузка модели по указанному пути
   */
  //int LoadModel(QString path);

  /**
   * Загрузка файла настроек
   */
 // void LoadSettings();

  void SetFasets(const std::vector<std::vector<GLuint>>& fasets) {
      fasets_ = fasets;
  }
};
}
#endif  // VIEWER_H
