#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>


void dir_list(char* dir_path, char * file_name, int max_lines){

	DIR *dir;
	struct dirent* entry;
	dir = opendir(dir_path);
	char buffer[30];



	if(dir){
		while((entry = readdir(dir)) != NULL){
			if(strstr(entry->d_name, file_name) != NULL){

				 FILE* fp =  fopen(strcat(strcat(dir_path,"/"),entry->d_name), "r");
			   fread(buffer, 1, 30,fp);
				 printf("\n%s\n%s", strcat(strcat(dir_path,"/"),entry->d_name), buffer);

			}
		}
	}



	closedir(dir);
}

int main(int argc, char *argv[]){


	int max_lines = atoi(argv[3]);

	printf("Resultado do buscador -- '%s' na pasta %s\n", argv[2], argv[1]);

	dir_list(argv[1], argv[2], max_lines);

	return(0);
}
