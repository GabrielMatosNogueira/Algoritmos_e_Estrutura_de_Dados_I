/*
AEDS 1 - Atividade de Programacao
0870863_Gabriel_Matos_Nogueira
*/

/*
 * ----------------------------------------
 * BIBLIOTECAS / DEPENDÊNCIAS
 * ----------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * ----------------------------------------
 * DEFINICOES GLOBAIS
 * ----------------------------------------
 */
#define MAX_STRING 256
#define MAX_DIM 10

typedef struct
{
    int a;
    int b;
    int c;
} EstruturaY;

/*
 * ----------------------------------------
 * PROTÓTIPOS DAS FUNÇÕES (MÉTODOS)
 * ----------------------------------------
 */
void metodo01(void);
void metodo02(void);
void metodo03(void);
void metodo04(void);
void metodo05(void);
void metodo06(void);
void metodo07(void);
void metodo08(void);

/*
 * ----------------------------------------
 * PROGRAMA PRINCIPAL
 * ----------------------------------------
 */
int main(void)
{
    // Variaveis
    int opcao = 0;

    // Laco do menu
    do
    {
        printf("\n\n--- MENU DE OPCOES ---\n");
        printf("1) Metodo 01 - Inverter Palavra\n");
        printf("2) Metodo 02 - Copiar Arranjo\n");
        printf("3) Metodo 03 - Trocar Linhas de Matriz\n");
        printf("4) Metodo 04 - Modificar Arranjo com Recursao\n");
        printf("5) Metodo 05 - Ordenar Struct\n");
        printf("6) Metodo 06 - Remover Espacos\n");
        printf("7) Metodo 07 - Matriz Triangular Inferior\n");
        printf("8) Metodo 08 - Desenhar Padrao\n");
        printf("0) Sair\n");

        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
            case 1:  metodo01(); break;
            case 2:  metodo02(); break;
            case 3:  metodo03(); break;
            case 4:  metodo04(); break;
            case 5:  metodo05(); break;
            case 6:  metodo06(); break;
            case 7:  metodo07(); break;
            case 8:  metodo08(); break;
            case 0:  break; // Sair
            default: printf("ERRO: Opcao invalida.\n"); break;
        }
    } while (opcao != 0);

    printf("\nEncerrando o programa.\n");
    return 0;
} // end main()

/*
 * ----------------------------------------
 * IMPLEMENTAÇÃO DOS MÉTODOS
 * ----------------------------------------
 */

/**
 * Metodo 01 - Inverte a primeira palavra de uma string.
 */
void metodo01(void)
{
    // Variaveis
    char resultado[50] = {0};
    char *string_original = " abacate maduro barato";
    int i = 0;
    int inicio = 0;
    int fim = 0;
    int tamanho = 0;

    printf("\n");

    while (string_original[inicio] == ' ')
    {
        inicio = inicio + 1;
    }
    fim = inicio;
    while (string_original[fim] != '\0' && string_original[fim] != ' ')
    {
        fim = fim + 1;
    }

    tamanho = fim - inicio;
    for (i = 0; i < tamanho; i = i + 1)
    {
        resultado[i] = string_original[fim - 1 - i];
    }
    resultado[tamanho] = '\0';

    printf("Original: \"%s\"\n", string_original);
    printf("Invertida: \"%s\"\n", resultado);

    printf("\nAperte ENTER para continuar.\n");
    getchar();
}

/**
 * Metodo 02 - Copia um sub-arranjo.
 */
