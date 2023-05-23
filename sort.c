#include "sort.h"

// Função para gerar vetor de Registros grandes (com 50 campos de string, 
// cada qual com 50 char) alocado dinamicamente com chave aleatória.

void gerar_vetor_reg_aleatorio(Registro *vetor, int tam){
    vetor = (Registro*)malloc(tam*sizeof(Registro));
    Registro novo;
    for(int i=0; i<tam; i++){
        novo.chave = rand();
        vetor[i] = novo;
    }
}

void gerar_vetor_reg_crescente(Registro *vetor, int tam){
    vetor = (Registro*)malloc(tam*sizeof(Registro));
    Registro novo;
    for(int i=0; i<tam; i++){
        novo.chave = i;
        vetor[i] = novo;
    }
}

void gerar_vetor_reg_decrescente(Registro *vetor, int tam){
    vetor = (Registro*)malloc(tam*sizeof(Registro));
    Registro novo;
    for(int i=tam-1; i>=0; i--){
        novo.chave = i;
        vetor[i] = novo;
    }
}

void gerar_vetor_inteiros_rand(int *vetor, int tam){
    for(int i=0; i<tam; i++){
        vetor[i] = rand();
    }
}

void gerar_vetor_inteiros_crescente(int *vetor, int tam){
    for(int i=0; i<tam; i++){
        vetor[i] = i;
    }
}

void gerar_vetor_inteiros_decrescente(int *vetor, int tam){
    for(int i=tam-1; i>=0; i--){
        vetor[i] = i;
    }
}

void liberar_vetor(Registro *reg){
    free(reg);
}

void swap(Registro *a, Registro *b, long int *desloc){
    Registro t = *a;
    *a = *b;
    *b = t;
    (*desloc) += 3;
}

// Selection Sort

void selectionSort(Registro arr[], int n, long int *comp, long int *desloc){
    int i, j, min_idx;

    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
            (*comp)++;
            if(arr[j].chave < arr[min_idx].chave){
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i], desloc);
    }
}

// QuickSort

int partition(Registro *array, int low, int high, long int *comp, long int *desloc){

    Registro pivot = array[high];
    // printf("%d\n", pivot.chave);
    int i = (low - 1);

    for(int j = low; j < high; j++){
        (*comp)++;
        if(array[j].chave <= pivot.chave) {
            i++;
            swap(&array[i], &array[j], desloc);
        }
    }

    swap(&array[i + 1], &array[high], desloc);
    return (i + 1);
}

void quickSort(Registro *array, int low, int high, long int *comp, long int *desloc){
    if (low < high) {

        int pi = partition(array, low, high, comp, desloc);

        quickSort(array, low, pi - 1, comp, desloc);

        quickSort(array, pi + 1, high, comp, desloc);
    }
}

// Insertion Sort 

void insertionSort(Registro arr[], int n, long int *comp, long int *desloc){
    Registro key;
    int j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].chave > key.chave) {
            (*desloc)++;
            (*comp)++;
            arr[j + 1] = arr[j];
            j--;
        }
        (*desloc)++;
        arr[j + 1] = key;
    }
}

// shell Sort

void shellSort(Registro arr[], int num, long int *comp, long int *desloc){
    int h = 1, i, j;
    Registro tmp;
    do h = h * 3 + 1; while (h < num);
    h /= 3;
    for (; h > 0; h /= 3) {
        for (i = h; i < num; i++) {
            for(j = i - h; j >= 0; j -= h) {
                (*comp)++;
                if (arr[j+h].chave >= arr[j].chave)
                    break;
                else {
                    swap(&arr[j], &arr[j+h], desloc);
                    // tmp = arr[k];
                    // arr[k] = arr[k+i];
                    // arr[k+i] = tmp;
                }
            }
        }
    }
}

// Heap Sort

void heapify(Registro arr[], int n, int i, long int *comp, long int *desloc){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    (*comp)++;
    if (left < n && arr[left].chave > arr[largest].chave)
        largest = left;
    (*comp)++;
    if (right < n && arr[right].chave > arr[largest].chave)
        largest = right;
    (*comp)++;
    if (largest != i) {
        swap(&arr[i], &arr[largest], desloc);
        heapify(arr, n, largest, comp, desloc);
    }
}

void heapSort(Registro arr[], int n, long int *comp, long int *desloc){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, comp, desloc);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i], desloc);
        heapify(arr, i, 0, comp, desloc);
    }
}

// Merge Sort

void merge(Registro arr[], int l, int m, int r, long int *comp, long int *desloc){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Registro *L = (Registro*)malloc(n1*sizeof(Registro));
    Registro *R = (Registro*)malloc(n2*sizeof(Registro));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2){
        (*comp)++;
        (*desloc)++;
        if (L[i].chave <= R[j].chave){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        (*desloc)++;
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        (*desloc)++;
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(Registro arr[], int l, int r, long int *comp, long int *desloc){
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, comp, desloc);
        mergeSort(arr, m + 1, r, comp, desloc);
        merge(arr, l, m, r, comp, desloc);
    }
}