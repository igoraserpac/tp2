#include "sort.h"



int main(){
    long int comp, desloc;
    struct timeval start, end;
    Registro *vetor = (Registro*)malloc(200000*sizeof(Registro));
    Registro novo;
    for(int i=0; i<200000; i++){
        novo.chave = rand();
        vetor[i] = novo;
    }
    gettimeofday(&start, NULL);
    quickSort(vetor, 0, 199999, &comp, &desloc);
    gettimeofday(&end, NULL);
    for(int i=0; i<200000; i++){
        printf("ordenado: %d\n", vetor[i].chave);
    }
    free(vetor);
    long double startTime = start.tv_sec + start.tv_usec / 1000000.0L,
        endTime = end.tv_sec + end.tv_usec / 1000000.0L;
    printf("Tempo inicial = %Lf\n", startTime);
    printf("Tempo final = %Lf\n", endTime);
    printf("Tempo decorrido = %Lf\n", endTime - startTime);
    printf("Comparações = %ld\n", comp);
    printf("Tempo decorrido = %ld\n", desloc);
    return 0;
}

