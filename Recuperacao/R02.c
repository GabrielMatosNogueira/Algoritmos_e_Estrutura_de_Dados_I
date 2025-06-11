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
 * @brief Quarta função do programa
 *
 * Gerar dois arquivos com números aleatórios: "metodo04_01.txt" e "metodo04_02.txt",
 * ler seus conteúdos em dois arranjos, filtrar os elementos **comuns entre eles**
 * sem repetições e gravar o resultado no arquivo "FILTRADOS.TXT".
 * A primeira linha do arquivo de saída contém a **quantidade de valores únicos filtrados**.
 *
 * Exemplo:
 * - Geração: método gera dois arquivos com até MAX valores aleatórios (0 a 100);
 * - Leitura: carrega os valores em arrays;
 * - Filtro: encontra os números comuns sem repetição;
 * - Gravação: salva no arquivo "FILTRADOS.TXT", com a quantidade na primeira linha.
 *
 * @param void
 * @return void
 */

void metodo04(void)
{
    // Declaracao de variaveis
    int array1[MAX], array2[MAX], comuns[MAX];
    int tam1 = 0, tam2 = 0, tam3 = 0;
    int i = 0, j = 0, k = 0;
    bool existe = false;

    FILE *arquivo1 = fopen("metodo04_01.txt", "rt");
    FILE *arquivo2 = fopen("metodo04_02.txt", "rt");
    FILE *saida = NULL;

    // Verificar se os arquivos foram abertos corretamente
    if (arquivo1 != NULL && arquivo2 != NULL)
    {
        // Ler dados do primeiro arquivo
        while (tam1 < MAX && fscanf(arquivo1, "%d", &array1[tam1]) == 1)
        {
            tam1++;
        }
        fclose(arquivo1);

        // Ler dados do segundo arquivo
        while (tam2 < MAX && fscanf(arquivo2, "%d", &array2[tam2]) == 1)
        {
            tam2++;
        }
        fclose(arquivo2);

        // Filtrar elementos comuns sem repetição
        for (i = 0; i < tam1; i++)
        {
            for (j = 0; j < tam2; j++)
            {
                if (array1[i] == array2[j])
                {
                    existe = false;

                    // Verificar se já foi adicionado
                    for (k = 0; k < tam3; k++)
                    {
                        if (comuns[k] == array1[i])
                        {
                            existe = true;
                        }
                    }

                    if (!existe)
                    {
                        comuns[tam3] = array1[i];
                        tam3++;
                    }
                }
            }
        }

        // Gravar no arquivo de saída
        saida = fopen("FILTRADOS.TXT", "wt");

        if (saida != NULL)
        {
            fprintf(saida, "%d\n", tam3); // primeira linha: quantidade
            for (i = 0; i < tam3; i++)
            {
                fprintf(saida, "%d\n", comuns[i]);
                IO_printf("Comum: %d\n", comuns[i]);
            }
            fclose(saida);
        }
        else
        {
            IO_print("Erro ao criar o arquivo FILTRADOS.TXT\n");
        }
    }
    else
    {
        IO_print("Erro ao abrir os arquivos metodo04_01.txt ou metodo04_02.txt\n");
    }

    IO_print("Aperte ENTER para encerrar o programa.");
    getchar();
}

/**
 * @brief Converter um vetor de bits binários para número decimal.
 *
 * Recebe um arranjo contendo apenas os valores 0 e 1, representando um número binário,
 * e retorna seu valor equivalente em decimal. O primeiro índice do vetor representa
 * o bit mais significativo (ordem direta).
 *
 * Exemplo:
 * - binario = {1, 0, 1, 1} → representa "1011" → resultado: 11
 *
 * @param binario Vetor de inteiros com valores 0 ou 1.
 * @param tamanho Quantidade de elementos no vetor binário.
 * @return Valor decimal correspondente ao número binário.
 */
int arranjo_paraDecimal(int binario[], int tamanho)
{
    int decimal = 0;
    int i = 0;

    for (i = 0; i < tamanho; i = i + 1)
    {
        decimal = decimal * 2 + binario[i];
    }

    return decimal;
}

/**
 * @brief Verificar se uma string contém apenas caracteres '0' e '1'.
 *
 * Lê uma cadeia de caracteres e verifica se todos os símbolos são
 * binários válidos. Retorna verdadeiro se for válida, falso caso contrário.
 *
 * @param texto Ponteiro para a string a ser verificada.
 * @return `true` se for binária, `false` caso contrário.
 */
bool ehBinario(char *texto)
{
    int i = 0;
    while (texto[i] != '\0' && texto[i] != '\n')
    {
        if (texto[i] != '0' && texto[i] != '1')
        {
            return false;
        }
        i++;
    }
    return true;
}

/**
 * @brief Quinta função do programa
 *
 * Ler cadeias de caracteres do arquivo "BINARIOS1.TXT", uma por linha,
 * contendo apenas os dígitos '0' e '1'. Cada linha válida é convertida
 * para um vetor de inteiros (int) e convertida em um número decimal.
 *
 * @param void
 * @return void
 */
void metodo05(void)
{
    char linha[100];
    int binario[100];
    int tamanho = 0;
    int i = 0;
    int valor = 0;
    bool valido = true;

    FILE *arquivo = fopen("BINARIOS1.TXT", "rt");

    if (arquivo != NULL)
    {
        while (fgets(linha, sizeof(linha), arquivo) != NULL)
        {
            tamanho = 0;
            valido = true;
            i = 0;

            // Validar e converter a linha para vetor de inteiros
            while (linha[i] != '\0' && linha[i] != '\n' && valido)
            {
                if (linha[i] == '0')
                {
                    binario[tamanho++] = 0;
                }
                else if (linha[i] == '1')
                {
                    binario[tamanho++] = 1;
                }
                else
                {
                    valido = false;
                }
                i++;
            }

            if (valido && tamanho > 0)
            {
                valor = arranjo_paraDecimal(binario, tamanho);
                IO_printf("Binario: %sDecimal: %d\n", linha, valor);
            }
            else
            {
                IO_printf("Linha ignorada (nao eh binario valido): %s", linha);
            }
        }

        fclose(arquivo);
    }
    else
    {
        IO_print("Erro ao abrir o arquivo BINARIOS1.TXT\n");
    }

    IO_print("Aperte ENTER para encerrar o programa.");
    getchar();
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

            case 4:
            metodo04();
            break;
            
            case 5:
            metodo05();
            break;
        }

    } while (opcao != 0);

    return 0;
} // end int main()
