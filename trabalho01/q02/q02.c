#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* nomeExecutavel(char const* nomeExecutavel){
	char *nome;
	int tam = strlen(nomeExecutavel);
	int i = 2, j = 0;

	nome = (char*)malloc(tam*sizeof(char));
	
	while(nomeExecutavel[i] != '\0'){
		nome[j] = nomeExecutavel[i];
		i++;
		j++;
	}

	nome[j] = '\0';
	return nome;
}


int main(int argc, char const *argv[]){
	printf("# de parametros: %d\n", argc - 1);
	printf("Nome do executavel: %s\n", nomeExecutavel(argv[0]));

	int i = 1;

	while(argv[i] != NULL){
		printf("Parametro #%d: %s\n", i, argv[i]);
		i++;
	}

	return 0;
}