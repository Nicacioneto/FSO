/*
  Contains functions that controls the producer threads
  The producer thread must get a random number each 100ms and put it in a vector
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#include "producer_thread.h"
#include "vector_information.h"

#define TRUE 1
#define TIME_SLEEP 100000 // in microseconds or 100 milliseconds

/*
  Generate a random integer number
  Return: a random integer number
*/
int generate_a_random_number () {
  int number1 = rand();
  int number2 = rand();

  int random_number = number2 - number1;

  return random_number;
}

/*
  Gets a random number each 100 milliseconds and puts it in a vector
  parameters: void* threads_args -> vector of type VectorInformation described by vector_information.h
  return void*: don't have
*/
void* control_producer_thread (void* threads_args) {
  VectorInformation *vector_information = (VectorInformation*) threads_args;

  srand ((unsigned)time(NULL));
  while (TRUE) {

    if (vector_information->current_position < 0) {
      vector_information->current_position = 0;
    }
    else {
      // do nothing
    }

    if (vector_information->current_position < LENGTH_VECTOR) {
      pthread_mutex_lock (&vector_information->lock_mutex);

      int number = generate_a_random_number ();

      vector_information->vector[vector_information->current_position] = number;
      vector_information->current_position ++;

      if (vector_information->current_position > vector_information->biggest_vector_occupation) {
        vector_information->biggest_vector_occupation = vector_information->current_position;
      }

      fprintf(vector_information->file, "[producao]: Numero gerado: %d\n", number);
      pthread_testcancel (); // thread cancellation point
      pthread_mutex_unlock (&vector_information->lock_mutex);
    }
    else {
      // do nothing
    }

    usleep (TIME_SLEEP);
  }
}
