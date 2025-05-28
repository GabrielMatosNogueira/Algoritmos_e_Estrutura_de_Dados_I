/*
Nome do Programa:   ED06
Data:               31/03/2025
Nome:               Gabriel Matos Nogueira
Codigo de Pessoa:   1563147
Matricula:          870863
Versao:             1.0

---------------------------------------------------------------------------------------------------

Como executar o programa no terminal:
1.0 - Certifique-se que o compilador MINGW esteja instalado e presente nas variaveis de ambiente 
da sua maquina

2.0 - Adentre a pasta para executar o programa:
cd 1563147_Gabriel_Matos_Nogueira (Windows, Linux e macOS)

    2.1 - Compile o programa
    Windows:    gcc -o ED06 ED06.c
    Linux:      gcc -o ED06 ED06.c
    macOS:      gcc -o ED06 ED06.c


    2.2 - Execute o programa
    Windows:     ED06
    Linux:      ./ED06
    macOS:      ./ED06

---------------------------------------------------------------------------------------------------
*/

// Declaracao de biblioteca(s)
#include "io.h"

// Declaracao dos metodos utilizados
void method_00();
void method_01();
void method_02();
void method_03();
void method_04();
void method_05();
void method_06();
void method_07();
void method_08();
void method_09();
void method_10();
void method_11();
void method_12();

// Funcao Principal
int main(void)
{
    // armazenar a opcao do usuario
    int opcao = 0;
    IO_id("\n\tOpcoes de Metodos:");

    // Menu de opcoes do usuario
    do
    {
        IO_print("\n0 - Parar");
        IO_print("\n1 - Metodo 0511");
        IO_print("\n2 - Metodo 0512");
        IO_print("\n3 - Metodo 0513");
        IO_print("\n4 - Metodo 0514");
        IO_print("\n5 - Metodo 0515");
        IO_print("\n6 - Metodo 0516");
        IO_print("\n7 - Metodo 0517");
        IO_print("\n8 - Metodo 0518");
        IO_print("\n9 - Metodo 0519");
        IO_print("\n10 - Metodo 0520");
        IO_print("\n11 - Metodo 05E1");
        IO_print("\n12 - Metodo 05E2");

        opcao = IO_readint("\nDigite uma opcao: ");
        switch(opcao)
        {
            case 0:
                    method_00();
                    break;

                case 1:
                    method_01();
                    break;

                case 2:
                    method_02();
                    break;

                case 3:
                    method_03();
                    break;

                case 4:
                    method_04();
                    break;

                case 5:
                    method_05();
                    break;

                case 6:
                    method_06();
                    break;

                case 7:
                    method_07();
                    break;

                case 8:
                    method_08();
                    break;

                case 9:
                    method_09();
                    break;

                case 10:
                    method_10();
                    break;

                case 11:
                    method_11();
                    break;

                case 12:
                    method_12();
                    break;
        }
    } while (opcao!=0);
}
// Funcoes do programa

/*
---------------------------------------------------------------------------------------------------
METODO 00
- Encerramento do programa
---------------------------------------------------------------------------------------------------
*/
void method_00(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 00\n");

    // Mensagem de encerramento
    IO_print ("ENCERRANDO O PROGRAMA...\n");

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}
/*
---------------------------------------------------------------------------------------------------
RECURSAO | METODO 0611
- Funcao recursiva que exibe os multiplos de 3 em ordem crescente
---------------------------------------------------------------------------------------------------
*/

void method_0611(int n, int quantidade)
{
    if (quantidade <= 0)
    {
        return;
    }

    // Exibe o multiplo de 3 atual
    printf("[%d] ", n);

    // Chama recursivamente para exibir o proximo multiplo de 3
    method_0611(n + 3, quantidade - 1);
}

/*
---------------------------------------------------------------------------------------------------
METODO 01
- 
---------------------------------------------------------------------------------------------------
*/

