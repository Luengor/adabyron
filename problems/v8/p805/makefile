CXX = clang++
CXXFLAGS = -fuse-ld=mold -std=c++11 -fsanitize=address -fsanitize=leak -g -Wunused-variable

main : main.cpp

test: main
	./main < sample.in > output
	diff output sample.out

pablo: main
	./main < pablo.in > output
	diff output pablo.out

copy: main.cpp
	cat main.cpp | wl-copy 

