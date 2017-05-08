#ifndef CONSUMER_THREAD_H
#define CONSUMER_THREAD_H

  /*
    Gets a number from vector each 150 milliseconds
    parameters: void* threads_args -> vector of type VectorInformation described by vector_information.h
    return void*: don't have
  */
  void* control_consumer_thread (void* threads_args);

#endif
