CC := clang++
CFLAGS := -std=c++11 -fsanitize=address -fsanitize=leak -g -Wunused-variable
LFLAGS := -lstdc++

main : main.cpp

test: main
	./main < sample.in > output
	diff output sample.out

copy: main.cpp
	cat main.cpp | wl-copy 

