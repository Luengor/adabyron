main : main.c
	prepreprocessor main.c ppmain.c
	gcc ppmain.c -o main -std=gnu89 -fsanitize=address -fsanitize=leak -g
	rm ppmain.c

mainperomal: main.c
	gcc main.c -o main

