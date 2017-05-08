/*
  Contains functions that controls the controller thread
  The controller thread must wait the user input to terminate the program
*/

#include <pthread.h>
#include <stdio.h>
#include <signal.h>

#include "vector_information.h"
#include "controller_thread.h"

VectorInformation *vector_information;

/*
  Show informations to user about the termination of program
*/
void show_informations_to_user () {
  printf("[aviso]: Maior numero gerado: %d\n", vector_information->biggest_value);
  printf("[aviso]: Menor numero gerado: %d\n", vector_information->smallest_value);
  printf("[aviso]: Maior ocupacao de buffer: %d\n", vector_information->biggest_vector_occupation);
}

/*
  Write informations about the termination of program in a file
*/
void write_informations () {
  fprintf(vector_information->file, "[aviso]: Termino solicitado. Aguardando threads...\n");
  fprintf(vector_information->file, "[aviso]: Maior numero gerado: %d\n", vector_information->biggest_value);
  fprintf(vector_information->file, "[aviso]: Menor numero gerado: %d\n", vector_information->smallest_value);
  fprintf(vector_information->file, "[aviso]: Maior ocupacao de buffer: %d\n", vector_information->biggest_vector_occupation);
  fprintf(vector_information->file, "[aviso]: Aplicacao encerrada.\n");
}

/*
  Handler that will response to signal SIGINT
*/
void terminate_program (int signal) {
  printf("\n[aviso]: Termino solicitado. Aguardando threads...\n");

  pthread_cancel (vector_information->ids_thread[0]);
  pthread_cancel (vector_information->ids_thread[1]);
  pthread_cancel (vector_information->ids_thread[2]);

  show_informations_to_user ();
  write_informations ();

  fclose (vector_information->file);
  printf("[aviso]: Aplicacao encerrada.\n");
}

/*
  Waits for user input to terminate the program
  parameters: void* threads_args -> vector of type VectorInformation described by vector_information.h
  return void*: don't have
*/
void* wait_terminate_threads (void* threads_args) {
  vector_information = (VectorInformation*) threads_args;

  signal (SIGINT, terminate_program);

  return (void*) 0;
}
