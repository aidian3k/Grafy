all:
	cc -c graph.c
	cc -c main.c
	cc -c bfs_algorithm.c
	cc -c dijkstra_algorithm_slaby.c
	cc -c errors.c
	cc -o grafy main.o graph.o bfs_algorithm.o dijkstra_algorithm_slaby.o errors.o
clean:
	rm *.o
