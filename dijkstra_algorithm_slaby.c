#include "graph.h"
#include <limits.h>
#include "errors.h"

int najmniejsza_waga(double *dojscia,int liczba_wierzcholkow,int *przetworzone){
    int ans;
    for(int i=0;i<liczba_wierzcholkow;i++)
        if(przetworzone[i]==0) ans=i;
    for(int i=0;i<liczba_wierzcholkow;i++){
        if(dojscia[ans]>dojscia[i]){
            if(przetworzone[i]==0)
                ans=i;
        }
    }
    return ans;
}

/* Trzeba dodac kopiec, by przyspieszyc algorytm, na razie taki naiwny */
double DIJKSTRA_ALGORITHM(int liczba_wierzcholkow,int wierzcholek1,int wierzcholek2, listV_t *graph){
    int przetworzone[liczba_wierzcholkow]; //Tworze tablice, w ktora będzie mi mowic, ktore wierzcholki juz algorytm przetworzyl, a ktore nie( 0 jesli nie przetworzyl i 1 jesli przetworzyl)
    for(int i=0;i<liczba_wierzcholkow;i++) przetworzone[i]=0; //Na początku wszystkie nie zostały przetworzone
    double dojscia[liczba_wierzcholkow]; //Tablica, w ktorej beda przechowywane wagi dojscia do poszczegolnych wierzcholkow
    for(int i=0;i<liczba_wierzcholkow;i++) dojscia[i]=INT_MAX; //Ustawiam wartosc nieskonczonosc
    dojscia[wierzcholek1]=0; //Waga dojscia do wierzcholka wyjsciowego jest 0
    int iteracje=0;
    while(iteracje<liczba_wierzcholkow){
        int current=najmniejsza_waga(dojscia,liczba_wierzcholkow,przetworzone); //Szukam najmniejszej wagi w nieprzetworzoncych wierzcholkach
        przetworzone[current]=1; //Zmieniam na przetworzone przez Dijkstre
        listV_t itr=graph[current];
        while(itr!=NULL){
            if(przetworzone[itr->Vn]==0 /* Jesli nie zostal jeszcze przetworzony */)
                if(dojscia[itr->Vn]>dojscia[current]+itr->waga)
                    dojscia[itr->Vn]=dojscia[current]+itr->waga;
            itr=itr->next;
        }
        iteracje++; //Przy kazdej iteracji zostaje przetworzony dokladnie jeden wierzcholek, po to jest ta zmienna
    }
    return dojscia[wierzcholek2];
}

int DIJKSTRA_GOING(int *wymiary,int wierzcholek_1,int wierzcholek_2, listV_t *graph){
		if((wierzcholek_1>=1 && wierzcholek_1<=wymiary[0]*wymiary[1]) && (wierzcholek_2>=1 && wierzcholek_2<=wymiary[0]*wymiary[1])){
			printf("Najkrotsze polaczenie pomiedzy wierzcholkiem %d, a wierzcholkiem %d\n\twynosi: %g",wierzcholek_1,wierzcholek_2,DIJKSTRA_ALGORITHM(wymiary[1]*wymiary[0],wierzcholek_1-1,wierzcholek_2-1,graph));
            return 1;
        }
		else{
            free_graph(graph,wymiary);
			INPUT_OUT_OF_RANGE();
			return -1;
		}
}
