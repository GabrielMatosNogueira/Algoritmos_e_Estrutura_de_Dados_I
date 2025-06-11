#include "io.h"
#define MAX 100

void fill_Array_Rand_Crescent(int array[])
{
    // Declaracao de Variaveis
    int i=0;
    int temp=0;
    bool swap=false;

    // Semeando funcao geradora de numeros aleatorios
    srand(time(NULL));

    for (i = 0; i < MAX; i = i + 1)
    {
        array[i] = rand() % 101;
    }

    do
    {
        swap = false;
        for (i = 0; i < MAX - 1; i = i + 1)
        {
            if (array[i + 1] < array[i])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);
}

void fill_Array_Rand_Decrescent(char *filename)
{
    // Declaracao de Variaveis
    int i=0;
    int temp=0;
    int array[MAX];
    bool swap=false;
    FILE *arquivo=fopen(filename,"rt");

    for(i=0; i<MAX; i=i+1)
    {
        fscanf(arquivo, "%d", &array[i]);
    }

    // Semeando funcao geradora de numeros aleatorios
    srand(time(NULL));

    for (i = 0; i < MAX; i = i + 1)
    {
        array[i] = rand() % 101;
    }

    do
    {
        swap = false;
        for (i = 0; i < MAX - 1; i = i + 1)
        {
            if (array[i + 1] > array[i])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);

    for(i=0; i<MAX; i=i+1)
    {
        IO_printf("[%d]\n", array[i]);
    }
}
