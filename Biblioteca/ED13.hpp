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
    string telefone2;
    string enderecoResidencial;
    string enderecoComercial;
    int quantidadeTelefones;
    bool OK;

public:
    contato(void)
    {
        this->nome = "";
        this->telefone = "";
        this->telefone2 = "";
        this->enderecoResidencial = "";
        this->enderecoComercial = "";
        this->OK = false;
        this->quantidadeTelefones = 0;
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

    void showPhone2(void)
    {
        cout << endl
             << "Telefone 2 lido: " << this->telefone2 << endl;
    }

    // Valida o formato do telefone conforme regras da ANATEL
    bool isValidPhone(const string &phone)
    {
        int tamanho = phone.length();

        if (phone.empty())
        {
            IO_print("Numero vazio.");
            this->OK = false;
            return false;
        }

        /*
        De acordo com a ANATEL, telefones moveis possuem nove digitos atualmente,
        desconsiderando o DDD
        Considerando o DDD: 2 numeros
        Considerando o numero: 9 digitos + 1('-')
        Total: 12 caracteres

        EXEMPLO: 3197158-5300
        */

        // Formato esperado: DDD + 5 dígitos + '-' + 4 dígitos (ex: 3197158-5300)
        if (tamanho == 12)
        {
            // Verifica se o caractere na posição 7 é '-'
            if (phone[7] != '-')
            {
                cout << endl
                     << "Use travessao para separar os algarismos antes do " << phone[7] << " na posicao [7]" << endl;
                this->OK = false;
                return false;
            }

            // Verifica se todos os outros caracteres são dígitos
            for (int i = 0; i < tamanho; ++i)
            {
                if (i == 7)
                    continue; // Posição do '-'
                if (!isdigit(phone[i]))
                {
                    cout << endl
                         << "Caractere [" << phone[i] << "] e' invalido na posicao [" << i << "]." << endl;
                    this->OK = false;
                    return false;
                }
            }
            this->OK = true;
            IO_print("\nNumero valido!\n");
            return true;
        }
        else
        {
            this->OK = false;
            IO_print("\nNumero invalido!\n");

            if (tamanho == 9)
            {
                IO_print("Insira o DDD da sua regiao sem utilizar '()'\n");
            }
            else if (tamanho == 11)
            {
                IO_print("\nUse travessao para separar o numero de telefone entre a quarta e a quinta posicao depois do '9'\n");
            }
            else if (tamanho == 13 || tamanho == 14)
            {
                IO_print("\nNao insira o DDI\n");
            }
            return false;
        }
    }

    void setPhone2(const string phone2)
    {
        if (phone2 == "")
        {
            cout << "Numero de telefone vazio." << endl;
        }

        else
        {
            this->telefone2 = phone2;
            this->quantidadeTelefones++;
        }
    }

    void getPhone2(void)
    {
        cout << endl
             << "Telefone 2 lido: " << this->telefone2 << endl;
    }

    void readFromFile(const string filename)
    {
        ifstream arquivo(filename);
        if (arquivo.is_open())
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
        cout << endl
             << "Nome lido do arquivo: " << this->nome;
    }

    void writeToFile(const string filename)
    {
        string nome;
        ofstream arquivo(filename);

        nome = IO_readstring("\nDigite o nome que deseja guardar no arquivo: ");

        arquivo << nome;

        arquivo.close();
    }

    int phones(void)
    {
        if (this->telefone2.empty())
        {
            this->quantidadeTelefones = 1;
        }
        else
        {
            this->quantidadeTelefones = 2;
        }
        return this->quantidadeTelefones;
    }

    void setPhone2a(const string phone2)
    {
        if (phone2 == "")
        {
            cout << "Numero de telefone vazio." << endl;
        }
        else
        {
            this->telefone2 = phone2;
            this->quantidadeTelefones = quantidadeTelefones + 1;
        }
    }

    void showPhone2a(void)
    {
        cout << endl
             << "Segundo telefone lido: " << this->telefone2 << endl;
    }

    void setPhone2b(const string phone2)
    {
        bool verificador = false;

        verificador = IO_readbool("\nDeseja alterar o segundo numero de telefone? (1 = Sim / 0 = Nao): ");
        if (verificador)
        {
            if (this->quantidadeTelefones < 2)
            {
                IO_print("\nErro: Contato nao possui dois numeros de telefone.");
            }
            else
            {
                this->telefone2 = phone2;
                this->quantidadeTelefones++;
                cout << "\nSegundo telefone alterado com sucesso!" << endl;
            }
        }
        else
        {
            cout << "\nNenhuma alteracao selecionada" << endl;
        }
    }

    void addPhone(const string phone)
    {
        if (this->quantidadeTelefones < 10)
        {
            this->setPhone2(phone);
        }
        else
        {
            cout << "\nLimite de telefones atingido. Nao e' possivel adicionar mais." << endl;
        }
    }

    void setEnderecoResidencial(const string endereco)
    {
        this->enderecoResidencial = endereco;
    }

    void getEnderecoResidencial(void)
    {
        cout << endl
             << "Endereco residencial lido: " << this->enderecoResidencial << endl;
    }

    void setEnderecoComercial(const string endereco)
    {
        this->enderecoComercial = endereco;
    }

    void getEnderecoComercial(void)
    {
        cout << endl
             << "Endereco comercial lido: " << this->enderecoComercial << endl;
    }
};
