#ifndef BFSH_ALGORITHM
#define BFSH_ALGORITHM
#include <stdlib.h>

typedef struct elem{
    int numer;
    struct elem *next;
}*kolejka;

kolejka dodaj_na_koniec(kolejka head,int wierzcholek);
kolejka usun_poczatek(kolejka head);
int sprawdz_czy_odwiedzone(int *odwiedzone,int liczba_wierzcholkow);
kolejka dodaj_do_kolejki(kolejka head,listV_t wierzcholek,int *odwiedzone);
int czy_pusta(kolejka head);
int BFS_ALGORITHM(int liczba_wierzcholkow,listV_t *graph);
void pisz_kolejka(kolejka kol);
#endif