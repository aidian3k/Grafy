all:
	cc -c graph.c
	cc -c main.c
	cc -c bfs_algorithm.c
	cc -c dijkstra_algorithm.c
	cc -c errors.c
	cc -c graph.c read.c 
	cc -c pq.c
	cc -o grafy main.o graph.o bfs_algorithm.o dijkstra_algorithm.o errors.o read.o pq.o
clean:
	rm *.o
