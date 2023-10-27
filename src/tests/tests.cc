#include "../controller/mwcontroller.h"
#include "../controller/command.h"

#include <gtest/gtest.h>

TEST(parser, vertexes) {
  s21::MWController* mw_cont_ = new s21::MWController;
  s21::ParseCommand pc(mw_cont_->model_, "tests/cube.obj");
  pc.Execute();

  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[0], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[1], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[2], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[3], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[4], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[5], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[6], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[7], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[8], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[9], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[10], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[11], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[12], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[13], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[14], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[15], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[16], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[17], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[18], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[19], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[20], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[21], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[22], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[23], 0);
}


TEST(rotation, rotate_x) {
  s21::MWController* mw_cont_ = new s21::MWController;
  s21::ParseCommand pc(mw_cont_->model_, "tests/cube.obj");
  pc.Execute();
  s21::RotateCommand rc(mw_cont_->model_, 'x', 3);
  rc.Execute();
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[0], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[1], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[2], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[3], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[4], -0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[5], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[6], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[7], -0.14112);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[8], -0.9899925);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[9], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[10], -0.9899925);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[11], 0.14112);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[12], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[13], -1.1311125);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[14], -0.84887248);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[15], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[16], -0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[17], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[18], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[19], -0.14112);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[20], -0.9899925);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[21], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[22], -0.9899925);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[23], 0.14112);

}


TEST(rotation, rotate_y) {
  s21::MWController* mw_cont_ = new s21::MWController;
  s21::ParseCommand pc(mw_cont_->model_, "tests/cube.obj");
  pc.Execute();
  s21::RotateCommand rc(mw_cont_->model_, 'y', 2);
  rc.Execute();
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[0], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[1], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[2], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[3], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[4], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[5], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[6], -0.90929741);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[7], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[8], -0.41614684);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[9], -0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[10], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[11], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[12], -0.90929741);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[13], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[14], -0.41614684);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[15], -0.41614684);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[16], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[17], 0.90929741);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[18], -1.3254442);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[19], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[20], 0.49315059);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[21], -0.41614684);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[22], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[23], 0.90929741);
}


TEST(rotation, rotate_z) {
  s21::MWController* mw_cont_ = new s21::MWController;
  s21::ParseCommand pc(mw_cont_->model_, "tests/cube.obj");
  pc.Execute();
  s21::RotateCommand rc(mw_cont_->model_, 'z', 2);
  rc.Execute();
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[0], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[1], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[2], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[3], -0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[4], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[5], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[6], -0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[7], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[8], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[9], -0.90929741);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[10], -0.41614684);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[11], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[12], -0.90929741);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[13], -0.41614684);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[14], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[15], -0.41614684);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[16], 0.90929741);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[17], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[18], -0.41614684);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[19], 0.90929741);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[20], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[21], -1.3254442);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[22], 0.49315059);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[23], 0);
}

TEST(scale, scale_test) {
  s21::MWController* mw_cont_ = new s21::MWController;
  s21::ParseCommand pc(mw_cont_->model_, "tests/cube.obj");
  pc.Execute();
  s21::ScaleCommand sc(mw_cont_->model_, 2);
  sc.Execute();
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[0], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[1], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[2], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[3], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[4], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[5], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[6], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[7], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[8], 2);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[9], -0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[10], 2);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[11], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[12], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[13], 2);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[14], 2);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[15], 2);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[16], -0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[17], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[18], 2);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[19], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[20], 2);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[21], 2);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[22], 2);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[23], 0);

}

TEST(move, move_x) {
  s21::MWController* mw_cont_ = new s21::MWController;
  s21::ParseCommand pc(mw_cont_->model_, "tests/cube.obj");
  pc.Execute();
  s21::MoveCommand mc(mw_cont_->model_, 'x', 8);
  mc.Execute();

  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[0], 8);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[1], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[2], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[3], 8);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[4], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[5], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[6], 8);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[7], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[8], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[9], 8);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[10], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[11], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[12], 8);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[13], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[14], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[15], 9);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[16], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[17], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[18], 9);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[19], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[20], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[21], 9);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[22], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[23], 0);

}

TEST(move, move_y) {
  s21::MWController* mw_cont_ = new s21::MWController;
  s21::ParseCommand pc(mw_cont_->model_, "tests/cube.obj");
  pc.Execute();
  s21::MoveCommand mc(mw_cont_->model_, 'y', 4);
  mc.Execute();

  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[0], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[1], 4);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[2], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[3], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[4], 4);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[5], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[6], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[7], 4);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[8], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[9], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[10], 5);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[11], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[12], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[13], 5);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[14], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[15], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[16], 4);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[17], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[18], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[19], 4);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[20], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[21], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[22], 5);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[23], 0);
}

TEST(move, move_z) {
  s21::MWController* mw_cont_ = new s21::MWController;
  s21::ParseCommand pc(mw_cont_->model_, "tests/cube.obj");
  pc.Execute();
  s21::MoveCommand mc(mw_cont_->model_, 'z', 0);
  mc.Execute();

  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[0], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[1], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[2], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[3], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[4], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[5], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[6], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[7], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[8], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[9], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[10], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[11], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[12], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[13], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[14], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[15], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[16], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[17], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[18], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[19], 0);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[20], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[21], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[22], 1);
  EXPECT_FLOAT_EQ(mw_cont_->model_->vertexes_[23], 0);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  return 0;
}
