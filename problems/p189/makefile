main : main.c
	prepreprocessor main.c ppmain.c
	gcc ppmain.c -o main -std=gnu89 -fsanitize=address -fsanitize=leak -g
	rm ppmain.c

mainperomal: main.c
	prepreprocessor main.c ppmain.c
	gcc ppmain.c -o main -std=gnu89
	rm ppmain.c

test: main
	./main < sample.in > output
	diff output sample.out

