#include "errors.h"
#include <stdio.h>

int SHOW_HELP(){
	printf("ERROR! Nieprawidlowy sposob uruchomienia programu! Wywoluje podreczny help do korzystania z programu!\n");
	printf("\t\t\t\t\t\t\tHELP:\n");
	printf("\tTryb generowania grafu: generowanie grafu:\n");
	printf("\t\t ./grafy -generate [wiersze] [kolumny] [waga dolna] [waga gorna]\n\n");
	printf("\tDo algorytmow BFS oraz DIJKSTRA potrzebny jest wczytany graf!\n\n");
	printf("\tTryb Dijkstra i BFS:\n");
	printf("\t\t./grafy --read [nazwa_pliku_z_grafem] --bfs --dijkstra [wierzcholek 1] [wierzcholek 2]");
    return 0;
}

int GENERATE_ERROR(){
    printf("GENERATE_ERROR:\n\t");
    printf("Podano nieprawidlowa liczbe argumentow do wygenerowania grafu\n\t\tPrawidlowa konwencja generowania grafu:\n\t\t\t--generate [liczba wierszy] [liczba kolumn] [waga dolna] [waga gorna]");
    return 0;
}

int FILE_ERROR(){
    printf("FILE_ERROR:\n\t");
    printf("Nie moge odczytac pliku z grafem-podano nieprawidlowy plik!");
    return 0;
}

int DIJKSTRA_ERROR(){
    printf("DIJKSTRA_ERROR:\n\t");
    printf("Uruchomiono dzialanie algorytmu dijkstra z nieprawidlowa liczba argumentow!\n\t\t");
	printf("Prawidlowa konwencja wywolania algorytmu dijkstry dla grafu w programie\n\t\t\t./grafy -read [nazwa_pliku] --dijkstra [wierzcholek a] [wierzcholek b]");
    return 0;
}

int WEIGHT_ERROR(){
    printf("WEIGHT_ERROR\n\t");
    printf("Podano nieprawidlowe wartosci wag w grafie-program konczy dzialanie");
    return 0;
}

int INPUT_NOT_INT(){
    printf("INPUT_NOT_INT_ERROR\n\t");
    printf("Podano wierzcholki, ktore nie sa liczbami calkowitymi dodatnimi");
    return 0;
}

int INPUT_OUT_OF_RANGE(){
    printf("INPUT_OUT_OF_RANGE_ERROR\n\t");
    printf("Podano wierzcholek, ktorego nie ma we wczytanym grafie");
    return 0;
}

int INPUT_INT_ERR(){
    printf("INPUT_INT_ERR\n\t");
    printf("Podano niedodatnia liczbe kolumn lub wierszy do generowania grafu!");
    return 0;
}

int INPUT_FORMAT_ERR(){
    printf("INPUT_FORMAT_ERR\n\t");
    printf("Plik wejsciowy z grafem jest zle sformatowany!\n");
    printf("Poprawny plik z grafem powinien wygladac np.:\n");
    printf("\t1 :0.5956998521442058 2 :0.9274149876681226\n\t0 :0.0636977381369554 3 :0.5678848678096593\n\t4 :0.4409732769434216 3 :0.4378655880865946\n\t1 :0.2069389713960416 2 :0.0232922532704157\n\t");
    return 0;
}

int MALLOC_ERR(){
    printf("MALLOC_MEMORY_ERR\n");;
    printf("Tragedia grecka-brakuje pamieci!\n");
    return 0;
}