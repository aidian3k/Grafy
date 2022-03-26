#ifndef DIJKSTRAH_ALGORITHM
#define DIJKSTRAH_ALGORITHM
double DIJKSTRA_ALGORITHM(int liczba_wierzcholkow,int wierzcholek1,int wierzcholek2, listV_t *graph);
int najmniejsza_waga(double *dojscia,int liczba_wierzcholkow,int *przetworzone);
void DIJKSTRA_GOING(int *wymiary,int wierzcholek_1,int wierzcholek_2, listV_t *graph);
#endif
