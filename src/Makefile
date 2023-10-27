CFLAGS = -Wall -Werror -Wextra
ARCH = $(shell arch)
ifeq "$(ARCH)" "i386"
MYFLAGS = -lm --coverage -lgtest -lgtest_main -std=c++17 -pthread
endif
ifeq "$(ARCH)" "x86_64"
MYFLAGS =-L/usr/lib -lm --coverage -lgtest
endif

all: clean test gcov_report

test:
	g++ tests/tests.cc controller/* model/* $(MYFLAGS) -o test
	./test
	gcov controller/*
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out

install:
	mkdir build
	cmake CMakeLists.txt -B build
	cmake --build build
	cp -r build/3dviewer_v2.app 3dviewer_v2.app
	rm -rf build

uninstall:
	rm -rf 3dviewer_v2.app

dist: install
	tar -czf calc.tar.gz 3dviewer_v2.app
	rm -rf 3dviewer_v2.app
	
dvi:
	open dvi.html

gcov_report: test
	./test
	gcovr --html-details rep.html
	open rep.html


clean:
	rm -rf *.o *.gcda *.a *.html *.gcno *.css
	rm -f test
	rm -rf *.gcno *.gcov *.gcda *.info ../*.h.gch
	rm -rf build
	rm -rf 3dviewer_v2.app

	

style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i *.cc model/*.cc view/*.cc controller/*.cc model/tests/*.cc
	clang-format -i *.h model/*.h view/*.h controller/*.h model/tests/*.h
	
git:
	git add *.cpp *.h *.cc model/*.cc model/*.h view/*.cc view/*.h controller/*.cc controller/*.h *.ui view/*.ui
	git add Makefile
	git add CMakeLists.txt
	git add view/*.vsh view/*.fsh
	git add ExtLibs/QtGifImage/src/3rdParty/giflib/CMakeLists.txt
	git add ExtLibs/QtGifImage/src/3rdParty/giflib/*.c
	git add ExtLibs/QtGifImage/src/3rdParty/giflib/*.h
	git add ExtLibs/QtGifImage/src/gifimage/CMakeLists.txt
	git add ExtLibs/QtGifImage/src/gifimage/*.cpp
	git add ExtLibs/QtGifImage/src/gifimage/*.h
	
	
