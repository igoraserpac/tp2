#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>

typedef struct{
    int chave;
    char campos[50][50];
}Registro;

void gerar_vetor_reg(Registro *reg, int tam);
void liberar_vetor(Registro *reg);
void selectionSort(Registro *reg, int tam);
void quickSort(Registro *array, int low, int high);

void gerar_vetor_reg_aleatorio(Registro *vetor, int tam);
void gerar_vetor_reg_crescente(Registro *vetor, int tam);
void gerar_vetor_reg_decrescente(Registro *vetor, int tam);
void gerar_vetor_inteiros_rand(int *vetor, int tam);
void gerar_vetor_inteiros_crescente(int *vetor, int tam);
void gerar_vetor_inteiros_decrescente(int *vetor, int tam);
void liberar_vetor(Registro *reg);
void selectionSort(Registro *reg, int tam);
void swap(Registro *a, Registro *b) ;
void quickSort(Registro *array, int low, int high) ;
void insertionSort(int arr[], int n);
void shellsort(int arr[], int num) ;
void heapify(int arr[], int n, int i) ;
void heapSort(int arr[], int n) ;
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);