/*
0870863_Gabriel_Matos_Nogueira
ED14
*/

/*
DEPENDENCIAS/BIBLIOTECAS
*/
#include "io.hpp"
#include "ED14.hpp"

/*
METODO 

Metodo para 

@param void
@return void
*/
void metodo01(void)
{

}

/*
METODO 

Metodo para 

@param void
@return void
*/
void metodo02(void)
{

}

/*
METODO 

Metodo para 

@param void
@return void
*/
void metodo03(void)
{

}

/*
METODO 

Metodo para 

@param void
@return void
*/
void metodo04(void)
{

}

/*
METODO 

Metodo para 

@param void
@return void
*/
void metodo05(void)
{

}

/*
METODO 

Metodo para 

@param void
@return void
*/
void metodo06(void)
{

}

/*
METODO 

Metodo para 

@param void
@return void
*/
void metodo07(void)
{

}

/*
METODO 

Metodo para 

@param void
@return void
*/
void metodo08(void)
{

}

/*
METODO 

Metodo para 

@param void
@return void
*/
void metodo09(void)
{

}

/*
METODO 

Metodo para 

@param void
@return void
*/
void metodo10(void)
{

}

/*
METODO 

Metodo para 

@param void
@return void
*/
void metodo_014E1(void)
{

}

/*
METODO 

Metodo para 

@param void
@return void
*/
void metodo_014E2(void)
{

}

/*
FUNCAO PRINCIPAL

Menu de opcoes para que o usuario possa escolher o metodo a ser utilizado

@param void
@return 0 (padrao)
*/
int main(void)
{
    int opcao = 0;
    do
    {
        IO_methods(14);
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
            metodo_014E1();
            break;

        case 12:
            metodo_014E2();
            break;
        }

    } while (opcao != 0);

    return 0;
}
