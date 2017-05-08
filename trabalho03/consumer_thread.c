/*
  Contains functions that controls the consumer threads
  The consumer thread must get a number from vector each 150ms
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#include "consumer_thread.h"
#include "vector_information.h"

#define TRUE 1
#define TIME_SLEEP 150000 // in microseconds or 150 milliseconds

/*
  Gets a number from vector each 150 milliseconds
  parameters: void* threads_args -> vector of type VectorInformation described by vector_information.h
  return void*: don't have
*/
void* control_consumer_thread (void* threads_args) {
  VectorInformation *vector_information = (VectorInformation*) threads_args;
  char thread = 'a';

  if (vector_information->ids_thread[1] != pthread_self ()) {
    thread = 'b';
  }
  else {
    // do nothing
  }

  while (TRUE) {
    pthread_mutex_lock (&vector_information->lock_mutex);

    if (vector_information->current_position > 0) {
      int number = vector_information->vector[vector_information->current_position-1];
      vector_information->current_position --;

      fprintf(vector_information->file, "[consumo %c]: Numero lido: %d\n", thread, number);

      if (number > vector_information->biggest_value) {
        vector_information->biggest_value = number;
      }
      else if (number < vector_information->smallest_value) {
        vector_information->smallest_value = number;
      }
      else {
        // do nothing
      }

       pthread_testcancel (); // thread cancellation point
    }
    else {
      // do nothing
    }

    pthread_mutex_unlock (&vector_information->lock_mutex);
    usleep (TIME_SLEEP);
  }
}
