CC := clang
CFLAGS := -std=c++11 -fsanitize=address -fsanitize=leak -g --pedantic -Wunused-variable

main : main.cpp
	$(CC) main.cpp -o main $(CFLAGS) 

test: main
	./main < sample.in > output
	diff output sample.out

copy: main.cpp
	cat main.cpp | wl-copy 

