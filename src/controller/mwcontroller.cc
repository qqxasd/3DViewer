#include "mwcontroller.h"
using namespace s21;
MWController::MWController() { model_ = new Model(); }

GLfloat *MWController::GetVertexes() { return model_->GetVertexes()->data(); }

GLuint MWController::GetVertexCount() { return model_->GetVertexes()->size(); }

std::vector<std::vector<GLuint>> &MWController::GetFasets() {
  return *(model_->GetFasets());
}
