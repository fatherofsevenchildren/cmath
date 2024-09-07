CC = gcc
LDFLAGS = -lcheck
FLAGS = -Wall -Werror -Wextra -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage

UNAME= $(shell uname -s)
ifeq ($(UNAME), Linux)
	OPEN_CMD = xdg-open
	LDFLAGS += -lm  -lsubunit -lpthread -lrt 
endif

all: s21_math.a test

s21_math.a: clean
	$(CC) $(GCCFLAGS) -std=c11 -c s21_*.c
	ar rc s21_math.a *.o
	mkdir binary_files
	mv *.o binary_files


gcov_report: s21_math.a
	gcc $(FLAGS) $(GCOVFLAGS) $(LDFLAGS) s21_*.c math_test.c  -o gcovreport
	./gcovreport
	lcov -t "gcovreport" -o gcovreport.info -c -d .
	genhtml -o report gcovreport.info
	rm -rf gcovreport gcovreport.info *.gcda *.gcno math_test.gcda math_test.gcno

test: s21_math.a
	$(CC) $(FLAGS) $(LDFLAGS) math_test.c s21_math.a -o math_test
	./math_test

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info binary_files test math_test report

valgrind_check:
	$(CC) $(SRC_TEST) $(LIB) -o $(TEST) $(LDFLAGS)
	CK_FORK=no valgrind --leak-check=full ./$(TEST)


style_check:
	cppcheck --enable=all --suppress=missingIncludeSystem .
	clang-format --style=Google -i *.c *.h

.PHONY: all, clean, test, s21_math.a, gcov_report