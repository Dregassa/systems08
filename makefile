all: main.c
	gcc -o stat_test main.c

run: all
	./stat_test
