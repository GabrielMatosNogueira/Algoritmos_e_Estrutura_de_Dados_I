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
#include <string.h>
#include <stdbool.h>
#define MAX 100
#define MAX_06 4

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
    char *filename = "metodo02_CRESCENTE.txt";
    FILE *arquivo01 = fopen(filename, "wt");

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
    double median = 0.0;

    median = ((array[50] + array[51]) / 2);

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
    int i = 0;
    bool swap = false;
    int temp = 0;
    int array[MAX];
    char *filename = "metodo03_tabela.txt";
    FILE *arquivo = fopen(filename, "wt");

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

    for (i = 0; i < MAX; i = i + 1)
    {
        IO_printf("%d\n", array[i]);
    }

    array_median(filename, array);

    // Encerramento do programa
    IO_print("Aperte ENTER para encerrar o programa.");
    getchar();
}

int search(int vetor[], int tamanho, int valor)
{
    int i;
    int posicao;

    i = 0;
    posicao = -1;

    while (i < tamanho)
    {
        if (vetor[i] == valor)
        {
            posicao = i;
            i = tamanho;
        }
        else
        {
            i++;
        }
    }

    return posicao;
}

/**
 * @brief (Função 04) Lê dois arranjos de arquivos, filtra os elementos comuns
 * sem repetições e grava o resultado em um terceiro arquivo.
 * - Lê arranjo de 'metodo04_01.txt'.
 * - Lê arranjo de 'metodo04_02.txt'.
 * - Grava resultado em 'metodo04_03.txt'.
 * @param void
 * @return void
 */
void metodo04()
{
    FILE *arquivo1 = fopen("metodo04_01.txt", "w");
    FILE *arquivo2 = fopen("metodo04_02.txt", "w");
    FILE *saida = NULL;

    int arr1[MAX];
    int arr2[MAX];
    int comuns[MAX];

    int tam1 = 0;
    int tam2 = 0;
    int tamComuns = 0;
    int i = 0;
    int num = 0;

    if (arquivo1 == NULL || arquivo2 == NULL)
    {
        printf("Erro ao criar arquivos de entrada.\n");
    }
    else
    {
        srand(time(NULL));

        i = 0;
        while (i < MAX)
        {
            num = rand() % 101;
            fprintf(arquivo1, "%d ", num);
            i++;
        }

        i = 0;
        while (i < MAX)
        {
            num = rand() % 101;
            fprintf(arquivo2, "%d ", num);
            i++;
        }

        fclose(arquivo1);
        fclose(arquivo2);

        arquivo1 = fopen("metodo04_01.txt", "r");
        arquivo2 = fopen("metodo04_02.txt", "r");
        saida = fopen("metodo04_03.txt", "w");

        if (arquivo1 == NULL || arquivo2 == NULL || saida == NULL)
        {
            printf("Erro ao abrir arquivos para leitura.\n");
        }
        else
        {
            while (tam1 < MAX && fscanf(arquivo1, "%d", &arr1[tam1]) == 1)
            {
                tam1++;
            }

            while (tam2 < MAX && fscanf(arquivo2, "%d", &arr2[tam2]) == 1)
            {
                tam2++;
            }

            i = 0;
            while (i < tam1)
            {
                if (search(arr2, tam2, arr1[i]) != -1)
                {
                    if (search(comuns, tamComuns, arr1[i]) == -1)
                    {
                        comuns[tamComuns] = arr1[i];
                        tamComuns++;
                    }
                }

                i++;
            }

            i = 0;
            while (i < tamComuns)
            {
                fprintf(saida, "%d ", comuns[i]);
                i++;
            }

            fclose(arquivo1);
            fclose(arquivo2);
            fclose(saida);

            printf("Elementos comuns gravados em metodo04_03.txt\n");
        }
    }
}

int arranjo_paraDecimal(int binario[], int tamanho)
{
    int i = 0;
    int decimal = 0;
    int expoente = 0;

    i = tamanho - 1;

    while (i >= 0)
    {
        decimal = decimal + binario[i] * (int)pow(2, expoente);
        expoente = expoente + 1;
        i = i - 1;
    }

    return decimal;
}

