#include <iostream>
#include <string>
#include <cstring>
#include "io.hpp"

#define MAX 100

using namespace std;

struct contato
{
private:
    string nome;
    string telefone;
    int quantidadeTelefones;
    bool OK;

public:
    contato(void)
    {
        this->nome = "";
        this->telefone = "";
        this->OK = false;
        this->quantidadeTelefones=0;
    }

    void setName(const string name)
    {
        this->nome = name;
    }

    void showName(void)
    {
        cout << "Nome recebido: " << this->nome;
    }

    void setPhone(const string phone)
    {
        if (phone == "")
        {
            cout << "Numero de telefone vazio." << endl;
        }

        else
        {
            this->telefone = phone;
        }
    }

    void showPhone(void)
    {
        cout << endl
             << "Telefone lido: " << this->telefone << endl;
    }

    void isValidPhone(const string &phone)
    {
        int i = 0;
        int tamanho = strlen(phone.c_str());

        if (phone.empty())
        {
            IO_print("Numero vazio.");
        }

        /*
        De acordo com a ANATEL, telefones moveis possuem nove digitos atualmente,
        desconsiderando o DDD
        Considerando o DDD: 2 numeros
        Considerando o numero: 9 digitos + 1('-')
        Total: 12 caracteres

        EXEMPLO: 31971585300
        */

        else
        {
            if (tamanho == 12)
            {
                for (i = 0; i < 13; i = i + 1)
                {
                    if (phone[7] != '-')
                    {
                        cout << endl
                             << "Use travessao para separas os algarismos antes do " << phone[i] << " na posicao [" << i << "]" << endl;
                        this->OK = false;
                        return;
                    }

                    if (phone[i] == '0' || phone[i] == '1' || phone[i] == '2' || phone[i] == '3' || phone[i] == '4' || phone[i] == '5' || phone[i] == '6' || phone[i] == '7' || phone[i] == '8' || phone[i] == '9' || phone[7] == '-')
                    {
                        //cout << endl;
                        //     << "Caractere [" << phone[i] << "] validado." << endl;
                        this->OK = true;
                    }

                    else
                    {
                        cout << endl
                             << "Caractere [" << phone[i] << "] e' invalido." << endl;
                        this->OK = false;
                        return;
                    }
                }
            }

            else
            {
                this->OK=false;
                
                if(OK==false){IO_print("\nNumero invalido!\n");};
                if (tamanho == 9)
                {
                    IO_print("Insira o DDD da sua regiao sem utilizar '()'\n");
                }

                if (tamanho == 11)
                {
                    IO_print("\nUse travessao para separar o numero de telefone emtre a quarta e a quinta posicao depois do '9'\n");
                }

                if (tamanho == 13 || tamanho == 14)
                {
                    IO_print("\nNao insira o DDI\n");
                }
                
            }
        }

        if(OK==true)
        {
            IO_print("\nNumero valido!\n");
        }
    }

    void readFromFile(const string filename)
    {
        ifstream arquivo (filename);
        if(arquivo.is_open())
        {
            arquivo >> this->nome;
            arquivo.close();
        }
        else
        {
            IO_print("\nErro ao abrir o arquivo.");
        }

    }

    void getReadNameFromFile(void)
    {
        cout << endl << "Nome lido do arquivo: " << this->nome;
    }

    void writeToFile (const string filename)
    {
        string nome;
        ofstream arquivo (filename);

        nome=IO_readstring("\nDigite o nome que deseja guardar no arquivo: ");

        arquivo << nome;

        arquivo.close();
    }
};
