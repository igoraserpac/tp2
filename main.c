#include "sort.h"



int main(){
    long int tam[] = {20, 500, 5000, 10000, 20000};
    long int comp = 0, desloc = 0;
    struct rusage start, end;
    Registro *vetor;
    Registro novo;

    for(int t=0; t<5; t++){
        vetor = (Registro*)malloc(tam[t]*sizeof(Registro));
        printf("\n\n*********************** %ld elementos **************************\n\n", tam[t]);
        // ---------------------------------------------------------------------------------------------
        //                                       Quick Sort
        // ---------------------------------------------------------------------------------------------
        for(int i=0; i<tam[t]; i++){
            novo.chave = rand();
            vetor[i] = novo;
        }
        getrusage(RUSAGE_SELF, &start);
        quickSort(vetor, 0, tam[t]-1, &comp, &desloc);
        getrusage(RUSAGE_SELF, &end);
        long double startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L,
            endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;
        printf("=============== Quick Sort ===============\n\n");
        printf("Tempo decorrido = %Lf\n", endTime - startTime);
        printf("Comparações = %ld\n", comp);
        printf("Deslocamentos = %ld\n\n", desloc);

        // ---------------------------------------------------------------------------------------------
        //                                       Shell Sort
        // ---------------------------------------------------------------------------------------------
        comp = 0;
        desloc = 0;
        for(int i=0; i<tam[t]; i++){
            novo.chave = rand();
            vetor[i] = novo;
        }
        getrusage(RUSAGE_SELF, &start);
        shellSort(vetor, tam[t], &comp, &desloc);
        getrusage(RUSAGE_SELF, &end);
        startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
        endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;
        printf("=============== Shell Sort ===============\n\n");
        printf("Tempo decorrido = %Lf\n", endTime - startTime);
        printf("Comparações = %ld\n", comp);
        printf("Deslocamentos = %ld\n\n", desloc);

        


        // ---------------------------------------------------------------------------------------------
        //                                       Heap Sort
        // ---------------------------------------------------------------------------------------------
        comp = 0;
        desloc = 0;
        for(int i=0; i<tam[t]; i++){
            novo.chave = rand();
            vetor[i] = novo;
        }
        getrusage(RUSAGE_SELF, &start);
        heapSort(vetor, tam[t], &comp, &desloc);
        getrusage(RUSAGE_SELF, &end);
        startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
        endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;
        printf("=============== Heap Sort ===============\n\n");
        printf("Tempo decorrido = %Lf\n", endTime - startTime);
        printf("Comparações = %ld\n", comp);
        printf("Deslocamentos = %ld\n\n", desloc);

        // ---------------------------------------------------------------------------------------------
        //                                       Merge Sort
        // ---------------------------------------------------------------------------------------------
        comp = 0;
        desloc = 0;
        for(int i=0; i<tam[t]; i++){
            novo.chave = rand();
            vetor[i] = novo;
        }
        getrusage(RUSAGE_SELF, &start);
        mergeSort(vetor, 0, tam[t]-1, &comp, &desloc);
        getrusage(RUSAGE_SELF, &end);
        startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
        endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;
        printf("=============== Merge Sort ===============\n\n");
        printf("Tempo decorrido = %Lf\n", endTime - startTime);
        printf("Comparações = %ld\n", comp);
        printf("Deslocamentos = %ld\n\n", desloc);

        // ---------------------------------------------------------------------------------------------
        //                                       Insertion Sort
        // ---------------------------------------------------------------------------------------------
        comp = 0;
        desloc = 0;
        for(int i=0; i<tam[t]; i++){
            novo.chave = rand();
            vetor[i] = novo;
        }
        getrusage(RUSAGE_SELF, &start);
        insertionSort(vetor, tam[t], &comp, &desloc);
        getrusage(RUSAGE_SELF, &end);
        startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
        endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;
        printf("=============== Insertion Sort ===============\n\n");
        printf("Tempo decorrido = %Lf\n", endTime - startTime);
        printf("Comparações = %ld\n", comp);
        printf("Deslocamentos = %ld\n\n", desloc);

        // ---------------------------------------------------------------------------------------------
        //                                       Selection Sort
        // ---------------------------------------------------------------------------------------------
        comp = 0;
        desloc = 0;
        for(int i=0; i<tam[t]; i++){
            novo.chave = rand();
            vetor[i] = novo;
        }
        getrusage(RUSAGE_SELF, &start);
        selectionSort(vetor, tam[t], &comp, &desloc);
        getrusage(RUSAGE_SELF, &end);
        startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
        endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;
        printf("=============== Selection Sort ===============\n\n");
        printf("Tempo decorrido = %Lf\n", endTime - startTime);
        printf("Comparações = %ld\n", comp);
        printf("Deslocamentos = %ld\n\n", desloc);

        free(vetor);
    }
    return 0;
}

