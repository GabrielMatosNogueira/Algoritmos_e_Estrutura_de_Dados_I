#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct y
{
    int a;
    int b;
    int c;
}y;

void saida ( void )
{
    printf("Encerrando o programa...\n");
}

void questao_01 ( void )
{
    printf("\nQuestao 01\n");

    int x = 0;
    int y = 0;
    int z = 0;
    char r[50];
    char *s = " abacate maduro barato";
    r[0] = '\0';

    while (z < strlen(s) && s[z] == ' ')
    {
        z = z + 1;
        y = z;
    }

    while (y < strlen(s) && s[y] != ' ')
    {
        y = y + 1;
    }

    for (x = 0; x < (y - z); x++)
    {
        r[x] = s[y - 1 - x];
    }
    r[y - z] = '\0';

    printf("String original: \"%s\"\n", s);
    printf("Primeira palavra invertida: \"%s\"\n", r);
    getchar();
}

int questao_02(int destination_array[], int source_array[], int n, int begin, int end)
{
    int m = 0;

    while (begin <= end && begin < n)
    {
        destination_array[m] = source_array[begin];
        m = m + 1;
        ++begin;
    }
    return (m);
}

void questao_03(int p, int q, int m_rows, int n_cols, int matrix[][10])
{
    int z = 0;
    int x = 0;
    int i = 0;
    int j = 0;

    printf("\nQuestao 03 - Matriz antes da troca:\n");
    for(i=0; i<m_rows; i=i+1)
    {
        for(j=0; j<n_cols; j=j+1)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    if (p >= 0 && p < m_rows && q >= 0 && q < m_rows)
    {
        for(x = 0; x < n_cols; x++)
        {
            z = matrix[p][x];
            matrix[p][x] = matrix[q][x];
            matrix[q][x] = z;
        }
    } else {
        printf("Indices de linha invalidos para a troca.\n");
    }

    printf("\nQuestao 03 - Matriz depois da troca:\n");
    for(i=0; i<m_rows; i=i+1)
    {
        for(j=0; j<n_cols; j=j+1)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void questao_04 (int x, int y, int a[])
{
    if (x < y - 1)
    {
        a[x] = a[x] + a[y];
        questao_04((x + y) / 2, y, a);
    }
    else
    {
        a[x] = 0;
    }
}

void questao_05 (struct y *r)
{
    int d;
    int e;

    d=r->a;
    e=r->c;
    
    if(d<e)
    {
        (*r).a=e;
        (*r).c=d;

        d=r->b;
        e=r->c;

        if(d<e)
        {
            r->b=e;
            r->c=d;
        }

        d=(*r).a;
        e=r->b;

        if(d<e)
        {
            r->a=e;
            (*r).b=d;
        }
    }

};

int main ( void )
{
    int a[] = {2,5,3,6,1,7,4};
    int b[10];
    int opcao = 0;
    int num_elementos_copiados_q2 = 0;
    int m[3][10]={{1,2,3,0,0,0,0,0,0,0}, {4,5,6,0,0,0,0,0,0,0}, {7,8,9,0,0,0,0,0,0,0}};
    int a_02[]={1,2,3,4,5,6,7};
    int size_a_02 = sizeof(a_02) / sizeof(a_02[0]);
    struct y*r;
    (*r).a=0;
    (*r).b=1;
    (*r).c=3;
    do
    {
        printf("\n\n");

        printf("Q01) Qual a saida para ' abacate maduro barato'\n");
        printf("Q02) Para int a[] = {2,5,3,6,1,7,4}, int b=[10], qual a saida b, se chamar questao_02 (b, a, 7, 2, 5)?\n");
        printf("Q03) Qual a saida da matriz m[3][10] se chamar questao_03 (0, 2, 3, 3, m)?\n");
        printf("Q04) Qual a saida para int a[]= {1,2,3,4,5,6,7} se chamar questao_04(0, 6, a[])?\n");
        printf("Q05) Dada as definicoes abaixo: struct y {int a, b, c}\n");
        printf("Q06) Dada uma cadeia de caracteres, se houver mais do que um espaco em branco seguido do outro, remover os excedentes deixando apenas um\nRestricao: Usar pelo menos dois while\n");

        printf("\nDigite uma opcao: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao)
        {
        case 0:
            saida();
            break;

        case 1:
            questao_01();
            break;

        case 2:
            num_elementos_copiados_q2 = questao_02(b, a, 7, 2, 5);
            printf("Questao 02\n");
            printf("Conteudo de b[] depois da chamada questao_02(b, a, 7, 2, 5): {");
            for (int i = 0; i < num_elementos_copiados_q2; i++)
            {
                printf("%d%s", b[i], (i == num_elementos_copiados_q2 - 1) ? "" : ", ");
            }
            printf("}\n");
            break;

        case 3:
            questao_03(0, 2, 3, 3, m);
            break;

        case 4:
            printf("\nQuestao 04\n");
            printf("Array antes da chamada questao_04: {");
            for (int i = 0; i < size_a_02; i++) {
                printf("%d%s", a_02[i], (i == size_a_02 - 1) ? "" : ", ");
            }
            printf("}\n");

            questao_04(0, 6, a_02);

            printf("Array depois da chamada questao_04: {");
            for (int i = 0; i < size_a_02; i++) {
                printf("%d%s", a_02[i], (i == size_a_02 - 1) ? "" : ", ");
            }
            printf("}\n");
            getchar();
            break;
        
        case 5:
            questao_05(r);
            break;

        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}
