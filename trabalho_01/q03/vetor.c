#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "vetor.h"

Vetor leVetor(){
  printf("\nDigite os elementos do vetor e tecle enter. Quando não desejar mais inserir valores digite -1.\n");

  int num = 0, i = 0;
  Vetor vetor;
  vetor.vetor = NULL;
  vetor.qtdElementos = 0;

  do {
    scanf("%d", &num);
    if(num > -1){
        vetor.vetor = (int*) realloc(vetor.vetor, sizeof(int));
        vetor.vetor[i] = num;
        (vetor.qtdElementos)++;
        i++;
    }
    else if (num != -1){
      printf("Digite apenas valores positivos: ");
    }
  } while(num != -1);

  vetorValido(vetor);
  return vetor;
}

void mostraVetorOrdemCrescente(Vetor vetor){
  printf("Saída crescente:\n");

  int i = 0;
  while(i < vetor.qtdElementos){
    printf("%d ", vetor.vetor[i]);
    i++;
  }
  printf("\n\n");
}

void mostraVetorOrdemDecrescente(Vetor vetor){
  printf("Saída descrescente:\n");

  int i = vetor.qtdElementos - 1; 
  while(i >= 0){
    printf("%d ", vetor.vetor[i]);
    i--;
  }
  printf("\n\n");
}

void vetorValido(Vetor vetor){
  if (vetor.vetor == NULL){
    fprintf(stderr, "\nErro: vetor vazio!\n");
  }
}