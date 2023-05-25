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

void selectionSort_g(Registro_g arr[], int n, long int *comp, long int *desloc);
void quickSort_g(Registro_g *array, int low, int high, long int *comp, long int *desloc);
void insertionSort_g(Registro_g arr[], int n, long int *comp, long int *desloc);
void shellSort_g(Registro_g arr[], int num, long int *comp, long int *desloc);
void heapSort_g(Registro_g arr[], int n, long int *comp, long int *desloc);
void mergeSort_g(Registro_g arr[], int l, int r, long int *comp, long int *desloc);

void selectionSort_p(Registro_p arr[], int n, long int *comp, long int *desloc);
void quickSort_p(Registro_p *array, int low, int high, long int *comp, long int *desloc);
void insertionSort_p(Registro_p arr[], int n, long int *comp, long int *desloc);
void shellSort_p(Registro_p arr[], int num, long int *comp, long int *desloc);
void heapSort_p(Registro_p arr[], int n, long int *comp, long int *desloc);
void mergeSort_p(Registro_p arr[], int l, int r, long int *comp, long int *desloc);