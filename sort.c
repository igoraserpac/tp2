#include "sort.h"

void gerar_vetor(registro *vetor, int tam){
    vetor = (registro*)malloc(tam*sizeof(registro));
    registro novo;
    for(int i=0; i<tam; i++){
        novo.chave = rand();
        vetor[i] = novo;
    }
}

void liberar_vetor(registro *reg){
    free(reg);
}

// Selection Sort

void selectionSort(registro *reg, int tam){
    int i, j, min;
    registro x;
    for (i = 0; i < tam; i++) {
        min = i;
        for (j = i + 1; j < tam; j++) {
            if (reg[j].chave < reg[min].chave) {
                min = j;
            }
        }
        x = reg[min];
        reg[min] = reg[i];
        reg[i] = x;
    }
}

// QuickSort

void swap(registro *a, registro *b) {
  registro t = *a;
  *a = *b;
  *b = t;
}

int partition(registro *array, int low, int high) {

  registro pivot = array[high];
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

void quickSort(registro *array, int low, int high) {
  if (low < high) {

    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
}