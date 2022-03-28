#include "graph.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "errors.h"

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

listV_t *czytaj_graf_z_pliku(FILE *in,int *wymiary) /*To int* to tablica, w ktorej beda trzymane wymiary grafu, zeby nie tworzyc nowej struktury */{
	int w1,w2,w3,w4; //Pomocnicze, zeby przechowywac numery wierzcholkow
	double n1,n2,n3,n4; //Pomocnicze, zeby zapisywac wage poszczegolnych krawedzi
	if(fscanf(in,"%d%d",&wymiary[0],&wymiary[1])!=2) exit(INPUT_FORMAT_ERR()); //Wczytuje liczbe wierszy oraz kolumn w grafie
	int W=wymiary[0],K=wymiary[1];
	while(fgetc(in)!='\n');
	listV_t *graph=malloc(sizeof(*graph)*W*K);
	char buf[1024];
	int linia=0;
	while(fgets(buf,1024,in)!=NULL){
		if(linia==0 || linia==K-1 || linia==W*K-K || linia==W*K-1) /* Na poczatku biore te, ktore lacza sie z dwoma wierzcholkami */ {
			char *pom=kopia_linii(buf);
			if(pom!=NULL){
				if(sscanf(pom,"%d%lf%d%lf",&w1,&n1,&w2,&n2)!=4){
					free_graph(graph,wymiary);
					exit(INPUT_FORMAT_ERR());
				}
				graph[linia]=dodaj(graph[linia],w1,n1);
				graph[linia]=dodaj(graph[linia],w2,n2);
			}
			else{
				free_graph(graph,wymiary);
				exit(MALLOC_ERR());
			}
		}
		else if(linia>0 && linia<K-1 || linia>W*K-K && linia<W*K-1 || linia%K==0 || linia%K==K-1) /* Potem trzy wierzcholki*/{
			char *pom=kopia_linii(buf);
			if(pom!=NULL){
				if(sscanf(pom,"%d%lf%d%lf%d%lf",&w1,&n1,&w2,&n2,&w3,&n3)!=6){
					free_graph(graph,wymiary);
					exit(INPUT_FORMAT_ERR()); 
				}
				graph[linia]=dodaj(graph[linia],w1,n1);
				graph[linia]=dodaj(graph[linia],w2,n2);
				graph[linia]=dodaj(graph[linia],w3,n3);
			}
			else{
				free_graph(graph,wymiary);
				exit(MALLOC_ERR());
			}
		}
		else /* Na koniec 4 */{
			char *pom=kopia_linii(buf);
			if(pom!=NULL){
				if(sscanf(pom,"%d%lf%d%lf%d%lf%d%lf",&w1,&n1,&w2,&n2,&w3,&n3,&w4,&n4)!=8){
					free_graph(graph,wymiary);
					exit(INPUT_FORMAT_ERR());
				}
				graph[linia]=dodaj(graph[linia],w1,n1);
				graph[linia]=dodaj(graph[linia],w2,n2);
				graph[linia]=dodaj(graph[linia],w3,n3);
				graph[linia]=dodaj(graph[linia],w4,n4);
			}
			else{
				free_graph(graph,wymiary);
				exit(MALLOC_ERR());
			}
		}
		linia++;
	}
	return graph;
}