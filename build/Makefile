CFLAGS = -Wall -Werror -Wextra
ARCH = $(shell arch)
ifeq "$(ARCH)" "i386"
MYFLAGS = -lm --coverage -lgtest -lgtest_main -std=c++17 -pthread
endif
ifeq "$(ARCH)" "x86_64"
MYFLAGS =-L/usr/lib -lm --coverage -lgtest
endif

all: install

test:
	g++ tests/tests.cc controller/* model/* $(MYFLAGS) -o test
	./test
	gcov controller/*
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out

install:
	mkdir build_files
	cmake ../src/CMakeLists.txt -B build_files
	cd build_files && make

uninstall:
	rm -rf 3dviewer_v2.app

dist: install
	tar -czf calc.tar.gz 3dviewer_v2.app
	rm -rf 3dviewer_v2.app
	
dvi:
	doxygen Doxyfile
	open html/index.html

gcov_report: test
	./test
	gcovr --html-details rep.html
	open rep.html


clean:
	rm -rf *.o *.gcda *.a *.html *.gcno *.css
	rm -f test
	rm -rf *.gcno *.gcov *.gcda *.info ../*.h.gch
	rm -rf build_files
	rm -rf 3dviewer_v2.app
	rm -rf latex html
	

style:
	clang-format -i -style=Google *.cc model/*.cc view/*.cc controller/*.cc model/tests/*.cc
	clang-format -i -style=Google *.h model/*.h view/*.h controller/*.h model/tests/*.h