#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>

typedef struct{
    int chave;
    char campos[50][50];
}Registro_g;


typedef struct{
    int chave;
}Registro_p;

void selectionSort_g(Registro_g arr[], int n, long unsigned int *comp, long unsigned int *desloc);
void quickSort_g(Registro_g arr[], long int n, long unsigned int *comp, long unsigned int *desloc);
void insertionSort_g(Registro_g arr[], int n, long unsigned int *comp, long unsigned int *desloc);
void shellSort_g(Registro_g arr[], int num, long unsigned int *comp, long unsigned int *desloc);
void heapSort_g(Registro_g arr[], int n, long unsigned int *comp, long unsigned int *desloc);
void mergeSort_g(Registro_g arr[], int l, int r, long unsigned int *comp, long unsigned int *desloc);

void selectionSort_p(Registro_p arr[], int n, long unsigned int *comp, long unsigned int *desloc);
void quickSort_p(Registro_p arr[], long int n, long unsigned int *comp, long unsigned int *desloc);
void insertionSort_p(Registro_p arr[], int n, long unsigned int *comp, long unsigned int *desloc);
void shellSort_p(Registro_p arr[], int num, long unsigned int *comp, long unsigned int *desloc);
void heapSort_p(Registro_p arr[], int n, long unsigned int *comp, long unsigned int *desloc);
void mergeSort_p(Registro_p arr[], int l, int r, long unsigned int *comp, long unsigned int *desloc);