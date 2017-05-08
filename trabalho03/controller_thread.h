#ifndef CONTROLLER_THREAD_H
#define CONTROLLER_THREAD_H

  /*
    Waits for user input to terminate the program
    parameters: void* threads_args -> vector of type VectorInformation described by vector_information.h
    return void*: don't have
  */
  void* wait_terminate_threads (void* threads_args);

#endif
