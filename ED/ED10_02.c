/*
Nome do Programa:   ED10_02
Data:               27/05/2025
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
    Windows:    gcc -o ED10_02 ED10_02.c
    Linux:      gcc -o ED10_02 ED10_02.c
    macOS:      gcc -o ED10_02 ED10_02.c


    2.2 - Execute o programa
    Windows:     ED10_02
    Linux:      ./ED10_02
    macOS:      ./ED10_02

---------------------------------------------------------------------------------------------------
*/

// Declaracao de biblioteca(s)
#include "io.h"

#define MAX 10

typedef struct s_int_Matrix
{
    int rows;
    int columns;
    ints *data;
    int ix, iy;
} int_Matrix;

typedef int_Matrix *Matriz;

// Declaracao dos metodos utilizados

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

    //

    // encerramento
    IO_end();
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

    // Encerrament
    IO_end();
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

    // Encerramento
    IO_end();
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

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO 06
---------------------------------------------------------------------------------------------------
*/
void method_1015(void)
{
    // Identificacao
    IO_start("\nMetodo 1015\n");
    ;

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO readMatrixFromFile
---------------------------------------------------------------------------------------------------
*/
Matriz readMatrixFromFile(char *filename)
{
    Matriz matriz1 = NULL;
    FILE *arquivo = fopen(filename, "r");
    int linhas = 0, colunas = 0, i = 0, j = 0;

    if (arquivo != NULL)
    {
        // lê linhas e colunas (nessa ordem)
        if (fscanf(arquivo, "%d %d", &linhas, &colunas) == 2 && linhas > 0 && colunas > 0)
        {
            matriz1 = (Matriz)malloc(sizeof(int_Matrix));
            matriz1->rows = linhas;
            matriz1->columns = colunas;
            matriz1->data = (int *)malloc(linhas * sizeof(int *));

            for (i = 0; i < linhas; i++)
            {
                matriz1->data[i] = (int *)malloc(colunas * sizeof(int));
                for (j = 0; j < colunas; j++)
                {
                    fscanf(arquivo, "%d", &matriz1->data[i][j]);
                }
            }
        }
        fclose(arquivo);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para leitura da matriz.\n");
    }

    return matriz1;
}

/*
---------------------------------------------------------------------------------------------------
METODO matrixTranspose
---------------------------------------------------------------------------------------------------
*/
Matriz matrixTranspose(Matriz m1)
{
    // Identificacao
    IO_start("\nMetodo matrixTranspose\n");

    // declaracao de variaveis
    int i = 0;
    int j = 0;
    Matriz transposta;

    // alocar struct da matriz transposta
    transposta = (Matriz)malloc(sizeof(int_Matrix));
    transposta->rows = m1->columns;
    transposta->columns = m1->rows;
    transposta->data = (int *)malloc(transposta->rows * sizeof(int *));

    // alocar linhas da matriz transposta
    for (i = 0; i < transposta->rows; i++)
    {
        transposta->data[i] = (int *)malloc(transposta->columns * sizeof(int));
    }

    // preencher valores transpostos
    for (i = 0; i < transposta->rows; i++)
    {
        for (j = 0; j < transposta->columns; j++)
        {
            transposta->data[i][j] = m1->data[j][i];
        }
    }

    // Encerramento
    return transposta;
}

/*
---------------------------------------------------------------------------------------------------
METODO 06
---------------------------------------------------------------------------------------------------
*/
void method_1016(void)
{
    // Identificacao
    IO_start("\nMetodo 1016\n");

    // Declaracao de variaveis
    int i= 0;
    int j= 0;
    Matriz m1;
    char *filename = "ED10_method_016_matriz.txt";

    m1 = readMatrixFromFile(filename);

    IO_print("\nMatriz antes da transposicao: ");
    for(i=0; i<m1->rows; i=i+1)
    {
        IO_print("\n");
        for(j=0; j<m1->columns; j=j+1)
        {
            printf("%d\t", m1->data[i][j]);
        }
    }
    m1= matrixTranspose(m1);
    IO_print("\nMatriz depois da transposicao: ");
    
    for(i=0; i<m1->rows; i=i+1)
    {
        IO_print("\n");
        for(j=0; j<m1->columns; j=j+1)
        {
            printf("%d\t", m1->data[i][j]);
        }
    }

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO matrixZero
---------------------------------------------------------------------------------------------------
*/
bool matrixZero (Matriz m1)
{
    int i=0;
    int j=0;
    int verificador=1;

    for(i=0; i<m1->rows; i=i+1)
    {
        for(j=0; j<m1->columns; j=j+1)
        {
            if(m1->data[i][j]!=0)
            {
                verificador=0;
                return verificador;
            }
        }
    }
    return verificador;
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

    // Declaracao de variaveis
    char *filename="ED10_method_016_matriz.txt";
    Matriz m1;
    int verificador=1;

    m1 = readMatrixFromFile(filename);
    verificador=matrixZero(m1);

    if(verificador==0)
    {
        IO_print("\nMatriz nao e composta somente de zeros");
    }
    else
    {
        IO_print("\nMatriz composta somente de zeros");
    }

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO 08
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
void method_11(void)
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
void method_12(void)
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
            method_11();
            break;

        case 12:
            method_12();
            break;
        }
    } while (opcao != 0);
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
