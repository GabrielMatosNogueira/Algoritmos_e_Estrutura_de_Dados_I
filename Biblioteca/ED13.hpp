#include <iostream>
#include <string>
#include "io.hpp"

using namespace std;

struct contato
{
private:
    string nome;
    string telefone;

public:
	contato()
	{this->nome = "";this->telefone = "";}

	void setName(const string name)
	{this->nome = name;}

	void showName()
	{cout << "Nome recebido: " << this->nome;}

    	void setPhone(const string phone)
    	{if(phone==""){cout << "Numero de telefone vazio.";}else{this->telefone = phone;}}

    	void showPhone()
    	{cout << endl << "Telefone lido: " << this->telefone;}
};
