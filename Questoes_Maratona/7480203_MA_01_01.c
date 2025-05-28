#include <stdio.h>

int calcula_Media(int quantidade, int media, int array[quantidade])
{
    int i = 0;
    int quantidade_Numeros = 0;

    for (i = 0; i < quantidade/2; i = i + 1)
    {
        if (array[i] > media)
        {
            quantidade_Numeros = quantidade_Numeros + 1;
        }
    }

    return quantidade_Numeros;
}

int main(void)
{
    int quantidade = 0;
    int quantidade_Numeros = 0;
    int soma = 0;
    int i = 0;
    int media = 0;

    scanf("%d", &quantidade);
    int array[quantidade];

    for (i = 0; i < quantidade; i = i + 1)
    {
        scanf("%d", &array[i]);
    }

    for (i = 0; i < quantidade; i = i + 1)
    {
        if(array[0] || array[quantidade])
        {

        }
        else
        {
            soma = soma + array[i];
        }
        
    }

    media = soma/quantidade;
    quantidade_Numeros = calcula_Media(quantidade, media, array);

    printf("%d ", quantidade);
    printf("%d ", soma);
    printf("%d\n", quantidade_Numeros);
    return 0;
}