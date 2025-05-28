/*
Nome do Programa:   2025-1_aed1_preparacao_02
Data:               26/05/2025
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
    Windows:    gcc -o 2025-1_aed1_preparacao_02 2025-1_aed1_preparacao_02.c
    Linux:      gcc -o 2025-1_aed1_preparacao_02 2025-1_aed1_preparacao_02.c
    macOS:      gcc -o 2025-1_aed1_preparacao_02 2025-1_aed1_preparacao_02.c


    2.2 - Execute o programa
    Windows:     2025-1_aed1_preparacao_02
    Linux:      ./2025-1_aed1_preparacao_02
    macOS:      ./2025-1_aed1_preparacao_02

---------------------------------------------------------------------------------------------------
*/

// Declaracao de biblioteca(s)
#include "io.h"

#define MAX 4

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

void _10E1();
void _10E2();

typedef struct aed1_preparacao_02
{
    double x;
    double y;
} aed1_preparacao_02;

aed1_preparacao_02 CoordenadasInicial, CoordenadasFinal;

/*
---------------------------------------------------------------------------------------------------
METODO 00
- Encerramento do programa
---------------------------------------------------------------------------------------------------
*/
void method_00(void)
{
    // Identificacao
    IO_start("\nMetodo 00\n");

    // Mensagem de encerramento
    IO_print("ENCERRANDO O PROGRAMA...\n");
}

