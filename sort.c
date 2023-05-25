#include "sort.h"

// Função para gerar vetor de Registros grandes (com 50 campos de string, 
// cada qual com 50 char) alocado dinamicamente com chave aleatória.

// void gerar_vetor_reg_aleatorio(Registro *vetor, int tam){
//     vetor = (Registro*)malloc(tam*sizeof(Registro));
//     Registro novo;
//     for(int i=0; i<tam; i++){
//         novo.chave = rand();
//         vetor[i] = novo;
//     }
// }

// void gerar_vetor_reg_crescente(Registro *vetor, int tam){
//     vetor = (Registro*)malloc(tam*sizeof(Registro));
//     Registro novo;
//     for(int i=0; i<tam; i++){
//         novo.chave = i;
//         vetor[i] = novo;
//     }
// }

// void gerar_vetor_reg_decrescente(Registro *vetor, int tam){
//     vetor = (Registro*)malloc(tam*sizeof(Registro));
//     Registro novo;
//     for(int i=tam-1; i>=0; i--){
//         novo.chave = i;
//         vetor[i] = novo;
//     }
// }

// void gerar_vetor_inteiros_aleatorio(int *vetor, int tam){
//     for(int i=0; i<tam; i++){
//         vetor[i] = rand();
//     }
// }

// void gerar_vetor_inteiros_crescente(int *vetor, int tam){
//     for(int i=0; i<tam; i++){
//         vetor[i] = i;
//     }
// }

// void gerar_vetor_inteiros_decrescente(int *vetor, int tam){
//     for(int i=tam-1; i>=0; i--){
//         vetor[i] = i;
//     }
// }

// void liberar_vetor(Registro *reg){
//     free(reg);
// }

void swap_g(Registro_g *a, Registro_g *b, long int *desloc){
    Registro_g t = *a;
    *a = *b;
    *b = t;
    (*desloc) += 3;
}

// Selection Sort

void selectionSort_g(Registro_g arr[], int n, long int *comp, long int *desloc){
    int i, j, min_idx;

    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
            (*comp)++;
            if(arr[j].chave < arr[min_idx].chave){
                min_idx = j;
            }
        }
        swap_g(&arr[min_idx], &arr[i], desloc);
    }
}

// QuickSort

int partition_g(Registro_g *array, int low, int high, long int *comp, long int *desloc){

    Registro_g pivot = array[high];
    // printf("%d\n", pivot.chave);
    int i = (low - 1);

    for(int j = low; j < high; j++){
        (*comp)++;
        if(array[j].chave <= pivot.chave) {
            i++;
            swap_g(&array[i], &array[j], desloc);
        }
    }

    swap_g(&array[i + 1], &array[high], desloc);
    return (i + 1);
}

void quickSort_g(Registro_g *array, int low, int high, long int *comp, long int *desloc)
{
    if (low < high) {

        int pi = partition_g(array, low, high, comp, desloc);

        quickSort_g(array, low, pi - 1, comp, desloc);

        quickSort_g(array, pi + 1, high, comp, desloc);
    }
}

// Insertion Sort 

void insertionSort_g(Registro_g arr[], int n, long int *comp, long int *desloc){
    Registro_g key;
    int j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        (*comp)++;
        while (j >= 0 && arr[j].chave > key.chave) {
            (*desloc)++;
            arr[j + 1] = arr[j];
            j--;
        }
        (*desloc)++;
        arr[j + 1] = key;
    }
}

// shell Sort

void shellSort_g(Registro_g arr[], int num, long int *comp, long int *desloc){
    int h = 1, i, j;
    Registro_g tmp;
    do h = h * 3 + 1; while (h < num);
    h /= 3;
    for (; h > 0; h /= 3) {
        for (i = h; i < num; i++) {
            for(j = i - h; j >= 0; j -= h) {
                (*comp)++;
                if (arr[j+h].chave >= arr[j].chave)
                    break;
                else {
                    swap_g(&arr[j], &arr[j+h], desloc);
                }
            }
        }
    }
}

// Heap Sort

void heapify_g(Registro_g arr[], int n, int i, long int *comp, long int *desloc){
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
        swap_g(&arr[i], &arr[largest], desloc);
        heapify_g(arr, n, largest, comp, desloc);
    }
}

