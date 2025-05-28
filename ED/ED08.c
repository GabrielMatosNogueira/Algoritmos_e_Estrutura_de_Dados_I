/*
Nome do Programa:   ED
Data:               //2025
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
    Windows:    gcc -o  .c
    Linux:      gcc -o  .c
    macOS:      gcc -o  .c


    2.2 - Execute o programa
    Windows:     ED
    Linux:      ./ED
    macOS:      ./

---------------------------------------------------------------------------------------------------
*/

// Declaracao de biblioteca(s)
#include "io.h"

// Definicao do tamanho maximo de um array
#define MAX 100

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
    IO_start("Metodo 00");

    // Mensagem de encerramento
    IO_print("ENCERRANDO O PROGRAMA...\n");

    // Encerrando o programa
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
LerPares
-
---------------------------------------------------------------------------------------------------
*/

void lerPares(int n, int *array)
{
    // identificacao
    IO_start("Metodo lerPares");

    // Declaracao de variaveis
    int i = 0;

    for (i = 0; i < n; i = i + 1)
    {
        printf("Digite numero positivo e par para a posicao [%d]: ", i);
        scanf("%d", &array[i]);
        getchar();

        if (array[i] <= 0 || array[i] % 2 != 0)
        {
            IO_print("Numero digitado nao e par ou nao e' positivo!\n");
            i = i - 1;
        }
    }

    for (i = 0; i < n; i = i + 1)
    {
        printf("\n[%d]", array[i]);
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO 01
-
---------------------------------------------------------------------------------------------------
*/

void method_01(void)
{
    // identificacao
    IO_start("Metodo 01");

    // Declaracao de variaveis 1
    int *array=0;
    int n=0;

    // Leitura do tamanho do array
    n=IO_readint("Digite o tamanho de n: ");

    // Alocacao de memoria para quantidade de testes
    array=(int*)malloc(sizeof(int)*n);

    if(n>0)
    {
        lerPares(n, array);
    }
    else
    {
        IO_print("\nValor invalido!\n");
    }

    // encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO gravarParesPositivos
---------------------------------------------------------------------------------------------------
*/

void gravarParesPositivos(char *filename, int *array)
{
    // Declaracao de variaveis
    FILE *arquivo = fopen(filename, "r");
    int valorLido = 0;
    int n = 0;
    int i = 0;

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Le os numeros do arquivo
    while (fscanf(arquivo, "%d", &n) != EOF)
    {
        // Verifica se o numero e' par e positivo
        if (n < 0 || n % 2 != 0)
        {
            printf("\nO numero %d e' impar ou negativo.\n", n);
        }
        else
        {
            array[i] = n;
            i=i+1;
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Exibe os numeros armazenados no array
    printf("\nNumeros pares e positivos lidos do arquivo:\n");
    for (int j = 0; j < i; j=j+1)
    {
        printf("%d\n", array[j]);
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO 02
- Criar um arquivo e inserir o tamanho do array na primeira linha e nas demais, numeros inteiros
separados por linha
- Ler e armazenar os numeros dentro de um arranjo
- Filtrar os valores impares e negativos
---------------------------------------------------------------------------------------------------
*/

void method_02(void)
{
    // Identificacao
    IO_start("Metodo 02");

    // Declaracao de Variaveis
    int array[MAX];
    char *filename="ED08_method02.txt";

    // chamada do metodo
    gravarParesPositivos(filename, array);
    
    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO gerarInt
---------------------------------------------------------------------------------------------------
*/

void gerarInt(int limiteInferior, int limiteSuperior)
{
    // Declaracao de variaveis
    int quantidade=0;
    int i=0;
    int numero=0;
    char nome[]="gerarInt.txt";
    FILE *arq=fopen(nome, "wt");

    // Leitura da quantidade de numeros randomicos
    quantidade=IO_readint("\nDigite a quantidade de numeros randomicos: ");

    fprintf(arq, "%d\n\n", quantidade);

    srand(time(NULL));

    for(i=0; i<quantidade; i=i+1)
    {
        numero=rand() % 100;
        if(numero>=limiteInferior && numero<=limiteSuperior)
        {
            fprintf(arq, "%d\n", numero);
            printf("%d\n", numero);
        }
        else
        {
            i=i-1;
        }
    }
    fclose(arq);
}

/*
---------------------------------------------------------------------------------------------------
METODO 03
- Delimitar dois intervalos abertos, limite inferior e superior e passar para outra função
- Gerar um número aleatório DENTRO desse intervalo 
- Ler a quantidade de numeros randômicos a serem gerados e amarzena-los em um array
- Passar o array linha a linha para dentro de um arquivo, sendo o primeiro elemento dentro do arquivo 
a quantidade de numeros
---------------------------------------------------------------------------------------------------
*/

void method_03(void)
{
    // Identificacao
    IO_start("Metodo 03");

    // Declaracao de variaveis
    int limiteInferior=0;
    int limiteSuperior=0;

    // Leitura dos limites
    limiteInferior=IO_readint("\nDigite o limite inferior: ");
    limiteSuperior=IO_readint("\nDigite o limite superior: ");

    // Passagem de parametros para a funcao
    gerarInt(limiteInferior,limiteSuperior);

    // Encerramento
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO lerArquivo
---------------------------------------------------------------------------------------------------
*/

void lerArquivo(char *filename,int *array)
{
    // Identificacao
    IO_start("Metodo lerArquivo");

    // Declarar variaveis
    FILE *arq=fopen(filename, "r");
    int leitor=0;
    int i=0;

    do
    {
        fscanf(arq, "%d", &array[i]);
        i=i+1;
    } while (i<100);

    for(i=0; i<100; i=i+1)
    {
        printf("%d\n",array[i]);
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO arranjo
---------------------------------------------------------------------------------------------------
*/

int acharMenorPar(char *filename, int *array)
{
    // Identificacao
    IO_start("Metodo arrajo");

    // Declaracao de variaveis
    int menor=0;
    int maior=0;
    int temp=0;
    FILE *arq=fopen(filename, "r");
    
    return (menor);
}

/*
---------------------------------------------------------------------------------------------------
METODO 04
- Criar uma funcao lerArquivo e acharMenorPar e aplicar respectivamente sobre, arranjo e menor
---------------------------------------------------------------------------------------------------
*/

void method_04(void)
{
    // Identificacao
    IO_start("Metodo 04");

    // Declaracao de variaveis
    int array[MAX];
    char *filename="method0804.txt";
    FILE *arq=fopen(filename, "r"); // O menor valor par da lista e' -932
    int menor=0;
    int i=0;

    // Chamar a funcao
    lerArquivo(filename, array);
    menor=acharMenorPar(filename, array);

    // Encerramento
    IO_end();
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
    IO_start("Metodo 05");

    // Encerramento
    IO_end();
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
    IO_start("Metodo 06");

    // Encerramento
    IO_end();
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
    IO_start("Metodo 07");

    // Encerramento
    IO_end();
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
    IO_start("Metodo 08");

    // Encerramento
    IO_end();
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
    IO_start("Metodo 09");

    // Encerramento
    IO_end();
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
    IO_start("Metodo 10");

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
    IO_start("Metodo 11");

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
    IO_start("\nMetodo 12\n");

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
