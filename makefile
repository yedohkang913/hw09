all: dir_info.c
	gcc -o run dir_info.c

run: all
	./run

clean: 
	rm run
	rm a.out
