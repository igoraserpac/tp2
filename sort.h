#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>

typedef struct{
    int chave;
    char campos[50][50];
}registro;

void gerar_vetor(registro *reg, int tam);
void liberar_vetor(registro *reg);
void selectionSort(registro *reg, int tam);
void quickSort(registro *array, int low, int high);
