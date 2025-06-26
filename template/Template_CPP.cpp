/*
0870863_Gabriel_Matos_Nogueira
ED
*/

/*
DEPENDENCIAS/BIBLIOTECAS
*/
#include "io.hpp"
using namespace std;

// Declaracao de funcoes

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
}

/**
 * AUXILIAR 02
 * @brief
 * 
 * 
 * 
 * @param
 * @return
**/
void auxiliar_02(void)
{
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
}

/**
 * AUXILIAR 03
 * @brief
 * 
 * 
 * 
 * @param
 * @return
**/
void auxiliar_03(void)
{
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
 * AUXILIAR 04
 * @brief
 * 
 * 
 * 
 * @param
 * @return
**/
void auxiliar_04(void)
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
 * AUXILIAR 05
 * @brief
 * 
 * 
 * 
 * @param
 * @return
**/
void auxiliar_05(void)
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
            IO_methods(0);
            opcao = IO_readint("\nDigite a opcao desejada: ");

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

        return 0;
    }
} // end main ( )
