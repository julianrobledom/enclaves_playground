#ifndef _UTILS_H
#define _UTILS_H

void wait(unsigned long long usec);
int random_waiting_time();
typedef struct {
    int subframe;
    int t1;
    int t2;
    int t3;
    int t4;
} current_line;
typedef int (*arr_t)[5];

void init_trace_file(const char *filename, current_line *cline, FILE** trc);
void getfield(char* line, current_line *cline);
int **parameters(current_line *cline, FILE** trc);


#endif