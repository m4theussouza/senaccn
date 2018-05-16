#include"lib.h"
#include<math.h>

float exponencialFloat(float base, int expoente){
  float resultado = 1;
  while( expoente > 0 ) {
    if (expoente % 2 == 1) {
      resultado *= base;
    }
    expoente /= 2;
    base *= base;
  }
  return resultado;
}

double exponencialDouble(double base, int expoente){
  double resultado = 1;
  while( expoente > 0 ) {
    if (expoente % 2 == 1) {
      resultado *= base;
    }
    expoente /= 2;
    base *= base;
  }
  return resultado;
}

long double exponencialLongDouble(long double base, int expoente){
  long double resultado = 1;
  while( expoente > 0 ) {
    if (expoente % 2 == 1) {
      resultado *= base;
    }
    expoente /= 2;
    base *= base;
  }
  return resultado;
}

float eulerFloat(float n){
  return exponencialFloat(1 + (1/n), n);
}

long double eulerLongDouble(long double n){
  return exponencialLongDouble(1 + (1/n), n);
}

double eulerDouble(double n){
  return exponencialDouble(1 + (1/n), n);
}