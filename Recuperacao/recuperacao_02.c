/*
AEDS 1
0870863_Gabriel_Matos_Nogueira
*/

/*
 * ----------------------------------------
 * BIBLIOTECAS / DEPENDÊNCIAS
 * ----------------------------------------
 * <stdio.h>    - Funções de entrada e saída (printf, fprintf, fopen, etc.)
 * <stdlib.h>   - Funções utilitárias (rand, srand, malloc, free, etc.)
 * <time.h>     - Manipulação de tempo (time, para semente de aleatoriedade)
 * "io.h"       - Biblioteca personalizada com funções auxiliares (IO_println, IO_readint, etc.)
 */

#include "io.h"

void metodo01(void)
{

}

/**
 * @brief Função principal do programa.
 *
 * Exibe um menu de opções para o usuário, lê a escolha e executa
 * o método correspondente com base na opção selecionada.
 *
 * @return int Código de término do programa (0 para sucesso).
 */

int main(void)
{
    int opcao=0;

    do
    {
        IO_Recuperation_Methods();
        opcao=IO_readint("\nDigite a opcao desejada: ");

        switch (opcao)
        {
        case 1:
            metodo01();
            break;
        
        default:
            break;
        }


    } while (opcao!=0);

    return 0;
} //end int main()
