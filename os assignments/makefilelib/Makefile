main: main.o libarith.a
	gcc -o main main.o -larith -L.
main.o: main.c
	gcc -c -o main.o main.c

clean: 
	rm -rf *.o main
