# Autorzy
Adrian Nowosielski <br/>
Cezary Skorupski
# Temat Projektu	
Grafy
# Cel projektu
Celem projektu w języku C jest napisanie programu, który: <br/>
-Potrafi wygenerować graf o zadanej liczbie kolumn,wierszy i wagach krawędzi losowanych w zadanym zakresie wartości <br/>
-Potrafi zapisać taki graf do pliku o ustalonym formacie <br/>
-Potrafi przeczytać z plku o ustalonym formacie taki graf <br/>
-Potrafi sprawdzić, czy dany graf jest spójny <br/>
-Potrafi znaleźć w tym grafie najkrótsze ścieżki pomiędzy wybranymi parami węzłów, wykorzystując Algorytm Dijkstry <br/>

# Kompilacja
W katalogu Kompilowanie: make
# Testowanie
W katalogu Kompilowanie: make test
# Uruchamianie
W katalogu Kod: <br/>
	tryb generowania grafu: <br/>
		 ./grafy -generate [wiersze] [kolumny] [waga dolna] [waga gorna] <br/>
	tryb czytania grafu<br/>
		 ./grafy --read [nazwa_pliku_z_grafem] <br/>
	tryb czytania grafu + bfs <br/>
		 ./grafy --read [nazwa_pliku_z_grafem] --bfs <br/>
	tryb czytania grafu + dijkstra <br/>
		 ./grafy --read [nazwa_pliku_z_grafem] --dijkstra [wierzcholek1] [wierzcholek2] <br/>
	tryb czytania grafu + bfs + dijkstra <br/>
		 ./grafy --read [nazwa_pliku_z_grafem] --bfs --dijkstra [wierzcholek1] [wierzcholek2] <br/>

