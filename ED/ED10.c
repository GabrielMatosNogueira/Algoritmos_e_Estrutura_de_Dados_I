/*
Nome do Programa:   ED10
Data:               18/05/2025
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
    Windows:    gcc -o ED10 ED10.c
    Linux:      gcc -o ED10 ED10.c
    macOS:      gcc -o ED10 ED10.c


    2.2 - Execute o programa
    Windows:     ED10
    Linux:      ./ED10
    macOS:      ./ED10

---------------------------------------------------------------------------------------------------
*/

// Declaracao de biblioteca(s)
#include "io.h"

// Declaracao dos metodos utilizados
void method_00();
void method_1011();
void method_1012();
void method_1013();
void method_1014();
void method_1015();
void method_1016();
void method_1017();
void method_1018(void);
void method_1019();
void method_1020();
void method_10E1();
void method_10E2();

// Definicao do tipo ints como ponteiro para int
typedef int *ints;

typedef struct s_int_Array
{
    int length;
    ints data;
    int ix;
} int_Array;

typedef int_Array *ref_int_Array;

typedef struct s_int_Matrix
{
    int rows;
    int columns;
    ints *data;
    int ix, iy;
} int_Matrix;

typedef int_Matrix *ref_int_Matrix;

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
            method_10E1();
            break;

        case 12:
            method_10E2();
            break;
        }
    } while (opcao != 0);
}

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
METODO RandomIntGenerate
- Gerar um numero inteiro aleatorio entre inferior e superior
- @param inferior - limite inferior
---------------------------------------------------------------------------------------------------
*/
int RandomIntGenerate(int inferior, int superior)
{
    // Verificacao dos limites
    if (inferior > superior)
    {
        IO_print("\nLimite inferior maior que o limite superior");
        return -1;
    }

    else
    {
        // Geracao do numero aleatorio
        int numero = (rand() % (superior - inferior + 1)) + inferior;
        return numero;
    }
} // fim RandomIntGenerate ( )

