#include <sys/time.h>

#include "time_functions.h"

void calcute_time_elapsed(struct timeval *time_begin, struct timeval *time_end, struct timeval *result) {
  long int diff = (time_end->tv_usec + 1000000 * time_end->tv_sec) - (time_begin->tv_usec + 1000000 * time_begin->tv_sec);
  result->tv_sec = diff / 1000000;
  result->tv_usec = diff % 1000000;
}
