#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define SIZE 5

int main(){

    // Versão OpenMP
    int vetorAP[] = {1,2,3,4,5};
    int vetorBP[] = {6,7,8,9,10};
    int vetorSumP = 0; 

    struct timespec start, end;
    clock_gettime ( CLOCK_MONOTONIC , &start );

    #pragma omp parallel for reduction(+:vetorSumP)
    for(int i = 0; i < SIZE; i++){
        vetorSumP += vetorAP[i] + vetorBP[i];
    }

    clock_gettime ( CLOCK_MONOTONIC , &end);

    double time_spent = ( end. tv_sec - start . tv_sec ) + (end. tv_nsec - start . tv_nsec ) / 1e9;

    printf (" Versao Paralela executou em %f segundos \n", time_spent );

    printf("\nA some dos vetores em paralelo é: %d", vetorSumP);


    //Versão Sequencial
    #pragma omp barrier 
    int vetorA[] = {1,2,3,4,5};
    int vetorB[] = {6,7,8,9,10};
    int vetorSum = 0; 

    struct timespec start1, end1;
    clock_gettime ( CLOCK_MONOTONIC , &start1 );

    for(int j = 0; j < SIZE; j++){
        vetorSum += vetorA[j] + vetorB[j];
    }

    clock_gettime ( CLOCK_MONOTONIC , &end1);

    time_spent = ( end1. tv_sec - start1 . tv_sec ) + (end1. tv_nsec - start1 . tv_nsec ) / 1e9;

    printf ("\nVersao Sequencial executou em %f segundos \n", time_spent );
    printf("\nA some dos vetores é: %d", vetorSum);

    return 0;
}