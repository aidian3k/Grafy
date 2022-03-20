#include "graph.h"
#include <ctype.h>
#include <string.h>
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
	srand(time(NULL));
	int i=0; //lewy górny róg
	graph[i] = dodaj(graph[i], i+1, losuj(a, b)); 
	graph[i] = dodaj(graph[i], i+K, losuj(a, b));
	i++;
	for(; i<K-1; i++) { //górna ściana bez rogów
		graph[i] = dodaj(graph[i], i-1, losuj(a, b)); 
		graph[i] = dodaj(graph[i], i+1, losuj(a, b)); 
		graph[i] = dodaj(graph[i], i+K, losuj(a, b)); 
	}
	//górny prawy róg; i=K-1
	graph[i] = dodaj(graph[i], i-1, losuj(a, b)); 
	graph[i] = dodaj(graph[i], i+K, losuj(a, b));
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
	graph[i] = dodaj(graph[i], i+K, losuj(a, b)); 
	graph[i] = dodaj(graph[i], i+1, losuj(a, b)); 
	i++;
	for(; i<W*K-1; i++) { // dolna ściana bez rogów
		graph[i] = dodaj(graph[i], i-1, losuj(a, b)); 
		graph[i] = dodaj(graph[i], i-K, losuj(a, b)); 
		graph[i] = dodaj(graph[i], i+1, losuj(a, b)); 
	}
	// dolny prawy róg; i=W*K-1
	graph[i] = dodaj(graph[i], i-K, losuj(a, b)); 
	graph[i] = dodaj(graph[i], i-1, losuj(a, b)); 
	
	return graph;	
}

listV_t dodaj(listV_t listV, int vn, long double w) { 
	// vn numer wierzcholka, w waga   
	listV_t n = malloc(sizeof *n);
	n->Vn = vn;
	n->waga = w;
	n->next = NULL;
	if(listV == NULL) return n;
	listV_t itr= listV;
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
			fprintf(out, "%d :%.16Lf ", graph[i]->Vn, graph[i]->waga);
			itr=itr->next;
		}
		fprintf(out, "\n");
	}
}

listV_t *czytaj_graf_z_pliku(FILE *in,int *wymiary) /*To int* to tablica, w ktorej beda trzymane wymiary grafu, zeby nie tworzyc nowej struktury */{
	int w1,w2,w3,w4; //Pomocnicze, zeby przechowywac numery wierzcholkow
	double n1,n2,n3,n4; //Pomocnicze, zeby zapisywac wage poszczegolnych krawedzi
	if(fscanf(in,"%d%d",&wymiary[0],&wymiary[1])!=2) return NULL; //Wczytuje liczbe wierszy oraz kolumn w grafie
	int W=wymiary[0],K=wymiary[1];
	while(fgetc(in)!='\n');
	listV_t *graph=malloc(sizeof(*graph)*W*K);
	char buf[1024];
	int linia=0;
	while(fgets(buf,1024,in)!=NULL){
		if(linia==0 || linia==K-1 || linia==W*K-1-K || linia==W*K-1) /* Na poczatku biore te, ktore lacza sie z dwoma wierzcholkami */ {
			char *pom=kopia_linii(buf);
			if(pom!=NULL){
				sscanf(pom,"%d%lf%d%lf",&w1,&n1,&w2,&n2);
				graph[linia]=dodaj(graph[linia],w1,n1);
				graph[linia]=dodaj(graph[linia],w2,n2);
			}
		}
		else if(linia>0 && linia<K-1 || linia>W*K-1-K && linia<W*K-1 || linia%K==0 || linia%K==K-1) /* Potem trzy wierzcholki*/{
			char *pom=kopia_linii(buf);
			if(pom!=NULL){
				sscanf(pom,"%d%lf%d%lf%d%lf",&w1,&n1,&w2,&n2,&w3,&n3);
				graph[linia]=dodaj(graph[linia],w1,n1);
				graph[linia]=dodaj(graph[linia],w2,n2);
				graph[linia]=dodaj(graph[linia],w3,n3);
			}
		}
		else /* Na koniec 4 */{
			char *pom=kopia_linii(buf);
			if(pom!=NULL){
				sscanf(pom,"%d%lf%d%lf%d%lf%d%lf",&w1,&n1,&w2,&n2,&w3,&n3,&w4,&n4);
				graph[linia]=dodaj(graph[linia],w1,n1);
				graph[linia]=dodaj(graph[linia],w2,n2);
				graph[linia]=dodaj(graph[linia],w3,n3);
				graph[linia]=dodaj(graph[linia],w4,n4);
			}
		}
		linia++;
	}
	return graph;
}

char *kopia_linii(char *linia){
	char *kopia=malloc(sizeof(char)*(strlen(linia)-1));
    int pom=0;
	for(int i=0;i<strlen(linia);i++){
		char c=linia[i];
		if(isdigit(c) || isspace(c) || c=='.'){
            kopia[pom]=c;
            pom++;
        }
	}
	return kopia;
}

