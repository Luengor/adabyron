CC := clang
CFLAGS := -std=gnu89 -fsanitize=address -fsanitize=leak -g --pedantic -Wunused-variable


main : main.c
	prepreprocessor main.c ppmain.c
	$(CC) ppmain.c -o main $(CFLAGS) 
	rm ppmain.c

test: main
	./main < sample.in > output
	diff output sample.out

