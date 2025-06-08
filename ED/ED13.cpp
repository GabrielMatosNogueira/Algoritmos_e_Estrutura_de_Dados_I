#include "io.hpp"
#include "ED13.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;

void metodo01(void)
{
	contato contato1;
	string name = "";

	cout << endl
		 << "Digite o nome do contato"
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

void metodo02(void)
{
	string telefone = "";
	contato contato1;

	cout << endl;
	telefone = IO_readstring("Digite o numero de telefone desejado: ");
	contato1.setPhone(telefone);
	contato1.showPhone();

	IO_print("Aperte ENTER para terminar");
	getchar();
}

void metodo03(void)
{
	string telefone = "";
	contato contato1;

	cout << endl;
	telefone = IO_readstring("Digite o numero do telefone que deseja verificar: ");

	contato1.setPhone(telefone);
	contato1.showPhone();
	contato1.isValidPhone(telefone);

	IO_print("Aperte ENTER para terminar");
	getchar();
}

void metodo04(void)
{
	contato contato1;
	string nome;

	nome = IO_readstring("Digite o nome do arquivo (com a extensao) que deseja ler: ");

	if (nome.empty())
	{
		do
		{
			IO_print("\nNao foi possivel obter o nome do arquivo, tente novamente.");
			nome = IO_readstring("\nDigite o nome do arquivo (com a extensao) que deseja ler: ");
		} while (!(nome.empty()));
	}
	else
	{
		contato1.readFromFile(nome);
		contato1.getReadNameFromFile();

		cout << endl;
		IO_print("Aperte ENTER para terminar");
		getchar();
	}
}

void metodo05(void)
{
	string filename;
	contato contato1;

	filename = IO_readstring("\nDigite o nome do arquivo: ");

	if (filename.empty())
	{
		do
		{
			filename = IO_readstring("\nNao foi possivel ler o nome do arquivo, tente novamente: ");
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
void metodo06(void)
{
	bool verificador = false;
	contato contato1;
	string nome;
	string telefone;
	string telefone2;

	nome = IO_readstring("\nDigite o nome do contato (sem espacos, utilize '_' entre nome e sobrenomes): ");
	contato1.setName(nome);
	contato1.showName();

	verificador = IO_readbool("\nDeseja inserir dois numeros de telefone? (1 = Sim / 0 = Nao): ");

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
Incluir um novo atributo à classe (1317) para
indicar quantos telefones estão associados a cada objeto.
Incluir um método para obter essa informação.
Incluir um método para testar essa nova característica.
DICA: Usar as modificações sugeridas no exemplo anterior.
Exemplo: int n = contato1.phones ( );
*/
void metodo07(void)
{
	contato contato1;
	int n = 0;
	string nome, telefone, telefone2;
	bool verificador = false;

	nome = IO_readstring("\nDigite o nome do contato (sem espacos, utilize '_' entre nome e sobrenomes): ");
	contato1.setName(nome);

	do
	{
		telefone = IO_readstring("\nDigite o numero de telefone: ");
		verificador = contato1.isValidPhone(telefone);
	} while (!verificador);

	contato1.setPhone(telefone);

	verificador = IO_readbool("\nDeseja adicionar um segundo telefone? (1 = Sim / 0 = Nao): ");
	if (verificador)
	{
		do
		{
			telefone2 = IO_readstring("\nDigite o segundo numero de telefone: ");
			verificador = contato1.isValidPhone(telefone2);
		} while (!verificador);

		contato1.setPhone2(telefone2);
	}

	n = contato1.phones();
	cout << "\nQuantidade de telefones associados ao contato: " << n << endl;

	// Exibir numero de telefones associados ao contato
	contato1.showPhone();
	contato1.showPhone2();

	IO_print("Aperte ENTER para terminar");
	getchar();
}

/*
Incluir um método público (1318) para
para atribuir valor ao segundo telefone.
Incluir um método para testar essa nova característica.
DICA: Se o contato só tiver um telefone, perguntar se quer acrescentar mais um número,
e mudar automaticamente a quantidade deles, se assim for desejado.
Exemplo: contato.setPhone2a ( “97777-3333” );
*/
void metodo08(void)
{
	contato contato1;
	string telefone2;
	string nome = "";
	bool verificador = false;
	bool inserirSegundoTelefone = false;

	nome = IO_readstring("\nDigite o nome do contato (sem espacos, utilize '_' entre nome e sobrenomes):");
	getchar();

	inserirSegundoTelefone = IO_readbool("\nDeseja inserir um segundo numero de telefone? (1 = Sim / 0 = Nao): ");
	getchar();

	if (inserirSegundoTelefone)
	{

		do
		{
			telefone2 = IO_readstring("\nDigite o segundo numero de telefone: ");
			verificador = contato1.isValidPhone(telefone2);
		} while (!verificador);

		contato1.setPhone2a(telefone2);
		contato1.showPhone2a();

		cout << "\nSegundo telefone adicionado com sucesso!" << endl;
	}
	else
	{
		cout << "\nNenhum segundo telefone sera adicionado." << endl;
	}

	IO_print("Aperte ENTER para terminar");
	getchar();
}

/*
Incluir um método público (01319) para
alterar o valor apenas do segundo telefone.
Incluir um método para testar essa nova característica.
DICA: Se o contato não tiver dois telefones, uma situação de erro deverá ser indicada.
Exemplo: contato.setPhone2b ( “97777-3333” );
*/
void metodo09(void)
{
	contato contato1;
	string telefone2;
	string nome = "";
	bool verificador = false;
	contato1.setPhone2a("97777-3333");

	nome = IO_readstring("\nDigite o nome do contato (sem espacos, utilize '_' entre nome e sobrenomes): ");
	contato1.setName(nome);
	contato1.showName();

	verificador = IO_readbool("\nDeseja alterar o segundo numero de telefone? (1 = Sim / 0 = Nao): ");
	getchar();
	if (verificador)
	{
		if (contato1.phones() < 2)
		{
			cout << "\nErro: Contato nao possui dois numeros de telefone." << endl;
		}
		else
		{
			do
			{
				telefone2 = IO_readstring("\nDigite o novo segundo numero de telefone: ");
				verificador = contato1.isValidPhone(telefone2);
			} while (!verificador);

			contato1.setPhone2a(telefone2);
			contato1.showPhone2a();
		}
	}
	else
	{
		cout << "\nNenhuma alteracao sera feita no segundo telefone." << endl;
	}

	IO_print("Aperte ENTER para terminar");
	getchar();
}

/*
Incluir um método público (01320) para
remover apenas o valor do segundo telefone.
Incluir um método para testar essa nova característica.
DICA: Se o contato só tiver um telefone, uma situação de erro deverá ser indicada.
*/
void metodo10(void)
{
	contato contato1;
	string nome = "";
	bool verificador = false;
	contato1.setPhone2a("97777-3333");

	nome = IO_readstring("\nDigite o nome do contato (sem espacos, utilize '_' entre nome e sobrenomes): ");
	contato1.setName(nome);
	contato1.showName();

	verificador = IO_readbool("\nDeseja remover o segundo numero de telefone? (1 = Sim / 0 = Nao): ");
	getchar();

	if (verificador)
	{
		if (contato1.phones() < 2)
		{
			cout << "\nErro: Contato nao possui dois numeros de telefone." << endl;
		}

		else
		{
			contato1.setPhone2b("");
			cout << "\nSegundo telefone removido com sucesso!" << endl;
			contato1.showPhone2a();
		}
	}

	else
	{
		cout << "\nNenhuma alteracao sera feita no segundo telefone." << endl;
	}

	IO_print("Aperte ENTER para terminar");
	getchar();
}

/*
Fazer modificações na classe Contato (013E1)
para lidar com qualquer quantidade de telefones, menor ou igual a 10.
Incluir testes para essa nova característica.
DICA: Guardar a quantidade de telefones e, separadamente, os telefones em arranjo.
*/
void metodo_013E1(void)
{
	int i = 0;
	bool verificador = false;
	contato contato1;
	string telefone;
	string nome = "";
	bool adicionar = true;
	bool alterarProximo = true;

	nome = IO_readstring("\nDigite o nome do contato (sem espacos, utilize '_' entre nome e sobrenomes): ");
	contato1.setName(nome);
	contato1.showName();

	for (i = 0; i < 10 && adicionar && alterarProximo; i = i + 1)
	{
		if (i == 0)
		{
			adicionar = true;
		}
		else
		{
			adicionar = IO_readbool("\nDeseja adicionar mais um numero de telefone? (1 = Sim / 0 = Nao): ");
		}

		if (adicionar)
		{
			do
			{
				telefone = IO_readstring("\nDigite o numero de telefone: ");
				verificador = contato1.isValidPhone(telefone);
			} while (!verificador);

			contato1.addPhone(telefone);
			cout << "\nTelefone adicionado: " << telefone << endl;

			alterarProximo = IO_readbool("\nDeseja alterar o proximo numero? (1 = Sim / 0 = Nao): ");
			if (!alterarProximo)
			{
				cout << "\nSaindo da insercao de telefones." << endl;
			}
		}
		else
		{
			cout << "\nNenhum telefone sera adicionado." << endl;
			adicionar = false;
		}
	}

	IO_print("Aperte ENTER para terminar");
	getchar();
}

/*
Fazer modificações na classe Contato (013E2)
para lidar também com endereços (residencial e profissional).
Incluir testes para essa nova característica.
DICA: Guardar separadamente o endereço residencial e o profissional.
*/
void metodo_013E2(void)
{
	contato contato1;
	string nome = "";
	string enderecoResidencial = "";
	string enderecoComercial = "";

	nome = IO_readstring("\nDigite o nome do contato (sem espacos, utilize '_' entre nome e sobrenomes): ");
	contato1.setName(nome);
	contato1.showName();

	enderecoResidencial = IO_readstring("\nDigite o endereco residencial: ");
	contato1.setEnderecoResidencial(enderecoResidencial);
	contato1.getEnderecoResidencial();

	enderecoComercial = IO_readstring("\nDigite o endereco comercial: ");
	contato1.setEnderecoComercial(enderecoComercial);
	contato1.getEnderecoComercial();

	IO_print("Aperte ENTER para finalizar.");
	getchar();
}

int main(void)
{
	int opcao = 0;
	do
	{
		IO_methods(13); // Funcao para implementar o menu de opcoes de acordo com o ED ( Finalmente (: )
		opcao = IO_readint("\nDigite a opcao desejada: ");
		switch (opcao)
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

		case 7:
			metodo07();
			break;

		case 8:
			metodo08();
			break;

		case 9:
			metodo09();
			break;

		case 10:
			metodo10();
			break;

		case 11:
			metodo_013E1();
			break;

		case 12:
			metodo_013E2();
			break;
		}

	} while (opcao != 0);

	return 0;
}
