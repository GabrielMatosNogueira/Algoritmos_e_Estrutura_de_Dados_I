/*
0870863_Gabriel_Matos_Nogueira
ED14
*/

/*
DEPENDENCIAS/BIBLIOTECAS
*/
#include "io.hpp"
using namespace std;

/*
CLASSE ED14

Classe necessaria para realizar a tarefa "Estudo Dirigido 14"
*/
class ED14
{
private:
    int numero_inteiro;
    double numero_real;
    string cadeia_caracteres;

public:
    /*
    CONSTRUTOR ED14

    Responsavel por criar e inicializar as variaveis a qual inicializa as variaveis 
    utilizadas no metodo private da classe ED14
    */
    ED14()
    {
        this->numero_inteiro = 0;
        this->numero_real = 0.0;
        this->cadeia_caracteres = "";
    }

    /*
    DESTRUTOR ED14

    Responsavel por desatribuir e desreferenciar atributos da classe privada de ED14
    */
    ~ED14()
    {
        this->numero_inteiro = 0;
        this->numero_real = 0.0;
        this->cadeia_caracteres = "";
    }

    /*
    METODO SETINT

    Responsavel por verificar a existencia de um valor inteiro disponivel para uso e,
    caso exista, atribuir um sinal positivo ou negativo ao mesmo

    @param valor inteiro para o objeto
    @return numero atribuido ou -1 (em caso de inexistencia)
    */
    int setInt(int valor)
    {
        if (this->numero_inteiro!=-1)
        {
            this->numero_inteiro = valor;
            return valor;
        }
        else
        {
            return -1;
        }
    }

    /*
    METODO SETDOUBLE

    Responsavel por verificar a existencia de um valor real disponivel para uso e,
    caso exista, atribuir um sinal positivo ou negativo ao mesmo

    @param valor real para o objeto
    @return numero atribuido ou -1 (em caso de inexistencia)
    */
    int setDouble(double valor)
    {
        if (this->numero_real!=-1.0)
        {
            this->numero_real = valor;
            return valor;
        }
        else
        {
            return -1;
        }
    }

    /*
    METODO SETSTRING

    Responsavel por verificar a existencia de uma string disponivel para uso e,
    caso exista, atribuir um uma cadeia de caracteres a ela

    @param cadeia de caracteres
    @return frase atribuida ou -1 (em caso de inexistencia)
    */
    string setString(string frase)
    {
        if (this->cadeia_caracteres != "")
        {
            this->cadeia_caracteres = frase;
            return cadeia_caracteres;
        }
        else
        {
            IO_println("Erro ao obter a frase");
        }
    }

    /*
    METODO GETINT

    Responsavel por retornar o valor inteiro, caso exista

    @param vazio
    @return numero atribuido ou -1 (em caso de inexistencia)
    */
    int getInt()
    {
        if (this->numero_inteiro!=-1)
        {
            return this->numero_inteiro;
        }
        else
        {
            return -1;
        }
    }

    /*
    METODO GETDOUBLE

    Responsavel por retornar o valor real, caso exista

    @param vazio
    @return numero atribuido ou -1 (em caso de inexistencia)
    */
    double getDouble()
    {
        if (this->numero_real!=-1.0)
        {
            return this->numero_real;
        }
        else
        {
            return -1.0;
        }
    }

    /*
    METODO GETSTRING

    Responsavel por retornar a cadeia de caracteres, caso exista

    @param vazio
    @return frase atribuida ou mensagem de erro
    */
    string getString()
    {
        if (!this->cadeia_caracteres.empty())
        {
            return this->cadeia_caracteres;
        }
        else
        {
            return "[String inexistente]";
        }
    }
};
