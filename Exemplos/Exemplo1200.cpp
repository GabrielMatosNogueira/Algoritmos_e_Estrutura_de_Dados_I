/*
====================================================================================================================================================
ED12.cpp - v1.0. -  01 / 06 / 2025
Author:             Gabriel Matos Nogueira
Registration code:  870863
====================================================================================================================================================
*/

/*
====================================================================================================================================================
BIBLIOTECAS / DEPENDENCIAS
====================================================================================================================================================
*/
#include <iostream>
#include "mymatrix.hpp"
using namespace std;

/*
====================================================================================================================================================
METODO 00

====================================================================================================================================================
*/
void Metodo00(void)
{
}

/*
====================================================================================================================================================
METODO 01

====================================================================================================================================================
*/
void Metodo01(void)
{
    // definir dados
    Matrix<int> int_matrix(2, 2, 0);
    int_matrix.set(0, 0, 1);
    int_matrix.set(0, 1, 2);
    int_matrix.set(1, 0, 3);
    int_matrix.set(1, 1, 4);

    // identificar
    cout << "\nMethod_01 - v0.0\n"
         << endl;

    // mostrar dados
    int_matrix.print();

    // encerrar
    pause("Apertar ENTER para continuar");
}

/*
====================================================================================================================================================
METODO 02

====================================================================================================================================================
*/
void Metodo02(void)
{
    // definir dados
    Matrix<int> matrix(2, 2, 0);
    // identificar
    cout << endl
         << "Method_02 - v0.0" << endl;
    // ler dados
    matrix.read(); // CORRECAO: Utilizacao de getchar ( ) na funcao read()
    // mostrar dados
    matrix.print();
    // encerrar
    pause("Apertar ENTER para continuar");
}

/*
====================================================================================================================================================
METODO 03

====================================================================================================================================================
*/
void Metodo03(void)
{
    // definir dados
    Matrix<int> matrix(2, 2, 0);
    // identificar
    cout << endl
         << "Method_03 - v0.0" << endl;
    // ler dados
    matrix.read();
    // mostrar dados
    matrix.print();
    // gravar dados
    matrix.fprint("MATRIX1.TXT");
    // encerrar
    pause("Apertar ENTER para continuar");
}

/*
====================================================================================================================================================
METODO 04

====================================================================================================================================================
*/
void Metodo04(void)
{
    // definir dados
    Matrix<int> matrix(1, 1, 0);
    // identificar
    cout << endl
         << "Method_04 - v0.0" << endl;
    // ler dados
    matrix.fread("MATRIX1.TXT");
    // mostrar dados
    matrix.print();
    // encerrar
    pause("Apertar ENTER para continuar");
}

/*
====================================================================================================================================================
METODO 05

====================================================================================================================================================
*/
void Metodo05(void)
{
    // definir dados
    Matrix<int> int_matrix1(1, 1, 0);
    Matrix<int> int_matrix2(1, 1, 0);
    // identificar
    cout << endl
         << "Method_05 - v0.0" << endl;
    // ler dados
    int_matrix1.fread("MATRIX1.TXT");
    // mostrar dados
    cout << "\nOriginal\n"
         << endl;
    int_matrix1.print();
    // copiar dados
    int_matrix2 = int_matrix1; // Copia de dados se faz por meio de "=" nao "<<"???
    // mostrar dados
    cout << "\nCopia\n"
         << endl;
    int_matrix2.print();
    // encerrar
    pause("Apertar ENTER para continuar");
}

/*
====================================================================================================================================================
METODO 06

====================================================================================================================================================
*/
void Metodo06(void)
{
    // definir dados
    Matrix<int> int_matrix(2, 2, 0);
    int_matrix.set(0, 0, 0);
    int_matrix.set(0, 1, 0);
    int_matrix.set(1, 0, 0);
    int_matrix.set(1, 1, 0);
    // identificar
    cout << endl
         << "Method_06 - v0.0" << endl;
    // mostrar dados
    int_matrix.print();
    // testar condicao
    cout << "Zeros = " << int_matrix.isZeros() << endl;
    // ler dados
    int_matrix.fread("MATRIX1.TXT");
    // mostrar dados
    int_matrix.print();
    // testar condicao
    cout << "Zeros = " << int_matrix.isZeros() << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
}

/*
====================================================================================================================================================
METODO 07

====================================================================================================================================================
*/
void Metodo07(void)
{
    // definir dados
    Matrix<int> int_matrix1(1, 1, 0);
    Matrix<int> int_matrix2(1, 1, 0);
    // identificar
    cout << endl
         << "Method_07 - v0.0" << endl;
    // ler dados
    int_matrix1.fread("MATRIX1.TXT");
    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    // copiar dados
    int_matrix2 = int_matrix1;
    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();
    // testar condicao
    cout << "Diferentes = " << (int_matrix1 != int_matrix2) << endl;
    // alterar dados
    int_matrix2.set(0, 0, (-1));
    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();
    // testar condicao
    cout << "Diferentes = " << (int_matrix1 != int_matrix2) << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
}