void metodo02(void)
{
    // Variaveis
    int origem[] = {2, 5, 3, 6, 1, 7, 4};
    int destino[10] = {0};
    int i = 0;
    int cont = 0;

    printf("\n");

    for (i = 2; i <= 5; i = i + 1)
    {
        destino[cont] = origem[i];
        cont = cont + 1;
    }

    printf("Sub-arranjo copiado: {");
    for (i = 0; i < cont; i = i + 1)
    {
        printf("%d", destino[i]);
        if (i < cont - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");

    printf("\nAperte ENTER para continuar.\n");
    getchar();
}

/**
 * Metodo 03 - Troca duas linhas de uma matriz.
 */
void metodo03(void)
{
    // Variaveis
    int matriz[MAX_DIM][MAX_DIM] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int i = 0;
    int j = 0;
    int temp = 0;
    int linha1 = 0;
    int linha2 = 2;
    int colunas = 3;

    printf("\n");

    printf("Matriz original:\n");
    for (i = 0; i < 3; i = i + 1)
    {
        for (j = 0; j < 3; j = j + 1)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    for (j = 0; j < colunas; j = j + 1)
    {
        temp = matriz[linha1][j];
        matriz[linha1][j] = matriz[linha2][j];
        matriz[linha2][j] = temp;
    }

    printf("\nMatriz com linhas trocadas:\n");
    for (i = 0; i < 3; i = i + 1)
    {
        for (j = 0; j < 3; j = j + 1)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nAperte ENTER para continuar.\n");
    getchar();
}

void aux_metodo04(int inicio, int fim, int arranjo[])
{
    if (inicio < fim - 1)
    {
        arranjo[inicio] = arranjo[inicio] + arranjo[fim];
        aux_metodo04((inicio + fim) / 2, fim, arranjo);
    }
    else
    {
        arranjo[inicio] = 0;
    }
}

/**
 * Metodo 04 - Modifica um arranjo de forma recursiva.
 */
void metodo04(void)
{
    // Variaveis
    int arranjo[] = {1, 2, 3, 4, 5, 6, 7};
    int i = 0;

    printf("\n");
    printf("Arranjo antes: {1, 2, 3, 4, 5, 6, 7}\n");
    aux_metodo04(0, 6, arranjo);

    printf("Arranjo depois: {");
    for (i = 0; i < 7; i = i + 1)
    {
        printf("%d", arranjo[i]);
        if (i < 6)
        {
            printf(", ");
        }
    }
    printf("}\n");

    printf("\nAperte ENTER para continuar.\n");
    getchar();
}

/**
 * Metodo 05 - Ordena os membros de uma struct.
 */
void metodo05(void)
{
    // Variaveis
    EstruturaY dados = {5, 10, 2};
    int temp = 0;

    printf("\n");
    printf("Struct antes: {a:%d, b:%d, c:%d}\n", dados.a, dados.b, dados.c);

    if (dados.a < dados.b) { temp = dados.a; dados.a = dados.b; dados.b = temp; }
    if (dados.b < dados.c) { temp = dados.b; dados.b = dados.c; dados.c = temp; }
    if (dados.a < dados.b) { temp = dados.a; dados.a = dados.b; dados.b = temp; }

    printf("Struct depois: {a:%d, b:%d, c:%d}\n", dados.a, dados.b, dados.c);

    printf("\nAperte ENTER para continuar.\n");
    getchar();
}

/**
 * Metodo 06 - Remove espacos em branco duplicados.
 */
void metodo06(void)
{
    // Variaveis
    char texto[MAX_STRING] = {0};
    int i = 0;
    int j = 0;

    printf("\n");
    printf("Digite uma string com espacos extras: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = 0;

    while (texto[i] != '\0')
    {
        texto[j] = texto[i];
        j = j + 1;
        if (texto[i] == ' ')
        {
            while (texto[i + 1] == ' ')
            {
                i = i + 1;
            }
        }
        i = i + 1;
    }
    texto[j] = '\0';

    printf("String corrigida: \"%s\"\n", texto);
    printf("\nAperte ENTER para continuar.\n");
    getchar();
}

/**
 * Metodo 07 - Gera matriz triangular inferior.
 */
void metodo07(void)
{
    // Variaveis
    int matriz[MAX_DIM][MAX_DIM] = {0};
    int tamanho = 0;
    int i = 0;
    int j = 0;

    printf("\n");
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tamanho);
    getchar();

    if (tamanho > 0 && tamanho <= MAX_DIM)
    {
        for (i = 0; i < tamanho; i = i + 1)
        {
            for (j = 0; j < tamanho; j = j + 1)
            {
                printf("Elemento [%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);
                getchar();
            }
        }
        printf("\nMatriz Triangular Inferior:\n");
        for (i = 0; i < tamanho; i = i + 1)
        {
            for (j = 0; j < tamanho; j = j + 1)
            {
                if (j > i)
                {
                    printf("0\t");
                }
                else
                {
                    printf("%d\t", matriz[i][j]);
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("ERRO: Tamanho invalido.\n");
    }

    printf("\nAperte ENTER para continuar.\n");
    getchar();
}

/**
 * Metodo 08 - Desenha um padrao de asteriscos.
 */
void metodo08(void)
{
    // Variaveis
    int n = 0;
    int i = 0;
    int j = 0;

    printf("\n");
    printf("Digite o numero base para o padrao: ");
    scanf("%d", &n);
    gerchar();

    if (n > 3)
    {
        i = 1;
        while (i < n)
        {
            j = 0;
            while (j < i)
            {
                printf("*");
                j = j + 1;
            }
            printf("\n");
            i = i + 1;
        }
        i = n - 2;
        while (i >= 1)
        {
            j = 0;
            while (j < i)
            {
                printf("*");
                j = j + 1;
            }
            printf("\n");
            i = i - 1;
        }
    }
    else
    {
        printf("ERRO: Numero deve ser maior que 3.\n");
    }
    
    printf("\nAperte ENTER para continuar.\n");
    getchar();
}
