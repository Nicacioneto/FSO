#ifndef GENERATE_OUTPUT_H
#define GENERATE_OUTPUT_H

void writer_pipe_active_process(const char* message, struct timeval *time_elapsed, FILE* pipe, int i);
void writer_pipe_lazy_child(struct timeval *time_elapsed, FILE* pipe, int i);
void get_message_pipe_and_write_file(FILE* pipe, FILE* output, struct timeval *time_begin);

#endif
