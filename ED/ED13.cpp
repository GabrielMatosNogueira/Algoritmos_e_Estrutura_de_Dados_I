#include "io.hpp"
#include "ED13.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;

void metodo01 ()
{
	contato contato1;
	string name = "";
	
	cout << endl << "Digite o nome do contato"
	" (sem espacos, utilize '_' entre nome e sobrenomes): ";

	cin >> name;
	cout << endl;	

	contato1.setName(name);
	contato1.showName();
	cout << endl;

	getchar();
}

void metodo02 ()
{
	string telefone="";
	contato contato1;
	
	cout << endl;
	telefone = IO_readstring("Digite o numero de telefone desejado: ");
	contato1.setPhone(telefone);
	contato1.showPhone();
}

int main ( void )
{
	int opcao=0;
	do
	{
		IO_methods(13);
		opcao=IO_readint("\nDigite a opcao desejada: ");
		switch(opcao)
		{
			case 1:
			metodo01();
			break;

			case 2:
			metodo02();
			break;
		}

	}while (opcao!=0);
	
	return 0;
}
