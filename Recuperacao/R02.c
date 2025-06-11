/*
AEDS 1
0870863_Gabriel_Matos_Nogueira
*/

/*
 * ----------------------------------------
 * BIBLIOTECAS / DEPENDÊNCIAS
 * ----------------------------------------
 * "io.h"   - Biblioteca com importacao de outras bibliotecas
 *  MAX     - Constante definida para realizacao dos metodo01 ate metodo10
 */

#include "io.h"
#include "recuperacao_02.h"
#include <stdio.h>
#include <stdbool.h>
#define MAX 100

/**
 * @brief Primeira funcao do programa.
 *
 * Criar um arquivo e preenche dentro do limite de uma constante MAX
 * O array le e preenche seu conteudo os valores de dentro do arquivo
 * Um bubble sort e aplicado para ordenacao decrescente dos seus valores
 *
 * @param void
 * @return Vazio
 */
void metodo01(void)
{
    // Declaracao de variaveis
    int i = 0;
    int temp = 0;
    int array[MAX];
    bool swap = false;
    FILE *arquivo01 = NULL;
    FILE *arquivo02 = NULL;
    FILE *arquivo03 = NULL;
    arquivo01 = fopen("metodo01.txt", "wt");
    arquivo02 = fopen("metodo01.txt", "rt");
    arquivo03 = fopen("metodo02.txt", "wt");

    // Semeando funcao geradora de numeros aleatorios
    srand(time(NULL));

    // Escrita de valores aleatorios dentro do arquivo
    for (i = 0; i < MAX; i = i + 1)
    {
        fprintf(arquivo01, "%d\n", rand() % 101);
    }
    fclose(arquivo01);

    // Lendo os valores para dentro do array
    for (i = 0; i < MAX; i = i + 1)
    {
        fscanf(arquivo02, "%d", &array[i]);
    }
    fclose(arquivo02);

    // Ordenacao decrescente usando bubble sort
    do
    {
        swap = false;
        for (i = 0; i < MAX - 1; i = i + 1)
        {
            if (array[i] < array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap = true;
            }
        }

    } while (swap);

    for (i = 0; i < MAX; i = i + 1)
    {
        fprintf(arquivo03, "[%d]\n", array[i]);
        IO_printf("[%d]\n", array[i]);
    }
    fclose(arquivo03);

    // Encerramento do programa
    IO_print("Aperte ENTER para encerrar o programa.");
    getchar();
}

/**
 * @brief Segunda funcao do programa
 *
 * Chama uma funcao chamada "array_Investor" definida na "recuperacao_02.h"
 * para inverter o arranjo criado no metodo02
 *
 * @param void
 * @return void
 */
void metodo02()
{
    // Declaracao de variaveis
    int i = 0;
    int temp = 0;
    int array[MAX];
    bool swap = false;
    char *filename="metodo02_CRESCENTE.txt";
    FILE *arquivo01=fopen(filename, "wt");

    // Semeando funcao geradora de numeros aleatorios
    srand(time(NULL));

    for (i = 0; i < MAX; i = i + 1)
    {
        array[i] = rand() % 101;
    }

    // Bubble Sort
    do
    {
        swap = false;
        for (i = 0; i < MAX - 1; i = i + 1)
        {
            if (array[i + 1] < array[i])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);

    for (i = 0; i < MAX; i = i + 1)
    {
        fprintf(arquivo01, "%d\n", array[i]);
        printf("[%d]\n", array[i]);
    }
    fclose(arquivo01);

    IO_print("\nForma decrescente:\n");

    fill_Array_Rand_Decrescent(filename);

    // Encerramento do programa
    IO_print("Aperte ENTER para encerrar o programa.");
    getchar();
}

/**
 * @brief Segunda funcao do programa
 *
 * Chama uma funcao chamada "array_Investor" definida na "recuperacao_02.h"
 * para inverter o arranjo criado no metodo02
 *
 * @param void
 * @return void
 */
void array_median(char *filename, int array[])
{
    // Declaracao de variaveis
    double median=0.0;

    median=((array[50]+array[51])/2);

    IO_printf("\nO valor da mediana e': [%.1lf]\n", median);
}

/**
 * @brief Segunda funcao do programa
 *
 * Chama uma funcao chamada "array_Investor" definida na "recuperacao_02.h"
 * para inverter o arranjo criado no metodo02
 *
 * @param void
 * @return void
 */
void metodo03(void)
{
    // Declaracao de variaveis
    int i=0;
    bool swap=false;
    int temp=0;
    int array[MAX];
    char *filename="metodo03_tabela.txt";
    FILE *arquivo=fopen(filename, "wt");
    
    // Semeando funcao geradora de numeros aleatorios
    srand(time(NULL));

    for (i = 0; i < MAX; i = i + 1)
    {
        fprintf(arquivo, "%d\n", rand() % 101);
    }
    fclose(arquivo);

    arquivo = fopen(filename, "rt");

    for (i = 0; i < MAX; i = i + 1)
    {
        fscanf(arquivo, "%d", &array[i]);
    }

    fclose(arquivo);

    // Bubble Sort
    do
    {
        swap = false;
        for (i = 0; i < MAX - 1; i = i + 1)
        {
            if (array[i + 1] < array[i])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);

    for(i=0; i<MAX; i=i+1)
    {
        IO_printf("%d\n", array[i]);
    }

    array_median(filename, array);

    // Encerramento do programa
    IO_print("Aperte ENTER para encerrar o programa.");
    getchar();
}

/**
 * @brief Segunda funcao do programa
 *
 * Chama uma funcao chamada "array_Investor" definida na "recuperacao_02.h"
 * para inverter o arranjo criado no metodo02
 *
 * @param void
 * @return void
 */
void metodo04(void)
{
    // Declaracao de variaveis
    int array1[MAX];
    int array2[MAX];
    int i=0;
    char *filename1="metoodo04.txt";
    char *filaname2="metodo04_02.txt";
    FILE *arquivo1=fopen(filename1, "wt");
    FILE *arquivo2=fopen(filaname2, "wt");

    // Semeando funcao geradora de numeros aleatorios
    srand(time(NULL));

    for(i=0; i<MAX; i=i+1)
    {
        fprintf(arquivo1, "%d\n", rand()%101);
    }

    for(i=0; i<MAX; i=i+1)
    {
        fprintf(arquivo2, "%d\n", &array1[i]);
    }


}

/**
 * @brief Segunda funcao do programa
 *
 * Exibe um menu de opções para o usuário, lê a escolha e executa
 * o método correspondente com base na opção selecionada.
 *
 * @return int Código de término do programa (0 para sucesso).
 */
int main(void)
{
    int opcao = 0;

    do
    {
        IO_Recuperation_Methods();
        opcao = IO_readint("\nDigite a opcao desejada: ");

        switch (opcao)
        {
        case 1:
            metodo01();
            break;

        case 2:
            metodo02();
            break;

        case 3:
            metodo03();
            break;
        default:
            break;
        }

    } while (opcao != 0);

    return 0;
} // end int main()
