#include "graph.h"
#include "bfs_algorithm.h"
#include "errors.h"
#include "read.h"
#include "dijkstra_algorithm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {
	if(argc<=2) exit(SHOW_HELP());
	else if(argc==3){
		if(strcmp(argv[1],"--generate")==0) exit(GENERATE_ERROR());
		else if(strcmp(argv[1],"--read")==0){
			FILE *in=fopen(argv[2],"r");
			if(in==NULL) exit(FILE_ERROR());
			int wymiary[2];
			listV_t *graph=czytaj_graf_z_pliku(in,wymiary);
			printf("Program przeczytal graf, ale nie wie co z nim ma zrobic:(\n");
			free_graph(graph,wymiary);
			return EXIT_SUCCESS;
		}
		else exit(SHOW_HELP());
	}
	else if(argc==4){
		if(strcmp(argv[1],"--generate")==0) exit(GENERATE_ERROR());
		else if(strcmp(argv[1],"--read")==0){
			FILE *in=fopen(argv[2],"r");
			if(in==NULL) exit(FILE_ERROR());
			int wymiary[2];
			listV_t *graph=czytaj_graf_z_pliku(in,wymiary);
			if(strcmp(argv[3],"--bfs")==0){
				BFS_GOING(wymiary,graph);
				free_graph(graph,wymiary);
			}
			else if(strcmp(argv[3],"--dijkstra")==0){
				free_graph(graph,wymiary);
				exit(DIJKSTRA_ERROR());
			}
			else{
				free_graph(graph,wymiary);
				exit(SHOW_HELP());
			}
		}
	}
	else if(argc==5){
		if(strcmp(argv[1],"--generate")==0) exit(GENERATE_ERROR());
		else if(strcmp(argv[1],"--read")==0){
			FILE *in=fopen(argv[2],"r");
			if(in==NULL) exit(FILE_ERROR());
			if( strcmp(argv[3],"--dijkstra")==0 || strcmp(argv[4],"--dijkstra")==0) exit(DIJKSTRA_ERROR());
			else exit(SHOW_HELP());
		}
		else exit(SHOW_HELP());
	}
	else if(argc==6){
		if(strcmp(argv[1],"--generate")==0){
			if(atoi(argv[2])<=0 || atoi(argv[3])<=0) exit(INPUT_INT_ERR());
			if(CHECK_IF_DIGIT(argv[2],argv[3])==0) exit(INPUT_INT_ERR());
			if(atof(argv[4])<0 || atof(argv[5])<0) exit(WEIGHT_ERROR());
			printf("Generuje graf w kratke do pliku mygraph\n");
			listV_t *graph=generujGraf(atoi(argv[2]),atoi(argv[3]),atof(argv[4]),atof(argv[5]));
			zapisz_graf_do_pliku(graph,atoi(argv[2]),atoi(argv[3]),"mygraph");
			int wymiary[2];
			wymiary[0]=atoi(argv[2]);
			wymiary[1]=atoi(argv[3]);
			free_graph(graph,wymiary);
			return EXIT_SUCCESS;
		}
		else if(strcmp(argv[1],"--read")==0){
			FILE *in=fopen(argv[2],"r");
			if(in==NULL) exit(FILE_ERROR());
			int wymiary[2];
			listV_t *graph=czytaj_graf_z_pliku(in,wymiary);
			if(strcmp(argv[3],"--dijkstra")==0){
				if(CHECK_IF_DIGIT(argv[4],argv[5])==1) DIJKSTRA_GOING(wymiary,atoi(argv[4]),atoi(argv[5]),graph);
				else{
					free_graph(graph,wymiary);
					exit(INPUT_NOT_INT());
				}
			}
			else if((strcmp(argv[3],"--bfs")==0) && (strcmp(argv[4],"--dijkstra")==0)){
				free_graph(graph,wymiary);
				exit(DIJKSTRA_ERROR());
			}
			else{
				free_graph(graph,wymiary);
				exit(SHOW_HELP());
			}
		}
		else exit(SHOW_HELP());
	}
	else if(argc==7){
		if(strcmp(argv[1],"--read")==0){
			FILE *in=fopen(argv[2],"r");
			if(in==NULL) exit(FILE_ERROR());
			int wymiary[2];
			listV_t *graph=czytaj_graf_z_pliku(in,wymiary);
			if((strcmp(argv[6],"--bfs")==0) && (strcmp(argv[3],"--dijkstra")==0)){
				BFS_GOING(wymiary,graph);
				if(CHECK_IF_DIGIT(argv[4],argv[5])==1) 
					DIJKSTRA_GOING(wymiary,atoi(argv[4]),atoi(argv[5]),graph);
    				else{
					free_graph(graph,wymiary);
					exit(INPUT_NOT_INT());
				}
			}
			else if((strcmp(argv[3],"--bfs")==0) && (strcmp(argv[4],"--dijkstra")==0)){
				BFS_GOING(wymiary,graph);
				if(CHECK_IF_DIGIT(argv[5],argv[6])==1)
					DIJKSTRA_GOING(wymiary,atoi(argv[5]),atoi(argv[6]),graph);
    				else{
					free_graph(graph,wymiary);
					exit(INPUT_NOT_INT());
				}
			}
			else{
				free_graph(graph,wymiary);
				exit(SHOW_HELP());
			}
		}
		else exit(SHOW_HELP());
	}
	else exit(SHOW_HELP());
}

