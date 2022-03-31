all:
	cc -c ../Kod/graph.c 
	cc -c ../Kod/main.c
	cc -c ../Kod/bfs_algorithm.c
	cc -c ../Kod/dijkstra_algorithm.c
	cc -c ../Kod/errors.c
	cc -c ../Kod/graph.c ../Kod/read.c 
	cc -c ../Kod/pq.c
	cc -o ../Kod/grafy main.o graph.o bfs_algorithm.o dijkstra_algorithm.o errors.o read.o pq.o
.SILENT:
test: 
	make -C ../Testy/test_kopiec
	make -C ../Testy/test_bfs
	make -C ../Testy/test_dijkstra
clean:
	rm *.o
