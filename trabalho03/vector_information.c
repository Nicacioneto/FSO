#include <stdio.h>
#include <pthread.h>

#include "vector_information.h"

/*
  Init the VectorInformation with default values
  parameter: char* file_name -> string that contains the name of log file
  return: VectorInformation vector -> VectorInformation with default values
*/
VectorInformation init_vector_information (char* file_name) {
  VectorInformation vector_information;

  vector_information.biggest_value = 0;
  vector_information.smallest_value = 0;
  vector_information.current_position = 0;
  vector_information.biggest_vector_occupation = 0;
  pthread_mutex_init (&vector_information.lock_mutex, NULL);
  vector_information.file = fopen (file_name, "w");;

  return vector_information;
}

void show_vector(VectorInformation vector) {
  int i = 0;
  while (i < 50) {
    printf("%d\n", vector.vector[i++]);
  }
}
