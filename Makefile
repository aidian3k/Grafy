all:
	cc -c graph.c
	cc -c main.c
	cc -c bfs_algorithm.c
	cc -c dijkstra_algorithm_slaby.c
	cc main.o graph.o bfs_algorithm.o dijkstra_algorithm_slaby.o
clean:
	rm *.o
