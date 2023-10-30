# 3DViewer

This is an app that used to open .obj files and view some 3D models.

## Usage

* Move to the build dir
* Use a makefile, type: `make install` and the project should be built, if you have some problems with that, make sure that you are fine with dependencies for this project
* App will be built inside build_files, you will know when you see it, it has .App extension
* Open the app, choose some .obj files and go use the rotating and screenshoting it.

## Dependencies

* Project was built, writen and tested on Linux and MacOS! 
* qt-6
* g++ 10.3.0
* make GNU 3.81
* cmake 3.23.0
* OpenGL/OpenGL.h, you can try to change it manually to GL/glut.h in the src/model/model.h and src/model/afine_strategy.h and the project still should be fine, but i'm not sure

#### if u want to test it (I'm still working on that, it should be easier to test it manually):

* lcov 2.0-1
* lgtest 1.14.0
