CC = gcc
OS1LVL = $(shell uname)
OS2LVL = $(shell uname -o)
CFLAGS = -Wall -Werror -Wextra -g -std=c11 

ALL_FUNC = $(wildcard ./*.c)

SOURCE_TESTS_FUNC = $(wildcard ./tests/*.c ./tests/s21_matrix/*.c)


ifeq ($(OS1LVL), Darwin)
	det_OS = -lcheck -lm -lpthread
	GCOV_FLAGS = -fprofile-arcs -ftest-coverage
else
	ifeq ($(OS2LVL), GNU/Linux)
		det_OS = -lcheck -lm -lpthread -lrt -lsubunit
	else
		det_OS = -lcheck -lm -lpthread -lrt
		GCOV_FLAGS = -fprofile-arcs -ftest-coverage
	endif
endif


all: s21_matrix.a

test: 
	@$(CC) $(CFLAGS) $(ALL_FUNC) $(SOURCE_TESTS_FUNC) $(GCOV_FLAGS) -g --coverage s21_matrix.a -o s21_test_matrix $(det_OS)
	@./s21_test_matrix

s21_matrix.a:
	@$(CC) $(CFLAGS) $(ALL_FUNC) -g -c
	@ar rc s21_matrix.a *.o
	@ranlib s21_matrix.a

gcov_report: clean s21_matrix.a test
	@lcov -t "s21_test_matrix" -o test.info --no-external -c -d .
	@genhtml -o report test.info
	open report/index.html
	rm -rf *.gcno *gcda *.gco

clean:
	@rm -rf test *.gcda *.gcno *.o *.info *.a *.h.gch tests/*.gcno report 
	@rm -rf s21_test_matrix
	@rm -rf tests/*.h.gch 

style:
	clang-format -n -style=google *.h $(ALL_FUNC) $(SOURCE_TESTS_FUNC)
	@rm -rf .clang-format

style_repair:
	@cp ../materials/linters/.clang-format ../src  
	@clang-format -i -style=google *.h $(ALL_FUNC) $(SOURCE_TESTS_FUNC)

leaks:
	valgrind --tool=memcheck --leak-check=yes ./s21_test_matrix

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov