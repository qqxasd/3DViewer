#include "command.h"

namespace s21 {

void RotateCommand::Execute() {
  if (axis_ == 'x') {
    RotateStrategyX strategy(*vertexes_, angle_);
    strategy.use();
  } else if (axis_ == 'y') {
    RotateStrategyY strategy(*vertexes_, angle_);
    strategy.use();
  } else {
    RotateStrategyZ strategy(*vertexes_, angle_);
    strategy.use();
  }
}

void MoveCommand::Execute() {
  MoveStrategy strategy(*vertexes_, dist_, axis_);
  strategy.use();
}

void ScaleCommand::Execute() {
  ScaleStrategy strategy(*vertexes_, value_);
  strategy.use();
}

void ParseCommand::Execute() {
  std::vector<GLfloat> &vertexes = *vertexes_;
  std::vector<std::vector<GLuint>> &fasets = *fasets_;
  vertexes.clear();
  fasets.clear();
  std::ifstream file(path_);
  std::string str;
    double max = 1.0;
  if (file.is_open()) {
    while (std::getline(file, str)) {
      int str_p = 2;
      if (str[0] == 'v' && str[1] == ' ') {
        str_p++;
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
        if (fabs(x) > max)
            max = fabs(x);
        if (fabs(y) > max)
            max = fabs(y);
        if (fabs(z) > max)
            max = fabs(z);
      } else if (str[0] == 'f') {
        std::vector<GLuint> faset;  
        while (str_p < str.size()) {
          GLuint dot_id = std::stoi(str.substr(str_p));
          faset.push_back(dot_id - 1);
          while (str_p < str.size() && str[str_p] != ' ') str_p++;
          while (str_p < str.size() && !(str[str_p] >= '0' && str[str_p] <= '9')) str_p++;
        }
        fasets.push_back(faset);
      }
    }
    for (auto &v : vertexes) {
      v /= max;
    }
  }
}
} // namespace s21
