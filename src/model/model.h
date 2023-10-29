#ifndef CPP4_3DVIEWER_V2_0_1_MODEL_MODEL_H_
#define CPP4_3DVIEWER_V2_0_1_MODEL_MODEL_H_

#include "OpenGL/OpenGL.h"
#include "command.h"
#include <vector>

namespace  s21  {

class Model
{
public:
    Model();
    std::vector<GLfloat> *GetVertexes() noexcept {return &vertexes_;}
    std::vector<std::vector<GLuint>> *GetFasets() {return &fasets_;}
    void ExecuteCommand(Command &command) {
        command.Execute();
    }
private:
    std::vector<GLfloat> vertexes_;
    std::vector<std::vector<GLuint>> fasets_;
};
}
#endif // CPP4_3DVIEWER_V2_0_1_MODEL_MODEL_H_
