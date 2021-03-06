#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "producer_thread.h"
#include "vector_information.h"
#include "consumer_thread.h"
#include "controller_thread.h"

int main(int argc, char const *argv[]) {
  char *file_name;
  if (argc < 2) { // user didn't informe the log file name
    file_name = (char*) malloc (100 * sizeof(char));

    printf("Nome do arquivo de log nao informado. Por favor informe: ");
    scanf("%s", file_name);
  }
  else {
    file_name = (char*) argv[1];
  }

  VectorInformation vector_information;
  pthread_t producer_thread, consumer_thread_a, consumer_thread_b, controller_thread;

  vector_information = init_vector_information (file_name);

  pthread_create (&producer_thread, NULL, &control_producer_thread, &vector_information);
  vector_information.ids_thread[0] = producer_thread;
  pthread_create (&consumer_thread_a, NULL, &control_consumer_thread, &vector_information);
  vector_information.ids_thread[1] = consumer_thread_a;
  pthread_create (&consumer_thread_b, NULL, &control_consumer_thread, &vector_information);
  vector_information.ids_thread[2] = consumer_thread_b;

  pthread_create (&controller_thread, NULL, &wait_terminate_threads, &vector_information);

  pthread_join (controller_thread, NULL);
  pthread_join (producer_thread, NULL);
  pthread_join (consumer_thread_a, NULL);
  pthread_join (consumer_thread_b, NULL);

  return 0;
}
