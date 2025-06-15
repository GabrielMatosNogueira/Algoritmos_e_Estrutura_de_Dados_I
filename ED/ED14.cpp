/*
0870863_Gabriel_Matos_Nogueira
ED14
*/

/*
DEPENDENCIAS/BIBLIOTECAS
*/
#include "io.hpp"
#include "ED14.hpp"
#include <stdbool.h>
using namespace std;

/** 
* @brief METODO 01
*
* @objective: Funcao para converter conteudo do objeto para valor inteiro com sinal, se possivel. 
*
* @param void
* @return valor inteiro equivalente, se valido;
*/
void metodo01(void)
{
    ED14 ED14_metodo01;
    int numero_inteiro=0;
    int valor_lido=0;

    cout << endl;
    numero_inteiro=IO_readint("Digite um numero inteiro para o objeto: ");
    cin.clear();
    ED14_metodo01.setInt(numero_inteiro);

    valor_lido=ED14_metodo01.getInt();
    IO_printf("Valor lido com a funcao get: %d", valor_lido);
    cout << endl;

    IO_println("Aperte ENTER para encerrar o programa.");
    getchar();
}

/** 
* @brief METODO 02
*
* @objective: Funcao para converter conteudo do objeto para valor real, se possivel, usando a funcao getDouble e setDouble.
*
* @param void
* @return valor real equivalente, se valido;
*/
void metodo02(void)
{
    ED14 ED14_metodo02;
    double numero_real=0.0;
    double valor_lido=0.0;

    cout << endl;
    numero_real=IO_readdouble("Digite um numero real para o objeto: ");
    cin.clear();
    ED14_metodo02.setDouble(numero_real);

    valor_lido=ED14_metodo02.getDouble();
    IO_printf("Valor lido com a funcao get: %.2f", valor_lido);
    cout << endl;

    IO_println("Aperte ENTER para encerrar o programa.");
    getchar();
}

/**
* @brief METODO 03
*
* @objective: Funcao para converter conteudo do objeto para valor lógico, se possivel, usando as funcoes getBoolean e setBoolean.
*             Nota: Considerar válidos: { false, true, F, T, 0, 1 }
*
* @param void
* @return true , se contiver (a partir de qualquer posicao);
*/
void metodo03(void)
{
    ED14 ED14_metodo03;
    string valor_logico;
    int valor_lido;

    cout << endl;
    valor_logico = IO_next("Digite um valor logico (true, false, T, F, 1, 0): ");
    
    if (ED14_metodo03.setBoolean(valor_logico) != -1)
    {
        valor_lido = ED14_metodo03.getBoolean();
        IO_printf("Valor lido com a funcao get: %d", valor_lido);
        cout << endl;
    }
    else
    {
        IO_println("Valor logico invalido.");
    }

    IO_println("Aperte ENTER para encerrar o programa.");
    getchar();
}

/** 
* @brief METODO 04
*
* @objective: Funcao para verificar se o parametro (subtexto) esta’ contido no conteudo.
*             Com a funcao bool contains ( std::string subtexto )
*
* @param void
* @return true , se contiver (a partir de qualquer posicao);
*/
void metodo04(void)
{
    ED14 ED14_metodo04;
    string frase, subtexto;

    cout << endl;
    frase = IO_next("Digite uma frase: ");
    ED14_metodo04.setString(frase);

    subtexto = IO_next("Digite um subtexto para verificar se esta contido na frase: ");

    if (!subtexto.empty() && ED14_metodo04.contains(frase, subtexto))
    {
        IO_println("Subtexto encontrado na frase.");
    }
    else
    {
        IO_println("Subtexto NAO encontrado na frase.");
    }

    IO_println("Aperte ENTER para encerrar o programa.");
    getchar();
}

/** 
* @brief METODO 05
* 
* @objective: Funcao para converter letras para maiusculas.
*            Com a funcao string toUpperCase ( std::string texto )
*
* @param void
* @return void
*/
void metodo05(void)
{
    ED14 ED14_metodo05;
    string texto;

    cout << endl;
    texto = IO_next("Digite um texto para converter para maiusculas: ");
    
    string resultado = ED14_metodo05.toUpperCase(texto);
    IO_printf("Texto convertido para maiusculas: %s", resultado.c_str());
    cout << endl;

    IO_println("Aperte ENTER para encerrar o programa.");
    getchar();
}

