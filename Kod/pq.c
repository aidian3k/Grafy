#include "pq.h"

#include <stdlib.h>

int parent(int i) {
        return (i - 1) / 2;
}
void swap(wierzcholek* x, wierzcholek * y) {
        wierzcholek temp = * x;
        * x = * y;
        * y = temp;
}

pq_t init_pq( int size ) {
	pq_t q = malloc( sizeof * q );
	q->q = malloc( size * sizeof *(q->q) );
	q->s = size;
	q->n = 0;
	return q;
}

static void double_pq_size( pq_t pq ) {
	wierzcholek *nq = realloc( pq->q, 2 * pq->s * sizeof *(pq->q) );
	if( nq == NULL )
		exit( 1 );
	pq->q = nq;
	pq->s *= 2;
}

void heap_up( wierzcholek h[], int n ) {
// before: h[0]...h[n-2] - a heap, h[n-1] - new element
// after: h[0]...h[n-1] - a heap
    int i = n-1; 
    while( i > 0 && h[parent(i)].d < h[i].d  ) {
	   swap(&h[parent(i)], &h[i]);
	   i=parent(i); 
	
    }
}

void add_to_pq( pq_t pq, wierzcholek x ) {
	if( pq->n == pq->s )
		double_pq_size( pq );
	pq->q[pq->n++] = x;
	heap_up( pq->q, pq->n );
}

int not_empty_pq( pq_t pq ) {
	return pq->n != 0;
}

static void heap_down( wierzcholek h[], int n ) {
// before: h[0]...h[n-1] - a heap but relation h[0] -> children can be false
// after: h[0]..h[n-1] - a heap
	int i = 0;
	int c = 2*i + 1;
	while( c < n ) {
		if( c+1 < n && h[c+1].d > h[c].d )
			c++;
		if( h[i].d >= h[c].d )
			return;
		wierzcholek tmp = h[i];
		h[i] = h[c];
		h[c] = tmp;
		i = c;
		c = 2*i + 1;
	}
}

wierzcholek pop_from_pq( pq_t pq ) {
	wierzcholek ret = pq->q[0];
	pq->q[0] = pq->q[--pq->n];
	heap_down( pq->q, pq->n );
	return ret;
}

void free_pq( pq_t pq ) {
	free( pq->q );
	free( pq );
}
	

