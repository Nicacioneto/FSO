#include <stdio.h>
#include "vetor.h"
#include "ordenaVetor.h"

int main(int argc, char *argv[]) {
	Vetor vetor;
	if(argc == 2){
		const char* opcoes = "dr";
			
		int opcao = 0;
		opcao = getopt(argc, argv, opcoes);
	
		if(opcao == '?'){
			fprintf(stderr, "Erro: parametro invalido!\n\n");
		  	return -1;
		}
	
		vetor = leVetor();
		vetor = ordenaVetor(vetor);
		switch (opcao) {
		  case 'd':
		  	mostraVetorOrdemCrescente(vetor);
		  	break;
		  case 'r':
		  	mostraVetorOrdemDecrescente(vetor);
		  	break;	  	
		}
	}

	else if (argc == 1){
		vetor = leVetor();
		vetor = ordenaVetor(vetor);
		mostraVetorOrdemCrescente(vetor);
	}

	else{
		fprintf(stderr, "Erro: muitos parametros informados\n\n");
	}

	return 0;
}