#include "sort.h"


int main(){
    long int tam_v[] = {20, 500, 5000, 10000, 190000};
    long unsigned int comp = 0, desloc = 0;
    struct rusage start, end;
    Registro_g *vetor_g = (Registro_g*)malloc(200000*sizeof(Registro_g));
    Registro_g novo_g;
    Registro_p *vetor_p = (Registro_p*)malloc(200000*sizeof(Registro_p));
    Registro_p novo_p;
    long double startTime, endTime, media_t;
    long unsigned int media_c, media_d;
    for(int tam_reg=0; tam_reg<2; tam_reg++){
        if(tam_reg == 0)printf("Registro pequeno:\n");
        else printf("Registro grande:\n");
        for(int organizacao=0; organizacao<3; organizacao++){
            if(organizacao == 0) printf("\tAleatório:\n");
            else if(organizacao == 1) printf("\tCrescente:\n");
            else if(organizacao == 2) printf("\tDecrescente:\n");
                for(int tam_vetor=0; tam_vetor<5; tam_vetor++){
                    printf("\t\t\t%ld itens:", tam_v[tam_vetor]);
                    media_t = 0;
                    media_c = 0;
                    media_d = 0;
                    for(int i=0; i<10; i++){
                        desloc = 0;
                        comp = 0;
                        if(tam_reg == 0){
                            if(organizacao == 0){
                                for(int j=0; j<tam_v[tam_vetor]; j++){
                                    novo_p.chave = rand();
                                    vetor_p[j] = novo_p;
                                }
                            }else if(organizacao == 1){
                                for(int j=0; j<tam_v[tam_vetor]; j++){
                                    novo_p.chave = j;
                                    vetor_p[j] = novo_p;
                                }
                            }else if(organizacao == 2){
                                int k = 0;
                                for(int j=tam_v[tam_vetor]; j>0; j--){
                                    novo_p.chave = j;
                                    vetor_p[k] = novo_p;
                                    k++;
                                }
                            }
                            getrusage(RUSAGE_SELF, &start);
                            quickSort_p(vetor_p, tam_v[tam_vetor], &comp, &desloc);
                            getrusage(RUSAGE_SELF, &end);
                        }else if(tam_reg == 1){
                            if(organizacao == 0){
                                for(int j=0; j<tam_v[tam_vetor]; j++){
                                    novo_g.chave = rand();
                                    vetor_g[j] = novo_g;
                                }
                            }else if(organizacao == 1){
                                for(int j=0; j<tam_v[tam_vetor]; j++){
                                    novo_g.chave = j;
                                    vetor_g[j] = novo_g;
                                }
                            }else if(organizacao == 2){
                                int k = 0;
                                for(int j=tam_v[tam_vetor]; j>0; j--){
                                    novo_g.chave = j;
                                    vetor_g[k] = novo_g;
                                    k++;
                                }
                            }
                            getrusage(RUSAGE_SELF, &start);
                            quickSort_g(vetor_g, tam_v[tam_vetor], &comp, &desloc);
                            getrusage(RUSAGE_SELF, &end);
                        }
                        startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
                        endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;
                        printf(" %Lf;", endTime - startTime);
                        media_t += endTime - startTime;
                        media_c += comp;
                        media_d += desloc;                    
                    }
                    printf("    Médias:  tempo:%Lf; comparações: %ld; delocamentos: %ld\n", media_t/10, media_c/10, media_d/10);
                }
            }
        }
    // }
    free(vetor_p);
    free(vetor_g);
    return 0;
}


