#ifndef VECTOR_INFORMATION_H
#define VECTOR_INFORMATION_H

  #define LENGTH_VECTOR 50

  /*
    define the vector's information that will be passed as parameter to threads control
  */
  typedef struct vector_information {
    int vector[50];
    int biggest_value;
    int smallest_value;
    int biggest_vector_occupation;
    int current_position;
    pthread_t ids_thread[3]; // 0 is the id of producer thread and 1 and 2 the consumer threads
    pthread_mutex_t lock_mutex;
    FILE* file;
  } VectorInformation;

  /*
    Init the VectorInformation with default values
    return: VectorInformation vector -> VectorInformation with default values
  */
  VectorInformation init_vector_information ();
  void show_vector(VectorInformation vector);

#endif
