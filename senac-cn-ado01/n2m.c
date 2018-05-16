#include"lib.h"

int main(int argc, char *argv[])
{
	int baseDesejada         = stringParaInteiro(argv[argc-1]);
	int baseAtual            = stringParaInteiro(argv[argc-2]);
	char * valor             = argv[argc-3];
	int numberoConvertido    = 0;
	
	if ( stringParaInteiro(valor) < 0 ) {
		return 1;
	}

	if( verificaBase(baseAtual) == 1 ){
		return 1;
	}

	if( verificaBase(baseDesejada) == 1 ){
		return 1;
	}

	numberoConvertido = converteParaBase10(valor, baseAtual);

	converteParaBaseN(valor, numberoConvertido, baseDesejada);
	
	printf("%s\n", valor);
	
	return 0;
}