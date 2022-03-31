all:
	cc -c graph.c
	cc -c main.c
	cc -c dijkstra_algorithm.c
	cc -c graph.c read.c 
	cc -c errors.c
	cc -c pq.c
	cc -o dijkstra main.o graph.o dijkstra_algorithm.o read.o  errors.o pq.o
	./dijkstra
clean:
	rm *.o
