main:
	gcc main.c array.c -o run

run: main
	./run

clean:
	rm run
