/*
Nome do Programa:   ED09
Data:               11/05/2025
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
    Windows:    gcc -o ED09 ED09.c -lm
    Linux:      gcc -o ED09 ED09.c -lm
    macOS:      gcc -o ED09 ED09.c -lm


    2.2 - Execute o programa
    Windows:     ED09
    Linux:      ./ED09
    macOS:      ./ED09

---------------------------------------------------------------------------------------------------
*/

// Declaracao de biblioteca(s)
#include "io.h"

// Declaracao dos metodos utilizados
void metodo_0000();
void metodo_0911();
void metodo_0912();
void metodo_0913();
void metodo_0914();
void metodo_0915();
void metodo_0916();
void metodo_0917();
void metodo_0918();
void metodo_0919();
void metodo_0920();
void metodo_09E1();
void metodo_09E2();

// Funcoes auxiliares para matrizes
void readPositiveDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas]);
void printDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas]);
void fprintDoubleMatrix(char paramNomeArquivo[], int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas]);
void freadDoubleMatrix(char paramNomeArquivo[], int paramLinhasEsperadas, int paramColunasEsperadas, double paramMatriz[paramLinhasEsperadas][paramColunasEsperadas]);
void printDiagonalDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas]);
void printSDiagonalDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas]);
void printLDTriangleDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas]);
void printLUTriangleDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas]);
void printSLDTriangleDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas]);
void printSLUTriangleDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas]);
bool allZerosLTriangleDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas]);
bool allNonZeroUTriangleDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas]);


// Funcao Principal
int main(void)
{
    int opcao = 0;
    IO_id("\n\nED09");
    IO_print("\n\tOpcoes de Metodos:");

    // Menu de opcoes do usuario
    do
    {
        IO_print("\n0 - Parar");
        IO_print("\n1 - Metodo 0911 (Ler e Mostrar Matriz Positiva)");
        IO_print("\n2 - Metodo 0912 (Gravar e Ler Matriz de Arquivo)");
        IO_print("\n3 - Metodo 0913 (Diagonal Principal)");
        IO_print("\n4 - Metodo 0914 (Diagonal Secundaria)");
        IO_print("\n5 - Metodo 0915 (Abaixo da Diagonal Principal)");
        IO_print("\n6 - Metodo 0916 (Acima da Diagonal Principal)");
        IO_print("\n7 - Metodo 0917 (Abaixo e Na Diagonal Secundaria)");
        IO_print("\n8 - Metodo 0918 (Acima e Na Diagonal Secundaria)");
        IO_print("\n9 - Metodo 0919 (Testar Zeros Abaixo Diag. Principal)");
        IO_print("\n10 - Metodo 0920 (Testar Nao Zeros Acima Diag. Principal)");
        IO_print("\n11 - Metodo 09E1 (Gerar Matriz Padrao 1 e Gravar)");
        IO_print("\n12 - Metodo 09E2 (Gerar Matriz Padrao 2 e Gravar)");

        opcao = IO_readint("\nDigite uma opcao: ");
        switch (opcao)
        {
        case 0:
            metodo_0000();
            break;
        case 1:
            metodo_0911();
            break;
        case 2:
            metodo_0912();
            break;
        case 3:
            metodo_0913();
            break;
        case 4:
            metodo_0914();
            break;
        case 5:
            metodo_0915();
            break;
        case 6:
            metodo_0916();
            break;
        case 7:
            metodo_0917();
            break;
        case 8:
            metodo_0918();
            break;
        case 9:
            metodo_0919();
            break;
        case 10:
            metodo_0920();
            break;
        case 11:
            metodo_09E1();
            break;
        case 12:
            metodo_09E2();
            break;
        default:
            IO_println("Opcao invalida. Tente novamente.");
            break;
        }
    } while (opcao != 0);
    return 0;
}

// Funcoes do programa

/*
---------------------------------------------------------------------------------------------------
METODO 00
- Encerramento do programa
---------------------------------------------------------------------------------------------------
*/
void metodo_0000(void)
{
    IO_start("Metodo 00");
    IO_print("ENCERRANDO O PROGRAMA...\n");
}

