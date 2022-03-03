#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int W, K; //liczba wierszy i kolumn
	int wymiary[2];
	long double a, b; // zakres wag krawedzi w generowanym grafie <a, b>
	listV_t *my_graph = czytaj_graf_z_pliku(fopen(argv[1],"r"),wymiary);
	W=wymiary[0];
	K=wymiary[1];	
	zapisz_graf_do_pliku(my_graph, W, K, "wyjscie");
	return 0;	
}


