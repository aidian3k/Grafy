#include "graph.h"
#include "bfs_algorithm.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dijkstra_algorithm_slaby.h"
int main(int argc, char **argv) {
	if(argc<=2){
		show_help();
		return EXIT_FAILURE;
	}
	else if(argc==3){
		if(strcmp(argv[1],"--generate")==0){
			GENERATE_ERROR();
			return EXIT_FAILURE;
		}
		else if(strcmp(argv[1],"--read")==0){
			FILE *in=fopen(argv[2],"r");
			if(in==NULL){
				FILE_ERROR();
				return EXIT_FAILURE;
			}
			int wymiary[2];
			listV_t *graph=czytaj_graf_z_pliku(in,wymiary);
			printf("Program przeczytal graf, ale nie wie co z nim ma zrobic:(");
			return EXIT_SUCCESS;
		}
		else{
			show_help();
			return EXIT_FAILURE;
		}
	}
	else if(argc==4){
		if(strcmp(argv[1],"--generate")==0){
			GENERATE_ERROR();
			return EXIT_FAILURE;
		}
		else if(strcmp(argv[1],"--read")==0){
			FILE *in=fopen(argv[2],"r");
			if(in==NULL){
				FILE_ERROR();
				return EXIT_FAILURE;
			}
			int wymiary[2];
			listV_t *graph=czytaj_graf_z_pliku(in,wymiary);
			if(strcmp(argv[3],"--bfs")==0) BFS_GOING(wymiary,graph);
			else if(strcmp(argv[3],"--dijkstra")==0){
				DIJKSTRA_ERROR();
				return EXIT_FAILURE;
			}
			else{
				show_help();
				return EXIT_FAILURE;
			}
		}
	}
	else if(argc==5){
		if(strcmp(argv[1],"--generate")==0){
			GENERATE_ERROR();
			return EXIT_FAILURE;
		}
		else if(strcmp(argv[1],"--read")==0){
			FILE *in=fopen(argv[2],"r");
			if(in==NULL){
				FILE_ERROR();
				return EXIT_FAILURE;
			}
			if( strcmp(argv[3],"--dijkstra")==0 || strcmp(argv[4],"--dijkstra")==0){
				DIJKSTRA_ERROR();
				return EXIT_FAILURE;
			}
			else{
				show_help();
				return EXIT_FAILURE;
			}
		}
		else{
			show_help();
			return EXIT_FAILURE;
		}
	}
	else if(argc==6){
		if(strcmp(argv[1],"--generate")==0){
			if(atoi(argv[2])<=0 || atoi(argv[3])<=0){
				INPUT_INT_ERR();
				return EXIT_FAILURE;
			}
			if(atof(argv[4])<0 || atof(argv[5])<0){
				WEIGHT_ERROR();
				return EXIT_FAILURE;
			}
			printf("Generuje graf w kratke do pliku mygraph");
			listV_t *graph=generujGraf(atoi(argv[2]),atoi(argv[3]),atof(argv[4]),atof(argv[5]));
			zapisz_graf_do_pliku(graph,atoi(argv[2]),atoi(argv[3]),"mygraph");
			return EXIT_SUCCESS;
		}
		else if(strcmp(argv[1],"--read")==0){
			FILE *in=fopen(argv[2],"r");
			if(in==NULL){
				FILE_ERROR();
				return EXIT_FAILURE;
			}
			int wymiary[2];
			listV_t *graph=czytaj_graf_z_pliku(in,wymiary);
			if(strcmp(argv[3],"--dijkstra")==0){
				if(isdigit(argv[4][0]) && isdigit(argv[5][0])) DIJKSTRA_GOING(wymiary,atoi(argv[4]),atoi(argv[5]),graph);
				else {
					INPUT_NOT_INT();
					return EXIT_SUCCESS;
				}
			}
			else if((strcmp(argv[3],"--bfs")==0) && (strcmp(argv[4],"--dijkstra")==0)){
				DIJKSTRA_ERROR();
				return EXIT_FAILURE;
			}
			else{
				show_help();
				return EXIT_FAILURE;
			}
		}
		else{
			show_help();
			return EXIT_FAILURE;
		}
	}
	else if(argc==7){
		if(strcmp(argv[1],"--read")==0){
			FILE *in=fopen(argv[2],"r");
			if(in==NULL){
				FILE_ERROR();
				return EXIT_FAILURE;
			}
			int wymiary[2];
			listV_t *graph=czytaj_graf_z_pliku(in,wymiary);
			if((strcmp(argv[6],"--bfs")==0) && (strcmp(argv[3],"--dijkstra")==0)){
				BFS_GOING(wymiary,graph);
				if(isdigit(argv[4][0]) && isdigit(argv[5][0])) DIJKSTRA_GOING(wymiary,atoi(argv[4]),atoi(argv[5]),graph);
    			else {
					INPUT_NOT_INT();
					return EXIT_FAILURE;
				}
			}
			else if((strcmp(argv[3],"--bfs")==0) && (strcmp(argv[4],"--dijkstra")==0)){
				BFS_GOING(wymiary,graph);
				if(isdigit(argv[5][0]) && isdigit(argv[6][0])) DIJKSTRA_GOING(wymiary,atoi(argv[5]),atoi(argv[6]),graph);
    			else {
					INPUT_NOT_INT();
					return EXIT_FAILURE;
				}
			}
			else{
				show_help();
				return EXIT_FAILURE;
			}
		}
		else{
			show_help();
			return EXIT_FAILURE;
		}
	}
}

