#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string.h>


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

int random_waiting_time(){
    int i = 300 + rand() % 701;
    std::cout << i << std::endl;
    return i;
}

int **parameters(current_line *cline, FILE** trc) {
    char line[1024];
    int **users = 0;
    users = new int*[5];
    static bool is_empty = false;
    int current_subframe = cline->subframe;

    if (is_empty) {
      fclose(*trc);
      return NULL;
    }
    int i = 0;
    do{
        users[i] = new int[5];
        users[i][0] = cline->subframe;
        users[i][1] = cline->t1;
        users[i][2] = cline->t2;
        users[i][3] = cline->t3;
        users[i][4] = cline->t4;
        i++;
        if ((is_empty = fgets(line, 1024, *trc)) == NULL)
        break;
        getfield(line, cline);
    }
    while (current_subframe == cline->subframe);

    return users;
}

void init_trace_file(const char *filename, current_line *cline, FILE** trc) {
    if(!(*trc = fopen(filename,"r")))
        perror(filename);
    char line[1024];
    if(!trc) {
        printf("Error opening trace file : %s",filename);
    }
    else {
        fgets(line, 1024, *trc); // remove header line
        //bool is_empty = false;
        fgets(line, 1024, *trc); // read first valid line
        getfield(line, cline);
    }
}

void getfield(char* line, current_line *cline)
{
    cline->subframe = atoi(strsep(&line, ","));
    cline->t1 = atoi(strsep(&line, ","));
    cline->t2 = atoi(strsep(&line, ","));
    cline->t3 = atoi(strsep(&line, ","));
    cline->t4 = atoi(strsep(&line, ","));
    return;
}
