#ifndef PRODUCER_THREAD_H
#define PRODUCER_THREAD_H

  /*
    Gets a random number each 100 milliseconds and puts it in a vector
    parameters: void* threads_args -> vector of type VectorInformation described by vector_information.h
    return void*: don't have
  */
  void* control_producer_thread (void* threads_args);

#endif
