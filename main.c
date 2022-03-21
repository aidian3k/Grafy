#include "graph.h"
#include "bfs_algorithm.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
	int W,K;
	double a,b;
	W=atoi(argv[1]);
	K=atoi(argv[2]);
	a=0;
	b=1;
	listV_t *graph=generujGraf(W,K,a,b);
	zapisz_graf_do_pliku(graph,W,K,"wyjscie");
	if(BFS_ALGORITHM(W*K,graph)==1) printf("Spojny");
	else printf("Niespojny");
}


