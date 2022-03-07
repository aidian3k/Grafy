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
	printf("%d",BFS_ALGORITHM(1,W*K,graph));
}