int validar_binario(char *str)
{
    int i = 0;
    int valido = 1;

    while (str[i] != '\0' && str[i] != '\n')
    {
        if (str[i] != '0' && str[i] != '1')
        {
            valido = 0;
        }

        i = i + 1;
    }

    return valido;
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

void metodo05()
{
    FILE *arquivo = NULL;
    chars frase = NULL;
    int i = 0;
    int j = 0;
    char binario[MAX];

    IO_println("\nMetodo05\n");

    arquivo = fopen("frase.txt", "w");
    if (arquivo == NULL)
    {
        IO_println("Erro ao criar arquivo.");
    }
    else
    {
        frase = IO_readln("Digite uma frase para salvar no arquivo: ");
        IO_fprintln(arquivo, frase); // grava a frase com \n
        fclose(arquivo);
        arquivo = NULL;

        // Abrir para leitura
        arquivo = fopen("frase.txt", "r");
        if (arquivo == NULL)
        {
            IO_println("Erro ao abrir arquivo para leitura.");
        }
        else
        {
            // Ler linha inteira
            frase = IO_freadln(arquivo);
            fclose(arquivo);

            IO_println("Conteudo do arquivo em binario:");

            for (i = 0; frase[i] != EOS; i++)
            {
                for (j = 7; j >= 0; j--)
                {
                    binario[7 - j] = ((frase[i] >> j) & 1) ? '1' : '0';
                }
                binario[8] = EOS;
                IO_print(binario);
                IO_print(" ");
            }
            IO_println(ENDL);
        }
    }
    free(frase);

    IO_print("\nAperte ENTER para encerrar o programa.");
    getchar();
}

/*
 FAZER um programa para:
 - ler dados para matrizes do arquivo MATRIZ1.TXT;
 - ler um número inteiro ( N ), por vez, para indicar
 a quantidade de linhas e colunas de uma matriz quadrada;
 - montar, mostrar e gravar no arquivo MATRIZ2.TXT
 uma matriz com a característica abaixo
 (tridiagonal crescente).
 Exemplo:
 10 9 0 0
 8 7 6 0
 0 5 4 3
 0 0 2 1
*/
void metodo06(void)
{
    // --- Declarações ---
    int i = 0;
    int j = 0;
    int n = 0;
    const char *filename = "metodo06_matriz.txt";
    FILE *arquivo_saida = NULL;

    n = IO_readint("\nDigite a ordem da matriz quadrada (N): ");

    int matriz[n][n];
    int contador = 3 * n - 2;

    if (!(n <= 0))
    {
    }
    else
    {
        IO_println("ERRO: A ordem deve ser um numero positivo.");
    }

    // Abre o arquivo de saída para escrita
    arquivo_saida = fopen(filename, "wt");

    if (arquivo_saida != NULL)
    {
        IO_println("\nMatriz gerada e gravada em metodo06_matriz.txt:");

        // Laço para construir, mostrar e gravar a matriz
        for (i = 0; i < n; i = i + 1)
        {
            for (j = 0; j < n; j = j + 1)
            {
                // Verifica se a célula (i, j) pertence à tridiagonal
                if (abs(i - j) <= 1)
                {
                    matriz[i][j] = contador;
                    contador = contador - 1;
                }
                else
                {
                    matriz[i][j] = 0;
                }

                // Mostra o valor na tela
                printf("%d\t", matriz[i][j]);

                // Grava o valor no arquivo
                fprintf(arquivo_saida, "%d\t", matriz[i][j]);
            }
            // Pula uma linha na tela e no arquivo ao final de cada linha da matriz
            printf("\n");
            fprintf(arquivo_saida, "\n");
        }

        // Fecha o arquivo após terminar de usá-lo
        fclose(arquivo_saida);

        IO_println("\nArquivo gravado com sucesso.");
    }
    else
    {
        IO_println("ERRO: Nao foi possivel criar o arquivo de saida.");
    }

    IO_println("\nAperte ENTER para encerrar o programa.");
    getchar();
}

/**
 * @brief Gera, mostra e grava uma matriz tridiagonal secundária.
 *
 * A matriz é preenchida com valores crescentes a partir do canto
 * inferior esquerdo, seguindo o padrão do exemplo.
 */
void metodo07(void)
{
    int n = 0;
    const char *FILENAME = "metodo07_matriz02.txt";
    FILE *arquivo = NULL;

    printf("\nDigite a ordem da matriz quadrada (N): ");
    scanf("%d", &n);
    getchar();

    if (!(n <= 0))
    {
        int matriz[n][n];
        int contador = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (abs((i + j) - (n - 1)) <= 1)
                {
                    matriz[i][j] = contador;
                    contador++;
                }
                else
                {
                    matriz[i][j] = 0;
                }
            }
        }

        printf("\n--- Matriz Gerada ---\n");

        arquivo = fopen(FILENAME, "wt");
        if (arquivo != NULL)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%d\t", matriz[i][j]);
                    fprintf(arquivo, "%d\t", matriz[i][j]);
                }
                printf("\n");
                fprintf(arquivo, "\n");
            }
        }
        else
        {
            printf("ERRO: Nao foi possivel criar o arquivo %s.\n", FILENAME);
        }
    }
    else
    {
        printf("\nERRO: A ordem da matriz deve ser um valor positivo.\n");
    }

    fclose(arquivo);
    printf("\nMatriz gravada com sucesso em %s\n", FILENAME);

    IO_println("\nAperte ENTER para encerrar o programa.");
    getchar();
}

