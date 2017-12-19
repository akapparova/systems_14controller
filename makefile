all:
	gcc controller.c
run: all
	./a.out
clean: 
	rm a.out
	rm *~
