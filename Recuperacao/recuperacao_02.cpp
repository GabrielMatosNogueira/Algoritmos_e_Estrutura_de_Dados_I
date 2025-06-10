/*
AEDS1
0870863_Gabriel_Matos_Nogueira
*/

/* 
// ----------------------
DEPENDENCIAS / BIBLIOTECAS
// ----------------------
*/
#include "io.hpp"
// ----------------------

#define MAX 100

/*
Metodo 01 - Ordenacao de arranjo de forma decrescente

Leitura de no maximo 100 valores dentro de um arquivo para armazena-los em um arranjo
e ordenar de forma decrescente o conteudo deste.

@param void
@return void
*/
void metodo01(void)
{
    int i=0;
    int array[MAX];
    ofstream arquivo ("metodo01.txt");
    srand(static_cast<unsigned int>(time(0)));

    if(!(arquivo))
    {
        IO_println("Erro ao abrir o arquivo");
    }
    else
    {
        IO_println("Gerando valores aleatorios dentro do arquivo...");

        for(i=0; i<MAX; i=i+1)
        {
            arquivo << rand() << endl;
        }

        for(i=0; i<MAX; i=i+1)
        {
            arquivo >> array[i];
        }

        arquivo.close();        
    }


}

int main(void)
{
    int opcao = 0;
    do
    {
        Recuperation_Methods();
        opcao = IO_readint("\nDigite a opcao desejada: ");

        switch (opcao)
        {
        case 0:
            break;
            		case 1:
                        metodo01();
                        break;
/*
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
                        metodo_013E1();
                        break;

                    case 12:
                        metodo_013E2();
                        break;
            */
        }

    } while (opcao != 0);

    return 0;
}
