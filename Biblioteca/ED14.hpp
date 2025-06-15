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
    bool numero_logico;
    string cadeia_caracteres;

public:
    ED14()
    {
        this->numero_inteiro = 0;
        this->numero_real = 0.0;
        this->cadeia_caracteres = "";
    }

    ~ED14()
    {
        this->numero_inteiro = 0;
        this->numero_real = 0.0;
        this->cadeia_caracteres = "";
    }

    int setInt(int valor)
    {
        if (this->numero_inteiro != -1)
        {
            this->numero_inteiro = valor;
            return valor;
        }
        else
        {
            return -1;
        }
    }

    int setDouble(double valor)
    {
        if (this->numero_real != -1.0)
        {
            this->numero_real = valor;
            return valor;
        }
        else
        {
            return -1;
        }
    }

    int setString(const string& valor)
    {
        if (!valor.empty())
        {
            this->cadeia_caracteres = valor;
            return 1; // Sucesso
        }
        else
        {
            IO_println("Cadeia de caracteres vazia");
            return -1; // Falha
        }
    }

    int getInt()
    {
        if (this->numero_inteiro != 0)
        {
            return this->numero_inteiro;
        }
        else
        {
            IO_println("Erro ao converter para inteiro");
            return -1;
        }
    }

    double getDouble()
    {
        if (this->numero_real != -1.0)
        {
            return this->numero_real;
        }
        else
        {
            return -1.0;
        }
    }

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

    bool getBoolean()
    {
        return this->numero_logico;
    }

    int setBoolean(const std::string& valor)
    {
        if (valor == "true" || valor == "T" || valor == "1")
        {
            this->numero_logico = true;
            return 1;
        }
        else if (valor == "false" || valor == "F" || valor == "0")
        {
            this->numero_logico = false;
            return 0;
        }
        else
        {
            IO_println("Valor logico invalido");
            return -1;
        }
    }

    int setBoolean(bool valor)
    {
        this->numero_logico = valor;
        return valor ? 1 : 0;
    }

    int setBoolean(int valor)
    {
        if (valor == 0)
        {
            this->numero_logico = false;
            return 0;
        }
        else if (valor == 1)
        {
            this->numero_logico = true;
            return 1;
        }
        else
        {
            IO_println("Valor logico invalido");
            return -1;
        }
    }

    int setBoolean(char valor)
    {
        if (valor == 'T' || valor == '1')
        {
            this->numero_logico = true;
            return 1;
        }
        else if (valor == 'F' || valor == '0')
        {
            this->numero_logico = false;
            return 0;
        }
        else
        {
            IO_println("Valor logico invalido");
            return -1;
        }
    }

    /** 
     * @brief METODO04
     * @objective: Funcao para verificar se o parametro (subtexto) esta’ contido no conteudo.
     *             Com a funcao bool contains ( std::string texto, std::string subtexto )
     * 
     */
    bool contains(const string& texto, const string& subtexto) const
    {
        if (texto.empty() || subtexto.empty())
        {
            IO_println("Cadeia de caracteres vazia");
            return false;
        }
        // Verifica se o subtexto está contido no texto
        return texto.find(subtexto) != string::npos;
    }
    /*
    Metodo toUpperCase
    * @brief Converte todas as letras da cadeia de caracteres para maiúsculas.
    * @return cadeia de caracteres convertida para maiúsculas
    */
    string toUpperCase(const string& texto)
    {
        if (texto.empty())
        {
            IO_println("Cadeia de caracteres vazia");
            return "Falha ao converter para maiusculas";
        }
        string upperCaseStr = texto;
        for (size_t i = 0; i < upperCaseStr.length(); ++i)
        {
            char c = upperCaseStr[i];
            // Se for letra minúscula ('a' a 'z'), converte para maiúscula
            if (c >= 'a' && c <= 'z')
            {
                upperCaseStr[i] = c - ('a' - 'A');
            }
        }
        return upperCaseStr;
    }

    // Sobrecarga para usar a string interna da classe
    string toUpperCase()
    {
        return toUpperCase(this->cadeia_caracteres);
    }

    /*
    Metodo toLowerCase
    * @brief Converte todas as letras da cadeia de caracteres para minúsculas.
    * @return cadeia de caracteres convertida para minúsculas
    */
    string toLowerCase(const string& texto)
    {
        if (texto.empty())
        {
            IO_println("Cadeia de caracteres vazia");
            return "";
        }
        string lowerCaseStr = texto;
        for (size_t i = 0; i < lowerCaseStr.length(); ++i)
        {
            char c = lowerCaseStr[i];
            if (c >= 'A' && c <= 'Z')
            {
                lowerCaseStr[i] = c + ('a' - 'A');
            }
        }
        return lowerCaseStr;
    }

    /**
     * @brief METODO07
     * 
     * @objective: Funcao para trocar todas as ocorrencias de certo caractere por outro novo.
     *             com a funcao replace(char caractere, char novo_caractere)
     * 
     * @param caractere - caractere a ser substituido
     * @param novo_caractere - novo caractere a ser inserido
     * @return true se a substituição for bem-sucedida, false caso contrário
     */
    bool replace(char caractere, char novo_caractere)
    {
        if (this->cadeia_caracteres.empty())
        {
            IO_println("Cadeia de caracteres vazia");
            return false;
        }
        size_t pos = this->cadeia_caracteres.find(caractere);
        if (pos != std::string::npos)
        {
            while (pos != std::string::npos)
            {
                this->cadeia_caracteres[pos] = novo_caractere;
                pos = this->cadeia_caracteres.find(caractere, pos + 1);
            }
            return true;
        }
        else
        {
            return false; // Caractere não encontrado
        }
    }

    /**
     * @brief METODO 08
     * 
     * @objective: Funcao para codificar o conteudo segundo a cifra de César (pesquisar)
     * @param int chave - chave de deslocamento para a cifra, string frase - texto a ser cifrado
     * @return  valor equivalente codificado, se houver; 
     *          o proprio valor, caso contrario 
     */
    string encrypt(int chave, const string& frase)
    {
        if (frase.empty())
        {
            IO_println("Cadeia de caracteres vazia");
            return "Erro ao cifrar a frase";
        }
        string encryptedStr = frase;
        for (size_t i = 0; i < encryptedStr.length(); ++i)
        {
            char c = encryptedStr[i];
            // Verifica se é uma letra
            if (isalpha(c))
            {
                char base;
                if (islower(c))
                {
                    base = 'a';
                }
                else
                {
                    base = 'A';
                }
                // Aplica a cifra de César
                encryptedStr[i] = (c - base + chave + 26) % 26 + base;
            }
        }
        return encryptedStr;
    }

    /**
     * @brief METODO09
     * 
     * @objective: Funcao para decodificar o conteudo previamente cifrado pela funcao acima.
     *             com a funcao decrypt(void)
     * 
     * @param void
     * @return valor equivalente decodificado, se houver; o proprio valor, caso contrario 
     */
    string decrypt(int chave)
    {
        if (this->cadeia_caracteres.empty())
        {
            IO_println("Cadeia de caracteres vazia");
            return "";
        }
        string decryptedStr = this->cadeia_caracteres;
        for (size_t i = 0; i < decryptedStr.length(); ++i)
        {
            char c = decryptedStr[i];
            // Verifica se é uma letra
            if (isalpha(c))
            {
                char base;
                if (islower(c))
                {
                    base = 'a';
                }
                else
                {
                    base = 'A';
                }
                // Aplica a cifra de César inversa
                decryptedStr[i] = (c - base - chave + 26) % 26 + base;
            }
        }
        return decryptedStr;
    }

    /**
     * @brief METODO 10
     * 
     * @objective: Funcao para verificar se o conteudo esta vazio.
     * @param void
     * @return true se estiver vazio, false caso contrario
     */
    bool isEmpty() const
    {
        if (this->cadeia_caracteres.empty())
        {
            IO_println("Cadeia de caracteres vazia");
            return true;
        }
        else
        {
            return false;
        }
    }

    /**
     * @brief METODO 11
     * 
     * @objective: Funcao para verificar se o conteudo esta vazio.
     * @param void
     * @return true se estiver vazio, false caso contrario
     */
    bool isNotEmpty() const
    {
        if (!this->cadeia_caracteres.empty())
        {
            return true;
        }
        else
        {
            IO_println("Cadeia de caracteres vazia");
            return false;
        }
    }
    
    /**
     * @brief METODO 12
     * 
     * @objective: Funcao para verificar se o conteudo é um número inteiro.
     * @param void
     * @return true se for um número inteiro, false caso contrário
     */
    bool isInteger() const
    {
        if (this->numero_inteiro != 0)
        {
            return true;
        }
        else
        {
            IO_println("O conteudo nao e um numero inteiro");
            return false;
        }
    }

};
