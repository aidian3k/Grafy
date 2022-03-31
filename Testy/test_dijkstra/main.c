#include <assert.h>
#include "graph.h"
#include "dijkstra_algorithm.h"
#include "read.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


//Aby uruchomić testy: ./grafy

int compare_double(double x, double y){
   double epsilon = 0.000001f;
   if(fabs(x - y) < epsilon)
      return 1; 
   return 0; 
}

int main(int argc, char **argv) {
	int wymiary[2];
	
	//TEST 31
	FILE *dane31=fopen("dane31.txt","r");
	listV_t *graph=czytaj_graf_z_pliku(dane31,wymiary);
	//printf("%lf", DIJKSTRA_ALGORITHM(wymiary[1]*wymiary[0],1-1,4-1,graph));
	assert(compare_double(DIJKSTRA_ALGORITHM(wymiary[1]*wymiary[0],1-1,4-1,graph), 3.0));
	assert(compare_double(DIJKSTRA_ALGORITHM2(wymiary[1]*wymiary[0],1-1,4-1,graph), 3.0));
	free_graph(graph,wymiary);
	printf("TEST 31 OK (DIJKSTRA)\n");
	
	//TEST 32
	FILE *dane32=fopen("dane32.txt","r");
	graph=czytaj_graf_z_pliku(dane31,wymiary);
	//printf("%lf", DIJKSTRA_ALGORITHM(wymiary[1]*wymiary[0],12-1,1-1,graph));
	assert(compare_double(DIJKSTRA_ALGORITHM(wymiary[1]*wymiary[0],12-1,1-1,graph), 146.105164));
	assert(compare_double(DIJKSTRA_ALGORITHM2(wymiary[1]*wymiary[0],12-1,1-1,graph), 146.105164));
	printf("TEST 32 OK (DIJKSTRA)\n");
	
	free_graph(graph,wymiary);
	return 0;	
}

