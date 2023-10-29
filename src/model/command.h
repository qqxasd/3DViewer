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
class Command {
 public:
  Command(std::vector<GLfloat> *vertexes = nullptr,
          std::vector<std::vector<GLuint>> *fasets = nullptr)
      : vertexes_(vertexes), fasets_(fasets) {}
  virtual void Execute() = 0;

 protected:
  std::vector<GLfloat> *vertexes_;
  std::vector<std::vector<GLuint>> *fasets_;
};

class RotateCommand : public Command {
 public:
  RotateCommand(std::vector<GLfloat> *vertexes, char axis, double angle)
      : Command(vertexes), axis_(axis), angle_(angle){};
  void Execute() override;

 private:
  char axis_;
  double angle_;
};

class MoveCommand : public Command {
 public:
  MoveCommand(std::vector<GLfloat> *vertexes, char axis, double dist)
      : Command(vertexes), axis_(axis), dist_(dist){};
  void Execute() override;

 private:
  char axis_;
  double dist_;
};

class ScaleCommand : public Command {
 public:
  ScaleCommand(std::vector<GLfloat> *vertexes, double value)
      : Command(vertexes), value_(value){};
  void Execute() override;

 private:
  double value_;
};

class ParseCommand : public Command {
 public:
  ParseCommand(std::vector<GLfloat> *vertexes,
               std::vector<std::vector<GLuint>> *fasets, std::string path)
      : Command(vertexes, fasets), path_(path){};
  void Execute() override;

 private:
  void ParseVertexes_(long vertex_count) const noexcept;
  void ParseFasets_(long fasets_count) const noexcept;
  std::pair<int, int> CountSize_(const char *path) const noexcept;
  std::string path_;
};

}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_1_CONTROLLER_COMMAND_H
