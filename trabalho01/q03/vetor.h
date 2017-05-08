#ifndef VETOR_H 
#define VETOR_H

/* Define um tipo Vetor que armazenará os elementos do vetor e a quantidade de elementos*/
typedef struct Vetor{
	int *vetor;
	int qtdElementos;
} Vetor;

/* Função usada para criar um vetor de inteiros alocado dinamicamente, ela retorna 
	um conteúdo do tipo Vetor*/
Vetor leVetor();

/* Função que recebe um Vetor como parametro e mostra seus elementos em ordem crescente*/
void mostraVetorOrdemCrescente(Vetor vetor);

/* Função que recebe um Vetor como parametro e mostra seus elementos em ordem decrescente*/
void mostraVetorOrdemDecrescente(Vetor vetor);

/* Função que verifica se um vetor é valido, ou seja, não nulo. Caso seja nulo ele para a execução do programa 
	e exibe uma mensagem de erro*/
void vetorValido(Vetor vetor);

#endif