/*
---------------------------------------------------------------------------------------------------
METODO 01
- Gerar numeros aleatorios entre limites inferior e superior
- @param limite_Inferior - limite inferior
---------------------------------------------------------------------------------------------------
*/
void method_1011(void)
{
    // identificacao
    IO_start("\nMetodo 1011\n");

    // Definicao de variaveis
    int limite_Inferior = 0;
    int limite_Superior = 0;
    int quantidade_Repeticoes = 0;
    int numero = 0;
    FILE *arquivo = NULL;
    char *nome_arquivo = "method_1011.txt";

    arquivo = fopen(nome_arquivo, "w");

    // Leitura dos limites inferior e superior
    limite_Inferior = IO_readint("\nDigite o limite inferior: ");
    limite_Superior = IO_readint("\nDigite o limite superior: ");

    // Leitura da quantidade de repeticoes
    quantidade_Repeticoes = IO_readint("\nDigite a quantidade de repeticoes: ");

    // Verificacao dos limites
    if (limite_Inferior > limite_Superior)
    {
        IO_print("\nLimite inferior maior que o limite superior");
    }
    else
    {
        fprintf(arquivo, "%d\n", quantidade_Repeticoes);
        for (int i = 0; i < quantidade_Repeticoes; i = i + 1)
        {
            // Geracao do numero aleatorio
            numero = RandomIntGenerate(limite_Inferior, limite_Superior);
            // Gravar o numero no arquivo
            fprintf(arquivo, "%d\n", numero);
        }
        IO_print("\nNumeros gerados no arquivo method_1011.txt\n");
    }

    fclose(arquivo);

    // encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO readArrayFromFile
- Lê um array de inteiros de um arquivo.
---------------------------------------------------------------------------------------------------
*/
ref_int_Array readArrayFromFile(char *filename)
{
    // Definicao de variaveis
    ref_int_Array array = NULL;
    FILE *arquivo = NULL;
    int length = 0;

    arquivo = fopen(filename, "r");

    // Verificacao do arquivo
    if (arquivo != NULL)
    {
        // Leitura da quantidade de numeros
        if (fscanf(arquivo, "%d", &length) == 1 && length > 0)
        {
            array = (ref_int_Array)malloc(sizeof(int_Array));
            array->length = length;
            array->data = (ints)malloc(length * sizeof(int));
            array->ix = 0;

            // Leitura dos numeros
            for (int i = 0; i < length; i = i + 1)
            {
                fscanf(arquivo, "%d", &array->data[i]);
            }
        }
        else
        {
            IO_print("\nErro ao ler o tamanho do array no arquivo");
        }
        fclose(arquivo);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo");
    }

    return array;
}

/*
---------------------------------------------------------------------------------------------------
METODO arraySearch
- Busca o valor no array
---------------------------------------------------------------------------------------------------
*/
ref_int_Array arraySearch(int valor, ref_int_Array array)
{
    // Definicao de variaveis
    ref_int_Array resultado = NULL;
    resultado = (ref_int_Array)malloc(sizeof(int_Array));
    resultado->length = 0;
    resultado->data = (ints)malloc(array->length * sizeof(int));
    resultado->ix = 0;

    // Verificacao do array
    if (array != NULL)
    {
        // Busca do valor no array
        for (int i = 0; i < array->length; i = i + 1)
        {
            if (array->data[i] == valor)
            {
                resultado->data[resultado->ix] = i;
                resultado->ix = resultado->ix + 1;
                resultado->length = resultado->length + 1;
            }
        }
    }

    return resultado;
}

/*
---------------------------------------------------------------------------------------------------
METODO method_1012
- Lê o tamanho do array e os elementos do teclado, salva no arquivo, depois lê do arquivo usando readArrayFromFile.
---------------------------------------------------------------------------------------------------
*/
void method_1012(void)
{
    // Identificacao
    IO_start("\nMetodo 1012\n");

    // Definicao de variaveis
    int tamanho = 0;
    FILE *arquivo = NULL;
    char *nome_arquivo = "method_1012.txt";

    // Leitura do tamanho do array
    tamanho = IO_readint("\nDigite o tamanho do array: ");

    // Salvar o tamanho e os elementos no arquivo
    arquivo = fopen(nome_arquivo, "w");
    if (arquivo != NULL)
    {
        fprintf(arquivo, "%d\n", tamanho);
        IO_print("\nDigite os elementos do array:\n");
        for (int i = 0; i < tamanho; i = i + 1)
        {
            int valor = IO_readint("");
            fprintf(arquivo, "%d\n", valor);
        }
        fclose(arquivo);
        IO_print("\nArray salvo no arquivo method_1012.txt\n");
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para escrita.\n");
    }

    ref_int_Array array = readArrayFromFile(nome_arquivo);

    if (array != NULL)
    {
        IO_print("\nElementos lidos do arquivo:\n");
        for (int i = 0; i < array->length; i++)
        {
            IO_printf("%d ", array->data[i]);
        }
        IO_print("\n");
        free(array->data);
        free(array);
    }
    else
    {
        IO_print("\nErro ao ler o array do arquivo.\n");
    }

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO arrayCompare
-
---------------------------------------------------------------------------------------------------
*/
ref_int_Array arrayCompare(ref_int_Array array1, ref_int_Array array2)
{
    // Definicao de variaveis
    ref_int_Array resultado = NULL;
    resultado = (ref_int_Array)malloc(sizeof(int_Array));
    resultado->length = 0;
    resultado->data = NULL;
    resultado->ix = 0;

    // Verificacao dos arrays
    if (array1 != NULL && array2 != NULL)
    {
        if (array1->length > array2->length)
        {
            IO_print("\nO primeiro array e' maior que o segundo.\n");
        }
        else if (array1->length < array2->length)
        {
            IO_print("\nO segundo array e' maior que o primeiro.\n");
        }
        else
        {
            IO_print("\nOs arrays possuem o mesmo tamanho.\n");
        }
    }

    return resultado;
}

/*
---------------------------------------------------------------------------------------------------
METODO method_1013
- Comparacao dos arrays (ler arrays do teclado, salvar em arquivos, ler dos arquivos)
---------------------------------------------------------------------------------------------------
*/
void method_1013(void)
{
    // Identificacao
    IO_start("\nMetodo 1013\n");

    // Definicao de variaveis
    int tamanho1 = 0, tamanho2 = 0;
    FILE *arquivo1 = NULL;
    FILE *arquivo2 = NULL;
    char *nome_arquivo1 = "array1_1013.txt";
    char *nome_arquivo2 = "array2_1013.txt";
    ref_int_Array array1 = NULL;
    ref_int_Array array2 = NULL;
    ref_int_Array resultado = NULL;

    // Leitura do primeiro array e gravacao no arquivo
    tamanho1 = IO_readint("\nDigite o tamanho do primeiro array: ");
    arquivo1 = fopen(nome_arquivo1, "w");
    if (arquivo1 != NULL)
    {
        fprintf(arquivo1, "%d\n", tamanho1);
        IO_print("\nDigite os elementos do primeiro array:\n");
        for (int i = 0; i < tamanho1; i = i + 1)
        {
            int valor = IO_readint("");
            fprintf(arquivo1, "%d\n", valor);
        }
        fclose(arquivo1);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para o primeiro array.\n");
        IO_end();
        return;
    }

    IO_print("\n-------------------------------------------------------------------------\n");

    // Leitura do segundo array e gravacao no arquivo
    tamanho2 = IO_readint("\nDigite o tamanho do segundo array: ");
    arquivo2 = fopen(nome_arquivo2, "w");
    if (arquivo2 != NULL)
    {
        fprintf(arquivo2, "%d\n", tamanho2);
        IO_print("\nDigite os elementos do segundo array:\n");
        for (int i = 0; i < tamanho2; i = i + 1)
        {
            int valor = IO_readint("");
            fprintf(arquivo2, "%d\n", valor);
        }
        fclose(arquivo2);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para o segundo array.\n");
        IO_end();
        return;
    }

    IO_print("\n-------------------------------------------------------------------------\n");

    // Leitura dos arrays dos arquivos
    array1 = readArrayFromFile(nome_arquivo1);
    array2 = readArrayFromFile(nome_arquivo2);

    // Comparacao dos arrays
    resultado = arrayCompare(array1, array2);

    // Liberacao da memoria
    if (array1 != NULL)
    {
        free(array1->data);
        free(array1);
    }
    if (array2 != NULL)
    {
        free(array2->data);
        free(array2);
    }

    if (resultado != NULL)
    {
        free(resultado);
    }

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO arrayAdd
- Multiplicar todos elementos do segundo array por um numero e somar o array 1 com o array 2
- @param array - array a ser multiplicado
---------------------------------------------------------------------------------------------------
*/
ref_int_Array arrayAdd(ref_int_Array array, int valor)
{
    // Definicao de variaveis
    ref_int_Array resultado = NULL;
    resultado = (ref_int_Array)malloc(sizeof(int_Array));
    resultado->length = array->length;
    resultado->data = (ints)malloc(resultado->length * sizeof(int));
    resultado->ix = 0;

    // Verificacao do array
    if (array != NULL)
    {
        // Multiplicacao dos elementos do array pelo valor
        for (int i = 0; i < array->length; i = i + 1)
        {
            resultado->data[i] = array->data[i] * valor;
        }
    }

    return resultado;
}

/*
---------------------------------------------------------------------------------------------------
METODO method_1014
- Multiplicar os elementos do array por um numero e depois somar ambos os array (ler do teclado)
---------------------------------------------------------------------------------------------------
*/
void method_1014(void)
{
    // Identificacao
    IO_start("\nMetodo 1014\n");

    // Definicao de variaveis
    ref_int_Array array1 = NULL;
    ref_int_Array array2 = NULL;
    ref_int_Array resultado = NULL;
    int numero = 0;
    int minLength = 0;
    int tamanho1 = 0, tamanho2 = 0;
    FILE *arquivo1 = NULL, *arquivo2 = NULL;
    char *nome_arquivo1 = "array1_1014.txt";
    char *nome_arquivo2 = "array2_1014.txt";

    // Leitura do numero
    numero = IO_readint("\nDigite o numero para multiplicar os elementos do segundo array: ");

    // Leitura do primeiro array e gravacao no arquivo
    tamanho1 = IO_readint("\nDigite o tamanho do primeiro array: ");
    arquivo1 = fopen(nome_arquivo1, "w");
    if (arquivo1 != NULL)
    {
        fprintf(arquivo1, "%d\n", tamanho1);
        IO_print("\nDigite os elementos do primeiro array:\n");
        for (int i = 0; i < tamanho1; i++)
        {
            int valor = IO_readint("");
            fprintf(arquivo1, "%d\n", valor);
        }
        fclose(arquivo1);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para o primeiro array.\n");
    }

    IO_print("\n-------------------------------------------------------------------------\n");

    // Leitura do segundo array e gravacao no arquivo
    tamanho2 = IO_readint("\nDigite o tamanho do segundo array: ");
    arquivo2 = fopen(nome_arquivo2, "w");
    if (arquivo2 != NULL)
    {
        fprintf(arquivo2, "%d\n", tamanho2);
        IO_print("\nDigite os elementos do segundo array:\n");
        for (int i = 0; i < tamanho2; i++)
        {
            int valor = IO_readint("");
            fprintf(arquivo2, "%d\n", valor);
        }
        fclose(arquivo2);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para o segundo array.\n");
    }

    IO_print("\n-------------------------------------------------------------------------\n");

    // Leitura dos arrays dos arquivos
    array1 = readArrayFromFile(nome_arquivo1);
    array2 = readArrayFromFile(nome_arquivo2);

    if (array1 != NULL && array2 != NULL)
    {
        // Multiplicacao dos elementos do array2 pelo numero
        resultado = arrayAdd(array2, numero);

        // Soma dos arrays elemento a elemento
        minLength = (array1->length < resultado->length) ? array1->length : resultado->length;
        for (int i = 0; i < minLength; i = i + 1)
        {
            resultado->data[i] = resultado->data[i] + array1->data[i];
        }

        // Exibicao do resultado
        IO_print("\nResultado da soma dos arrays: ");
        for (int i = 0; i < resultado->length; i = i + 1)
        {
            IO_printf("%d ", resultado->data[i]);
        }
        IO_print("\n");

        // Liberacao da memoria
        free(array1->data);
        free(array1);
        free(array2->data);
        free(array2);
        free(resultado->data);
        free(resultado);
    }
    else
    {
        IO_print("\nErro ao ler os arrays dos arquivos.\n");
        if (array1)
        {
            free(array1->data);
            free(array1);
        }
        if (array2)
        {
            free(array2->data);
            free(array2);
        }
    }

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO isArrayDecrescent
- Verifica se o array e' decrescente
---------------------------------------------------------------------------------------------------
*/
ref_int_Array isArrayDecrescent(ref_int_Array array)
{
    // Definicao de variaveis
    ref_int_Array resultado = NULL;
    resultado = (ref_int_Array)malloc(sizeof(int_Array));
    resultado->length = 0;
    resultado->data = NULL;
    resultado->ix = 0;

    // Verificacao do array
    if (array != NULL)
    {
        // Verificacao se o array e' decrescente
        for (int i = 0; i < array->length - 1; i = i + 1)
        {
            if (array->data[i] < array->data[i + 1])
            {
                resultado->length = 0;
                return resultado;
            }
        }
        resultado->length = 1;
    }

    return resultado;
}

/*
---------------------------------------------------------------------------------------------------
METODO 1015
- Verifica se o array e' decrescente (ler do teclado)
---------------------------------------------------------------------------------------------------
*/
void method_1015(void)
{
    // Identificacao
    IO_start("\nMetodo 1015\n");

    // Definicao de variaveis
    ref_int_Array array = NULL;
    int tamanho = 0;

    // Leitura do array
    tamanho = IO_readint("\nDigite o tamanho do array: ");
    array = (ref_int_Array)malloc(sizeof(int_Array));
    array->length = tamanho;
    array->data = (ints)malloc(tamanho * sizeof(int));
    array->ix = 0;

    IO_print("\nDigite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++)
    {
        array->data[i] = IO_readint("");
    }

    IO_print("\n-------------------------------------------------------------------------\n");

    // Verificacao se o array e' decrescente
    ref_int_Array resultado = isArrayDecrescent(array);
    if (resultado->length > 0)
    {
        IO_print("\nO array e' decrescente\n");
    }
    else
    {
        IO_print("\nO array nao e' decrescente\n");
    }

    // Liberacao da memoria
    free(array->data);
    free(array);
    free(resultado);

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO matrixTranspose
- Calcula a transposta de uma matriz
---------------------------------------------------------------------------------------------------
*/
ref_int_Matrix matrixTranspose(ref_int_Matrix matriz1)
{
    ref_int_Matrix matriz2 = NULL;
    if (matriz1 == NULL)
        return NULL;

    matriz2 = (ref_int_Matrix)malloc(sizeof(int_Matrix));
    matriz2->rows = matriz1->columns;
    matriz2->columns = matriz1->rows;
    matriz2->data = (ints *)malloc(matriz2->rows * sizeof(int *));
    matriz2->ix = 0;
    matriz2->iy = 0;

    for (int i = 0; i < matriz2->rows; i = i + 1)
    {
        matriz2->data[i] = (int *)malloc(matriz2->columns * sizeof(int));
        for (int j = 0; j < matriz2->columns; j = j + 1)
        {
            matriz2->data[i][j] = matriz1->data[j][i];
        }
    }

    return matriz2;
}

/*
---------------------------------------------------------------------------------------------------
METODO 1016
- Ler matriz do teclado, obter a transposta e exibir ambas
---------------------------------------------------------------------------------------------------
*/
void method_1016(void)
{
    // Identificacao
    IO_start("\nMetodo 1016\n");

    // Definicao de variaveis
    int rows = 0, columns = 0;

    rows = IO_readint("\nDigite o numero de linhas da matriz: ");
    columns = IO_readint("Digite o numero de colunas da matriz: ");

    ref_int_Matrix matrix = (ref_int_Matrix)malloc(sizeof(int_Matrix));
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->data = (ints *)malloc(rows * sizeof(int *));
    matrix->ix = 0;
    matrix->iy = 0;

    IO_print("\nDigite os elementos da matriz (linha por linha):\n");
    for (int i = 0; i < rows; i++)
    {
        matrix->data[i] = (int *)malloc(columns * sizeof(int));
        for (int j = 0; j < columns; j++)
        {
            matrix->data[i][j] = IO_readint("");
        }
    }

    IO_print("\nMatriz original:\n");
    for (int i = 0; i < matrix->rows; i = i + 1)
    {
        for (int j = 0; j < matrix->columns; j = j + 1)
        {
            IO_printf("%d ", matrix->data[i][j]);
        }
        IO_print("\n");
    }

    ref_int_Matrix transposta = matrixTranspose(matrix);

    IO_print("\nMatriz transposta:\n");
    for (int i = 0; i < transposta->rows; i = i + 1)
    {
        for (int j = 0; j < transposta->columns; j = j + 1)
        {
            IO_printf("%d ", transposta->data[i][j]);
        }
        IO_print("\n");
    }

    // Liberacao da memoria
    for (int i = 0; i < matrix->rows; i = i + 1)
        free(matrix->data[i]);
    for (int i = 0; i < transposta->rows; i = i + 1)
        free(transposta->data[i]);
    free(matrix->data);
    free(matrix);
    free(transposta->data);
    free(transposta);

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO matrixZero
- Verifica se a matriz contem algum valor nulo (zero)
- Retorna 1 se houver pelo menos um zero e 0 caso nao houver
---------------------------------------------------------------------------------------------------
*/
int matrixZero(ref_int_Matrix matriz1)
{
    if (matriz1 == NULL)
    {
        IO_print("\nErro ao tentar ler a matriz\n");
        return 0;
    }

    for (int i = 0; i < matriz1->rows; i = i + 1)
    {
        for (int j = 0; j < matriz1->columns; j = j + 1)
        {
            if (matriz1->data[i][j] == 0)
            {
                return 1; // Encontrou valor nulo
            }
        }
    }
    return 0; // Nenhum valor nulo encontrado
}

/*
---------------------------------------------------------------------------------------------------
METODO 1017
- Testar se uma matriz só contém valores iguais a zero.
  Ler matriz do teclado e aplicar a função sobre a matriz lida.
---------------------------------------------------------------------------------------------------
*/
void method_1017(void)
{
    // Identificacao
    IO_start("\nMetodo 1017\n");

    // Definicao de variaveis
    ref_int_Matrix matriz = NULL;
    int rows = 0;
    int columns = 0;
    int i = 0;

    rows = IO_readint("\nDigite o numero de linhas da matriz: ");
    columns = IO_readint("Digite o numero de colunas da matriz: ");

    matriz = (ref_int_Matrix)malloc(sizeof(int_Matrix));
    matriz->rows = rows;
    matriz->columns = columns;
    matriz->data = (ints *)malloc(rows * sizeof(int *));
    matriz->ix = 0;
    matriz->iy = 0;

    IO_print("\nDigite os elementos da matriz (linha por linha):\n");
    for (int i = 0; i < rows; i++)
    {
        matriz->data[i] = (int *)malloc(columns * sizeof(int));
        for (int j = 0; j < columns; j++)
        {
            matriz->data[i][j] = IO_readint("");
        }
    }

    IO_print("\nMatriz lida:\n");
    for (int i = 0; i < matriz->rows; i++)
    {
        for (int j = 0; j < matriz->columns; j++)
        {
            IO_printf("%d ", matriz->data[i][j]);
        }
        IO_print("\n");
    }

    int verificador = matrixZero(matriz);

    if (verificador == 1)
    {
        IO_print("\n\nA matriz possui pelo menos um valor nulo\n");
    }
    else
    {
        IO_print("\n\nA matriz nao possui nenhum valor nulo\n");
    }

    // Liberacao da memoria
    for (i = 0; i < matriz->rows; i++)
    {
        free(matriz->data[i]);
    }

    free(matriz->data);
    free(matriz);

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO readMatrixFromFile
- Le uma matriz de inteiros de um arquivo.
---------------------------------------------------------------------------------------------------
*/
ref_int_Matrix readMatrixFromFile(char *filename)
{
    ref_int_Matrix matriz = NULL;
    FILE *arquivo = fopen(filename, "r");
    int rows = 0, columns = 0, i = 0, j = 0;

    if (arquivo != NULL)
    {
        if (fscanf(arquivo, "%d %d", &rows, &columns) == 2 && rows > 0 && columns > 0)
        {
            matriz = (ref_int_Matrix)malloc(sizeof(int_Matrix));
            matriz->rows = rows;
            matriz->columns = columns;
            matriz->data = (ints *)malloc(rows * sizeof(int *));
            matriz->ix = 0;
            matriz->iy = 0;

            for (i = 0; i < rows; i++)
            {
                matriz->data[i] = (int *)malloc(columns * sizeof(int));
                for (j = 0; j < columns; j++)
                {
                    fscanf(arquivo, "%d", &matriz->data[i][j]);
                }
            }
        }
        fclose(arquivo);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para leitura da matriz.\n");
    }

    return matriz;
}

/*
---------------------------------------------------------------------------------------------------
METODO matrixCompare
- Comparar a igualdade entre duas matrizes
- Retorna 1 se forem iguais e 0 se forem diferentes
---------------------------------------------------------------------------------------------------
*/
int matrixCompare(ref_int_Matrix matriz1, ref_int_Matrix matriz2)
{
    if (matriz1 != NULL && matriz2 != NULL)
    {
        if (matriz1->rows != matriz2->rows || matriz1->columns != matriz2->columns)
        {
            return 0; // Matrizes de tamanhos diferentes
        }

        for (int i = 0; i < matriz1->rows; i++)
        {
            for (int j = 0; j < matriz1->columns; j++)
            {
                if (matriz1->data[i][j] != matriz2->data[i][j])
                {
                    return 0; // Matrizes diferentes
                }
            }
        }
        return 1; // Matrizes iguais
    }
    else
    {
        IO_print("\nErro ao comparar matrizes: uma ou ambas as matrizes sao nulas.\n");
        return 0;
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO 08
- Para testar, receber dados de arquivos e
aplicar a função sobre as matrizes com os valores lidos.
DICA: Verificar se os tamanhos são compatíveis.
Usar o modelo de matriz proposto nos exemplos.
Exemplo: matriz1   = readMatrixFromFile ( "DADOS1.TXT" );
matriz2   = readMatrixFromFile ( "DADOS2.TXT" );
resposta = matrixCompare
( matriz1, matriz2 );
---------------------------------------------------------------------------------------------------
*/
void method_1018(void)
{
    // Identificacao
    IO_start("\nMetodo 1018\n");

    // Definicao de variaveis
    int resultado = 0;
    ref_int_Matrix matriz1 = NULL;
    ref_int_Matrix matriz2 = NULL;
    char *nome_arquivo1 = "matrix1.txt";
    char *nome_arquivo2 = "matrix2.txt";
    FILE *arquivo1 = NULL;
    FILE *arquivo2 = NULL;

    // Leitura do primeiro arquivo
    arquivo1 = fopen(nome_arquivo1, "w");
    if (arquivo1 != NULL)
    {
        int rows = IO_readint("\nDigite o numero de linhas da matriz 1: ");
        int columns = IO_readint("Digite o numero de colunas da matriz 1: ");
        fprintf(arquivo1, "%d %d\n", rows, columns);
        IO_print("\nDigite os elementos da matriz 1 (linha por linha):\n");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                int valor = IO_readint("");
                fprintf(arquivo1, "%d ", valor);
            }
            fprintf(arquivo1, "\n");
        }
        fclose(arquivo1);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para a matriz 1.\n");
    }

    // Leitura do segundo arquivo
    arquivo2 = fopen(nome_arquivo2, "w");
    if (arquivo2 != NULL)
    {
        int rows = IO_readint("\nDigite o numero de linhas da matriz 2: ");
        int columns = IO_readint("Digite o numero de colunas da matriz 2: ");
        fprintf(arquivo2, "%d %d\n", rows, columns);
        IO_print("\nDigite os elementos da matriz 2 (linha por linha):\n");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                int valor = IO_readint("");
                fprintf(arquivo2, "%d ", valor);
            }
            fprintf(arquivo2, "\n");
        }
        fclose(arquivo2);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para a matriz 2.\n");
    }

    IO_print("\n-------------------------------------------------------------------------\n");

    // Leitura da matriz 1 e 2
    matriz1 = readMatrixFromFile(nome_arquivo1);
    matriz2 = readMatrixFromFile(nome_arquivo2);

    // Comparacao das matrizes
    resultado = matrixCompare(matriz1, matriz2);
    if (resultado == 1)
    {
        IO_print("\nAs matrizes sao iguais.\n");
    }
    else
    {
        IO_print("\nAs matrizes sao diferentes.\n");
    }

    // Liberacao da memoria
    for (int i = 0; i < matriz1->rows; i = i + 1)
    {
        free(matriz1->data[i]);
    }

    for (int i = 0; i < matriz2->rows; i = i + 1)
    {
        free(matriz2->data[i]);
    }
    free(matriz1->data);
    free(matriz1);
    free(matriz2->data);
    free(matriz2);

    // Fechamento dos arquivos
    fclose(arquivo1);
    fclose(arquivo2);

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO matrixAdd
- Retorna a soma de duas matrizes sendo a segunda multiplicada por uma constante
---------------------------------------------------------------------------------------------------
*/
ref_int_Matrix matrixAdd(ref_int_Matrix matriz1, ref_int_Matrix matriz2, int constante)
{
    ref_int_Matrix resultado = NULL;

    if (matriz1 != NULL && matriz2 != NULL && matriz1->rows == matriz2->rows && matriz1->columns == matriz2->columns)
    {
        resultado = (ref_int_Matrix)malloc(sizeof(int_Matrix));
        resultado->rows = matriz1->rows;
        resultado->columns = matriz1->columns;
        resultado->data = (ints *)malloc(resultado->rows * sizeof(int *));
        resultado->ix = 0;
        resultado->iy = 0;

        for (int i = 0; i < resultado->rows; i++)
        {
            resultado->data[i] = (int *)malloc(resultado->columns * sizeof(int));
            for (int j = 0; j < resultado->columns; j++)
            {
                resultado->data[i][j] = matriz1->data[i][j] + (matriz2->data[i][j] * constante);
            }
        }
    }

    return resultado;
}

/*
---------------------------------------------------------------------------------------------------
METODO 09
- obter o produto de duas matrizes.
---------------------------------------------------------------------------------------------------
*/
void method_1019(void)
{
    // Identificacao
    IO_start("\nMetodo 1019\n");

    // Definicao de variaveis
    ref_int_Matrix matriz1 = NULL;
    ref_int_Matrix matriz2 = NULL;
    ref_int_Matrix resultado = NULL;
    char *nome_arquivo1 = "matrix1.txt";
    char *nome_arquivo2 = "matrix2.txt";
    FILE *arquivo1 = NULL;
    FILE *arquivo2 = NULL;
    int constante = 0;
    int rows1 = 0;
    int columns1 = 0;
    int rows2 = 0;
    int columns2 = 0;
    int i = 0;
    int j = 0;

    constante = IO_readint("\nDigite o valor da constante para multiplicar a segunda matriz: ");

    // Leitura do primeiro arquivo
    arquivo1 = fopen(nome_arquivo1, "w");
    if (arquivo1 != NULL)
    {
        rows1 = IO_readint("\nDigite o numero de linhas da matriz 1: ");
        columns1 = IO_readint("Digite o numero de colunas da matriz 1: ");
        fprintf(arquivo1, "%d %d\n", rows1, columns1);
        IO_print("\nDigite os elementos da matriz 1 (linha por linha):\n");
        for (i = 0; i < rows1; i = i + 1)
        {
            for (j = 0; j < columns1; j = j + 1)
            {
                int valor = IO_readint("");
                fprintf(arquivo1, "%d ", valor);
            }
            fprintf(arquivo1, "\n");
        }
        fclose(arquivo1);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para a matriz 1.\n");
        IO_end();
        return;
    }

    // Leitura do segundo arquivo
    arquivo2 = fopen(nome_arquivo2, "w");
    if (arquivo2 != NULL)
    {
        rows2 = IO_readint("\nDigite o numero de linhas da matriz 2: ");
        columns2 = IO_readint("Digite o numero de colunas da matriz 2: ");
        fprintf(arquivo2, "%d %d\n", rows2, columns2);
        IO_print("\nDigite os elementos da matriz 2 (linha por linha):\n");
        for (i = 0; i < rows2; i = i + 1)
        {
            for (j = 0; j < columns2; j = j + 1)
            {
                int valor = IO_readint("");
                fprintf(arquivo2, "%d ", valor);
            }
            fprintf(arquivo2, "\n");
        }
        fclose(arquivo2);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para a matriz 2.\n");
        IO_end();
        return;
    }

    IO_print("\n-------------------------------------------------------------------------\n");

    // Leitura da matriz 1 e 2
    matriz1 = readMatrixFromFile(nome_arquivo1);
    matriz2 = readMatrixFromFile(nome_arquivo2);

    // Produto das matrizes
    resultado = matrixAdd(matriz1, matriz2, constante);

    if (resultado != NULL)
    {
        IO_print("\nSoma das matrizes (segunda multiplicada pela constante):\n");
        for (i = 0; i < resultado->rows; i = i + 1)
        {
            for (j = 0; j < resultado->columns; j = j + 1)
            {
                IO_printf("%d ", resultado->data[i][j]);
            }
            IO_print("\n");
        }
    }
    else
    {
        IO_print("\nErro ao calcular a soma das matrizes.\n");
    }

    // Liberacao da memoria
    if (matriz1)
    {
        for (i = 0; i < matriz1->rows; i = i + 1)
        {
            free(matriz1->data[i]);
        }
        free(matriz1->data);
        free(matriz1);
    }
    if (matriz2)
    {
        for (i = 0; i < matriz2->rows; i = i + 1)
        {
            free(matriz2->data[i]);
        }
        free(matriz2->data);
        free(matriz2);
    }
    if (resultado)
    {
        for (i = 0; i < resultado->rows; i = i + 1)
        {
            free(resultado->data[i]);
        }
        free(resultado->data);
        free(resultado);
    }

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO matrixProduct
- obter o produto de duas matrizes.
---------------------------------------------------------------------------------------------------
*/
ref_int_Matrix matrixProduct(ref_int_Matrix matriz1, ref_int_Matrix matriz2)
{
    ref_int_Matrix resultado = NULL;

    if (matriz1 != NULL && matriz2 != NULL && matriz1->columns == matriz2->rows)
    {
        resultado = (ref_int_Matrix)malloc(sizeof(int_Matrix));
        resultado->rows = matriz1->rows;
        resultado->columns = matriz2->columns;
        resultado->data = (ints *)malloc(resultado->rows * sizeof(int *));
        resultado->ix = 0;
        resultado->iy = 0;

        for (int i = 0; i < resultado->rows; i++)
        {
            resultado->data[i] = (int *)malloc(resultado->columns * sizeof(int));
            for (int j = 0; j < resultado->columns; j++)
            {
                resultado->data[i][j] = 0;
                for (int k = 0; k < matriz1->columns; k++)
                {
                    resultado->data[i][j] += matriz1->data[i][k] * matriz2->data[k][j];
                }
            }
        }
    }
    else
    {
        resultado = NULL;
    }

    return resultado;
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
    IO_start("\nMetodo 1019\n");

    // Definicao de variaveis
    ref_int_Matrix matriz1 = NULL;
    ref_int_Matrix matriz2 = NULL;
    ref_int_Matrix resultado = NULL;
    char *nome_arquivo1 = "matrix1.txt";
    char *nome_arquivo2 = "matrix2.txt";
    FILE *arquivo1 = NULL;
    FILE *arquivo2 = NULL;
    int rows1 = 0;
    int columns1 = 0;
    int rows2 = 0;
    int columns2 = 0;
    int i = 0;
    int j = 0;

    // Leitura do primeiro arquivo
    arquivo1 = fopen(nome_arquivo1, "w");
    if (arquivo1 != NULL)
    {
        rows1 = IO_readint("\nDigite o numero de linhas da matriz 1: ");
        columns1 = IO_readint("Digite o numero de colunas da matriz 1: ");
        fprintf(arquivo1, "%d %d\n", rows1, columns1);
        IO_print("\nDigite os elementos da matriz 1 (linha por linha):\n");
        for (i = 0; i < rows1; i = i + 1)
        {
            for (j = 0; j < columns1; j = j + 1)
            {
                int valor = IO_readint("");
                fprintf(arquivo1, "%d ", valor);
            }
            fprintf(arquivo1, "\n");
        }
        fclose(arquivo1);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para a matriz 1.\n");
    }

    // Leitura do segundo arquivo
    arquivo2 = fopen(nome_arquivo2, "w");
    if (arquivo2 != NULL)
    {
        rows2 = IO_readint("\nDigite o numero de linhas da matriz 2: ");
        columns2 = IO_readint("Digite o numero de colunas da matriz 2: ");
        fprintf(arquivo2, "%d %d\n", rows2, columns2);
        IO_print("\nDigite os elementos da matriz 2 (linha por linha):\n");
        for (i = 0; i < rows2; i = i + 1)
        {
            for (j = 0; j < columns2; j = j + 1)
            {
                int valor = IO_readint("");
                fprintf(arquivo2, "%d ", valor);
            }
            fprintf(arquivo2, "\n");
        }
        fclose(arquivo2);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para a matriz 2.\n");
    }

    IO_print("\n-------------------------------------------------------------------------\n");

    // Leitura da matriz 1 e 2
    matriz1 = readMatrixFromFile(nome_arquivo1);
    matriz2 = readMatrixFromFile(nome_arquivo2);

    // Produto das matrizes
    resultado = matrixProduct(matriz1, matriz2);
    if (resultado != NULL)
    {
        IO_print("\nProduto das matrizes:\n");
        for (i = 0; i < resultado->rows; i = i + 1)
        {
            for (j = 0; j < resultado->columns; j = j + 1)
            {
                IO_printf("%d ", resultado->data[i][j]);
            }
            IO_print("\n");
        }
    }
    else
    {
        IO_print("\nErro ao calcular o produto das matrizes.\n");
    }

    // Liberacao da memoria
    for (i = 0; i < matriz1->rows; i = i + 1)
    {
        free(matriz1->data[i]);
    }
    for (i = 0; i < matriz2->rows; i = i + 1)
    {
        free(matriz2->data[i]);
    }
    for (i = 0; i < resultado->rows; i = i + 1)
    {
        free(resultado->data[i]);
    }

    free(matriz1->data);
    free(matriz1);
    free(matriz2->data);
    free(matriz2);
    free(resultado->data);
    free(resultado);

    // Fechamento dos arquivos
    fclose(arquivo1);
    fclose(arquivo2);

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO sortArrayDown
- colocar um arranjo em ordem decrescente
---------------------------------------------------------------------------------------------------
*/
ref_int_Array sortArrayDown(ref_int_Array arranjo)
{
    // Definicao de variaveis
    ref_int_Array resultado = NULL;
    resultado = (ref_int_Array)malloc(sizeof(int_Array));
    resultado->length = arranjo->length;
    resultado->data = (ints)malloc(resultado->length * sizeof(int));
    resultado->ix = 0;

    // Copiar os dados do array original
    if (arranjo != NULL)
    {
        for (int i = 0; i < arranjo->length; i=i+1)
        {
            resultado->data[i] = arranjo->data[i];
        }

        // Ordenacao decrescente (Bubble Sort) AEDS II???????????
        for (int i = 0; i < resultado->length - 1; i++)
        {
            for (int j = 0; j < resultado->length - 1 - i; j++)
            {
                if (resultado->data[j] < resultado->data[j + 1])
                {
                    int temp = resultado->data[j];
                    resultado->data[j] = resultado->data[j + 1];
                    resultado->data[j + 1] = temp;
                }
            }
        }
    }

    return resultado;
}

/*
---------------------------------------------------------------------------------------------------
METODO 11
- colocar um arranjo em ordem decrescente
---------------------------------------------------------------------------------------------------
*/
void method_10E1(void)
{
    // Identificacao
    IO_start("\n10E1\n");

    // Definicao de variaveis
    ref_int_Array arranjo = NULL;
    int tamanho = 0;
    ref_int_Array resultado = NULL;
    FILE *arquivo = NULL;
    char *nome_arquivo = "method_10E1.txt";

    // Leitura do array e gravação no arquivo
    tamanho = IO_readint("\nDigite o tamanho do array: ");
    arquivo = fopen(nome_arquivo, "w");
    if (arquivo != NULL)
    {
        fprintf(arquivo, "%d\n", tamanho);
        IO_print("\nDigite os elementos do array:\n");
        for (int i = 0; i < tamanho; i = i + 1)
        {
            int valor = IO_readint("");
            fprintf(arquivo, "%d\n", valor);
        }
        fclose(arquivo);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para gravacao.\n");
        IO_end();
        return;
    }

    // Agora lê o array do arquivo
    arranjo = readArrayFromFile(nome_arquivo);

    if (arranjo == NULL)
    {
        IO_print("\nErro ao ler o array do arquivo.\n");
        IO_end();
        return;
    }

    IO_print("\n-------------------------------------------------------------------------\n");

    // Ordenacao do array
    resultado = sortArrayDown(arranjo);

    // Exibicao do resultado
    IO_print("\nArray ordenado em ordem decrescente: ");

    for (int i = 0; i < resultado->length; i = i + 1)
    {
        IO_printf("%d ", resultado->data[i]);
    }

    IO_print("\n");

    // Liberacao da memoria
    free(arranjo->data);
    free(arranjo);
    free(resultado->data);
    free(resultado);

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO identityMatrix
- testar se o produto de duas matrizes é igual à matriz identidade
---------------------------------------------------------------------------------------------------
*/
ref_int_Matrix identityMatrix(int size)
{
    ref_int_Matrix matriz = NULL;
    matriz = (ref_int_Matrix)malloc(sizeof(int_Matrix));
    matriz->rows = size;
    matriz->columns = size;
    matriz->data = (ints *)malloc(size * sizeof(int *));
    matriz->ix = 0;
    matriz->iy = 0;

    for (int i = 0; i < size; i = i + 1)
    {
        matriz->data[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j = j + 1)
        {
            if (i == j)
            {
                matriz->data[i][j] = 1;
            }
            else
            {
                matriz->data[i][j] = 0;
            }
        }
    }

    return matriz;
}

/*
---------------------------------------------------------------------------------------------------
METODO 12
- Testar se o produto de duas matrizes e igual a matriz identidade
---------------------------------------------------------------------------------------------------
*/
void method_10E2(void)
{
    // Identificacao
    IO_start("\n10E2\n");

    // Variaveis
    ref_int_Matrix matriz1 = NULL;
    ref_int_Matrix matriz2 = NULL;
    ref_int_Matrix resultado = NULL;
    ref_int_Matrix identidade = NULL;
    char *nome_arquivo1 = "matrix1.txt";
    char *nome_arquivo2 = "matrix2.txt";
    FILE *arquivo1 = NULL;
    FILE *arquivo2 = NULL;
    int rows1 = 0, columns1 = 0;
    int rows2 = 0, columns2 = 0;
    int i = 0, j = 0;
    int igual = 1;

    // Leitura do primeiro arquivo
    arquivo1 = fopen(nome_arquivo1, "w");
    if (arquivo1 != NULL)
    {
        rows1 = IO_readint("\nDigite o numero de linhas da matriz 1: ");
        columns1 = IO_readint("Digite o numero de colunas da matriz 1: ");
        fprintf(arquivo1, "%d %d\n", rows1, columns1);
        IO_print("\nDigite os elementos da matriz 1 (linha por linha):\n");
        for (i = 0; i < rows1; i++)
        {
            for (j = 0; j < columns1; j++)
            {
                int valor = IO_readint("");
                fprintf(arquivo1, "%d ", valor);
            }
            fprintf(arquivo1, "\n");
        }
        fclose(arquivo1);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para a matriz 1.\n");
        IO_end();
        return;
    }

    // Leitura do segundo arquivo
    arquivo2 = fopen(nome_arquivo2, "w");
    if (arquivo2 != NULL)
    {
        rows2 = IO_readint("\nDigite o numero de linhas da matriz 2: ");
        columns2 = IO_readint("Digite o numero de colunas da matriz 2: ");
        fprintf(arquivo2, "%d %d\n", rows2, columns2);
        IO_print("\nDigite os elementos da matriz 2 (linha por linha):\n");
        for (i = 0; i < rows2; i++)
        {
            for (j = 0; j < columns2; j++)
            {
                int valor = IO_readint("");
                fprintf(arquivo2, "%d ", valor);
            }
            fprintf(arquivo2, "\n");
        }
        fclose(arquivo2);
    }
    else
    {
        IO_print("\nErro ao abrir o arquivo para a matriz 2.\n");
        IO_end();
        return;
    }

    IO_print("\n-------------------------------------------------------------------------\n");

    // Leitura das matrizes dos arquivos
    matriz1 = readMatrixFromFile(nome_arquivo1);
    matriz2 = readMatrixFromFile(nome_arquivo2);

    // Produto das matrizes
    resultado = matrixProduct(matriz1, matriz2);

    if (resultado != NULL)
    {
        IO_print("\nProduto das matrizes:\n");
        for (i = 0; i < resultado->rows; i++)
        {
            for (j = 0; j < resultado->columns; j++)
            {
                IO_printf("%d ", resultado->data[i][j]);
            }
            IO_print("\n");
        }
    }
    else
    {
        IO_print("\nErro ao calcular o produto das matrizes.\n");
        // Liberar memoria e encerrar
        if (matriz1)
        {
            for (i = 0; i < matriz1->rows; i++) free(matriz1->data[i]);
            free(matriz1->data);
            free(matriz1);
        }
        if (matriz2)
        {
            for (i = 0; i < matriz2->rows; i=i+1) 
            {
                free(matriz2->data[i]);
            }
            free(matriz2->data);
            free(matriz2);
        }
        IO_end();
        return;
    }

    // Criar matriz identidade
    if (resultado->rows == resultado->columns)
    {
        identidade = identityMatrix(resultado->rows);
        IO_print("\nMatriz identidade:\n");
        for (i = 0; i < identidade->rows; i++)
        {
            for (j = 0; j < identidade->columns; j++)
            {
                IO_printf("%d ", identidade->data[i][j]);
            }
            IO_print("\n");
        }

        // Verificar se o produto e igual a identidade
        for (i = 0; i < resultado->rows; i++)
        {
            for (j = 0; j < resultado->columns; j++)
            {
                if (resultado->data[i][j] != identidade->data[i][j])
                {
                    igual = 0;
                }
            }
        }
        if (igual == 1)
        {
            IO_print("\nO produto das matrizes e igual a matriz identidade.\n");
        }
        else
        {
            IO_print("\nO produto das matrizes NAO e igual a matriz identidade.\n");
        }
    }
    else
    {
        IO_print("\nO produto nao e quadrado, nao pode comparar com matriz identidade.\n");
    }

    // Liberacao da memoria
    if (matriz1)
    {
        for (i = 0; i < matriz1->rows; i++) free(matriz1->data[i]);
        free(matriz1->data);
        free(matriz1);
    }
    if (matriz2)
    {
        for (i = 0; i < matriz2->rows; i++) free(matriz2->data[i]);
        free(matriz2->data);
        free(matriz2);
    }
    if (resultado)
    {
        for (i = 0; i < resultado->rows; i++) free(resultado->data[i]);
        free(resultado->data);
        free(resultado);
    }
    if (identidade)
    {
        for (i = 0; i < identidade->rows; i++) free(identidade->data[i]);
        free(identidade->data);
        free(identidade);
    }

    // Encerramento
    IO_end();
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
