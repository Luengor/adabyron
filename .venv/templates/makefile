CC := clang++
CFLAGS := -std=c++11 -fsanitize=address -fsanitize=leak -g -Wunused-variable
LFLAGS := -lstdc++

main : main.cpp
	prepreprocessor main.cpp ppmain.cpp
	$(CC) ppmain.cpp -o main $(CFLAGS) $(LFLAGS)
	rm ppmain.cpp

test: main
	./main < sample.in > output
	diff output sample.out

copy: main.cpp
	prepreprocessor main.cpp | wl-copy 

