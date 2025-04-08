#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

void wait(unsigned long long usec){
    struct timeval tv_begin, tv_current;
    gettimeofday(&tv_begin, NULL);

    for (;;) {
        gettimeofday(&tv_current, NULL);
        unsigned long long diff = 
            (tv_current.tv_sec * 1000000 + tv_current.tv_usec) -
            (tv_begin.tv_sec * 1000000 + tv_begin.tv_usec);
        if (diff > usec)
            break;
    }

    return;
}