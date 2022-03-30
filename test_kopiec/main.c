#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pq.h"
#include <assert.h>

#define SIZE 64

//Aby uruchomić testy: ./grafy

int main( int argc, char **argv ) {

	wierzcholek test11[] = {{42.0, 2}, {5.53, 4}, {5.0, 1}, {0.425, 3}, {1.2, 0}}; 
	wierzcholek test11_zdjete[] = {{42.0, 2}, {5.53, 4}, {5.0, 1}, {1.2, 0}, {0.425, 3}};
	
	wierzcholek test12[] = {{86.2474, 4}, {79.0586, 2}, {75.912500, 0}, {21.276100, 1}, {34.665500, 3}}; 
	wierzcholek test12_zdjete[] = {{86.2474, 4}, {79.0586, 2}, {75.9125, 0}, {34.6655, 3}, {21.2761, 1}};
	
	wierzcholek test13[] = {{96.059400, 3}, {80.231500, 1}, {81.927500, 5}, {59.130900, 0}, {17.282000, 9}, {67.317300, 2}, {20.184500, 6}, {47.440800, 7}, {28.942300, 8}, {3.284380, 4}}; 
	wierzcholek test13_zdjete[] = {{96.059400, 3}, {81.927500, 5},{80.231500, 1}, {67.317300, 2},{59.130900, 0}, {47.440800, 7}, {28.942300, 8}, {20.184500, 6}, {17.282000, 9}, {3.284380, 4},};
	
	pq_t pq = init_pq( SIZE );
	int n;
	wierzcholek x;
	
	//test 11
	FILE *dane1 = fopen("dane1.txt", "r");
	fscanf(dane1, "%d", &n);
	for(int i=0; i<n; i++) {
		fscanf(dane1, "%d %lf", &x.w, &x.d);
		add_to_pq(pq, x);
	}
	for(int i=0; i<n; i++) {
		x = pq->q[i];
		assert(test11[i].d == x.d && test11[i].w == x.w);
	}
	for(int i=0; i<n; i++) {
		x = pop_from_pq(pq);
		assert(test11_zdjete[i].d == x.d && test11_zdjete[i].w == x.w);
	}
	
	//test12
	FILE *dane2 = fopen("dane2.txt", "r");
	fscanf(dane2, "%d", &n);
	for(int i=0; i<n; i++) {
		fscanf(dane2, "%d %lf", &x.w, &x.d);
		add_to_pq(pq, x);
	}
	for(int i=0; i<n; i++) {
		x = pq->q[i];
		assert(test12[i].d == x.d && test12[i].w == x.w);
	}
	for(int i=0; i<n; i++) {
		x = pop_from_pq(pq);
		assert(test12_zdjete[i].d == x.d && test12_zdjete[i].w == x.w);
	}
	
	//test13
	FILE *dane3 = fopen("dane3.txt", "r");
	fscanf(dane3, "%d", &n);
	for(int i=0; i<n; i++) {
		fscanf(dane3, "%d %lf", &x.w, &x.d);
		add_to_pq(pq, x);
	}
	/*
	for(int i=0; i<n; i++) {
		printf("%lf %d ", pq->q[i].d, pq->q[i].w);
	}
	*/
	for(int i=0; i<n; i++) {
		x = pq->q[i];
		assert(test13[i].d == x.d && test13[i].w == x.w);
	}
	for(int i=0; i<n; i++) {
		x = pop_from_pq(pq);
		assert(test13_zdjete[i].d == x.d && test13_zdjete[i].w == x.w);
	}

	free_pq( pq );
	return 0;
}