/*
---------------------------------------------------------------------------------------------------
Funcao readPositiveDoubleMatrix
- 
---------------------------------------------------------------------------------------------------
*/
void readPositiveDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas])
{
    int i = 0;
    int j = 0;
    char solicitacao[STR_SIZE]; 
    double valorElemento;       

    IO_println("\nDigite os elementos da matriz:");
    for (i = 0; i < paramLinhas; i = i + 1)
    {
        for (j = 0; j < paramColunas; j = j + 1)
        {
            valorElemento = -1.0;
            sprintf(solicitacao, "Elemento [%d][%d]: ", i, j);
            do
            {
                valorElemento = IO_readdouble(solicitacao);
                if (valorElemento < 0.0)
                {
                    IO_println("Valor invalido. Digite um valor positivo ou zero.");
                }
            } while (valorElemento < 0.0);
            paramMatriz[i][j] = valorElemento;
        }
    }
}

/*
---------------------------------------------------------------------------------------------------
Funcao printDoubleMatrix
- 
---------------------------------------------------------------------------------------------------
*/
void printDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas])
{
    int i = 0;
    int j = 0;

    IO_println("\nMatriz:");
    for (i = 0; i < paramLinhas; i = i + 1)
    {
        for (j = 0; j < paramColunas; j = j + 1)
        {
            printf("%.2lf\t", paramMatriz[i][j]);
        }
        printf("\n");
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO 0911
- 
---------------------------------------------------------------------------------------------------
*/
void metodo_0911(void)
{
    IO_start("Metodo_0911");

    int linhasMatriz = IO_readint("Digite o numero de linhas: ");    
    int colunasMatriz = IO_readint("Digite o numero de colunas: "); 

    if (linhasMatriz > 0 && colunasMatriz > 0)
    {
        double matriz[linhasMatriz][colunasMatriz]; 
        readPositiveDoubleMatrix(linhasMatriz, colunasMatriz, matriz);
        printDoubleMatrix(linhasMatriz, colunasMatriz, matriz);
    }
    else
    {
        IO_println("Erro: numero de linhas ou colunas invalido.");
    }

    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
Funcao fprintDoubleMatrix
- 
---------------------------------------------------------------------------------------------------
*/
void fprintDoubleMatrix(char paramNomeArquivo[], int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas])
{
    FILE *ponteiroArquivo = fopen(paramNomeArquivo, "wt"); 
    int i = 0;
    int j = 0;

    if (ponteiroArquivo != NULL)
    {
        fprintf(ponteiroArquivo, "%d\n", paramLinhas);
        fprintf(ponteiroArquivo, "%d\n", paramColunas);

        for (i = 0; i < paramLinhas; i = i + 1)
        {
            for (j = 0; j < paramColunas; j = j + 1)
            {
                fprintf(ponteiroArquivo, "%.2lf\n", paramMatriz[i][j]);
            }
        }
        fclose(ponteiroArquivo);
        IO_printf("Matriz gravada no arquivo %s com sucesso.\n", paramNomeArquivo);
    }
    else
    {
        IO_println("Erro ao abrir arquivo para escrita.");
    }
}

/*
---------------------------------------------------------------------------------------------------
Funcao freadDoubleMatrix
- 
---------------------------------------------------------------------------------------------------
*/
void freadDoubleMatrix(char paramNomeArquivo[], int paramLinhasEsperadas, int paramColunasEsperadas, double paramMatriz[paramLinhasEsperadas][paramColunasEsperadas])
{
    FILE *ponteiroArquivo = fopen(paramNomeArquivo, "rt"); 
    int i = 0;
    int j = 0;
    int linhasDoArquivo = 0;   
    int colunasDoArquivo = 0; 

    if (ponteiroArquivo != NULL)
    {
        fscanf(ponteiroArquivo, "%d", &linhasDoArquivo);
        getchar( );
        fscanf(ponteiroArquivo, "%d", &colunasDoArquivo);
        getchar( );

        if (linhasDoArquivo == paramLinhasEsperadas && colunasDoArquivo == paramColunasEsperadas)
        {
            for (i = 0; i < linhasDoArquivo; i = i + 1)
            {
                for (j = 0; j < colunasDoArquivo; j = j + 1)
                {
                    fscanf(ponteiroArquivo, "%lf", &paramMatriz[i][j]);
                    getchar( );
                }
            }
            IO_printf("Matriz lida do arquivo %s com sucesso.\n", paramNomeArquivo);
        }
        else
        {
            IO_printf("Erro: Dimensoes no arquivo (%dx%d) nao correspondem as esperadas (%dx%d).\n",
                      linhasDoArquivo, colunasDoArquivo, paramLinhasEsperadas, paramColunasEsperadas);
        }
        fclose(ponteiroArquivo);
    }
    else
    {
        IO_println("Erro ao abrir arquivo para leitura.");
    }
}


/*
---------------------------------------------------------------------------------------------------
METODO 0912
- 
- 
---------------------------------------------------------------------------------------------------
*/
void metodo_0912(void)
{
    IO_start("Metodo_0912");

    int linhas = IO_readint("Digite o numero de linhas para a matriz: ");
    int colunas = IO_readint("Digite o numero de colunas para a matriz: ");
    char nomeDoArquivo[] = "MATRIX_01.TXT"; 

    if (linhas > 0 && colunas > 0)
    {
        double matrizOriginal[linhas][colunas]; 
        IO_println("Leitura da matriz original:");
        readPositiveDoubleMatrix(linhas, colunas, matrizOriginal);
        fprintDoubleMatrix(nomeDoArquivo, linhas, colunas, matrizOriginal);

        double matrizLida[linhas][colunas]; 
        IO_println("\nLeitura da matriz do arquivo:");
        freadDoubleMatrix(nomeDoArquivo, linhas, colunas, matrizLida);
        printDoubleMatrix(linhas, colunas, matrizLida);
    }
    else
    {
        IO_println("Dimensoes invalidas.");
    }

    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
Funcao printDiagonalDoubleMatrix
- 
---------------------------------------------------------------------------------------------------
*/
void printDiagonalDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas])
{
    if (paramLinhas == paramColunas && paramLinhas > 0)
    {
        IO_println("\nDiagonal principal:");
        for (int i = 0; i < paramLinhas; i = i + 1)
        {
            printf("%.2lf ", paramMatriz[i][i]);
        }
        printf("\n");
    }
    else
    {
        IO_println("Matriz nao e quadrada ou tem dimensoes invalidas para esta operacao.");
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO 0913
- 
---------------------------------------------------------------------------------------------------
*/
void metodo_0913(void)
{
    IO_start("Metodo_0913");

    int linhas = IO_readint("Digite o numero de linhas: ");
    int colunas = IO_readint("Digite o numero de colunas: ");

    if (linhas > 0 && colunas > 0)
    {
        double matriz[linhas][colunas];
        readPositiveDoubleMatrix(linhas, colunas, matriz);
        printDoubleMatrix(linhas, colunas, matriz);
        printDiagonalDoubleMatrix(linhas, colunas, matriz);
    }
    else
    {
        IO_println("Dimensoes invalidas.");
    }
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
Funcao printSDiagonalDoubleMatrix
- 
---------------------------------------------------------------------------------------------------
*/
void printSDiagonalDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas])
{
    if (paramLinhas == paramColunas && paramLinhas > 0)
    {
        IO_println("\nDiagonal secundaria:");
        for (int i = 0; i < paramLinhas; i = i + 1)
        {
            printf("%.2lf ", paramMatriz[i][paramColunas - 1 - i]);
        }
        printf("\n");
    }
    else
    {
        IO_println("Matriz nao e quadrada ou tem dimensoes invalidas para esta operacao.");
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO 0914
- 
---------------------------------------------------------------------------------------------------
*/
void metodo_0914(void)
{
    IO_start("Metodo_0914");
    int linhas = IO_readint("Digite o numero de linhas: ");
    int colunas = IO_readint("Digite o numero de colunas: ");

    if (linhas > 0 && colunas > 0)
    {
        double matriz[linhas][colunas];
        readPositiveDoubleMatrix(linhas, colunas, matriz);
        printDoubleMatrix(linhas, colunas, matriz);
        printSDiagonalDoubleMatrix(linhas, colunas, matriz);
    }
    else
    {
        IO_println("Dimensoes invalidas.");
    }
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
Funcao printLDTriangleDoubleMatrix
- 
---------------------------------------------------------------------------------------------------
*/
void printLDTriangleDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas])
{
    if (paramLinhas == paramColunas && paramLinhas > 0)
    {
        IO_println("\nValores abaixo da diagonal principal:");
        for (int i = 0; i < paramLinhas; i = i + 1)
        {
            for (int j = 0; j < paramColunas; j = j + 1)
            {
                if (i > j)
                {
                    printf("%.2lf\t", paramMatriz[i][j]);
                }
                else
                {
                    printf(" \t"); 
                }
            }
            printf("\n");
        }
    }
    else
    {
        IO_println("Matriz nao e quadrada ou tem dimensoes invalidas para esta operacao.");
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO 0915
- 
---------------------------------------------------------------------------------------------------
*/
void metodo_0915(void)
{
    IO_start("Metodo_0915");
    int linhas = IO_readint("Digite o numero de linhas: ");
    int colunas = IO_readint("Digite o numero de colunas: ");

    if (linhas > 0 && colunas > 0)
    {
        double matriz[linhas][colunas];
        readPositiveDoubleMatrix(linhas, colunas, matriz);
        printDoubleMatrix(linhas, colunas, matriz);
        printLDTriangleDoubleMatrix(linhas, colunas, matriz);
    }
    else
    {
        IO_println("Dimensoes invalidas.");
    }
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
Funcao printLUTriangleDoubleMatrix
- 
---------------------------------------------------------------------------------------------------
*/
void printLUTriangleDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas])
{
     if (paramLinhas == paramColunas && paramLinhas > 0)
    {
        IO_println("\nValores acima da diagonal principal:");
        for (int i = 0; i < paramLinhas; i = i + 1)
        {
            for (int j = 0; j < paramColunas; j = j + 1)
            {
                if (i < j)
                {
                    printf("%.2lf\t", paramMatriz[i][j]);
                }
                else
                {
                    printf(" \t");
                }
            }
            printf("\n");
        }
    }
    else
    {
        IO_println("Matriz nao e quadrada ou tem dimensoes invalidas para esta operacao.");
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO 0916
- 
---------------------------------------------------------------------------------------------------
*/
void metodo_0916(void)
{
    IO_start("Metodo_0916");
    int linhas = IO_readint("Digite o numero de linhas: ");
    int colunas = IO_readint("Digite o numero de colunas: ");

    if (linhas > 0 && colunas > 0)
    {
        double matriz[linhas][colunas];
        readPositiveDoubleMatrix(linhas, colunas, matriz);
        printDoubleMatrix(linhas, colunas, matriz);
        printLUTriangleDoubleMatrix(linhas, colunas, matriz);
    }
    else
    {
        IO_println("Dimensoes invalidas.");
    }
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
Funcao printSLDTriangleDoubleMatrix
- 
---------------------------------------------------------------------------------------------------
*/
void printSLDTriangleDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas])
{
    if (paramLinhas == paramColunas && paramLinhas > 0)
    {
        IO_println("\nValores abaixo e na diagonal secundaria:");
        for (int i = 0; i < paramLinhas; i = i + 1)
        {
            for (int j = 0; j < paramColunas; j = j + 1)
            {
                if (i + j >= paramLinhas - 1) 
                {
                    printf("%.2lf\t", paramMatriz[i][j]);
                }
                else
                {
                    printf(" \t");
                }
            }
            printf("\n");
        }
    }
    else
    {
        IO_println("Matriz nao e quadrada ou tem dimensoes invalidas para esta operacao.");
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO 0917
- 
---------------------------------------------------------------------------------------------------
*/
void metodo_0917(void)
{
    IO_start("Metodo_0917");
    int linhas = IO_readint("Digite o numero de linhas: ");
    int colunas = IO_readint("Digite o numero de colunas: ");

    if (linhas > 0 && colunas > 0)
    {
        double matriz[linhas][colunas];
        readPositiveDoubleMatrix(linhas, colunas, matriz);
        printDoubleMatrix(linhas, colunas, matriz);
        printSLDTriangleDoubleMatrix(linhas, colunas, matriz);
    }
    else
    {
        IO_println("Dimensoes invalidas.");
    }
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
Funcao printSLUTriangleDoubleMatrix
- 
---------------------------------------------------------------------------------------------------
*/
void printSLUTriangleDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas])
{
    if (paramLinhas == paramColunas && paramLinhas > 0)
    {
        IO_println("\nValores acima e na diagonal secundaria:");
        for (int i = 0; i < paramLinhas; i = i + 1)
        {
            for (int j = 0; j < paramColunas; j = j + 1)
            {
                if (i + j <= paramLinhas - 1) 
                {
                    printf("%.2lf\t", paramMatriz[i][j]);
                }
                else
                {
                    printf(" \t");
                }
            }
            printf("\n");
        }
    }
    else
    {
        IO_println("Matriz nao e quadrada ou tem dimensoes invalidas para esta operacao.");
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO 0918
- 
---------------------------------------------------------------------------------------------------
*/
void metodo_0918(void)
{
    IO_start("Metodo_0918");
    int linhas = IO_readint("Digite o numero de linhas: ");
    int colunas = IO_readint("Digite o numero de colunas: ");

    if (linhas > 0 && colunas > 0)
    {
        double matriz[linhas][colunas];
        readPositiveDoubleMatrix(linhas, colunas, matriz);
        printDoubleMatrix(linhas, colunas, matriz);
        printSLUTriangleDoubleMatrix(linhas, colunas, matriz);
    }
    else
    {
        IO_println("Dimensoes invalidas.");
    }
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
Funcao allZerosLTriangleDoubleMatrix
- 
---------------------------------------------------------------------------------------------------
*/
bool allZerosLTriangleDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas])
{
    bool resultado = true; 
    if (paramLinhas == paramColunas && paramLinhas > 0)
    {
        for (int i = 0; i < paramLinhas; i = i + 1)
        {
            for (int j = 0; j < paramColunas; j = j + 1)
            {
                if (i > j) 
                {
                    if (paramMatriz[i][j] != 0.0)
                    {
                        resultado = false; 
                        break;          
                    }
                }
            }
            if (!resultado)
            {
                break; 
            }
        }
    }
    else
    {
        IO_println("Matriz nao e quadrada ou tem dimensoes invalidas para esta operacao.");
        return false; 
    }
    return resultado;
}

/*
---------------------------------------------------------------------------------------------------
METODO 0919
- 
---------------------------------------------------------------------------------------------------
*/
void metodo_0919(void)
{
    IO_start("Metodo_0919");
    int linhas = IO_readint("Digite o numero de linhas: ");
    int colunas = IO_readint("Digite o numero de colunas: ");

    if (linhas > 0 && colunas > 0)
    {
        if (linhas != colunas) {
            IO_println("A matriz precisa ser quadrada para esta operacao.");
        } else {
            double matriz[linhas][colunas];
            readPositiveDoubleMatrix(linhas, colunas, matriz);
            printDoubleMatrix(linhas, colunas, matriz);
            bool todosSaoZeros = allZerosLTriangleDoubleMatrix(linhas, colunas, matriz); 
            if (todosSaoZeros)
            {
                IO_println("Todos os valores abaixo da diagonal principal SAO zeros.");
            }
            else
            {
                IO_println("Nem todos os valores abaixo da diagonal principal sao zeros (ou a matriz nao e' valida).");
            }
        }
    }
    else
    {
        IO_println("Dimensoes invalidas.");
    }
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
Funcao allNonZeroUTriangleDoubleMatrix
- 
---------------------------------------------------------------------------------------------------
*/
bool allNonZeroUTriangleDoubleMatrix(int paramLinhas, int paramColunas, double paramMatriz[paramLinhas][paramColunas])
{
    bool resultado = true; 
    if (paramLinhas == paramColunas && paramLinhas > 0)
    {
        for (int i = 0; i < paramLinhas; i = i + 1)
        {
            for (int j = 0; j < paramColunas; j = j + 1)
            {
                if (i < j) 
                {
                    if (paramMatriz[i][j] == 0.0)
                    {
                        resultado = false; 
                        break;
                    }
                }
            }
            if (!resultado)
            {
                break;
            }
        }
    }
    else
    {
        IO_println("Matriz nao e quadrada ou tem dimensoes invalidas para esta operacao.");
        return false;
    }
    return resultado;
}

/*
---------------------------------------------------------------------------------------------------
METODO 0920
-
---------------------------------------------------------------------------------------------------
*/
void metodo_0920(void)
{
    IO_start("Metodo_0920");
    int linhas = IO_readint("Digite o numero de linhas: ");
    int colunas = IO_readint("Digite o numero de colunas: ");

    if (linhas > 0 && colunas > 0)
    {
         if (linhas != colunas) {
            IO_println("A matriz precisa ser quadrada para esta operacao.");
        } else {
            double matriz[linhas][colunas];
            readPositiveDoubleMatrix(linhas, colunas, matriz);
            printDoubleMatrix(linhas, colunas, matriz);
            bool todosSaoNaoZeros = allNonZeroUTriangleDoubleMatrix(linhas, colunas, matriz); 
            if (todosSaoNaoZeros)
            {
                IO_println("Todos os valores acima da diagonal principal NAO SAO zeros.");
            }
            else
            {
                IO_println("Pelo menos um valor acima da diagonal principal e zero (ou a matriz nao e' valida).");
            }
        }
    }
    else
    {
        IO_println("Dimensoes invalidas.");
    }
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO 09E1
- 
---------------------------------------------------------------------------------------------------
*/
void metodo_09E1(void)
{
    IO_start("Metodo_09E1");
    int linhas = IO_readint("Digite o numero de linhas: ");
    int colunas = IO_readint("Digite o numero de colunas: ");
    char nomeDoArquivo[] = "DADOS_E1.TXT"; 

    if (linhas > 0 && colunas > 0)
    {
        double matriz[linhas][colunas];
        for (int j = 0; j < colunas; j = j + 1)
        {
            for (int i = 0; i < linhas; i = i + 1)
            {
                matriz[i][j] = (double)(i + 1 + (j * linhas));
            }
        }
        IO_println("\nMatriz gerada (Padrao E1):");
        printDoubleMatrix(linhas, colunas, matriz);
        fprintDoubleMatrix(nomeDoArquivo, linhas, colunas, matriz);
    }
    else
    {
        IO_println("Dimensoes invalidas.");
    }
    IO_end();
}

/*
---------------------------------------------------------------------------------------------------
METODO 09E2
- Ler do teclado as quantidades de linhas e colunas de uma matriz,
  e montar uma matriz com a característica:
  16 15 14 13
  12 11 10  9
   8  7  6  5
   4  3  2  1
  (para 4x4)
  A qual deverá ser gravada em arquivo.
---------------------------------------------------------------------------------------------------
*/
void metodo_09E2(void)
{
    IO_start("Metodo_09E2");
    int linhas = IO_readint("Digite o numero de linhas: ");
    int colunas = IO_readint("Digite o numero de colunas: ");
    char nomeDoArquivo[] = "DADOS_E2.TXT"; 

    if (linhas > 0 && colunas > 0)
    {
        double matriz[linhas][colunas];
        double valorAtual = (double)linhas * colunas; 
        for (int i = 0; i < linhas; i = i + 1)
        {
            for (int j = 0; j < colunas; j = j + 1)
            {
                matriz[i][j] = valorAtual;
                valorAtual = valorAtual - 1.0;
            }
        }
        IO_println("\nMatriz gerada (Padrao E2):");
        printDoubleMatrix(linhas, colunas, matriz);
        fprintDoubleMatrix(nomeDoArquivo, linhas, colunas, matriz);
    }
    else
    {
        IO_println("Dimensoes invalidas.");
    }
    IO_end();
}

/*-------------------------------------------------------------------------------------------------
DOCUMENTACAO
-------------------------------------------------------------------------------------------------

1.0 - DOCUMENTACAO COMPLEMENTAR

---------------------------------------------------------------------------------------------------

2.0 - TESTES

*Method_00: OK
- Sem observacoes

*Method_01: (0911)
-

*Method_02: (0912)
-

*Method_03: (0913)
-

*Method_04: (0914)
-

*Method_05: (0915)
-

*Method_06: (0916)
-

*Method_07: (0917)
-

*Method_08: (0918)
-

*Method_09: (0919)
-

*Method_10: (0920)
-

*Method_11: (09E1)
-

*Method_12: (09E2)
-
---------------------------------------------------------------------------------------------------
*/
