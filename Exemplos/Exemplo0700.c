#include "io.h"

void writeInts ( chars fileName, int x );
void readInts ( chars fileName );
void readDoubles ( chars fileName );
void readDoubles ( chars fileName );
void writeText ( chars fileName );
void method_01 ();
void method_02 ();
void method_03 ();
void method_04 ();
void method_05 ();

int main(void)
{
    //method_01();
    //method_02();
    //method_03();
    //method_04();
    method_05();
    return 0;
}

void writeInts ( chars fileName, int x )
{
// definir dados
    FILE* arquivo = fopen ( fileName, "wt" );
    int y = 0;
// repetir para a quantidade de dados
    for ( y = 1; y <= x; y = y + 1 )
    {
    // gravar valor
        fprintf ( arquivo, "%d\n", y );
    } // end for
// fechar arquivo (INDISPENSAVEL para gravacao)
    fclose ( arquivo );
} // end writeInts ( )
/**
 * Method_01 - Mostrar certa quantidade de valores.
 */
void method_01 ( )
{
// identificar
    IO_id ( "Method_01 - v0.0" );
// executar o metodo auxiliar
    writeInts ( "DADOS1.TXT", 10 );
// encerrar
    IO_pause ( "Apertar ENTER para continuar" );
}

void readInts ( chars fileName )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "rt" );
 int x = 0;
// tentar ler o primeiro
 fscanf ( arquivo, "%d", &x );
// repetir enquanto houver dados
 while ( ! feof ( arquivo ) )
 {
 // mostrar valor
 printf ( "%d\n", x );
 // tentar ler o proximo
 fscanf ( arquivo, "%d", &x );
 } // end while
// fechar arquivo (RECOMENDAVEL para leitura)
 fclose ( arquivo );
} // end readInts ( )
/**
 Method_02.
*/
void method_02 ( )
{
// identificar
 IO_id ( "Method_02 - v0.0" );
// executar o metodo auxiliar
 readInts ( "DADOS1.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( 

void writeDoubles ( chars fileName, int x )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "wt" );
 int y = 0;
// gravar quantidade de valores
 IO_fprintf ( arquivo, "%d\n", x );
// repetir para a quantidade de dados
 for ( y = 1; y <= x; y = y + 1 )
 {
 // gravar valor
 IO_fprintf ( arquivo, "%lf\n", (0.1*y) );
 } // end for
// fechar arquivo (INDISPENSAVEL para gravacao)
 fclose ( arquivo );
} // end writeDoubles ( )
/**
 Method_03.
*/
void method_03 ( )
{
// identificar
 IO_id ( "Method_03 - v0.0" );
// executar o metodo auxiliar
 writeDoubles ( "DADOS2.TXT", 10 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ()

void readDoubles ( chars fileName )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "rt" );
 int x = 0 ;
 int y = 1 ;
 double z = 0.0;
// tentar ler a quantidade de dados
 fscanf ( arquivo, "%d", &x );
// repetir enquanto houver dados e
// quantidade nao tiver sido alcancada
 while ( ! feof ( arquivo ) && y <= x )
 {
 // tentar ler
 fscanf ( arquivo, "%lf", &z );
 // mostrar valor
 printf ( "%2d: %lf\n", y, z );
 // passar ao proximo
 y = y + 1;
 } // end while
// fechar arquivo (RECOMENDAVEL para leitura)
 fclose ( arquivo );
} // end readDoubles ( )
/**
 Method_04.
*/
void method_04 ( )
{
// identificar
 IO_id ( "Method_04 - v0.0" );
// executar o metodo auxiliar
 readDoubles ( "DADOS2.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( 

void writeText ( chars fileName )
{
// definir dados
 FILE* arquivo = fopen ( fileName, "wt" );
 chars linha = IO_new_chars ( STR_SIZE );
// repetir ate' desejar parar
 IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" );
 do
 {
 // ler do teclado
 strcpy ( linha, IO_readln ( "" ) );
 // gravar valor
 IO_fprintf ( arquivo, "%s\n", linha );
 }
 while ( strcmp ( "PARAR", linha ) != 0 );
// fechar arquivo (INDISPENSAVEL para gravacao)
 fclose ( arquivo );
} // end writeText ( )
/**
 Method_05.
*/
void method_05 ( )
{
// identificar
 IO_id ( "Method_05 - v0.0" );
// executar o metodo auxiliar
 writeText ( "DADOS3.TXT" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/*
---------------------------------------------------------------------------------------------------
RESULTADOS DADOS1.TXT
Programa 01
01- Sem erros de compilação
02- Resultados dentro de DADOS1.TXT: 1 2 3 4 5 6 7 8 9 10

Programa 02
01- Sem erros de compilação
02- Resultados exibidos na tela: 1 2 3 4 5 6 7 8 9 10

Programa 03
01- Sem erros de compilação COM ERRO DE EXECUÇÃO
02- Arquivos gerados no DADOS2.TXT: 10
                                    0.100000
                                    0.200000
                                    0.300000
                                    0.400000
                                    0.500000
                                    0.600000
                                    0.700000
                                    0.800000
                                    0.900000
                                    1.000000
OBSERVACAO: Y é inteiro e está sendo operado junto á um real, entretanto, a funcao print permite este caso

Programa 04
01- Sem erros de compilação
02- Saida apos leitura do arquivo em DADOS2.TXT:1:  1: 0.100000
                                                    2: 0.200000
                                                    3: 0.300000
                                                    4: 0.400000
                                                    5: 0.500000
                                                    6: 0.600000
                                                    7: 0.700000
                                                    8: 0.800000
                                                    9: 0.900000
                                                    10: 1.000000

PROGRAMA 05
01 - Sem erros de compilação
02 - Saida apos leitura do arquivo em DADOS3.TXT:   10
                                                    9
                                                    8
                                                    7
                                                    6
                                                    5
                                                    4
                                                    3
                                                    2
                                                    1
                                                    0
                                                    -1
                                                    -2
                                                    -3
                                                    -4
                                                    -5
                                                    -6
                                                    -7
                                                    -8
                                                    -9
                                                    -10
                                                    PARAR

PROGRAMA 06
*/
