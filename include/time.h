#include <stdio.h>
#include <stdlib.h>
typedef long time_t;
struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};
//https://www.tutorialspoint.com/c_standard_library/time_h.htm
struct timespec {
    time_t tv_sec;
    long tv_nsec;
};
unsigned int sleep(unsigned int seconds);
int nanosleep(const struct timespec *req, struct timespec *rem);
