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

std::pair<int, int> ParseCommand::CountSize_(const char *path) const noexcept {
  FILE *file = fopen(path, "r");
  char buf[100];
  long v_size = 0, f_size = 0;
  if (file != nullptr) {
    while (!feof(file) && !ferror(file)) {
      fgets(buf, 100, file);
      if (buf[0] == 'v' && buf[1] == ' ') {
        v_size++;
      } else if (buf[0] == 'f' && buf[1] == ' ') {
        f_size++;
      }
    }
  }
  fclose(file);
  return std::make_pair(v_size, f_size);
}

void ParseCommand::ParseVertexes_(long vertex_count) const noexcept {
  double max = 1;
  FILE *file = fopen(path_.c_str(), "r");
  char buf[100] = {0};
  while (!feof(file) && !ferror(file)) {
    fgets(buf, 100, file);
    std::string str = buf;
    int str_p = 3;
    if (str[0] == 'v' && str[1] == ' ') {
      double x = std::stof(str.substr(str_p));
      while (str[str_p] != ' ') str_p++;
      str_p++;
      double y = std::stof(str.substr(str_p));
      while (str[str_p] != ' ') str_p++;
      str_p++;
      double z = std::stof(str.substr(str_p));
      vertexes_->push_back(x);
      vertexes_->push_back(y);
      vertexes_->push_back(z);
      max = std::max(std::max(std::abs(x), std::abs(y)),
                     std::max(std::abs(z), max));
    }
  }
  for (auto &v : *vertexes_) {
    v /= max;
  }
  fclose(file);
}

void ParseCommand::ParseFasets_(long fasets_count) const noexcept {
  char buf[100] = {0};
  FILE *file = fopen(path_.c_str(), "r");
  while (!feof(file) && !ferror(file)) {
    fgets(buf, 100, file);
    std::string str = buf;
    if (str[0] == 'f') {
      int str_p = 2;
      std::vector<GLuint> faset;
      while (str_p < str.size()) {
        GLuint dot_id = std::stoi(str.substr(str_p));
        faset.push_back(dot_id - 1);
        while (str_p < str.size() && str[str_p] != ' ') str_p++;
        while (str_p < str.size() && !(str[str_p] >= '0' && str[str_p] <= '9'))
          str_p++;
      }
      fasets_->push_back(faset);
    }
  }
  fclose(file);
}

void ParseCommand::Execute() {
  std::ios::sync_with_stdio(false);
  vertexes_->clear();
  fasets_->clear();
  auto size = CountSize_(path_.c_str());
  vertexes_->reserve(size.first);
  fasets_->reserve(size.second);
  std::thread th([this, size]() { this->ParseFasets_(size.second); });
  ParseVertexes_(size.first);
  th.join();
  std::ios::sync_with_stdio(true);
}
}  // namespace s21
