CC := clang
CFLAGS := -std=gnu89 -fsanitize=address -fsanitize=leak -g -Wall 


main : main.c
	prepreprocessor main.c ppmain.c
	$(CC) ppmain.c -o main $(CFLAGS) 
	rm ppmain.c

test: main
	./main < sample.in > output
	diff output sample.out

testpython: main tester.py
	python3 tester.py 0 pysample.in
	./main < pysample.in 

