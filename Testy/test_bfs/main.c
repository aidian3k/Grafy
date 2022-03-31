#include "graph.h"
#include "bfs_algorithm.h"
#include "read.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <assert.h>

//Aby uruchomić testy: ./grafy

int main(int argc, char **argv) {
	int wymiary[2];
	
	//TEST 21
	FILE *dane21=fopen("graf_spojny.txt","r");
	listV_t *graph=czytaj_graf_z_pliku(dane21,wymiary); 
	assert(BFS_GOING(wymiary,graph) == 1); //test dla grafu spojnego
	free_graph(graph,wymiary);
	printf("TEST 21 OK (BFS)\n");
	
	//TEST 22
	FILE *dane22=fopen("graf_niespojny.txt","r");
	graph=czytaj_graf_z_pliku(dane22,wymiary); 
	assert(BFS_GOING(wymiary,graph) == 0); //test dla grafu spojnego
	free_graph(graph,wymiary);
	printf("TEST 22 OK (BFS)\n");
	
}

