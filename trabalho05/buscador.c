#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>



void dir_list(char* dir_path){

	DIR *dir;
	struct dirent *entry;

	dir = opendir(dir_path);

	if(dir){
		while((entry = readdir(dir)) != NULL){
			printf("Passou");
		}
	}

	closedir(dir);
}
int main(int argc, char *argv[]){

	int args = atoi(argv[3]);

	printf("Resultado do buscador -- '%s' na pasta %s\n", argv[2], argv[1]);
	dir_list(argv[1]);

	return(0);
}
