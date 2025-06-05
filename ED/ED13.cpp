#include "io.hpp"
#include "ED13.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;

void metodo01 ( void )
{
	contato contato1;
	string name = "";
	
	cout << endl << "Digite o nome do contato"
	" (sem espacos, utilize '_' entre nome e sobrenomes): ";

	cin >> name;
	cout << endl;	

	contato1.setName(name);
	getchar();

	contato1.showName();
	cout << endl;

	IO_print("Aperte ENTER para terminar");
	getchar();
}

void metodo02 ( void )
{
	string telefone="";
	contato contato1;
	
	cout << endl;
	telefone = IO_readstring("Digite o numero de telefone desejado: ");
	contato1.setPhone(telefone);
	contato1.showPhone();

	IO_print("Aperte ENTER para terminar");
	getchar();	
}

void metodo03 ( void )
{
	string telefone="";
	contato contato1;
	
	cout << endl;
	telefone = IO_readstring("Digite o numero do telefone que deseja verificar: ");
	
	contato1.setPhone(telefone);
	contato1.showPhone();
	contato1.isValidPhone(telefone);

	IO_print("Aperte ENTER para terminar");
	getchar();		
}

void metodo04 ( void )
{
	contato contato1;
	string nome;

	nome=IO_readstring("Digite o nome do arquivo (com a extensao) que deseja ler: ");

	if(nome.empty())
	{
		do
		{
			IO_print("\nNao foi possivel obter o nome do arquivo, tente novamente.");
			nome=IO_readstring("\nDigite o nome do arquivo (com a extensao) que deseja ler: ");
		} while (!(nome.empty()));
	}
	else
	{
		contato1.readFromFile(nome);
		contato1.getReadNameFromFile();
		
		cout<< endl;
		IO_print("Aperte ENTER para terminar");
		getchar();	
	}

}

void metodo05 ( void )
{
	
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

			case 3:
			metodo03();
			break;

			case 4:
			metodo04();
			break;
		}

	}while (opcao!=0);
	
	return 0;
}
