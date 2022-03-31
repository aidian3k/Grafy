/* Tutaj ma być kopiec do dijkstry */

#ifndef _PQ_H_
#define _PQ_H_

typedef struct {
	double d; //dystans
	int w; //wierzcholek
} wierzcholek;

typedef struct {
	wierzcholek *q; //kolejka
	int n; // liczba elementow kolejki
	int s; // rozmiar 
} * pq_t;

pq_t init_pq(int size);

void add_to_pq( pq_t pq, wierzcholek x );

int not_empty_pq( pq_t pq );

wierzcholek pop_from_pq( pq_t pq );

void free_pq( pq_t pq );

#endif



