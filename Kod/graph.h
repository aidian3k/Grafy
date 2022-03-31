#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct listV {
	int Vn; //numer wierzcholka do ktorego prowadzi krawedz
	long double waga; // waga krawedzi
	struct listV * next;
} * listV_t;

listV_t dodaj(listV_t listV, int vn, long double w);
listV_t * generujGraf(int W, int K, long double a, long double b);
long double losuj(long double a, long double b);
void zapisz_graf_do_pliku(listV_t *graph, int W, int K, char *plik);
void free_graph(listV_t *graph, int *wymiary);

#endif