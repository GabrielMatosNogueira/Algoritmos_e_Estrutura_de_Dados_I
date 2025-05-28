/*
Nome do Programa:   ED05
Data:               24/03/2025
Nome:               Gabriel Matos Nogueira
Codigo de Pessoa:   1563147
Matricula:          870863
Versao:             1.0

---------------------------------------------------------------------------------------------------

Como executar o programa no terminal:
1.0 - Certifique-se que o compilador MINGW esteja instalado e presente nas variaveis de ambiente
da sua maquina

2.0 - Adentre a pasta para executar o programa:
cd 1563147_Gabriel_Matos_Nogueira (Windows, Linux e macOS)

    2.1 - Compile o programa
    Windows:    gcc -o ED05 ED05.c
    Linux:      gcc -o ED05 ED05.c
    macOS:      gcc -o ED05 ED05.c


    2.2 - Execute o programa
    Windows:     ED05
    Linux:      ./ED05
    macOS:      ./ED05

---------------------------------------------------------------------------------------------------
*/

// Declaracao de biblioteca(s)
#include "io.h"

// Declaracao dos metodos utilizados
void method_00();
void method_01();
void method_02();
void method_03();
void method_04();
void method_05();
void method_06();
void method_07();
void method_08();
void method_09();
void method_10();
void method_11();
void method_12();

// Declaracao das funcoes auxiliares
void FUNCAO_0511(int n);
void METODO_0512(int n);
void METODO_0514(int quantidade);
void METODO_0515(int quantidade);
void METODO_0516(int quantidade);
double METODO_0517(double quantidade);
int METODO_0518(int quantidade);


// Funcao Principal
int main(void)
{
    // armazenar a opcao do usuario
    int opcao = 0;
    IO_id("\n\t");

    // Menu de opcoes do usuario
    do
    {
        IO_id("\n\tOpcoes de Metodos");
        IO_print("\n0 - Parar");
        IO_print("\n1 - Metodo 0511");
        IO_print("\n2 - Metodo 0512");
        IO_print("\n3 - Metodo 0513");
        IO_print("\n4 - Metodo 0514");
        IO_print("\n5 - Metodo 0515");
        IO_print("\n6 - Metodo 0516");
        IO_print("\n7 - Metodo 0517");
        IO_print("\n8 - Metodo 0518");
        IO_print("\n9 - Metodo 0519");
        IO_print("\n10 - Metodo 0520");
        IO_print("\n11 - Metodo 05E1");
        IO_print("\n12 - Metodo 05E2");

        opcao = IO_readint("\nDigite uma opcao: ");
        switch(opcao)
        {
            case 0:
                    method_00();
                    break;

                case 1:
                    method_01();
                    break;

                case 2:
                    method_02();
                    break;

                case 3:
                    method_03();
                    break;

                case 4:
                    method_04();
                    break;

                case 5:
                    method_05();
                    break;

                case 6:
                    method_06();
                    break;

                case 7:
                    method_07();
                    break;

                case 8:
                    method_08();
                    break;

                case 9:
                    method_09();
                    break;

                case 10:
                    method_10();
                    break;

                case 11:
                    method_11();
                    break;

                case 12:
                    method_12();
                    break;
        }
    } while (opcao!=0);
}
// Funcoes do programa