/*
---------------------------------------------------------------------------------------------------
METODO 01
-
---------------------------------------------------------------------------------------------------
*/
void method_1011(void)
{
    // identificacao
    IO_start("\nMetodo 1011\n");

    // Declaracao de variaveis
    double variacaoX = 0.0;
    double variacaoY = 0.0;
    double distancia = 0.0;
    FILE *arquivo = NULL;
    FILE *arquivo1 = NULL;
    arquivo = fopen("DADOS_1.txt", "r");
    arquivo1 = fopen("SAIDA_01.txt", "wt");

    while (!feof(arquivo) /*|| (CoordenadasInicial.x == 0 && CoordenadasInicial.y == 0) || (CoordenadasFinal.x == 0 && CoordenadasFinal.y == 0)*/)
    {
        fscanf(arquivo, "%lf", &CoordenadasInicial.x);
        fscanf(arquivo, "%lf", &CoordenadasInicial.y);

        fscanf(arquivo, "%lf", &CoordenadasFinal.x);
        fscanf(arquivo, "%lf", &CoordenadasFinal.y);

        variacaoX = CoordenadasInicial.x - CoordenadasFinal.x;
        variacaoY = CoordenadasInicial.y - CoordenadasFinal.y;

        distancia = pow(variacaoX, 2) + pow(variacaoY, 2);
        distancia = sqrt(distancia);

        fprintf(arquivo1, "%.2lf\n", distancia);

        printf("A distancia entre (%.2lf, %.2lf) e (%.2lf, %.2lf) e: %.2lf\n", CoordenadasInicial.x, CoordenadasInicial.y, CoordenadasFinal.x, CoordenadasFinal.y, distancia);
    }

    fclose(arquivo);
    fclose(arquivo1);

    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO procuraMenorEMaior
-
---------------------------------------------------------------------------------------------------
*/
void procuraMaioreMenorValor(double vetor_Resultados[], int n)
{
    double maior = 0;
    double menor = 100000000.0;
    int i = 0;
    FILE *arquivo = NULL;
    arquivo = fopen("SAIDA_01.txt", "r");

    for (i = 0; i <= MAX; i = i + 1)
    {
        fscanf(arquivo, "%lf", &vetor_Resultados[i]);

        if (vetor_Resultados[i] > maior)
        {
            maior = vetor_Resultados[i];
        }

        if (vetor_Resultados[i] < menor)
        {
            menor = vetor_Resultados[i];
        }

        printf("\tMenor : [%.2lf]\t |   Maior : [%.2lf]\n", menor, maior);
    }

    printf("\nMaior elemento encontrado no array: %.2lf\n", maior);
    printf("Menor elemento encontrado no array: %.2lf\n", menor);

    fclose(arquivo);
}

/*
---------------------------------------------------------------------------------------------------
METODO 02
-
---------------------------------------------------------------------------------------------------
*/
void method_1012(void)
{
    // Identificacao
    IO_start("\nMetodo 1012\n");

    // Declaracao de variaveis
    int n = 5;
    double vetor_Resultados[5] = {0.0, 0.0, 0.0, 0.0, 0.0};

    procuraMaioreMenorValor(vetor_Resultados, n);

    // Encerramento

    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO distanciaMedia
---------------------------------------------------------------------------------------------------
*/
double distancia_Media(double vetor_Resultados[], int n)
{
    double maior = 0;
    double menor = 100000000.0;
    double soma = 0.0;
    int i = 0;
    FILE *arquivo = NULL;
    arquivo = fopen("SAIDA_01.txt", "r");

    for (i = 0; i < 5; i = i + 1)
    {
        fscanf(arquivo, "%lf", &vetor_Resultados[i]);
        soma = soma + vetor_Resultados[i];

        if (vetor_Resultados[i] > maior)
        {
            maior = vetor_Resultados[i];
        }

        if (vetor_Resultados[i] < menor)
        {
            menor = vetor_Resultados[i];
        }
    }

    printf("Valor da soma incluindo %.2lf e %.2lf: %.2lf\n", maior, menor, soma);

    soma = soma - (maior + menor);

    printf("O valor da soma e excluindo %.2lf e %.2lf: %.2lf\n", maior, menor, soma);

    return soma;
    fclose(arquivo);
}

/*
---------------------------------------------------------------------------------------------------
METODO 03
-
---------------------------------------------------------------------------------------------------
*/
void method_1013(void)
{
    // Identificacao
    IO_start("\nMetodo 1013\n");

    // Declaracao de variaveis
    double soma=0.0;
    double vetor_Resultados[5] = {0.0, 0.0, 0.0, 0.0, 0.0};

    soma=distancia_Media(vetor_Resultados, MAX);
    soma=soma/4.0;

    printf("O valor da media das distancias e: %.2lf\n", soma);
    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO ordenacaoMatrizCrescente
---------------------------------------------------------------------------------------------------
*/
void ordenacaoMatrizCrescente(double Matriz[2][2])
{
    int l = 0;
    int c = 0;
    double temp = 0.0;

    FILE *arquivo = NULL;
    arquivo = fopen("SAIDA_01.txt", "r");

    if (arquivo != NULL)
    {
        for(l=0;l<2;l=l+1)
        {
            for(c=0; c<2; c=c+1)
            {
                fscanf(arquivo, "%lf", &Matriz[l][c]);
            }
        }

        for(c=0; c<2; c=c+1)
        {
            for(l=0;l<2;l=l+1)
            {
                if (Matriz[l][c]>Matriz[l][c+1])
                {
                    temp=Matriz[l][c];
                    Matriz[l][c]=Matriz[l][c+1];
                    Matriz[l][c+1]=temp;
                }
            }
        }
        
        for(l=0;l<2;l=l+1)
        {
            printf("\n");

            for(c=0;c<2;c=c+1)
            {
                printf("%.2lf ", Matriz[l][c]);
            }
        }
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo");
    }

    fclose(arquivo);
    IO_print("\n");
}

/*
---------------------------------------------------------------------------------------------------
METODO 04
-
---------------------------------------------------------------------------------------------------
*/

void method_1014(void)
{
    // Identificacao
    IO_start("\nMetodo 1014\n");

    // Declaracao de variaveis
    double Matriz[2][2] = {{0.0, 0.0}, {0.0, 0.0}};

    ordenacaoMatrizCrescente(Matriz);

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO 05
-
---------------------------------------------------------------------------------------------------
*/

void method_1015(void)
{
    // Identificacao
    IO_start("\nMetodo 1015\n");

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO 06
-
---------------------------------------------------------------------------------------------------
*/

void method_1016(void)
{
    // Identificacao
    IO_start("\nMetodo 1016\n");

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO 07
-
---------------------------------------------------------------------------------------------------
*/

void method_1017(void)
{
    // Identificacao
    IO_start("\nMetodo 1017\n");

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO 08
-
---------------------------------------------------------------------------------------------------
*/

void method_1018(void)
{
    // Identificacao
    IO_start("\nMetodo 1018\n");

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO 09
-
---------------------------------------------------------------------------------------------------
*/

void method_1019(void)
{
    // Identificacao
    IO_start("\nMetodo 1019\n");

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO 10
-
---------------------------------------------------------------------------------------------------
*/

void method_1020(void)
{
    // Identificacao
    IO_start("\nMetodo 1020\n");

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO 11
-
---------------------------------------------------------------------------------------------------
*/

void _10E1(void)
{
    // Identificacao
    IO_start("\n10E1\n");

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO 12
-
---------------------------------------------------------------------------------------------------
*/

void _10E2(void)
{
    // Identificacao
    IO_start("\n10E2\n");

    // Encerramento
    IO_end();
}

// Funcao Principal
int main(void)
{
    // armazenar a opcao do usuario
    int opcao = 0;
    IO_id("ED");
    IO_print("\n\tOpcoes de Metodos:");

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
            method_1011();
            break;

        case 2:
            method_1012();
            break;

        case 3:
            method_1013();
            break;

        case 4:
            method_1014();
            break;

        case 5:
            method_1015();
            break;

        case 6:
            method_1016();
            break;

        case 7:
            method_1017();
            break;

        case 8:
            method_1018();
            break;

        case 9:
            method_1019();
            break;

        case 10:
            method_1020();
            break;

        case 11:
            _10E1();
            break;

        case 12:
            _10E2();
            break;
        }
    } while (opcao != 0);
}
// Funcoes do programa

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
