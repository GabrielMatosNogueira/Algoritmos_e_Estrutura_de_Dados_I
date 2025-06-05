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
    bool OK;

public:
    contato()
    {
        this->nome = "";
        this->telefone = "";
        this->OK = false;
    }

    void setName(const string name)
    {
        this->nome = name;
    }

    void showName()
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

    void showPhone()
    {
        cout << endl
             << "Telefone lido: " << this->telefone << endl;
    }

    void isValidPhone(const string &phone)
    {
        int i = 0;
        int tamanho = strlen(phone.c_str());

        if (phone == "")
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
                if (tamanho == 9)
                {
                    IO_print("Insira o DDD da sua regiao sem utilizar '()'");
                }

                if (tamanho == 11)
                {
                    IO_print("\nUse travessao para separar o numero de telefone na quarta posicao depois do '9'\n");
                }

                if (tamanho == 13 || tamanho == 14)
                {
                    IO_print("\nNao insira o DDI\n");
                }
                this->OK=false;
                return;
            }
        }

        if(OK==true)
        {
            IO_print("\nNumero valido!\n");
        }
        else
        {
            IO_print("\nNumero invalido!\n");
        }
    }
};
