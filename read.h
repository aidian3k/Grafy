#ifndef READ_H
#define READ_H
#include <stdio.h>

listV_t *czytaj_graf_z_pliku(FILE *,int *wymiary);
char *kopia_linii(char *linia);

#endif