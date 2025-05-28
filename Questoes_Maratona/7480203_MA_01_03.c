#include <stdio.h>
#include <string.h>

int main ( void )
{
    int i=0;
    int j=0;
    int quantidade_Vogais=0;
    int quantidade_Frases=0;
    int verficiacoes=0;
    char frase[100];

    scanf("%d", &quantidade_Frases);
    getchar( );

    for(i=0; i<quantidade_Frases; i=i+1)
    {
        fgets(frase, 100, stdin);
        verficiacoes=strlen(frase);

        for(j=0; j<verficiacoes; j=j+1)
        {
            if (frase[i]=='a' && (frase[i+1]=='e' || frase[i+1]=='i' || frase[i+1]=='o' || frase[i+1]=='u'))
            {
                frase[i]='A';
                quantidade_Vogais=quantidade_Vogais+1;
            }
            if (frase[i]=='e' && (frase[i+1]=='a' || frase[i+1]=='i' || frase[i+1]=='o' || frase[i+1]=='u'))
            {
                frase[i]='E';
                quantidade_Vogais=quantidade_Vogais+1;
            }
            if (frase[i]=='i' && (frase[i+1]=='a' || frase[i+1]=='e' || frase[i+1]=='o' || frase[i+1]=='u'))
            {
                frase[i]='I';
                quantidade_Vogais=quantidade_Vogais+1;
            }
            if (frase[i]=='o' && (frase[i+1]=='a' || frase[i+1]=='e' || frase[i+1]=='i' || frase[i+1]=='u'))
            {
                frase[i]='O';
                quantidade_Vogais=quantidade_Vogais+1;
            }
            if (frase[i]=='u' && (frase[i+1]=='a' || frase[i+1]=='e' || frase[i+1]=='i' || frase[i+1]=='o'))
            {
                frase[i]=='U';
                quantidade_Vogais=quantidade_Vogais+1;
            }
        }
        printf("%d\n", quantidade_Vogais);
        printf("%s", frase);
    }
}