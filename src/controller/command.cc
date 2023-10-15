#include "command.h"

namespace s21 {

void RotateCommand::flip_rel_z_(std::vector<GLfloat> &cords, int dots_amount,
                                double flip_angle) {
  for (int i = 0; i < dots_amount; i += 3) {
    double rem_cur = cords[i];
    cords[i] = rem_cur * cos(flip_angle) - cords[i + 1] * sin(flip_angle);
    cords[i + 1] = rem_cur * sin(flip_angle) + cords[i + 1] * cos(flip_angle);
  }
}

void RotateCommand::flip_rel_x_(std::vector<GLfloat> &cords, int dots_amount,
                                double flip_angle) {
  for (int i = 0; i < dots_amount; i += 3) {
    double rem_cur = cords[i + 1];
    cords[i + 1] = rem_cur * cos(flip_angle) - cords[i + 2] * sin(flip_angle);
    cords[i + 2] = rem_cur * sin(flip_angle) + cords[i + 2] * cos(flip_angle);
  }
}

void RotateCommand::flip_rel_y_(std::vector<GLfloat> &cords, int dots_amount,
                                double flip_angle) {
  for (int i = 0; i < dots_amount; i += 3) {
    double rem_cur = cords[i];
    cords[i] = rem_cur * cos(flip_angle) - cords[i + 2] * sin(flip_angle);
    cords[i + 2] = rem_cur * sin(flip_angle) + cords[i + 2] * cos(flip_angle);
  }
}

void RotateCommand::Execute() {
  if (axis_ == 'x') {
    flip_rel_x_(GetModel()->vertexes_, GetModel()->vertexes_.size(), angle_);
  } else if (axis_ == 'y') {
    flip_rel_y_(GetModel()->vertexes_, GetModel()->vertexes_.size(), angle_);
  } else {
    flip_rel_z_(GetModel()->vertexes_, GetModel()->vertexes_.size(), angle_);
  }
}

void MoveCommand::Execute() {
  int i;
  if (axis_ == 'x') {
    i = 0;
  } else if (axis_ == 'y') {
    i = 1;
  } else {
    i = 2;
  }
  for (; i < GetModel()->vertexes_.size() - 1; i += 3) {
    GetModel()->vertexes_[i] += dist_;
  }
}

void ScaleCommand::Execute() {
  for (int i = 0; i < GetModel()->vertexes_.size() - 1; i++) {
    GetModel()->vertexes_[i] *= value_;
  }
}

void ParseCommand::Execute() {
  std::vector<GLfloat> &vertexes = GetModel()->vertexes_;
  std::vector<std::vector<GLuint>> &fasets = GetModel()->fasets_;
  std::ifstream file(path_);
  std::string str;
  if (file.is_open()) {
    while (std::getline(file, str)) {
      int str_p = 2;
      if (str[0] == 'f') {
        double x = std::stod(str.substr(str_p));
        while (str[str_p] != ' ') str_p++;
        str_p++;
        double y = std::stod(str.substr(str_p));
        while (str[str_p] != ' ') str_p++;
        str_p++;
        double z = std::stod(str.substr(str_p));
        vertexes.push_back(x);
        vertexes.push_back(y);
        vertexes.push_back(z);
      } else if (str[0] == 'v') {
        std::vector<GLuint> faset;
        while (str_p < str.size()) {
          GLuint dot_id = std::stoi(str.substr(str_p));
          faset.push_back(dot_id);
          while (str_p < str.size() && str[str_p] != ' ') str_p++;
          str_p++;
        }
        fasets.push_back(faset);
      }
    }
  } else {
    throw std::logic_error("file " + path_ + " doesn't exist");
  }
}

}  // namespace s21