void heapSort_g(Registro_g arr[], int n, long int *comp, long int *desloc){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_g(arr, n, i, comp, desloc);

    for (int i = n - 1; i >= 0; i--) {
        swap_g(&arr[0], &arr[i], desloc);
        heapify_g(arr, i, 0, comp, desloc);
    }
}

// Merge Sort

void merge_g(Registro_g arr[], int l, int m, int r, long int *comp, long int *desloc){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Registro_g *L = (Registro_g*)malloc(n1*sizeof(Registro_g));
    Registro_g *R = (Registro_g*)malloc(n2*sizeof(Registro_g));

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

void mergeSort_g(Registro_g arr[], int l, int r, long int *comp, long int *desloc){
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort_g(arr, l, m, comp, desloc);
        mergeSort_g(arr, m + 1, r, comp, desloc);
        merge_g(arr, l, m, r, comp, desloc);
    }
}
// ***********************************************************************************************
// ************************************* Registros Pequenos **************************************
// ***********************************************************************************************

void swap_p(Registro_p *a, Registro_p *b, long int *desloc){
    Registro_p t = *a;
    *a = *b;
    *b = t;
    (*desloc) += 3;
}

// Selection Sort

void selectionSort_p(Registro_p arr[], int n, long int *comp, long int *desloc){
    int i, j, min_idx;

    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
            (*comp)++;
            if(arr[j].chave < arr[min_idx].chave){
                min_idx = j;
            }
        }
        swap_p(&arr[min_idx], &arr[i], desloc);
    }
}

// QuickSort

int partition_p(Registro_p *array, int low, int high, long int *comp, long int *desloc){

    Registro_p pivot = array[high];
    // printf("%d\n", pivot.chave);
    int i = (low - 1);

    for(int j = low; j < high; j++){
        (*comp)++;
        if(array[j].chave <= pivot.chave) {
            i++;
            swap_p(&array[i], &array[j], desloc);
        }
    }

    swap_p(&array[i + 1], &array[high], desloc);
    return (i + 1);
}

void quickSort_p(Registro_p *array, int low, int high, long int *comp, long int *desloc){
    if (low < high) {

        int pi = partition_p(array, low, high, comp, desloc);

        quickSort_p(array, low, pi - 1, comp, desloc);

        quickSort_p(array, pi + 1, high, comp, desloc);
    }
}

// Insertion Sort 

void insertionSort_p(Registro_p arr[], int n, long int *comp, long int *desloc){
    Registro_p key;
    int j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        (*comp)++;
        while (j >= 0 && arr[j].chave > key.chave) {
            (*desloc)++;
            arr[j + 1] = arr[j];
            j--;
        }
        (*desloc)++;
        arr[j + 1] = key;
    }
}

// shell Sort

void shellSort_p(Registro_p arr[], int num, long int *comp, long int *desloc){
    int h = 1, i, j;
    Registro_p tmp;
    do h = h * 3 + 1; while (h < num);
    h /= 3;
    for (; h > 0; h /= 3) {
        for (i = h; i < num; i++) {
            for(j = i - h; j >= 0; j -= h) {
                (*comp)++;
                if (arr[j+h].chave >= arr[j].chave)
                    break;
                else {
                    swap_p(&arr[j], &arr[j+h], desloc);
                }
            }
        }
    }
}

// Heap Sort

void heapify_p(Registro_p arr[], int n, int i, long int *comp, long int *desloc){
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
        swap_p(&arr[i], &arr[largest], desloc);
        heapify_p(arr, n, largest, comp, desloc);
    }
}

void heapSort_p(Registro_p arr[], int n, long int *comp, long int *desloc){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_p(arr, n, i, comp, desloc);

    for (int i = n - 1; i >= 0; i--) {
        swap_p(&arr[0], &arr[i], desloc);
        heapify_p(arr, i, 0, comp, desloc);
    }
}

// Merge Sort

void merge_p(Registro_p arr[], int l, int m, int r, long int *comp, long int *desloc){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Registro_p *L = (Registro_p*)malloc(n1*sizeof(Registro_p));
    Registro_p *R = (Registro_p*)malloc(n2*sizeof(Registro_p));

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

void mergeSort_p(Registro_p arr[], int l, int r, long int *comp, long int *desloc){
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort_p(arr, l, m, comp, desloc);
        mergeSort_p(arr, m + 1, r, comp, desloc);
        merge_p(arr, l, m, r, comp, desloc);
    }
}