/** 
* @brief METODO 
*
* @objective: Funcao para converter letras para minusculas. 
*
* @param void
* @return void
*/
void metodo06(void)
{
    ED14 ED14_metodo06;
    string texto;

    cout << endl;
    texto = IO_next("Digite um texto para converter para minusculas: ");
    
    string resultado = ED14_metodo06.toLowerCase(texto);
    IO_printf("Texto convertido para minusculas: %s", resultado.c_str());
    cout << endl;

    IO_println("Aperte ENTER para encerrar o programa.");
    getchar();
}

/** 
* @brief METODO 07
*
* @objective: Funcao para trocar todas as ocorrencias de certo caractere por outro novo.
*             com a funcao replace(char caractere, char novo_caractere)
*
* @param void
* @return void
*/
void metodo07(void)
{
    ED14 ED14_metodo07;
    string texto;
    char caractere= '\0';
    char novo_caractere='\0';

    cout << endl;
    texto = IO_next("Digite o texto onde sera feita a substituicao: ");
    caractere = IO_next("Digite o caractere a ser substituido: ")[0];
    novo_caractere = IO_next("Digite o novo caractere: ")[0];

    ED14_metodo07.setString(texto);

    if (ED14_metodo07.replace(caractere, novo_caractere))
    {
        IO_printf("Texto apos substituicao: %s\n", ED14_metodo07.getString().c_str());
    }
    else
    {
        IO_println("Caractere nao encontrado.");
    }

    IO_println("Aperte ENTER para encerrar o programa.");
    getchar();
}

/**
 * @brief METODO 08
 * 
 * @objective: Funcao para codificar o conteudo segundo a cifra de César (pesquisar)
 * @param int chave - chave de deslocamento para a cifra, string frase - texto a ser cifrado
 * @return  valor equivalente codificado, se houver; 
 *          o proprio valor, caso contrario 
 */
void metodo08(void)
{
    ED14 ED14_metodo08;
    string frase;
    int chave;

    cout << endl;
    frase = IO_next("Digite uma frase para cifrar: ");
    
    // Solicita a chave de deslocamento
    chave = IO_readint("Digite a chave de deslocamento (numero inteiro): ");

    ED14_metodo08.setString(frase);
    string texto_cifrado = ED14_metodo08.encrypt(chave, frase);

    IO_printf("Texto cifrado: %s", texto_cifrado.c_str());
    cout << endl;

    IO_println("Aperte ENTER para encerrar o programa.");
    getchar();
}


/**
 * @brief METODO 09
 * 
 * @objective: Funcao para decodificar o conteudo previamente cifrado pela funcao acima.
 * @param void
 * @return valor equivalente decodificado, se houver; o proprio valor, caso contrario 
 */
void metodo09(void)
{
    ED14 ED14_metodo09;
    string frase;
    int chave;

    cout << endl;
    frase = IO_next("Digite uma frase cifrada para decifrar: ");
    
    // Solicita a chave de deslocamento
    chave = IO_readint("Digite a chave de deslocamento (numero inteiro): ");
    
    ED14_metodo09.setString(frase);
    string texto_decifrado = ED14_metodo09.decrypt(chave);

    IO_printf("Texto decifrado: %s", texto_decifrado.c_str());
    
    cout << endl;

    IO_println("Aperte ENTER para encerrar o programa.");
    getchar();
}

/**
 * @brief METODO 10
 * 
 * @objective:  Funcao para separar todas as sequencias de caracteres separadas por espaços em branco.
 * @param sequencia - arranjo para armazenar possiveis cadeias de caracteres identificadas
 * @return quantidade de sequencias de caracteres identificadas, se houver; 
 *         zero, caso contrario
 */
