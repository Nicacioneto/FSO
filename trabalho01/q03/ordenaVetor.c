#include <stdio.h>
#include "vetor.h"

Vetor ordenaVetor(Vetor vetor){
	int i = 0, aux;
    int lim = vetor.qtdElementos - 1;

    while(lim > 0){
        i = 0;
        while (i < lim) {
            if(vetor.vetor[i] > vetor.vetor[i+1]){
                aux = vetor.vetor[i+1];
                vetor.vetor[i+1] = vetor.vetor[i];
                vetor.vetor[i] = aux;
            }

            i++;
        }

        lim--;
    }
    return vetor;
}