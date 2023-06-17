CC := clang
CFLAGS := -std=gnu89 -fsanitize=address -fsanitize=leak -g --pedantic -Wunused-variable

main : main.cpp
	$(CC) main.cpp -o main $(CFLAGS) 

test: main
	./main < sample.in > output
	diff output sample.out

copy: main.cpp
	cat main.cpp | wl-copy 

