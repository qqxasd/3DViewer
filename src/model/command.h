#ifndef CPP4_3DVIEWER_V2_0_1_MODEL_COMMAND_H_
#define CPP4_3DVIEWER_V2_0_1_MODEL_COMMAND_H_

#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>

#include "afine_strategy.h"

namespace s21 {
/**
 * @brief Command virtual class
*/
class Command {
 public:
 /**
  * @brief default constructor
  * @param vertexes defaults to nullptr, vertexes vector
  * @param fasets defaults to null, fasets vector
 */
  Command(std::vector<GLfloat> *vertexes = nullptr,
          std::vector<std::vector<GLuint>> *fasets = nullptr)
      : vertexes_(vertexes), fasets_(fasets) {}
  virtual void Execute() = 0;

 protected:
  std::vector<GLfloat> *vertexes_;
  std::vector<std::vector<GLuint>> *fasets_;
};

/**
 * @brief Performs the rotation of model
 * 
*/
class RotateCommand : public Command {
 public:
 /**
  * @brief the only constructor.
  * @param vertexes - pointer to vector where vertexes are stored
  * @param axis - relatively from this axis rotate will be executed
  * @param angle - rotate angle in radians
 */
  RotateCommand(std::vector<GLfloat> *vertexes, char axis, double angle)
      : Command(vertexes), axis_(axis), angle_(angle){};
  /**
   * @brief performs the rotation
  */
  void Execute() override;

 private:
  char axis_;
  double angle_;
};

/**
 * @brief performs the move of the model on given distation
*/
class MoveCommand : public Command {
 public:
 /**
  * @brief the only constructor
  * @param vertexes - pointer to vector where vertexes are stored
  * @param axis - relatively from this axis move will be executed
  * @param dist - the distation on which move will be executed
 */
  MoveCommand(std::vector<GLfloat> *vertexes, char axis, double dist)
      : Command(vertexes), axis_(axis), dist_(dist){};
  /**
   * @brief performs the move
  */
  void Execute() override;

 private:
  char axis_;
  double dist_;
};

/**
 * @brief perfoms scale
*/
class ScaleCommand : public Command {
 public:
 /**
  * @brief only constructor
  * @param vertexes - pointer to the vector where vertexes stored
  * @param value - the scale coeficent
 */
  ScaleCommand(std::vector<GLfloat> *vertexes, double value)
      : Command(vertexes), value_(value){};
  void Execute() override;

 private:
  double value_;
};
/**
 * @brief performs parse, using FILE * from C is a code-perfomance question
*/
class ParseCommand : public Command {
 public:
  /**
   * @brief the only constructor
   * @param vertexes - pointer to the vector where vertexes stored
   * @param fasets - pointer to the fasets vector
   * @param path - path to the .obj file
  */
  ParseCommand(std::vector<GLfloat> *vertexes,
               std::vector<std::vector<GLuint>> *fasets, std::string path)
      : Command(vertexes, fasets), path_(path){};
  /**
   * @brief performs parse, splits into two threads, first parses vertexes, second - fasets.
  */
  void Execute() override;

 private:
 /**
  * @brief parses vertexes
  * @param vertex_count - vertexes amount needs to allocate memory once in vector
 */
  void ParseVertexes_(long vertex_count) const noexcept;
/**
 * @brief parses fasets
 * @param fasets_count - fasets amount needs to allocate memory once in vector
*/
  void ParseFasets_(long fasets_count) const noexcept;
/**
 * @brief counts the sizes for vertexes and fasets vectors, needs to allocate memory once (no reallocs)
*/
  std::pair<int, int> CountSize_(const char *path) const noexcept;
  std::string path_;
};

}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_1_CONTROLLER_COMMAND_H
