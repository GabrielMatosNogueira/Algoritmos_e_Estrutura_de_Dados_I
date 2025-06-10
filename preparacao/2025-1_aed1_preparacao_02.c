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
    int array[MAX];
    bool verificacation = false;
    ofstream arquivoEscrita("metodo01.txt");
    srand(static_cast<unsigned int>(time(0)));

    if (arquivoEscrita)
    {
        cout << "Gerando valores aleatorios e salvando no arquivo..." << endl;
        for (int i = 0; i < MAX; i++)
        {
            int valor = rand() % 101;
            arquivoEscrita << valor << endl;
        }
        arquivoEscrita.close();
        verificacation = true;
    }
    else
    {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
    }

    if (verificacation)
    {
        ifstream arquivoLeitura("metodo01.txt");

        if (arquivoLeitura)
        {
            for (int i = 0; i < MAX && arquivoLeitura >> array[i]; i++);

            arquivoLeitura.close();

            // Ordenação manual (bubble sort em ordem decrescente)
            for (int i = 0; i < MAX - 1; i++)
            {
                for (int j = 0; j < MAX - 1 - i; j++)
                {
                    if (array[j] < array[j + 1])
                    {
                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }

            cout << "Valores ordenados de forma decrescente:" << endl;
            for (int i = 0; i < MAX; i++)
            {
                cout << array[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Erro ao abrir o arquivo para leitura." << endl;
        }
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