/*
====================================================================================================================================================
METODO 08

====================================================================================================================================================
*/
void Metodo08(void)
{
    // definir dados
    Matrix<int> int_matrix1(1, 1, 0); // Removacao da declaracao de x e y no comeco, por que as declaracoes estao duplicadas
    Matrix<int> int_matrix2(1, 1, 0);
    Matrix<int> int_matrix3(1, 1, 0);
    // identificar
    cout << endl
         << "Method_08 - v0.0" << endl;
    // ler dados
    int_matrix1.fread("MATRIX1.TXT");
    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    // copiar dados
    int_matrix2 = int_matrix1;
    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();
    // operar dados
    int_matrix3 = int_matrix1 - int_matrix2;
    // mostrar dados
    cout << "\nMatrix_3\n";
    int_matrix3.print();
    // encerrar
    pause("Apertar ENTER para continuar");
}

/*
====================================================================================================================================================
METODO 09

====================================================================================================================================================
*/
void Metodo09(void)
{
    // definir dados
    Matrix<int> int_matrix1(2, 2, 0);
    int_matrix1.set(0, 0, 1);
    int_matrix1.set(0, 1, 0);
    int_matrix1.set(1, 0, 0);
    int_matrix1.set(1, 1, 1);
    Matrix<int> int_matrix2(1, 1, 0);
    Matrix<int> int_matrix3(1, 1, 0);
    // identificar
    cout << endl
         << "Method_09 - v0.0" << endl;
    // ler dados
    int_matrix2.fread("MATRIX1.TXT");
    // mostrar dados
    cout << "\nMatrix_1\n";
    int_matrix1.print();
    // mostrar dados
    cout << "\nMatrix_2\n";
    int_matrix2.print();
    // operar dados
    int_matrix3 = int_matrix1 * int_matrix2;
    // mostrar dados
    cout << "\nMatrix_3\n";
    int_matrix3.print();
    // encerrar
    pause("Apertar ENTER para continuar");
}

/*
====================================================================================================================================================
METODO 10

====================================================================================================================================================
*/
void Metodo10(void)
{
    // definir dados
    Matrix<int> int_matrix(3, 3, 0);
    int x = 0;
    int y = 0;
    // identificar
    cout << endl
         << "Method_10 - v0.0" << endl;
    // ler dados
    int_matrix.fread("MATRIX1.TXT");
    // mostrar dados
    cout << "\nMatrix\n";
    int_matrix.print();
    // operar dados
    for (int x = 0; x < int_matrix.getRows(); x = x + 1)
    {
        for (int y = 0; y < int_matrix.getColumns(); y = y + 1)
        {
            int_matrix.set(x, y, int_matrix.get(x, y) * (-1));
        } // end for
    } // end for
    // mostrar dados
    cout << "\nMatrix\n";
    int_matrix.print();
    // encerrar
    pause("Apertar ENTER para continuar");
}

/*
====================================================================================================================================================
METODO 11

====================================================================================================================================================
*/
void Metodo11(void)
{
}

/*
====================================================================================================================================================
METODO 12

====================================================================================================================================================
*/
void Metodo12(void)
{
}

/*
====================================================================================================================================================
FUNCAO PRINCIPAL
====================================================================================================================================================
*/
int main(void)
{
    int opcao = 0;
    do
    {
        cout << "====================================================================================================================================================";
        cout << endl
             << "MENU DE OPCOES:" << endl;

        cout
            << "01 - Metodo XXXX" << endl
            << "02 - Metodo XXXX" << endl
            << "03 - Metodo XXXX" << endl
            << "04 - Metodo XXXX" << endl
            << "05 - Metodo XXXX" << endl
            << "06 - Metodo XXXX" << endl
            << "07 - Metodo XXXX" << endl
            << "08 - Metodo XXXX" << endl
            << "09 - Metodo XXXX" << endl
            << "10 - Metodo XXXX" << endl
            << "11 - Metodo XXXX" << endl
            << "12 - Metodo XXXX" << endl;

        cout << "Digite a opcao: ";
        cin >> opcao;
        getchar();

        switch (opcao)
        {
        case 0:
            Metodo00();
            break;

        case 1:
            Metodo01();
            break;

        case 2:
            Metodo02();
            break;

        case 3:
            Metodo03();
            break;

        case 4:
            Metodo04();
            break;

        case 5:
            Metodo05();
            break;

        case 6:
            Metodo06();
            break;

        case 7:
            Metodo07();
            break;

        case 8:
            Metodo08();
            break;

        case 9:
            Metodo09();
            break;

        case 10:
            Metodo10();
            break;

        case 11:
            Metodo11();
            break;

        case 12:
            Metodo12();
            break;

        default:
            cout << "Opcao invalida. Opcoes validas: [0,12]" << endl;
            cout << "Aperte ENTER para continuar";
            getchar();
            break;
        }
    } while (opcao != 0);

    return 0;
}