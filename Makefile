all:
	cc -c graph.c
	cc -c main.c
	cc main.o graph.o
	
clean:
	rm *.o
