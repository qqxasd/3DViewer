#ifndef CPP4_3DVIEWER_V2_0_1_MODEL_MODEL_H_
#define CPP4_3DVIEWER_V2_0_1_MODEL_MODEL_H_

#include <vector>

#include "OpenGL/OpenGL.h"

#include "command.h"

namespace s21 {

/**
 * @brief MVC model, there all commands are executed
*/
class Model {
 public:
 /**
  * @brief default constructor
 */
  Model() {}
  /**
   * @brief Vertexes getter
  */
  std::vector<GLfloat> *GetVertexes() noexcept { return &vertexes_; }
  /**
   * @brief Fasets getter
  */
  std::vector<std::vector<GLuint>> *GetFasets() { return &fasets_; }
  /**
   * @brief Executes the command
   * @param command - command to be executed
  */
  void ExecuteCommand(Command &command) { command.Execute(); }

 private:
  std::vector<GLfloat> vertexes_;
  std::vector<std::vector<GLuint>> fasets_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_1_MODEL_MODEL_H_
