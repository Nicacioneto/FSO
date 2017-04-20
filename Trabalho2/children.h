#ifndef CHILDREN_H
#define CHILDREN_H

  void execute_active_process(pid_t active_process_pipe[2], struct timeval *time_begin);
  void execute_lazy_child(pid_t lazy_child_pipe[2], struct timeval *time_begin);
  
#endif