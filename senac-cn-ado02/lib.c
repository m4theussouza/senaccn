#include "lib.h"

#include <stdio.h>
#include <stdlib.h>

long double potencia(long double base, int expoente){
    long double resultado = 1;
    while(expoente > 0){
        resultado *= base;
        expoente--;
    }
    return resultado;
}

long double fatorial(long double n){
    if(n == 1 || n ==0){
        return 1;
    }
    return n * fatorial(n-1);
}

long double cosseno(long double x, long double* erro){
    long double resultadoAtual = 0;
    long double resultadoAnterior = 0;
    int n = 0;
    for(int i = 0; i < 10; i++){
        if(i % 2 == 0){
            resultadoAtual += potencia(x, n) / fatorial(n);   
        }else{
            resultadoAtual -= potencia(x, n) / fatorial(n);
        }
        n += 2;
        *erro = (resultadoAtual-resultadoAnterior) / resultadoAtual;
        resultadoAnterior = resultadoAtual;
    }
    return resultadoAtual;
}

long double erroAbsolutoCosseno(long double x){
    return potencia(x, 20)/ fatorial(20);
}

long double seno(long double x, long double* erro){
    long double resultadoAtual = 0;
    long double resultadoAnterior = 0;
    int n = 1;
    for(int i = 0; i < 10; i++){
        if(i % 2 == 0){
            resultadoAtual += potencia(x, n) / fatorial(n);   
        }else{
            resultadoAtual -= potencia(x, n) / fatorial(n);
        }
        n += 2;
        *erro = (resultadoAtual-resultadoAnterior) / resultadoAtual;
        resultadoAnterior = resultadoAtual;
    }
    return resultadoAtual;
}

long double erroAbsolutoSeno(long double x){
    return potencia(x, 21)/fatorial(21);
}