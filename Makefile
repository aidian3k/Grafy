all:
	cc -c graph.c
	cc -c main.c
	cc -c bfs_algorithm.c
	cc main.o graph.o bfs_algorithm.o
	
clean:
	rm *.o
