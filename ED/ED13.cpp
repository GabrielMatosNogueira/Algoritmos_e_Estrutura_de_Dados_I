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
	string filename;
	contato contato1;

	filename=IO_readstring("\nDigite o nome do arquivo: ");

	if(filename.empty())
	{
		do
		{
			filename=IO_readstring("\nNao foi possivel ler o nome do arquivo, tente novamente: ");
		} while (!(filename.empty()));
		
	}
	else
	{
		contato1.writeToFile(filename);
		contato1.readFromFile(filename);
		contato1.getReadNameFromFile();
	}

	cout << endl;
	IO_print("Aperte ENTER para terminar");
	getchar();	
}

/*
	Metodo para inserir n numeros de telefone em um contato (objeto)
*/
void metodo06 ( void )
{
	bool verificador=false;
	contato contato1;
	string nome;
	string telefone;
	string telefone2;

	nome= IO_readstring("\nDigite o nome do contato (sem espacos, utilize '_' entre nome e sobrenomes): ");
	contato1.setName(nome);
	contato1.showName();

	verificador=IO_readbool("\nDeseja inserir dois numeros de telefone? (1 = Sim / 0 = Nao): ");

	if (verificador)
	{
		do
		{
			telefone = IO_readstring("\nDigite o numero de telefone: ");
			verificador = contato1.isValidPhone(telefone);
		} while (verificador == false);

		contato1.setPhone(telefone);
		contato1.showPhone();

		do
		{
			telefone2 = IO_readstring("\nDigite o segundo numero de telefone: ");
			verificador = contato1.isValidPhone(telefone2);
		} while (verificador == false);
		
		contato1.setPhone2(telefone2);
		contato1.showPhone2();
	}

	IO_print("Aperte ENTER para terminar");
	getchar();	
}

/*
	Metodo para checar quantos numeros de telefones estao associados a cada contato (objeto)
*/
void metodo07 ( void )
{
	int quantidade=0;
	contato contato1;



}

int main ( void )
{
	int opcao=0;
	do
	{
		IO_methods(13);									// Funcao para implementar o menu de opcoes de acordo com o ED (Finalmente :)
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

			case 5:
			metodo05();
			break;

			case 6:
			metodo06();
			break;
		}

	}while (opcao!=0);
	
	return 0;
}
