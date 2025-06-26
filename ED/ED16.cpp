/*
0870863_Gabriel_Matos_Nogueira
ED
*/

/*
DEPENDENCIAS/BIBLIOTECAS
*/
#include "io.hpp"
#include "ED16.hpp"
using namespace std;

/**
 * AUXILIAR 01
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void auxiliar_01(void)
{
}

/**
 * METODO 01
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void metodo01(void)
{
    IO_println("METODO 01 - PUSH BACK");

    // Cria um ponteiro para um novo objeto ED16
    ED16 *ED16_metodo01 = new ED16();
    int i=0;
    int valor = 0;
    int opcao = 0;
    do
    {
        // Valor da matriz original
        ED16_metodo01->print_Array();
        valor = IO_readint("Digite o valor que deseja inserir no fim da fila: ");
        getchar();

        ED16_metodo01->ED16_array_push_back(valor);

        // Imprimindo para ver o resultado
        ED16_metodo01->print_Array();
        i=i+1;
    } while ();
    
    IO_print("Aperte ENTER para terminar.");
    getchar();
}

/**
 * METODO 02
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void metodo02(void)
{
    ED16 *ED16_metodo02 = new ED16();
    IO_println("METODO 02 - POP BACK");
    int valor = 0;
    int opcao = 0;
    do
    {
        // Valor da matriz original
        ED16_metodo02->print_Array();
        valor = IO_readint("Digite o valor que deseja inserir no fim da fila: ");

        ED16_metodo02->ED16_array_push_back(valor);

        // Imprimindo para ver o resultado
        ED16_metodo02->print_Array();
        opcao = IO_readint("Deseja continuar? (1 - Sim , 0 - Nao): ");
    
    } while (opcao != 0);


    cout<<endl;
    IO_println("POP BACK");

    do
    {
        // Valor da matriz original
        ED16_metodo02->print_Array();

        ED16_metodo02->ED16_pop_back(valor);

        // Imprimindo para ver o resultado
        ED16_metodo02->print_Array();
        opcao = IO_readint("Deseja continuar removendo valores no fim da fila? (1 - Sim , 0 - Nao): ");
    } while (opcao != 0);
}

/**
 * METODO 03
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void metodo03(void)
{
}

/**
 * METODO 04
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void metodo04(void)
{
}

/**
 * METODO 05
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void metodo05(void)
{
}

/**
 * AUXILIAR 06
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void auxiliar_06(void)
{
}

/**
 * METODO 06
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void metodo06(void)
{
}

/**
 * AUXILIAR 07
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void auxiliar_07(void)
{
}

/**
 * METODO 07
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void metodo07(void)
{
}

/**
 * AUXILIAR 08
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void auxiliar_08(void)
{
}

/**
 * METODO 08
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void metodo08(void)
{
}

/**
 * AUXILIAR 09
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void auxiliar_09(void)
{
}

/**
 * METODO 09
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void metodo09(void)
{
}

/**
 * AUXILIAR 10
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void auxiliar_10(void)
{
}

/**
 * METODO 10
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void metodo10(void)
{
}

/**
 * AUXILIAR XXE2
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void auxiliar_11(void)
{
}

/**
 * METODO 015E1
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void metodo_16E1(void)
{
}

/**
 * AUXILIAR XXE2
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void auxiliar_12(void)
{
}

/**
 * METODO 015E2
 * @brief
 *
 *
 *
 * @param
 * @return
 **/
void metodo_16E2(void)
{
}

/**
 * METODO PRINCIPAL
 * @brief
 *
 * @param
 * @return
 */
int main(void)
{
    {
        int opcao = 0;
        do
        {
            IO_methods(16);
            opcao = IO_readint("\nDigite a opcao desejada: ");
            getchar();

            switch (opcao)
            {
            case 0:
                break;
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

            case 11:
                metodo_16E1();
                break;

            case 12:
                metodo_16E2();
                break;
            }
        } while (opcao != 0);
    }
    return 0;
} // end main ( )
