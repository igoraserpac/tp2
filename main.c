#include "sort.h"



int main(){
    long int comp = 0, desloc = 0, tam = 10000;
    struct rusage start, end;
    Registro *vetor = (Registro*)malloc(tam*sizeof(Registro));
    Registro novo;

    // ---------------------------------------------------------------------------------------------
    //                                       Quick Sort
    // ---------------------------------------------------------------------------------------------
    for(int i=0; i<tam; i++){
        novo.chave = rand();
        vetor[i] = novo;
    }
    getrusage(RUSAGE_SELF, &start);
    quickSort(vetor, 0, tam-1, &comp, &desloc);
    getrusage(RUSAGE_SELF, &end);
    long double startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L,
        endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;
    printf("=============== Quick Sort ===============\n\n");
    printf("Tempo inicial = %Lf\n", startTime);
    printf("Tempo final = %Lf\n", endTime);
    printf("Tempo decorrido = %Lf\n", endTime - startTime);
    printf("Comparações = %ld\n", comp);
    printf("Deslocamentos = %ld\n\n", desloc);

    // ---------------------------------------------------------------------------------------------
    //                                       Shell Sort
    // ---------------------------------------------------------------------------------------------
    comp = 0;
    desloc = 0;
    for(int i=0; i<tam; i++){
        novo.chave = rand();
        vetor[i] = novo;
    }
    getrusage(RUSAGE_SELF, &start);
    shellSort(vetor, tam, &comp, &desloc);
    getrusage(RUSAGE_SELF, &end);
    startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
    endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;
    printf("=============== Shell Sort ===============\n\n");
    printf("Tempo inicial = %Lf\n", startTime);
    printf("Tempo final = %Lf\n", endTime);
    printf("Tempo decorrido = %Lf\n", endTime - startTime);
    printf("Comparações = %ld\n", comp);
    printf("Deslocamentos = %ld\n\n", desloc);


    // ---------------------------------------------------------------------------------------------
    //                                       Heap Sort
    // ---------------------------------------------------------------------------------------------
    comp = 0;
    desloc = 0;
    for(int i=0; i<tam; i++){
        novo.chave = rand();
        vetor[i] = novo;
    }
    getrusage(RUSAGE_SELF, &start);
    heapSort(vetor, tam, &comp, &desloc);
    getrusage(RUSAGE_SELF, &end);
    startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
    endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;
    printf("=============== Heap Sort ===============\n\n");
    printf("Tempo inicial = %Lf\n", startTime);
    printf("Tempo final = %Lf\n", endTime);
    printf("Tempo decorrido = %Lf\n", endTime - startTime);
    printf("Comparações = %ld\n", comp);
    printf("Deslocamentos = %ld\n\n", desloc);

    // ---------------------------------------------------------------------------------------------
    //                                       Merge Sort
    // ---------------------------------------------------------------------------------------------
    // comp = 0;
    // desloc = 0;
    // for(int i=0; i<tam; i++){
    //     novo.chave = rand();
    //     vetor[i] = novo;
    // }
    // getrusage(RUSAGE_SELF, &start);
    // mergeSort(vetor, 0, tam-1, &comp, &desloc);
    // getrusage(RUSAGE_SELF, &end);
    // startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
    // endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;
    // printf("=============== Merge Sort ===============\n\n");
    // printf("Tempo inicial = %Lf\n", startTime);
    // printf("Tempo final = %Lf\n", endTime);
    // printf("Tempo decorrido = %Lf\n", endTime - startTime);
    // printf("Comparações = %ld\n", comp);
    // printf("Deslocamentos = %ld\n\n", desloc);

    // ---------------------------------------------------------------------------------------------
    //                                       Insertion Sort
    // ---------------------------------------------------------------------------------------------
    comp = 0;
    desloc = 0;
    for(int i=0; i<tam; i++){
        novo.chave = rand();
        vetor[i] = novo;
    }
    getrusage(RUSAGE_SELF, &start);
    insertionSort(vetor, tam, &comp, &desloc);
    getrusage(RUSAGE_SELF, &end);
    startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
    endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;
    printf("=============== Insertion Sort ===============\n\n");
    printf("Tempo inicial = %Lf\n", startTime);
    printf("Tempo final = %Lf\n", endTime);
    printf("Tempo decorrido = %Lf\n", endTime - startTime);
    printf("Comparações = %ld\n", comp);
    printf("Deslocamentos = %ld\n\n", desloc);

    // ---------------------------------------------------------------------------------------------
    //                                       Selection Sort
    // ---------------------------------------------------------------------------------------------
    comp = 0;
    desloc = 0;
    for(int i=0; i<tam; i++){
        novo.chave = rand();
        vetor[i] = novo;
    }
    getrusage(RUSAGE_SELF, &start);
    selectionSort(vetor, tam, &comp, &desloc);
    getrusage(RUSAGE_SELF, &end);
    startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
    endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;
    printf("=============== Selection Sort ===============\n\n");
    printf("Tempo inicial = %Lf\n", startTime);
    printf("Tempo final = %Lf\n", endTime);
    printf("Tempo decorrido = %Lf\n", endTime - startTime);
    printf("Comparações = %ld\n", comp);
    printf("Deslocamentos = %ld\n\n", desloc);

    free(vetor);
    return 0;
}

