#include "graph.h"
#include "bfs_algorithm.h"

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
    head=head->next;
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
    if(sprawdz_czy_odwiedzone(odwiedzone,liczba_wierzcholkow)) return 1;
    else return 0;

}