void method_01(void)
{
    // identificacao
    printf("%s\n", "\nMetodo 01\n");

    // Declaracao de Variaveis
    int quantidade=0;

    // Leitura da variavel quantidade
    quantidade=IO_readint("Digite a quantidade de numeros multiplos de 3 que deseja exibir: ");

    // Chamada da funcao recursiva
    method_0611(3, quantidade);

    // encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
RECURSAO | METODO 0612
- Funcao recursiva que exibe os multiplos de 3 em ordem decrescente
---------------------------------------------------------------------------------------------------
*/

void method_0612(int n, int quantidade)
{
    // Exibe o multiplo de 3 atual
    printf("[%d] ", n);

    // Chama recursivamente para exibir o proximo multiplo de 3
    if (quantidade > 1) 
    {
        method_0612(n - 3, quantidade - 1);
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO 02
- 
---------------------------------------------------------------------------------------------------
*/

void method_02(void)
{
    // identificacao
    printf("%s\n", "\nMetodo 01\n");

    // Declaracao de Variaveis
    int quantidade=0;
    int n=3;

    // Leitura da variavel quantidade
    quantidade=IO_readint("Digite a quantidade de numeros multiplos de 3 que deseja exibir: ");

    n= 3*quantidade;

    // Chamada da funcao recursiva
    method_0612(n, quantidade);

    // encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 613
- 
---------------------------------------------------------------------------------------------------
*/

void method_0613(int n, int quantidade)
{
    if (quantidade <= 0)
    {
        return;
    }
    printf("[1/%d] ", n);
    method_0613(n + 3, quantidade - 1);
}

/*
---------------------------------------------------------------------------------------------------
METODO 03
- 
---------------------------------------------------------------------------------------------------
*/

void method_03(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 03\n");

    // Declaracao de variaveis
    int quantidade=0;

    // Leitura da variavel quantidade
    quantidade=IO_readint("Digite quantos numeros multiplos de 3: ");


    if (quantidade==0 || quantidade<0)
    {
        printf("\n0");
    }
    else
    {
        printf("[1\1] ");
    }

    // Chamada da funcao com atribuicao de valor
    method_0613(3, quantidade);

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 614
- 
---------------------------------------------------------------------------------------------------
*/

double method_0614(int n, int quantidade)
{
    double soma=0.0;

    if (quantidade <= 0)
    {
        return soma;
    }

    printf("[1/%d] ", n);
    soma = (1.0 / n) + method_0614(n - 3, quantidade - 1);
    return soma;
}

/*
---------------------------------------------------------------------------------------------------
METODO 03
- 
---------------------------------------------------------------------------------------------------
*/

void method_04(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 04\n");

    // Declaracao de variaveis
    int quantidade=0;
    double soma=0.0;

    // Leitura da variavel quantidade
    quantidade=IO_readint("Digite quantos numeros multiplos de 3: ");

    // Chamada da funcao com atribuicao de valor
    soma=method_0614(3*quantidade, quantidade);

    // Exibicao do valor
    printf("\n\nResultado da soma e: %lf\n", soma);

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 0615

|x  |   y  |  z |
|3  |   1  |  4 |
|4  |   3  |  7 |
|7  |   5  |  12|
|12 |   7  |  19|

3 + 4 + 7 + 12 + 19
Soma de z no caso 5 = 45
---------------------------------------------------------------------------------------------------
*/

int method_0615(int x, int y, int z, int quantidade, int soma)
{
    if(quantidade<1)                         // 2: Ocorre porque a primeira soma é 3 depois o resultado das somas
    {
        printf("\nA soma e: [%d]\n ", soma);
        return soma;
    }

    soma=soma+z;

    printf("\t[%d]\t ", x);
    printf("[%d]\t ", y);
    printf("[%d]\n ", z);

    x=z;
    y=y+2;  
    z=x+y;

    method_0615(x, y, z, quantidade-1, soma);
}

/*
---------------------------------------------------------------------------------------------------
METODO 05
- Alterar a solucao com menos parametros para mais eficiencia do programa
---------------------------------------------------------------------------------------------------
*/

void method_05(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 05\n");

    // Declaracao de variaveis
    int quantidade=0;
    int x=3;
    int y=1;
    int z=4;
    int soma=0;

    // Leitura da variavel quantidade
    quantidade=IO_readint("Digite quantos numeros multiplos de 3: ");

    // Chamada da funcao com atribuicao de valor
    soma=method_0615(x,y,z,quantidade-1, soma+3);

    // Exibicao da soma
    printf("\n\tResultado da soma e: %d", soma);
    IO_print("\n");

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 0616
- Recursivo
    [1/3] = 0.333333
    [1/9] = 0.111111
    [1/15] = 0.066667
    [1/21] = 0.047619
    [1/27] = 0.037037
    SOMA CALCULADORA CASSIO MODELO FX-82MS = 0.595767195
---------------------------------------------------------------------------------------------------
*/

double method_0616(int quantidade, double numero, double soma)
{
    if (quantidade > 0)                                       
    {                                                                // [1, "infinito") ---> ate o limite da memoria
        printf("\t[1/%.0lf] = %.15lf\n", numero, 1.0 / numero);      // Mostrando cada termo
        soma = soma + (1.0 / (double)numero);                        // Acumulando soma corretamente
        return method_0616(quantidade - 1, numero + 6.0, soma);      // Chamando recursivamente com soma atualizada
    }
    return soma; // Retorna a soma final
}

/*
---------------------------------------------------------------------------------------------------
METODO 06
- 
---------------------------------------------------------------------------------------------------
*/

void method_06(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 06\n");

    // Declaracao de variaveis
    int quantidade=0;
    double numero=3.0;
    double soma=0.0;

    // Leitura da variavel
    quantidade=IO_readint("Digite quantos fracoes cujos denominadores sao multiplos de 3 deseja ver: ");

    // Chamada da funcao
    soma=method_0616(quantidade, numero, soma);

    // Exibicao da soma
    IO_print("\nO valor da soma: ");
    printf("%lf", soma);

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 617
- 
---------------------------------------------------------------------------------------------------
*/

/*
---------------------------------------------------------------------------------------------------
METODO 617
- Exibir cada caractere da string ao contrario, um por linha.
---------------------------------------------------------------------------------------------------
*/
void method_0617(char string[80], int tamanho)
{
    // Verificar se ainda há caracteres para exibir
    if (tamanho >= 0) 
    {
        // Exibir o caractere atual
        printf("%c\n", string[tamanho]); 
        
        // Chamar a funcao para o proximo caractere
        method_0617(string, tamanho - 1); 
    }
}

/*
---------------------------------------------------------------------------------------------------
METODO 07
- Ler uma string e chamar o metodo recursivo para exibi-la ao contrario.
---------------------------------------------------------------------------------------------------
*/
void method_07(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 06\n");
    
    // Declaracao de variaveis
    char string[81]; 
 
    // Leitura da string do usuario
    strcpy(string, IO_readstring("\nDigite uma frase: ")); 

    // Determinacao do tamanho da string
    int tamanho = strlen(string) - 1;

    // Chamar a funcao para exibir os caracteres ao contrario
    method_0617(string, tamanho);

    // Encerramento
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 08
- Contar os dígitos com valores pares em uma cadeia de caracteres usando recursão.
---------------------------------------------------------------------------------------------------
*/

int method_0618(char *frase, int posicao)
{
    // Caso base: chegou ao fim da string
    if (frase[posicao] == '\0') return 0;

    int contador = 0;

    // Se for digito e for par
    if (isdigit(frase[posicao]) && (frase[posicao] - '0') % 2 == 0)
    {
        printf("Digito par encontrado: '%c'\n", frase[posicao]);
        contador = 1;
    }

    // Chamada recursiva
    return contador + method_0618(frase, posicao + 1);
}

/*
---------------------------------------------------------------------------------------------------
METODO 08
---------------------------------------------------------------------------------------------------
*/

void method_08(void)
{
    // Identificacao
    printf("\nMetodo 08\n");

    // Declarar variaveis
    char frase[81];

    // Leitura da frase
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    // Remover quebra de linha do fgets, se existir
    frase[strcspn(frase, "\n")] = '\0';

    // Chamada da função recursiva
    int pares = method_0618(frase, 0);

    // Mostrar resultado
    printf("Quantidade de dígitos pares: [%d]\n", pares);

    // Encerramento
    printf("\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
Função Recursiva 0619
- Conta letras maiusculas entre ['D' , 'O']
---------------------------------------------------------------------------------------------------
*/
int method_0619(char *frase, int posicao)
{
    if (frase[posicao] == '\0') return 0;

    int contador = 0;

    if (frase[posicao] >= 'D' && frase[posicao] <= 'O')
    {
        printf("Maiúscula entre 'C' e 'P' encontrada: '%c'\n", frase[posicao]);
        contador = 1;
    }

    return contador + method_0619(frase, posicao + 1);
}

/*
---------------------------------------------------------------------------------------------------
METODO 09
---------------------------------------------------------------------------------------------------
*/
void method_09(void)
{
    // Identificacao
    printf("\nMetodo 09\n");

    // Declarcao de Variaveis
    char frase[81];

    // Leitura da frase
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    // Remover '\n' do final se existir
    frase[strcspn(frase, "\n")] = '\0';

    // Chamada da funcao recursiva
    int quantidade = method_0619(frase, 0);

    // Exibir resultado
    printf("Quantidade de letras maiúsculas entre 'C' e 'P': [%d]\n", quantidade);

    // Encerramento
    printf("\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
Função recursiva 0620
- Soma os N primeiros termos pares da sequência de Fibonacci começando em 1
---------------------------------------------------------------------------------------------------
*/
int method_0620(int a, int b, int quantidade, int cont)
{
    if (quantidade == 0) return 0;

    int c = a + b;

    if (c % 2 == 0)
    {
        printf("[%d]. Termo par desta chamada: %d\n", cont + 1, c);
        return c + method_0620(b, c, quantidade - 1, cont + 1);
    }

    return method_0620(b, c, quantidade, cont);
}

/*
---------------------------------------------------------------------------------------------------
METODO 10
---------------------------------------------------------------------------------------------------
*/
void method_10(void)
{
    // Identificacao
    printf("\nMetodo 10\n");

    int quantidade;

    // Ler a quantidade do usuario
    quantidade = IO_readint("Digite quantos termos pares da sequência de Fibonacci deseja somar: ");

    // Chamada da funcao recursiva
    int soma = method_0620(0, 1, quantidade, 0);

    // Resultado
    printf("\nSoma de todos os [%d] termos: %d\n", quantidade, soma);

    // Encerramento
    printf("\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
METODO 11
---------------------------------------------------------------------------------------------------
*/

// Funcao recursiva (06E1)
int f06E1(int x, int n)
{
    if (n < 3) return 1; // Caso base: só o 1

    if (n % 2 == 0) return f06E1(x, n - 1); // Ignora pares

    return pow(x, n) + f06E1(x, n - 2); // Soma x^n com o termo anterior
}

// Metodo 11
void method_11(void)
{
    // Identificacao
    printf("\nMetodo 11\n");

    int x = 0;
    int n = 0;

    // Entrada
    printf("Digite o valor de x: ");
    scanf("%d", &x);

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    // Chamada da funcao
    int resultado = f06E1(x, n);

    // Resultado
    printf("Resultado da funcao f(x, n) = %d\n", resultado);

    // Encerramento
    printf("\nApertar ENTER para continuar\n");
    getchar(); getchar(); // Dois getchar() para capturar o ENTER corretamente
}

/*
---------------------------------------------------------------------------------------------------
METODO 12
---------------------------------------------------------------------------------------------------
*/

// Funcao para calcular fatorial
double fatorial(int n)
{
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}

// Funcao recursiva 06E2
double f06E2(int termo)
{
    if (termo == 0) return 1; // Primeiro termo é 1

    int numerador = 2 * termo + 1;
    int expoente = 1 << termo; // 2^termo usando bit shift
    double denominador = fatorial(expoente);

    return (numerador / denominador) + f06E2(termo - 1);
}

// Metodo 12
void method_12(void)
{
    // Identificacao
    printf("\nMetodo 12\n");

    int n = 0;

    // Leitura do valor de n
    n=IO_readint("Digite o numero de termos: ");
        
    // Chamada da funcao
    double resultado = f06E2(n - 1);

    // Exibicao da resultado
    printf("Resultado da expressao: %.10lf\n", resultado);

    // Encerramento
    printf("\nApertar ENTER para continuar\n");
    getchar();
}

/*-------------------------------------------------------------------------------------------------
DOCUMENTACAO
-------------------------------------------------------------------------------------------------

1.0 - DOCUMENTACAO COMPLEMENTAR

- Metodo 05:
  Bem limitado pela formatacao int o que nao permite grandes somas como >2000

---------------------------------------------------------------------------------------------------

2.0 - TESTES

*Method_00: OK
- Sem observacoes

*Method_01:
-

*Method_02:
-

*Method_03:
-

*Method_04:
-

*Method_05:
-

*Method_06:
-

*Method_07:
-

*Method_08:
-

*Method_09:
-

*Method_10:
-

*Method_11:
-

*Method_12:
-
---------------------------------------------------------------------------------------------------
*/
// ALTERAR AS CONDICOES DE ENTRADA DAS CHAMADAS RECURSIVAS
