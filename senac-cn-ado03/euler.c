#ifndef _POSIX_C_SOURCE
    #define _POSIX_C_SOURCE 2
#endif
#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

int main() {

    FILE * f = popen("gnuplot", "w");
    if (!f) {
        return 1;
    }

    fprintf(f, "set term png \n");
    fprintf(f, "set output \"euler_flt.png\" \n");
    fprintf(f, "set logscale x \n");
    fprintf(f, "plot \'-\' with lines \n");
    for (long int i = 1; i < 1000000000000000000; i = i * 10) {
        fprintf(f, "%f \t %f \n", (float) i, eulerFloat(i));
    }
    printf("foo\n");
    fprintf(f, "e \n");

    fprintf(f, "set term png \n");
    fprintf(f, "set output \"euler_dbl.png\" \n");
    fprintf(f, "set logscale x \n");
    fprintf(f, "plot \'-\' with lines \n");
    for (long int i = 1; i < 1000000000000000000; i = i * 10) {
        fprintf(f, "%f \t %f \n", (double) i, eulerDouble(i));
    }
    fprintf(f, "e \n");

    fprintf(f, "set term png \n");
    fprintf(f, "set output \"euler_ldbl.png\" \n");
    fprintf(f, "set logscale x \n");
    fprintf(f, "plot \'-\' with lines \n");
    for (long int i = 1; i < 1000000000000000000; i = i * 10) {
        fprintf(f, "%LF \t %LF \n", (long double) i, eulerLongDouble(i));
    }
    fprintf(f, "e \n");
    
    fclose(f);

    return 0;
} 