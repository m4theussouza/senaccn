#ifndef _POSIX_C_SOURCE
    #define _POSIX_C_SOURCE 2
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib.h"

int main() {

    FILE
        * senoData = fopen("seno.dat", "w"),
        * cossenoData = fopen("cosseno.dat", "w")
    ;
    long double
        senoErro = 0,
        cosErro = 0
    ;
    
    for (unsigned int i = 0; i < 5; i++) {
        for (unsigned int j = 0; j < 100000; j++) {
    
            long double            
                    x = i + ( (double) j / 100000),
                sin_x = seno(x, &senoErro),
                cos_x = cosseno(x, &cosErro)
            ;

            fprintf(senoData, "%LF \t %LF \t %LF \t %.15LF\n", 
                x, 
                sin_x,
                erroAbsolutoSeno(x),
                senoErro
            );            
            fprintf(cossenoData, "%LF \t %LF \t %LF \t %.15LF\n", 
                x, 
                cos_x,
                erroAbsolutoCosseno(x),
                cosErro
            );    
        }
    }
    fclose(senoData); fclose(cossenoData);

    FILE * gnuplot = popen("gnuplot", "w");
    if (gnuplot) {

        fprintf(gnuplot, "set term png \n");
        fprintf(gnuplot, "set output \"seno.png\" \n");
        fprintf(gnuplot, "plot \"seno.dat\" with lines \n");

        fprintf(gnuplot, "set term png \n");
        fprintf(gnuplot, "set output \"cos.png\" \n");
        fprintf(gnuplot, "plot \"cosseno.dat\" with lines \n");
        
        fflush(gnuplot);
        pclose(gnuplot);
    }     

    return 0;
} 