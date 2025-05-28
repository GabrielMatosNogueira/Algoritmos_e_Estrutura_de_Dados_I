#include <stdio.h>

int main ( void )
{
    int linhas=0;
    int colunas=0;
    int diagonal=0;
    int i=0;
    int j=0;

    scanf("%d", &linhas);
    scanf("%d", &colunas);

    int matriz[linhas][colunas];

    for (i=0; i<linhas; i=i+1)
    {
        for(j=0; j<colunas; j=j+1)
        {
            scanf("%d", &matriz[i][j]);
            if(i>j)
            {
                diagonal= diagonal + matriz[i][j];
            }
            if(i==j)
            {
                
            }
        }
    }

    printf("%d\n", linhas);
    printf("%d", colunas);

    for(i=0; i<linhas; i=i+1)
    {
        printf("\n");

        for(j=0; j<colunas; j=j+1)
        {
            printf("%d ", matriz[i][j]);
        }
    }

    return 0;
}