// int main(){
//     long int tam_v[] = {20, 500, 5000, 10000, 100000};
//     long int comp = 0, desloc = 0;
//     struct rusage start, end;
//     Registro_p *vetor_p = (Registro_p*)malloc(200000*sizeof(Registro_p));
//     Registro_p novo_p;
//     Registro_g *vetor_g = (Registro_g*)malloc(200000*sizeof(Registro_g));
//     Registro_g novo_g;
//     long double startTime, endTime, media_t;
//     int media_c, media_d;
//     // for(int tam_reg=0; tam_reg<2; tam_reg++){
//     //     if(tam_reg == 0)printf("Registro pequeno:\n");
//     //     else printf("Registro grande:\n");
//         for(int organizacao=0; organizacao<3; organizacao++){
//             if(organizacao == 0) printf("\tAleatório:\n");
//             else if(organizacao == 1) printf("\tCrescente:\n");
//             else if(organizacao == 2) printf("\tDecrescente:\n");
//             for(int algoritmo=0; algoritmo<6; algoritmo++){
//                 if(algoritmo == 0) printf("\t\tSelection Sort:\n");
//                 else if(algoritmo == 1) printf("\t\tInsertion Sort:\n");
//                 else if(algoritmo == 2) printf("\t\tQuick Sort:\n");
//                 else if(algoritmo == 3) printf("\t\tShell Sort:\n");
//                 else if(algoritmo == 4) printf("\t\tHeap Sort:\n");
//                 else if(algoritmo == 5) printf("\t\tMerge Sort:\n");
//                 for(int tam_vetor=0; tam_vetor<5; tam_vetor++){
//                     printf("\t\t\t%ld itens:", tam_v[tam_vetor]);
//                     media_t = 0;
//                     media_c = 0;
//                     media_d = 0;
//                     for(int i=0; i<10; i++){
//                         desloc = 0;
//                         comp = 0;
//                         // if(tam_reg == 0){
//                             if(organizacao == 0){
//                                 for(int j=0; j<tam_v[tam_vetor]; j++){
//                                     novo_p.chave = rand();
//                                     vetor_p[j] = novo_p;
//                                 }
//                             }else if(organizacao == 1){
//                                 for(int j=0; j<tam_v[tam_vetor]; j++){
//                                     novo_p.chave = j;
//                                     vetor_p[j] = novo_p;
//                                 }
//                             }else if(organizacao == 2){
//                                 for(int j=tam_v[tam_vetor]; j>0; j--){
//                                     novo_p.chave = j;
//                                     vetor_p[j] = novo_p;
//                                 }
//                             }
//                             getrusage(RUSAGE_SELF, &start);
//                             if(algoritmo == 0){
//                                 selectionSort_p(vetor_p, tam_v[tam_vetor], &comp, &desloc);
//                             }else if(algoritmo == 1){
//                                 insertionSort_p(vetor_p, tam_v[tam_vetor], &comp, &desloc);
//                             }else if(algoritmo == 2){
//                                 quickSort_p(vetor_p, 0, tam_v[tam_vetor]-1, &comp, &desloc);
//                             }else if(algoritmo == 3){
//                                 shellSort_p(vetor_p, tam_v[tam_vetor], &comp, &desloc);
//                             }else if(algoritmo == 4){
//                                 heapSort_p(vetor_p, tam_v[tam_vetor], &comp, &desloc);
//                             }else if(algoritmo == 5){
//                                 mergeSort_p(vetor_p, 0, tam_v[tam_vetor]-1, &comp, &desloc);
//                             }
//                             getrusage(RUSAGE_SELF, &end);
//                         // }else if(tam_reg == 1){
//                         //     if(organizacao == 0){
//                         //         for(int j=0; j<tam_v[tam_vetor]; j++){
//                         //             novo_g.chave = rand();
//                         //             vetor_g[j] = novo_g;
//                         //         }
//                         //     }else if(organizacao == 1){
//                         //         for(int j=0; j<tam_v[tam_vetor]; j++){
//                         //             novo_g.chave = j;
//                         //             vetor_g[j] = novo_g;
//                         //         }
//                         //     }else if(organizacao == 2){
//                         //         for(int j=tam_v[tam_vetor]; j>0; j--){
//                         //             novo_g.chave = j;
//                         //             vetor_g[j] = novo_g;
//                         //         }
//                         //     }
//                         //     getrusage(RUSAGE_SELF, &start);
//                         //     if(algoritmo == 0){
//                         //         selectionSort_g(vetor_g, tam_v[tam_vetor], &comp, &desloc);
//                         //     }else if(algoritmo == 1){
//                         //         insertionSort_g(vetor_g, tam_v[tam_vetor], &comp, &desloc);
//                         //     }else if(algoritmo == 2){
//                         //         quickSort_g(vetor_g, 0, tam_v[tam_vetor]-1, &comp, &desloc);
//                         //     }else if(algoritmo == 3){
//                         //         shellSort_g(vetor_g, tam_v[tam_vetor], &comp, &desloc);
//                         //     }else if(algoritmo == 4){
//                         //         heapSort_g(vetor_g, tam_v[tam_vetor], &comp, &desloc);
//                         //     }else if(algoritmo == 5){
//                         //         mergeSort_g(vetor_g, 0, tam_v[tam_vetor]-1, &comp, &desloc);
//                         //     }
//                         //     getrusage(RUSAGE_SELF, &end);
//                         // }
//                         startTime = start.ru_utime.tv_sec + start.ru_utime.tv_usec / 1000000.0L;
//                         endTime = end.ru_utime.tv_sec + end.ru_utime.tv_usec / 1000000.0L;
//                         printf(" %Lf;", endTime - startTime);
//                         media_t += endTime - startTime;
//                         media_c += comp;
//                         media_d += desloc;
//                     }
//                     printf("    Médias:  tempo:%Lf; comparações: %d; delocamentos: %d\n", media_t/10, media_c/10, media_d/10);
//                 }
//             }
//         }
//     // }
//     free(vetor_p);
//     free(vetor_g);
//     return 0;
// }
