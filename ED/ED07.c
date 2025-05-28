/*
Nome do Programa:   ED07
Data:               04/23/2025
Nome:               Gabriel Matos Nogueira
Codigo de Pessoa:   1563147
Matricula:          870863
Versao:             1.0

---------------------------------------------------------------------------------------------------

Como executar o programa no terminal:
1.0 - Certifique-se que o compilador GCC esteja instalado e presente nas variaveis de ambiente
da sua maquina

2.0 - Adentre a pasta para executar o programa:
cd 1563147_Gabriel_Matos_Nogueira (Windows, Linux e macOS)

    2.1 - Compile o programa
    Windows:    gcc -o ED07 ED07.c
    Linux:      gcc -o ED07 ED07.c
    macOS:      gcc -o ED07 ED07.c


    2.2 - Execute o programa
    Windows:     ED07
    Linux:      ./ED07
    macOS:      ./ED07

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

// Funcao Principal
int main(void)
{
    // armazenar a opcao do usuario
    int opcao = 0;
    IO_id("\n\tOpcoes de Metodos:");

    // Menu de opcoes do usuario
    do
    {
        IO_print("\n0 - Parar");
        IO_print("\n1 - Metodo 0a11");
        IO_print("\n2 - Metodo 0a12");
        IO_print("\n3 - Metodo 0a13");
        IO_print("\n4 - Metodo 0a14");
        IO_print("\n5 - Metodo 0a15");
        IO_print("\n6 - Metodo 0a16");
        IO_print("\n7 - Metodo 0a17");
        IO_print("\n8 - Metodo 0a18");
        IO_print("\n9 - Metodo 0a19");
        IO_print("\n10 - Metodo 0a20");
        IO_print("\n11 - Metodo 0a21");
        IO_print("\n12 - Metodo 0a22");

        opcao = IO_readint("\nDigite uma opcao: ");
        switch (opcao)
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
    } while (opcao != 0);
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
    IO_print("ENCERRANDO O PROGRAMA...\n");

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 01
- Ler um valor inteiro do teclado que representa quantidade de numeros
- Gravar a quantidade em números múltiplos de 4
---------------------------------------------------------------------------------------------------
*/

void method_01(void)
{
    // identificacao
    printf("%s\n", "\nMetodo 01\n");

    // Declaracao de variaveis
    int quantidade=0;
    char nomeArq[]="ED07.txt";
    FILE *arq=fopen(nomeArq,"w");
    int i=0;
    int multiplo=0;

    // Ler a quantidade de vezes
    quantidade=IO_readint("Digite a quantidade de multiplos de 4: ");

    // Elaboracao da logica de multiplos de 4
    for (i=0; i<quantidade; i= i+1)
    {
        multiplo= multiplo+4;
        fprintf(arq, "%d\n", multiplo);
    }

    fclose(arq);

    // encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 02
-
---------------------------------------------------------------------------------------------------
*/

void method_02(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 02\n");

    // Declaracao de variaveis
    int quantidade=0;
    //int *memoria=0;
    int multiplo=1;
    int i=0;
    char nomeArq[]="ED07_02.txt";
    FILE *arq=fopen(nomeArq,"wt");

    // Leitura da quantidade
    quantidade=IO_readint("Digite a quantidade de multiplos de 15: ");

    // Alocacao de memoria
    //memoria=malloc(quantidade*sizeof(int));

    // Salvar a quantidade de multiplos no arquivo
    fprintf(arq, "[%d]\n", quantidade);

    // Definicao do ultimo termo da multiplicacao
    multiplo=15*quantidade;

    // Logica de implementacao
    for(i=0; i<quantidade; i=i+1)
    {
        printf("[%d]\n", multiplo);
        fprintf(arq, "\n[%d]. %d", i, multiplo);
        multiplo=multiplo-15;
    }

    fclose(arq);
    //free(memoria);

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 03
-
---------------------------------------------------------------------------------------------------
*/

void method_03(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 03\n");

    int quantidade=0;
    int multiplo=1;
    int i=0;
    char nomeArq[]="ED07_02.txt";
    FILE *arq=fopen(nomeArq,"wt");

    quantidade=IO_readint("\nDigite a quantidade de numeros multiplos de 3: ");

    fprintf(arq, "\nQUANTIDADE: [%d]", quantidade);
    //printf("\n[%d]\n", 1);

    for(i=1; i<=quantidade; i=i+1)
    {
        printf("[%d]\n", multiplo);
        fprintf(arq, "[%d]. %d", i, multiplo);
        multiplo=multiplo*3;
    }

    fclose(arq);

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 04
-
---------------------------------------------------------------------------------------------------
*/

void method_04(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 04\n");

    int quantidade=0;
    int multiplo=1;
    int i=0;
    char nomeArq[]="ED07_02.txt";
    FILE *arq=fopen(nomeArq,"wt");

    quantidade=IO_readint("\nDigite a quantidade de numeros multiplos de 3: ");

    fprintf(arq, "\nQUANTIDADE: [%d]", quantidade);
    multiplo=pow(3, quantidade-1);

    for(i=1; i<=quantidade; i=i+1)
    {
        printf("[1/%d]\n", multiplo);
        fprintf(arq, "\n[%d]. 1/%d", i, multiplo);
        multiplo=multiplo/3.0;
    }

    fclose(arq);

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 05
-
---------------------------------------------------------------------------------------------------
*/

void method_05(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 05\n");

    // Declaracao de variaveis
    int n=0;
    int i=0;
    int x=1;
    double impar=1.0;
    double valor=1.0;
    char nomeArq[]="ED07_02.txt";
    FILE *arq=fopen(nomeArq,"wt");

    // Leitura da quantidade 'n' e do numero 'x'
    x=IO_readdouble("Digite um numero a ser elevado: ");
    n=IO_readint("\nDigite a quantidade de vezes: ");

    printf("\nNUMERO: [%d]", x);
    printf("\nQUANTIDADE: [%d]", n);

    for(i=0; i<n; i=i+1)
    {
        printf("[1/%.2lf]\n", valor, impar);
        impar=impar+2.0;
        valor=pow(x,impar);
    }

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 06
-
---------------------------------------------------------------------------------------------------
*/

void method_06(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 06\n");

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 07
-
---------------------------------------------------------------------------------------------------
*/

void method_07(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 07\n");

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
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
    printf("%s\n", "\nMetodo 08\n");

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 09
-
---------------------------------------------------------------------------------------------------
*/

void method_09(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 09\n");

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 10
-
---------------------------------------------------------------------------------------------------
*/

void method_10(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 10\n");

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 11
-
---------------------------------------------------------------------------------------------------
*/

void method_11(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 11\n");

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 12
-
---------------------------------------------------------------------------------------------------
*/

void method_12(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 12\n");

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
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
