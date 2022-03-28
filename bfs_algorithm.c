#include "graph.h"
#include "bfs_algorithm.h"
#include <stdlib.h>

void free_kolejka(kolejka kol, int dlugosc){
	kolejka next=NULL;
	while(kol!=NULL){
		next=kol->next;
		free(kol);
		kol=next;
	}
	free(kol);
	free(next);
}

kolejka dodaj_na_koniec(kolejka head,int wierzcholek){
    kolejka nowa=malloc(sizeof(kolejka));
    nowa->next=NULL;
    nowa->numer=wierzcholek;
    if(head==NULL)
    {
        head=nowa;
        return nowa;
    }
    else{
        kolejka itr=head;
        while(itr->next!=NULL) itr=itr->next;
        itr->next=nowa;
        return head;
    }
}

kolejka usun_poczatek(kolejka head){
    kolejka tmp=head;
    head=head->next;
    free(tmp);
    return head;
}

int czy_pusta(kolejka head){
    if(head==NULL) return 0;
    else return 1;
}

kolejka dodaj_do_kolejki(kolejka head,listV_t wierzcholek,int *odwiedzone){
    listV_t itr=wierzcholek;
    while(itr!=NULL){
        if(odwiedzone[itr->Vn]==0){
            head=dodaj_na_koniec(head,itr->Vn);
            odwiedzone[itr->Vn]=1;
        }
        itr=itr->next;
    }
    return head;
}

int sprawdz_czy_odwiedzone(int *odwiedzone,int liczba_wierzcholkow){
    for(int i=0;i<liczba_wierzcholkow;i++) if(odwiedzone[i]!=1) return 0;
    return 1;
}

void pisz_kolejka(kolejka kol){
	kolejka itr=kol;
	while(itr!=NULL){
		printf("%d ",itr->numer);
		itr=itr->next;
	}
	free(itr);
	//free_kolejka(itr, liczba_wierzcholkow);
}

int BFS_ALGORITHM(int liczba_wierzcholkow,listV_t *graph) /* Biore numer wierzcholka, od ktorego chce zaczac poszukiwanie, liczba wierzcholkow, caly graf */{
    int odwiedzone[liczba_wierzcholkow];
    for(int i=0;i<liczba_wierzcholkow;i++) odwiedzone[i]=0; //0 symbolizuje, ze dany wierzcholek nie byl odwiedzony, natomiast 1, ze byl odwiedzony
    odwiedzone[0]=1;
    kolejka kol=NULL;
    int n;
    kol=dodaj_na_koniec(kol,0);
    while(czy_pusta(kol)){
        n=kol->numer;
        kol=usun_poczatek(kol);
        kol=dodaj_do_kolejki(kol,graph[n],odwiedzone);
    }
    //free_kolejka(kol, liczba_wierzcholkow);
    free(kol);
    if(sprawdz_czy_odwiedzone(odwiedzone,liczba_wierzcholkow)) return 1;
    else return 0;

}

int BFS_GOING(int *wymiary,listV_t *graph){
    printf("Wywolano prgram z flaga BFS,sprawdzam czy podany graf jest spojny:\n\t");
	if(BFS_ALGORITHM(wymiary[0]*wymiary[1],graph)==1){
		printf("Podany graf jest spojny!\n");
		return 1;
	}
	else{
		printf("Podany graf nie jest spojny!\n");
		return 0;
	}
}