/*
---------------------------------------------------------------------------------------------------
METODO 00
- Encerramento do programa
---------------------------------------------------------------------------------------------------
*/
void method_00(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 00\n");

    // Mensagem de encerramento
    IO_print ("ENCERRANDO O PROGRAMA...\n");

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------

FUNCAO 0511
- Mostrar 'n' numeros digitados pelo usuario na funcao METODO 01 para gerar valores multiplos de 3

---------------------------------------------------------------------------------------------------
*/

void FUNCAO_0511(int n)
{
    // Declaracao de variaveis
    int i = 0;
    int tamanho = n; // Recebimendo do tamanho do loop pelo tamanho indicado pelo ponteiro

    // Loop sequencial dos multiplos de 3
    for (i = 1; i < tamanho+1; i=i+1)
    {
        printf("[%d] ", i * 3);
    }
    IO_print("\n");
}

/*
---------------------------------------------------------------------------------------------------

METODO 01
- Ler um numero inteiro indicando o numero de repeticoes

---------------------------------------------------------------------------------------------------
*/

void method_01(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 01\n");

    // Declaracao de variaveis
    int n = 0;

    // Requisicao da quantidade de numeros multiplos de 3
    // que o usuario deseja ver
    n = IO_readint("Digite a quantidade de numeros multiplos de 3 que se deseja ver: ");

    // Chamada da funcao de exibicao dos multiplos de 3
    FUNCAO_0511(n);

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO_0512
- Exibe os valores multiplos de 3 e 5 | MMC(3,5)= 15
---------------------------------------------------------------------------------------------------
*/

void METODO_0512(int n)
{
    // Identificacao
    printf("%s\n", "\nMetodo 02\n");

    // Declaracao das variaveis
    int i=0;

    IO_print("Os valores multiplos de 3 e 5 sao:\n");

    // Exibicao dos valores inteiros multiplos de 3 E 5
    for(i=1; i<n+1; i=i+1)
    {
        printf("[%d]\n", i*(3*5));
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO 02
- Ler um valor inteiro do teclado
---------------------------------------------------------------------------------------------------
*/

void method_02(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 02\n");

    // Declaracao das variaveis
    int n=0;

    // Leitura da variavel n
    n=IO_readint("Digite quantos numeros quer exibir dos multiplos de 3 E 5: ");

    // Chamada da funcao para exibir dos multiplos de 3 e 5
    METODO_0512(n);

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}
/*
---------------------------------------------------------------------------------------------------
METODO_0513
- Geracao de potencias de grandeza 4 de forma decrescente
---------------------------------------------------------------------------------------------------
*/

void METODO_0513 (int tamanho) // ESTRUTURA PARA COMPILAR A MATH.H -> gcc programa.c -o programa -lm
{
    // Declaracao de variaveis
    int i=0;
    double expoente = (double)tamanho;
    printf("%lf\n", expoente);
    printf("%d\n", tamanho);
    IO_print("\nOs numeros elevadas a quarta de maneira descrescente sao:\n");

    // Loop para exibicao
    for(i=0; i<=tamanho; i=i+1)
    {
        printf("[%.2lf]\n", pow(4, expoente));
        expoente = expoente-1.0;
        if(tamanho==0)
        {

        }
    }

}

/*
---------------------------------------------------------------------------------------------------
METODO 03
- Ler quantas unidades exibir do numero digitado a quarta potencia de forma decrescente ate 4
---------------------------------------------------------------------------------------------------
*/

void method_03(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 03\n");

    // Declaracao de variaveis
    int tamanho=0;

    // Leitura do tamanho
    tamanho=IO_readint("\nDigite a quantidade de numeros elevada a quarta potencia em forma decrescente a exibir: ");

    // Chamada da funcao para exibir as potencias
    METODO_0513(tamanho);

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 0514
- Exibir a quantidade de numeros com denominadores multiplos de 3
---------------------------------------------------------------------------------------------------
*/

void METODO_0514 (int quantidade)
{
    // Declaracao de variaveis
    int i=0;

    // Loop para a exibicao das numeros fracionarios
    for (i=1; i <(quantidade+1); i=i+1)
    {
        printf("[1/%d]\n", i*3);
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO 04
- Leitura da quantidade de numeros
---------------------------------------------------------------------------------------------------
*/

void method_04(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 04\n");

    // Declaracao de variaveis
    int quantidade=0;

    // Leitura da quantidade
    quantidade=IO_readint("Digite a quantidade de numeros fracionarios com denominador multiplo de 3: ");

    // Chamada da funcao
    METODO_0514(quantidade);


    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO_0515
- Exibir os fracionarios com os denominadores elevados ao quadrado
---------------------------------------------------------------------------------------------------
*/

void METODO_0515 (int quantidade)
{
    // Declaracao de Variaveis
    int x=2;
    int i=0;

    // Loop para exibir os numeros fracionarios
    for (i=1; i< quantidade; i=i+1)
    {
        printf("[1/x^[%d]]\n", x);
        x=x+2;
    }

}

/*
---------------------------------------------------------------------------------------------------
METODO 05
- Leitura da quantidade e passagem de parametro para a funcao METODO_0515
---------------------------------------------------------------------------------------------------
*/

void method_05(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 05\n");

    // Declaracao de variaveis
    int quantidade=0.0;

    // Leitura da variavel numero
    quantidade=IO_readint("\nDigite a quantidade de numeros fracionarios com denominador elevado a numeros sequencialmente somados por 2: ");

    // Chamada da funcao para exibir os numeros
    METODO_0515(quantidade);

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO_0516
- Calcular e exibir os numeros multiplos de 3 e nao multiplos de 4
---------------------------------------------------------------------------------------------------
*/

void METODO_0516(int quantidade)
{
    // Declaracao de variaveis
    int i=1;
    int numero=1;

    // Loop para mostrar os multiplos de 3 e nao multiplos
    while (i <= quantidade)
    {
        numero = i * 3;
        if (numero % 4 != 0)
        {
            printf("[%d] ", numero);
        }
        else
        {
            quantidade = quantidade + 1;
        }
        i = i + 1;
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO 06
- Ler a quantidade de numeros multiplos de 3 e nao multiplo de 4
---------------------------------------------------------------------------------------------------
*/

void method_06(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 06\n");

    // Declaracao de variavel
    int quantidade=0;

    // Leitura da variavel
    quantidade=IO_readint("Digite a quantidade de numeros multiplos de 3 e nao multiplos de 4 que deseja ver: ");

    // Chamada da funcao
    METODO_0516(quantidade);

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 0517
-
---------------------------------------------------------------------------------------------------
*/

double METODO_0517(double quantidade)
{
    // Declaracao de variaveis
    double valor = 4.0;
    int i = 0;
    double soma = 0.0;

    // Loop para soma
    for(i = 0; i < quantidade; i=i+1)
    {
        soma = soma + (1.0 / valor);
        valor = valor + 4.0;           
    }
    return soma;
}

/*
---------------------------------------------------------------------------------------------------
METODO 07
- Metodo para calcular a soma dos inversos de 4 em 4, com indice inicial em 4
---------------------------------------------------------------------------------------------------
*/

void method_07(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 07\n");

    // Declarar variaveis
    double quantidade = 0.0;
    double soma=0.0;

    // Leitura de quatidade de vezes
    quantidade=IO_readdouble("Digite quantas operacoes deseja fazer: ");
    quantidade= (double)quantidade;

    // Atribuir o valor da soma retornado pela funcao
    soma=METODO_0517(quantidade);

    // Exibir o resultado da soma dos elementos
    IO_print("O resultado da soma e: ");
    printf("%.4lf", soma);

    // Quebra de linha
    IO_print("\n");

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 0518
- Calcular a soma com indice em 5, 
---------------------------------------------------------------------------------------------------
*/

int METODO_518(int quantidade) 
{
    // Declaração de variáveis
    int valorAtual1 = 5;
    int valorAtual2 = 1;
    int soma = 0;
    
    // Loop para calcular a soma
    for(int i = 1; i <= quantidade; i = i + 1) {
        soma = soma + valorAtual1;
        valorAtual1 = valorAtual1 + valorAtual2;
        valorAtual2 = valorAtual2 + 1;
    }
    
    return soma;
}

/*
---------------------------------------------------------------------------------------------------
METODO 08
- 
---------------------------------------------------------------------------------------------------
*/

void method_08(void)
{
    // Identificacao
    printf("\nMetodo 08\n");

    // Declarar variaveis
    int quantidade=0;
    int soma=0;

    // Leitura da quantidade de operacoes
    quantidade=IO_readint("Digite quantas operacoes deseja fazer: ");

    // Atribuir o valor da soma retornado pela funcao METODO_518
    soma = METODO_518(quantidade);

    // Exibir o resultado da soma dos elementos
    printf("O resultado da soma e: %d\n", soma);

    // Mensagem final para o usuario
    printf("\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 0519
- Calcular a soma dos quadrados dos números naturais começando no valor 25
---------------------------------------------------------------------------------------------------
*/

int METODO_0519(int quantidade)
{
    // Declaracao de variaveis
    int i = 0;
    int numero = 25;
    int soma = 0;

    // Loop para somar os quadrados dos números naturais
    for(i = 0; i < quantidade; i = i + 1)
    {
        soma = soma + (numero * numero);
        numero = numero + 1;
    }

    return soma;
}

/*
---------------------------------------------------------------------------------------------------
METODO 09
- Chama o METODO 0519 e exibe o resultado da soma dos quadrados
---------------------------------------------------------------------------------------------------
*/

void method_09(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 09\n");

    // Declarar variaveis
    int quantidade = 0;
    int soma = 0;

    // Leitura da quantidade de operacoes
    quantidade = IO_readint("Digite quantos quadrados dos numeros naturais deseja somar começando no 25: ");

    // Chama a funcao METODO_0519 para calcular a soma
    soma = METODO_0519(quantidade);

    // Exibe o resultado
    printf("A soma dos quadrados e: %d\n", soma);

    // Mensagem final para o usuario
    printf("\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 0520
- Calcular a soma dos inversos (1/x) das adicoes de numeros naturais terminando no valor 3
---------------------------------------------------------------------------------------------------
*/

double METODO_0520(int quantidade)
{
    // Declaracao de variaveis
    int i = 0;
    double soma = 0.0;
    int numero = 13;

    // Loop para calcular a soma dos inversos
    for(i = 0; i < quantidade; i = i + 1)
    {
        soma = soma + (1.0 / numero);
        numero = numero - 1;
    }

    return soma;
}

/*
---------------------------------------------------------------------------------------------------
METODO 10
- Chama o METODO 0520 e exibe o resultado da soma dos inversos
---------------------------------------------------------------------------------------------------
*/

void method_10(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 10\n");

    // Declarar variaveis
    int quantidade = 0;
    double soma = 0.0;

    // Leitura da quantidade de operacoes
    quantidade = IO_readint("Digite quantos inversos deseja somar começando de 1/13 até 1/3: ");

    // Chama a funcao METODO_0520 para calcular a soma
    soma = METODO_0520(quantidade);

    // Exibe o resultado
    printf("A soma dos inversos e: %.4lf\n", soma);

    // Mensagem final para o usuario
    printf("\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 05E1
- Ler um numero inteiro e calcular o fatorial do valor
---------------------------------------------------------------------------------------------------
*/

int METODO_05E1(int n)
{
    // Declaracao de variaveis
    int fatorial = 1;

    // Calcular o fatorial de n
    for(int i = 1; i <= n; i = i + 1)
    {
        fatorial = fatorial * i;
    }

    return fatorial;
}

/*
---------------------------------------------------------------------------------------------------
METODO 11
- Chama o METODO 05E1 e exibe o resultado do fatorial
---------------------------------------------------------------------------------------------------
*/

void method_11(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 11\n");

    // Declarar variaveis
    int n = 0;
    int fatorial = 0;

    // Leitura do numero
    n = IO_readint("Digite um numero para calcular o fatorial: ");

    // Chama a funcao METODO_05E1 para calcular o fatorial
    fatorial = METODO_05E1(n);

    // Exibe o resultado
    printf("O fatorial de %d e: %d\n", n, fatorial);

    // Mensagem final para o usuario
    printf("\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 05E2
- Calcular a funcao f(n) = (1+2/3!) * (1+4/5!) * (1+6/7!) * ...
---------------------------------------------------------------------------------------------------
*/

double METODO_05E2(int n)
{
    // Declaracao de variaveis
    double resultado = 1.0;

    // Calcular a funcao
    for(int i = 1; i <= n; i = i + 1)
    {
        double denominador = (2 * i + 1);
        double fatorial = 1;

        // Calcular o fatorial de 3, 5, 7, etc.
        for(int j = 1; j <= denominador; j = j + 1)
        {
            fatorial = fatorial * j;
        }

        // Atualizar o resultado
        resultado = resultado * (1 + (2.0 / fatorial));
    }

    return resultado;
}

/*
---------------------------------------------------------------------------------------------------
METODO 12
- Chama o METODO 05E2 e exibe o resultado
---------------------------------------------------------------------------------------------------
*/

void method_12(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 12\n");

    // Declarar variaveis
    int n = 0;
    double resultado = 0.0;

    // Leitura do numero
    n = IO_readint("Digite um numero para calcular a funcao f(n): ");

    // Chama a funcao METODO_05E2 para calcular o resultado
    resultado = METODO_05E2(n);

    // Exibe o resultado
    printf("O resultado da funcao e: %.4lf\n", resultado);

    // Mensagem final para o usuario
    printf("\nApertar ENTER para continuar\n");
    getchar();
}

/*-------------------------------------------------------------------------------------------------
DOCUMENTACAO
-------------------------------------------------------------------------------------------------

1.0 - DOCUMENTACAO COMPLEMENTAR

- Sem observacoes

---------------------------------------------------------------------------------------------------

2.0 - TESTES

*Method_00: OK
- Sem observacoes

*Method_01:
-

*Method_02:
-

*Method_03:
-

*Method_04:
-

*Method_05:
-

*Method_06:
-

*Method_07:
-

*Method_08:
-

*Method_09:
-

*Method_10:
-

*Method_11:
-

*Method_12:
-
---------------------------------------------------------------------------------------------------
*/
