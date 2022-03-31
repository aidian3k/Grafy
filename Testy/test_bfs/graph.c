#include "graph.h"
#include <string.h>
#include "errors.h"
// i==0 ... (2)
// dopoki i<K-1 ... (3)
// i==K-1 ... (2)
// dopoki i<(w-1)*K
//	jesli i%K==0 ... (3)
//	jesli i%k==K-1 ... (3)
//	w innym wypadku ... (4)
// i==(W-1)*K ...(2)
// dopoki i<W*K-1 ... (3)
// i==W*K-1 ... (2)
listV_t * generujGraf(int W, int K, long double a, long double b) {
	int v = W*K;
	listV_t *graph = malloc(v * sizeof *graph);
	for(int x=0; x<v; x++)
		graph[x] = NULL;
	srand(time(NULL));
	int i=0; //lewy górny róg
	if(K>1) graph[i] = dodaj(graph[i], i+1, losuj(a, b)); 
	if(W>1) graph[i] = dodaj(graph[i], i+K, losuj(a, b));
	i++;
	if(K>2) {
		for(; i<K-1; i++) { //górna ściana bez rogów
			graph[i] = dodaj(graph[i], i-1, losuj(a, b)); 
			graph[i] = dodaj(graph[i], i+1, losuj(a, b)); 
			if(W>1)
				graph[i] = dodaj(graph[i], i+K, losuj(a, b)); 
		}
	}
	//górny prawy róg; i=K-1
	if(K>1) graph[i] = dodaj(graph[i], i-1, losuj(a, b)); 
	if(W>1) graph[i] = dodaj(graph[i], i+K, losuj(a, b));
	
	i++;
	for(; i<(W-1)*K; i++) { // bez pierwszego i ostatniego wiersza
		if(i%K==0) { // lewa ściana bez rogów
			graph[i] = dodaj(graph[i], i-K, losuj(a, b)); 
			graph[i] = dodaj(graph[i], i+1, losuj(a, b)); 
			graph[i] = dodaj(graph[i], i+K, losuj(a, b)); 
		}
		else if(i%K==K-1) { // prawa ściana bez rogów
			graph[i] = dodaj(graph[i], i-K, losuj(a, b)); 
			graph[i] = dodaj(graph[i], i-1, losuj(a, b)); 
			graph[i] = dodaj(graph[i], i+K, losuj(a, b)); 
		}
		else { // środek siatki
			graph[i] = dodaj(graph[i], i-K, losuj(a, b)); 
			graph[i] = dodaj(graph[i], i-1, losuj(a, b)); 
			graph[i] = dodaj(graph[i], i+1, losuj(a, b)); 
			graph[i] = dodaj(graph[i], i+K, losuj(a, b)); 
		}
	}
	
	//dolny lewy róg; i=(W-1)*K
	if(W>1 && i==(W-1)*K) graph[i] = dodaj(graph[i], i-K, losuj(a, b)); 
	if(K>1 && i==(W-1)*K) graph[i] = dodaj(graph[i], i+1, losuj(a, b)); 
	
	i++;
	for(; i<W*K-1; i++) { // dolna ściana bez rogów
		graph[i] = dodaj(graph[i], i-1, losuj(a, b)); 
		graph[i] = dodaj(graph[i], i-K, losuj(a, b)); 
		graph[i] = dodaj(graph[i], i+1, losuj(a, b)); 
	}
	// dolny prawy róg; i=W*K-1
	if(W>1) graph[i] = dodaj(graph[i], i-K, losuj(a, b)); 
	if(K>1) graph[i] = dodaj(graph[i], i-1, losuj(a, b)); 
	
	return graph;	
}

listV_t dodaj(listV_t listV, int vn, long double w) { 
	// vn numer wierzcholka, w waga   

	listV_t n = malloc(sizeof *n);
	n->Vn = vn;
	n->waga = w;
	n->next = NULL;
	if(listV == NULL) return n;
	listV_t itr = listV;
	while(itr-> next!= NULL) itr=itr->next;
	itr->next = n;
	return listV;
}

long double losuj(long double a, long double b) {
	return a + (long double)rand() / RAND_MAX *(b-a);
}

void zapisz_graf_do_pliku(listV_t *graph, int W, int K, char *plik) {
	FILE *out = fopen(plik, "w");
	fprintf(out, "%d %d\n", W, K);
	for(int i=0; i<W*K; i++) {
		fprintf(out, "\t ");
		listV_t itr=graph[i];
		while(itr!= NULL) {
			fprintf(out, "%d :%.16Lf ", itr->Vn, itr->waga);
			itr=itr->next;
		}
		fprintf(out, "\n");
	}
	fclose(out);
}

void free_graph(listV_t *graph, int *wymiary){
	for(int i=0;i<wymiary[0]*wymiary[1];i++){
		listV_t current=graph[i];
		listV_t next=NULL;
		while(current!=NULL){
			next=current->next;
			free(current);
			current=next;
		}
	}
	free(graph);
	
}

