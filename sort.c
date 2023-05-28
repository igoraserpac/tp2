#include "sort.h"


// ***********************************************************************************************
// ************************************* Registros Pequenos **************************************
// ***********************************************************************************************


void swap_p(Registro_p *a, Registro_p *b, long unsigned int *desloc){
    Registro_p t = *a;
    *a = *b;
    *b = t;
    (*desloc) += 3;
}

// ################################################################################################
// #################################### Selection Sort ############################################
// ################################################################################################

void selectionSort_p(Registro_p arr[], int n, long unsigned int *comp, long unsigned int *desloc){
    int i, j, min_idx;

    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
            // printf("ordenando: %d %d\n", arr[j].chave, arr[min_idx].chave);
            (*comp)++;
            if(arr[j].chave < arr[min_idx].chave){
                min_idx = j;
            }
        }
        swap_p(&arr[min_idx], &arr[i], desloc);
    }
}

// ################################################################################################
// ###################################### QuickSort ###############################################
// ################################################################################################

void particionar_p(long int esq, long int dir, long int *i, long int *j, Registro_p arr[], long unsigned int *comp, long unsigned int *desloc) {
    Registro_p x, w;
    *i = esq; *j = dir;
    x = arr[(*i + *j) / 2];
    /* obtem o pivo x */
    do {
        while (x.chave > arr[*i].chave){
            (*comp)++;
            (*i)++;
        }
        while (x.chave < arr[*j].chave){
            (*comp)++;
            (*j)--;
        }
        if (*i <= *j) {
            (*desloc) += 3;
            w = arr[*i]; 
            arr[*i] = arr[*j]; 
            arr[*j] = w;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void ordenar_p(long int esq, long int dir, Registro_p arr[], long unsigned int *comp, long unsigned int *desloc) {
    long int i, j;
    particionar_p(esq, dir, &i, &j, arr, comp, desloc);
    if (esq < j) ordenar_p(esq, j, arr, comp, desloc);
    if (i < dir) ordenar_p(i, dir, arr, comp, desloc);
}

void quickSort_p(Registro_p arr[], long int n, long unsigned int *comp, long unsigned int *desloc) {
    ordenar_p(0, n-1, arr, comp, desloc);
}

// ####################################################################################################
// ###################################### InsertionSort ###############################################
// ####################################################################################################

void insertionSort_p(Registro_p arr[], int n, long unsigned int *comp, long unsigned int *desloc){
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
        // (*desloc)++;
        arr[j + 1] = key;
    }
}

// ################################################################################################
// ####################################### Shell Sort #############################################
// ################################################################################################

void shellSort_p(Registro_p arr[], int num, long unsigned int *comp, long unsigned int *desloc){
    int h = 1, i, j;
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

// ################################################################################################
// ######################################## Heap Sort #############################################
// ################################################################################################

void heapify_p(Registro_p arr[], int n, int i, long unsigned int *comp, long unsigned int *desloc){
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

void heapSort_p(Registro_p arr[], int n, long unsigned int *comp, long unsigned int *desloc){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_p(arr, n, i, comp, desloc);

    for (int i = n - 1; i >= 0; i--) {
        swap_p(&arr[0], &arr[i], desloc);
        heapify_p(arr, i, 0, comp, desloc);
    }
}

// ################################################################################################
// ###################################### Merge Sort ##############################################
// ################################################################################################

void merge_p(Registro_p arr[], int l, int m, int r, long unsigned int *comp, long unsigned int *desloc){
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

void mergeSort_p(Registro_p arr[], int l, int r, long unsigned int *comp, long unsigned int *desloc){
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort_p(arr, l, m, comp, desloc);
        mergeSort_p(arr, m + 1, r, comp, desloc);
        merge_p(arr, l, m, r, comp, desloc);
    }
}

// ***********************************************************************************************
// ************************************* Registros Grandes ***************************************
// ***********************************************************************************************


void swap_g(Registro_g *a, Registro_g *b, long unsigned int *desloc){
    Registro_g t = *a;
    *a = *b;
    *b = t;
    (*desloc) += 3;
}

// ################################################################################################
// #################################### Selection Sort ############################################
// ################################################################################################


void selectionSort_g(Registro_g arr[], int n, long unsigned int *comp, long unsigned int *desloc){
    int i, j, min_idx;

    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
            // printf("ordenando: %d %d\n", arr[j].chave, arr[min_idx].chave);
            (*comp)++;
            if(arr[j].chave < arr[min_idx].chave){
                min_idx = j;
            }
        }
        swap_g(&arr[min_idx], &arr[i], desloc);
    }
}

// ################################################################################################
// ######################################## Quick Sort ############################################
// ################################################################################################

void particionar_g(long int esq, long int dir, long int *i, long int *j, Registro_g arr[], long unsigned int *comp, long unsigned int *desloc) {
    Registro_g x, w;
    *i = esq; *j = dir;
    x = arr[(*i + *j) / 2];
    /* obtem o pivo x */
    do {
        while (x.chave > arr[*i].chave){
            (*comp)++;
            (*i)++;
        }
        while (x.chave < arr[*j].chave){
            (*comp)++;
            (*j)--;
        }
        if (*i <= *j) {
            (*desloc) += 3;
            w = arr[*i]; 
            arr[*i] = arr[*j]; 
            arr[*j] = w;
            (*i)++; (*j)--;
        }
    } while (*i <= *j);
}

void ordenar_g(long int esq, long int dir, Registro_g arr[], long unsigned int *comp, long unsigned int *desloc) {
    long int i, j;
    particionar_g(esq, dir, &i, &j, arr, comp, desloc);
    if (esq < j) ordenar_g(esq, j, arr, comp, desloc);
    if (i < dir) ordenar_g(i, dir, arr, comp, desloc);
}

void quickSort_g(Registro_g arr[], long int n, long unsigned int *comp, long unsigned int *desloc) {
    ordenar_g(0, n-1, arr, comp, desloc);
}


// ################################################################################################
// #################################### Insertion Sort ############################################
// ################################################################################################


void insertionSort_g(Registro_g arr[], int n, long unsigned int *comp, long unsigned int *desloc){
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
        // (*desloc)++;
        arr[j + 1] = key;
    }
}


// ################################################################################################
// ###################################### Shell Sort ##############################################
// ################################################################################################


void shellSort_g(Registro_g arr[], int num, long unsigned int *comp, long unsigned int *desloc){
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

// ################################################################################################
// ###################################### Heap Sort ###############################################
// ################################################################################################

void heapify_g(Registro_g arr[], int n, int i, long unsigned int *comp, long unsigned int *desloc){
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

void heapSort_g(Registro_g arr[], int n, long unsigned int *comp, long unsigned int *desloc){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_g(arr, n, i, comp, desloc);

    for (int i = n - 1; i >= 0; i--) {
        swap_g(&arr[0], &arr[i], desloc);
        heapify_g(arr, i, 0, comp, desloc);
    }
}

// ################################################################################################
// ######################################## Merge Sort ############################################
// ################################################################################################


void merge_g(Registro_g arr[], int l, int m, int r, long unsigned int *comp, long unsigned int *desloc){
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

void mergeSort_g(Registro_g arr[], int l, int r, long unsigned int *comp, long unsigned int *desloc){
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort_g(arr, l, m, comp, desloc);
        mergeSort_g(arr, m + 1, r, comp, desloc);
        merge_g(arr, l, m, r, comp, desloc);
    }
}

