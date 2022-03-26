#include "errors.h"
#include <stdio.h>

void show_help(){
	printf("ERROR! Nieprawidlowy sposob uruchomienia programu! Wywoluje podreczny help do korzystania z programu!\n");
	printf("\t\t\t\t\t\t\tHELP:\n");
	printf("\tTryb generowania grafu: generowanie grafu:\n");
	printf("\t\t ./grafy -generate [wiersze] [kolumny] [waga dolna] [waga gorna]\n\n");
	printf("\tDo algorytmow BFS oraz DIJKSTRA potrzebny jest wczytany graf!\n\n");
	printf("\tTryb Dijkstra i BFS:\n");
	printf("\t\t./grafy --read [nazwa_pliku_z_grafem] --bfs --dijkstra [wierzcholek 1] [wierzcholek 2]");
}

void GENERATE_ERROR(){
    printf("GENERATE_ERROR:\n\t");
    printf("Podano nieprawidlowa liczbe argumentow do wygenerowania grafu\n\t\tPrawidlowa konwencja generowania grafu:\n\t\t\t--generate [liczba wierszy] [liczba kolumn] [waga dolna] [waga gorna]");
}

void FILE_ERROR(){
    printf("FILE_ERROR:\n\t");
    printf("Nie moge odczytac pliku z grafem-podano nieprawidlowy plik!");
}

void DIJKSTRA_ERROR(){
    printf("DIJKSTRA_ERROR:\n\t");
    printf("Uruchomiono dzialanie algorytmu dijkstra z nieprawidlowa liczba argumentow!\n\t\t");
	printf("Prawidlowa konwencja wywolania algorytmu dijkstry dla grafu w programie\n\t\t\t./grafy -read [nazwa_pliku] --dijkstra [wierzcholek a] [wierzcholek b]");
}

void WEIGHT_ERROR(){
    printf("WEIGHT_ERROR\n\t");
    printf("Podano nieprawidlowe wartosci wag w grafie-program konczy dzialanie");
}

void INPUT_NOT_INT(){
    printf("INPUT_NOT_INT_ERROR\n\t");
    printf("Podano wierzcholki, ktore nie sa liczbami calkowitymi dodatnimi");
}

void INPUT_OUT_OF_RANGE(){
    printf("INPUT_OUT_OF_RANGE_ERROR\n\t");
    printf("Podano wierzcholek, ktorego nie ma we wczytanym grafie");
}

void INPUT_INT_ERR(){
    printf("INPUT_INT_ERR\n\t");
    printf("Podano niedodatnia liczbe kolumn lub wierszy do generowania grafu!");
}