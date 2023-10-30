#ifndef CPP4_3DVIEWER_V_2_0_1_MODEL_AFINE_STATEGY_H_
#define CPP4_3DVIEWER_V_2_0_1_MODEL_AFINE_STATEGY_H_

#include <cmath>
#include <vector>

#include "OpenGL/OpenGL.h"
namespace s21 {
/**
 * @brief Strategy virtual class
*/
class AfineStrategy {
 public:
  AfineStrategy(std::vector<GLfloat> &vec) : dots_(vec) {}
  virtual ~AfineStrategy(){};
  virtual void use() = 0;

 protected:
  std::vector<GLfloat> &dots_;
};

/**
 * @brief Rotate relatively X strategy
*/
class RotateStrategyX : public AfineStrategy {
 public:
 /**
  * @brief constructor for rotate strategy
  * @param vec - vertexes vector
  * @param angle - angle to flip in radians
 */
  RotateStrategyX(std::vector<GLfloat> &vec, double angle)
      : AfineStrategy(vec), angle_(angle) {}

  void use() override;

 private:
  double angle_;
};

/**
 * @brief Rotate relatively Y strategy
*/
class RotateStrategyY : public AfineStrategy {
 public:
  /**
  * @brief constructor for rotate strategy
  * @param vec - vertexes vector
  * @param angle - angle to flip in radians
 */
  RotateStrategyY(std::vector<GLfloat> &vec, double angle)
      : AfineStrategy(vec), angle_(angle) {}

  void use() override;

 private:
  double angle_;
};

/**
 * @brief Rotate relatively Z strategy
*/
class RotateStrategyZ : public AfineStrategy {
 public:
  /**
  * @brief constructor for rotate strategy
  * @param vec - vertexes vector
  * @param angle - angle to flip in radians
 */
  RotateStrategyZ(std::vector<GLfloat> &vec, double angle)
      : AfineStrategy(vec), angle_(angle) {}

  void use() override;

 private:
  double angle_;
};

/**
 * @brief Move relatively given axis strategy
*/
class MoveStrategy : public AfineStrategy {
 public:
  /**
  * @brief constructor for MoveStrategy
  * @param vec - vertexes vector
  * @param mov - distatance to move model
  * @param axis - relatively from this axis move will be executed
 */
  MoveStrategy(std::vector<GLfloat> &vec, double mov, char axis)
      : AfineStrategy(vec), mov_(mov), axis_(axis) {}

  void use() override;

 private:
  double mov_;
  char axis_;
};

/**
 * @brief scale strategy
*/
class ScaleStrategy : public AfineStrategy {
 public:
  /**
  * @brief constructor for scale strategy
  * @param vec - vertexes vector
  * @param scale - scale coeficent
 */
  ScaleStrategy(std::vector<GLfloat> &vec, double scale)
      : AfineStrategy(vec), scale_(scale) {}

  void use() override;

 private:
  double scale_;
};
}  // namespace s21
#endif