void metodo10(void)
{
    ED14 ED14_metodo10;
    string sequencia;
    cout << endl;
    sequencia = IO_next("Digite uma sequencia de caracteres: ");

    // Verifica se a sequencia esta vazia
    if (!(sequencia.empty()))
    {  
        // Fragmenta a sequencia usando espaço em branco como delimitador
        size_t inicio = 0, fim = 0;
        int quantidade = 0;
        IO_println("Fragmentos encontrados:");
        while ((fim = sequencia.find(' ', inicio)) != string::npos)
        {
            if (fim > inicio) // Ignora espaços consecutivos
            {
                string token = sequencia.substr(inicio, fim - inicio);
                IO_printf("Fragmento: %s\n", token.c_str());
                quantidade++;
            }
            inicio = fim + 1;
        }
        if (inicio < sequencia.length())
        {
            string token = sequencia.substr(inicio);
            if (!token.empty())
            {
                IO_printf("Fragmento: %s\n", token.c_str());
                quantidade++;
            }
        }
        IO_printf("Quantidade de fragmentos: %d\n", quantidade);
    }
    else
    {
        IO_println("Sequencia vazia. Nenhum fragmento encontrado.");
    }

    IO_println("Aperte ENTER para encerrar o programa.");
    getchar();
}

/**
 * @brief METODO E1
 * 
 * @objective: Acrescentar um método (e testes) para fragmentar o conteúdo usando outros delimitadores, 
 *             à escolha (passar parâmetro), diferentes de espaço em branco.
 * @param 
 * @return
 */
void metodo_014E1(void)
{
    ED14 ED14_metodoE1;
    string sequencia;
    char delimitador;

    cout << endl;
    sequencia = IO_next("Digite uma sequencia de caracteres: ");
    delimitador = IO_next("Digite o delimitador desejado: ")[0];

    int fragmentos = 0;
    size_t inicio = 0;
    size_t pos = 0;

    IO_println("Fragmentos encontrados:");
    while ((pos = sequencia.find(delimitador, inicio)) != string::npos) {
        string frag = sequencia.substr(inicio, pos - inicio);
        IO_printf("Fragmento: %s", frag.c_str());
        fragmentos++;
        inicio = pos + 1;
    }
    // Último fragmento (ou único, se não houver delimitador)
    if (inicio <= sequencia.length()) {
        string frag = sequencia.substr(inicio);
        IO_printf("Fragmento: %s", frag.c_str());
        fragmentos++;
    }

    IO_printf("Quantidade de fragmentos: %d", fragmentos);
    cout << endl;

    IO_println("Aperte ENTER para encerrar o programa.");
    getchar();
}

/**
 * @brief METODO E2
 * 
 * @objective: Acrescentar um método (e testes) para inverter a ordem dos símbolos na cadeia de caracteres
 * @param
 * @return
 */
void metodo_014E2(void)
{
    ED14 ED14_metodoE2;
    string texto;

    cout << endl;
    texto = IO_next("Digite um texto para inverter a ordem dos simbolos: ");
    
    // Inverte a ordem dos simbolos
    string texto_invertido = string(texto.rbegin(), texto.rend());

    IO_printf("Texto invertido: %s", texto_invertido.c_str());
    cout << endl;

    IO_println("Aperte ENTER para encerrar o programa.");
    getchar();
}

/**
 * @brief METODO PRINCIPAL
 * 
 * @objective:  Funcao para apresentar o menu de opcoes e chamar os metodos correspondentes.
 * @param void
 * @return 0, se tudo ocorrer bem; outro valor, caso contrario
 */
int main(void)
{
    int opcao = 0;
    do
    {
        IO_methods(14);
        opcao = IO_readint("\nDigite a opcao desejada: ");

        switch (opcao)
        {
        case 0:
            break;
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
            metodo_014E1();
            break;

        case 12:
            metodo_014E2();
            break;
        }

    } while (opcao != 0);

    return 0;
}

/*
void metodo01(void)
{
    int opcao=0;
    int numero_inteiro=0;
    double numero_real=0.0;
    ED14 ED14_metodo01;

    IO_println("Escolha se deseja obter o sinal de um numero INTEIRO ou REAL:");
    IO_println("0 - Encerrar");
    IO_println("1 - Inteiro");
    IO_println("2 - Real");
    opcao=IO_readint("");

    do
    {
        if(opcao==1)
        {
            cout << endl;
            numero_inteiro=IO_readint("Digite o valor do numero inteiro: ");
            if(numero_inteiro<0)
            {
                IO_print
            }
            if(numero_inteiro>0)
            {

            }
            else
            {
                IO_print("Numero e' nulo.");
            }
        }
        if(opcao==2)
        {

        }
        else
        {
            IO_print("Opcao invalida. Tente novamente");
        }
    }while(opcao!=0);

}
*/
