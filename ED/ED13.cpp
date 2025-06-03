#include "io.hpp"

int main ( void )
{
	int opcao=0;
	do
	{
		IO_methods(13);
		opcao=IO_readint("\nDigite a opcao desejada: ");
	}while (opcao!=0);
	
	return 0;
}
