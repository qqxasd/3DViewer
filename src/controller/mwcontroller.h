#ifndef CPP4_3DVIEWER_V2_0_1_CONTROLLER_MWCONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_1_CONTROLLER_MWCONTROLLER_H_
#include "../model/model.h"
#include <cstring>

namespace s21 {

class MWController {
 public:
  MWController();
  std::vector<std::vector<GLuint>> &GetFasets();
  GLfloat *GetVertexes();
  GLuint GetVertexCount();
  GLuint GetFasetsCount();
  bool ContainsModel() {
    return model_ != nullptr;
  }
  void PerformRotate(char axis, double angle) {
    RotateCommand rc(model_->GetVertexes(), axis, angle);
    model_->ExecuteCommand(rc);
  }
  void PerformMove(char axis, double dist) {
    MoveCommand mc(model_->GetVertexes(), axis, dist);
    model_->ExecuteCommand(mc);
  }
  void PerformScale(double val) {
    ScaleCommand sc(model_->GetVertexes(), val);
    model_->ExecuteCommand(sc);
  }
  void PerformParse(std::string path) {
    ParseCommand pc(model_->GetVertexes(), model_->GetFasets(), path);
    model_->ExecuteCommand(pc);
  }


 private:
  Model *model_;
};
}  // namespace s21
#endif  //CPP4_3DVIEWER_V2_0_1_CONTROLLER_MWCONTROLLER_H
