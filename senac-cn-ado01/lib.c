#include"lib.h"

// Converte string para inteiro
int stringParaInteiro( char *s )
{
	int i = 0, x = 0, j = 0;
	
	while ( s[i] != '\0' )
	{
		
    i++;
	
  }

	InverteString(s);

	while (j < i)
	{

		x += charParaInt( s[j] ) * ( potencia(10,j) );

		j++;
	}

	return x;
}

//verifica se a base esta entre 2 e 36
int verificaBase( int numero )
{
	if ( numero > 36 )
	{
	
		return 1;
	
	}
	
	if ( numero < 2 )
	{
	
		return 1;
	
	}
	
	return ~0;
}

// Calcula a potencia 
int potencia(int base, int expoente)
{
	int resultado = 1;
	
	if (expoente == 0)
	{
	
		return 1;
	
	}

	while ( expoente-- )
	{
		
		resultado = resultado * base;
	
		if ( expoente == 0 )
		{
	
			return resultado;
	 
	 	}		
	
	}

	return resultado;
}

//converte char para inteiro
int charParaInt( char c )
{
	if (c >= '0' && c <= '9')
	{
	
		return (int) c - '0';
	
	} else if ( c >= 'a' && c <= 'z') 
	{
	
		return (int) c - 'a' + 10;
	
	} else if ( c >= 'A' && c <= 'Z')
	{
	
		return (int) c - 'A' + 10;

	}

	return ~0;
}

//converte para base 10
int converteParaBase10( char * numero, int base )
{
	int resultado = 0; 
	int tamanho   = strlen(numero);
	
	for (int i = 0; i < tamanho; i++)
	{
		
		resultado += ( charParaInt(numero[i]) ) * potencia(base, i);
	
	}

	InverteString(numero);
	
	return resultado;
}

//converte para a base desejada
void converteParaBaseN( char * output, int numero, int baseDeDestino )
{
	int i = 0;
	char map[] ={
		'0','1','2','3','4','5',
	  '6','7','8','9','A','B',
	  'C','D','E','F','G','H',
	  'I','J','K','L','M','N',
	  'O','P','Q','R','S','T',
	  'U','V','W','X','Y','Z',
				     };
	
	while ( numero > 0 ) 
	{
		
		output[i] = map[ numero % baseDeDestino ];
		
		numero = numero / baseDeDestino;
		
		i++;

	}
	
	output[i] = '\0';
	
	InverteString( output );
  
}

//Inverte a string
void InverteString( char* s ) 
{
    int aux, i, j;
    int tamanho = strlen( s )-1;

    for (i = 0, j = tamanho; i < j; i++, j--)
    {
        
        aux = s[i];
        
        s[i] = s[j];
        
        s[j] = aux;
    
    }
}