/*
Ler uma matriz de um arquivo e verificar se possui a caracteristica de potencia
por colunas
*/
void metodo08(void)
{
    // --- Declaração de todas as variáveis ---
    char *filename = "metodo08.TXT";
    FILE *arquivo;
    int linhas = 0, colunas = 0;
    int i = 0, j = 0;
    bool eValida = true; // Variável de controle booleana

    // --- 1. Criar um arquivo de exemplo para o teste ---
    arquivo = fopen(filename, "wt"); // "wt" para escrever
    if (arquivo == NULL)
    {
        printf("ERRO: Nao foi possivel criar o arquivo de teste.\n");
        return; // Sai do método se houver erro
    }
    printf("Criando arquivo de teste '%s'...\n", filename);
    fprintf(arquivo, "4\n4\n"); // Grava dimensões 4x4
    for (i = 0; i < 4; i = i + 1)
    {
        for (j = 0; j < 4; j = j + 1)
        {
            fprintf(arquivo, "%d ", (int)pow(j + 1, i));
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo); // Fecha o arquivo após a escrita

    // --- 2. Abrir e ler o arquivo ---
    arquivo = fopen(filename, "rt"); // "rt" para ler
    if (arquivo == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo '%s' para leitura.\n", filename);
        return;
    }

    // Lê as dimensões do arquivo
    fscanf(arquivo, "%d", &linhas);
    fscanf(arquivo, "%d", &colunas);

    // Declara a matriz com as dimensões lidas (VLA - C99)
    int matriz[linhas][colunas];

    printf("Matriz lida do arquivo:\n");
    for (i = 0; i < linhas; i = i + 1)
    {
        for (j = 0; j < colunas; j = j + 1)
        {
            fscanf(arquivo, "%d", &matriz[i][j]);
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    fclose(arquivo); // Fecha o arquivo após a leitura

    // --- 3. Verificar a característica da matriz ---
    for (i = 0; i < linhas; i = i + 1)
    {
        for (j = 0; j < colunas; j = j + 1)
        {
            int valorEsperado = (int)pow(j + 1, i);
            if (matriz[i][j] != valorEsperado)
            {
                eValida = false; // Encontrou um erro, marca como inválida
                break;
            }
        }
        if (eValida == false)
        {
            break;
        }
    }

    // --- 4. Exibir o resultado final ---
    printf("\n--- Resultado da Verificacao ---\n");
    if (eValida)
    {
        printf("A matriz possui a caracteristica de potencia por colunas.\n");
    }
    else
    {
        printf("A matriz NAO possui a caracteristica de potencia por colunas.\n");
    }
}

/*
FAZER um programa para:
 - ler matriz do arquivo MATRIZ4.TXT;
 - definir uma função lógica para verificar e
 testar se a matriz lida apresenta a característica abaixo (potências decrescentes por colunas).
 Exemplo:
 1 8 27 64
 1 4 9 16
 1 2 3 4
 1 1 1 1
*/
void metodo09(void)
{
    char* nome_arquivo = "matriz09.txt";
    FILE* arquivo = NULL;
    int ordem = 0;
    int i = 0;
    int j = 0;
    int valor = 0;

    printf("\nDigite a ordem da matriz quadrada: ");
    scanf("%d", &ordem);
    getchar();

    if (ordem > 0)
    {
        arquivo = fopen(nome_arquivo, "wt");
        if (arquivo != NULL)
        {
            fprintf(arquivo, "%d\n", ordem);
            fprintf(arquivo, "%d\n", ordem);

            for(i = 0; i < ordem; i = i + 1)
            {
                for(j = 0; j < ordem; j = j + 1)
                {
                    valor = (int)pow(j + 1, ordem - 1 - i);
                    fprintf(arquivo, "%d ", valor);
                }
                fprintf(arquivo, "\n");
            }
            fclose(arquivo);
            printf("\nArquivo '%s' gravado com sucesso.\n", nome_arquivo);

            arquivo = fopen(nome_arquivo, "rt");
            if (arquivo != NULL)
            {
                int linhas_lidas = 0;
                int colunas_lidas = 0;
                fscanf(arquivo, "%d", &linhas_lidas);
                fscanf(arquivo, "%d", &colunas_lidas);

                int matriz_lida[linhas_lidas][colunas_lidas];

                printf("\nMatriz lida do arquivo:\n");
                for(i = 0; i < linhas_lidas; i = i + 1)
                {
                    for(j = 0; j < colunas_lidas; j = j + 1)
                    {
                        fscanf(arquivo, "%d", &matriz_lida[i][j]);
                        printf("%d\t", matriz_lida[i][j]);
                    }
                    printf("\n");
                }
                fclose(arquivo);
            }
            else
            {
                printf("\nERRO: Nao foi possivel ler o arquivo '%s'.\n", nome_arquivo);
            }
        }
        else
        {
            printf("\nERRO: Nao foi possivel criar o arquivo '%s'.\n", nome_arquivo);
        }
    }
    else
    {
        printf("\nERRO: A ordem deve ser um numero positivo.\n");
    }
}

void metodo10(void)
{
    const char* nome_arquivo = "metodo10.txt";
    FILE* arquivo = NULL;
    int quantidade = 0;
    int i = 0;
    double soma_precos = 0.0;
    double preco_medio = 0.0;
    int encontrados = 0;

    arquivo = fopen(nome_arquivo, "w");

    if (arquivo == NULL)
    {
        printf("ERRO: Nao foi possivel criar o arquivo de dados.\n");
    }
    else
    {
        // Grava os dados de exemplo no arquivo
        fprintf(arquivo, "5\n");
        fprintf(arquivo, "A 101 4.50\n");
        fprintf(arquivo, "B 102 3.99\n");
        fprintf(arquivo, "C 103 4.15\n");
        fprintf(arquivo, "D 104 5.20\n");
        fprintf(arquivo, "E 105 4.85\n");
        fclose(arquivo);

        // --- Parte 2: Ler os dados do arquivo ---
        arquivo = fopen(nome_arquivo, "r");
        if (arquivo == NULL)
        {
            printf("ERRO: Nao foi possivel ler o arquivo de dados.\n");
        }
        else
        {
            fscanf(arquivo, "%d", &quantidade);

            char nomes[quantidade][50];
            int codigos[quantidade];
            double precos[quantidade];

            for (i = 0; i < quantidade; i = i + 1)
            {
                fscanf(arquivo, "%s %d %lf", nomes[i], &codigos[i], &precos[i]);
            }
            fclose(arquivo);

            for (i = 0; i < quantidade; i = i + 1)
            {
                soma_precos = soma_precos + precos[i];
            }

            if (quantidade > 0)
            {
                preco_medio = soma_precos / quantidade;
                printf("\nO preco medio do produto e: R$ %.2f\n", preco_medio);
            }

            printf("\nSupermercados com precos abaixo da media:\n");
            for (i = 0; i < quantidade; i = i + 1)
            {
                if (precos[i] < preco_medio)
                {
                    printf("- %s (Preco: R$ %.2f)\n", nomes[i], precos[i]);
                    encontrados = encontrados + 1;
                }
            }

            if (encontrados == 0)
            {
                printf("Nenhum supermercado encontrado com preco abaixo da media.\n");
            }
        }
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
        }

    } while (opcao != 0);

    return 0;
} // end int main()
