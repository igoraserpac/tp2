#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>

typedef struct{
    int chave;
    char campos[50][50];
}Registro;

// void gerar_vetor_reg_aleatorio(Registro *vetor, int tam);
// void gerar_vetor_reg_crescente(Registro *vetor, int tam);
// void gerar_vetor_reg_decrescente(Registro *vetor, int tam);
// void gerar_vetor_inteiros_aleatorio(int *vetor, int tam);
// void gerar_vetor_inteiros_crescente(int *vetor, int tam);
// void gerar_vetor_inteiros_decrescente(int *vetor, int tam);
// void liberar_vetor(Registro *reg);
void selectionSort(Registro *reg, int tam, long int *comp, long int *desloc);
void quickSort(Registro *array, int low, int high, long int *comp, long int *desloc);
void insertionSort(Registro arr[], int n, long int *comp, long int *desloc);
void shellSort(Registro arr[], int num, long int *comp, long int *desloc);
void heapSort(Registro arr[], int n, long int *comp, long int *desloc);
void mergeSort(Registro arr[], int l, int r, long int *comp, long int *desloc);