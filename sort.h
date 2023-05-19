#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>

typedef struct{
    int chave;
    char campos[50][50];
}Registro;

void gerar_vetor_reg_aleatorio(Registro *vetor, int tam);
void gerar_vetor_reg_crescente(Registro *vetor, int tam);
void gerar_vetor_reg_decrescente(Registro *vetor, int tam);
void gerar_vetor_inteiros_rand(int *vetor, int tam);
void gerar_vetor_inteiros_crescente(int *vetor, int tam);
void gerar_vetor_inteiros_decrescente(int *vetor, int tam);
void liberar_vetor(Registro *reg);
void selectionSort(Registro *reg, int tam, int *comp, int *desloc);
void quickSort(Registro *array, int low, int high, int *comp, int *desloc);
void insertionSort(Registro arr[], int n, int *comp, int *desloc);
void shellSort(Registro arr[], int num, int *comp, int *desloc);
void heapSort(Registro arr[], int n, int *comp, int *desloc);
void mergeSort(Registro arr[], int l, int r, int *comp, int *desloc);