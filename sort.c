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

void swap(Registro *a, Registro *b){
    Registro t = *a;
    *a = *b;
    *b = t;
}

// Selection Sort

void selectionSort(Registro arr[], int n){
    int i, j, min_idx;

    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j].chave < arr[min_idx].chave)
            min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}
// QuickSort

int partition(Registro *array, int low, int high){

    Registro pivot = array[high];
    printf("%d\n", pivot.chave);
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j].chave <= pivot.chave) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(Registro *array, int low, int high){
    if (low < high) {

        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);

        quickSort(array, pi + 1, high);
    }
}

// Insertion Sort 

void insertionSort(Registro arr[], int n){
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i].chave;
        j = i - 1;

        while (j >= 0 && arr[j].chave > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1].chave = key;
    }
}

// shell Sort

void shellSort(Registro arr[], int num){
    int i, j, k;
    Registro tmp;
    for (i = num / 2; i > 0; i /= 2) {
        for (j = i; j < num; j++) {
            for(k = j - i; k >= 0; k -= i) {
                if (arr[k+i].chave >= arr[k].chave)
                    break;
                else {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
    }
}

// Heap Sort

void heapify(Registro arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].chave > arr[largest].chave)
        largest = left;

    if (right < n && arr[right].chave > arr[largest].chave)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(Registro arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Merge Sort

void merge(Registro arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Registro L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2){
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
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Registro arr[], int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}