/*
Nome do Programa:   ED04
Data:               18/03/2025
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
    Windows:    gcc -o ED04 ED04.c
    Linux:      gcc -o ED04 ED04.c
    macOS:      gcc -o ED04 ED04.c


    2.2 - Execute o programa
    Windows:     ED04
    Linux:      ./ED04
    macOS:      ./ED04

---------------------------------------------------------------------------------------------------
*/

// Declaracao de biblioteca(s)
#include "io.h"

// Declaracao das funcoes
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
    IO_id("\n\t");

    IO_print("\n0 - Parar");
    IO_print("\n1 - Metodo ");
    IO_print("\n2 - Metodo ");
    IO_print("\n3 - Metodo ");
    IO_print("\n4 - Metodo ");
    IO_print("\n5 - Metodo ");
    IO_print("\n6 - Metodo ");
    IO_print("\n7 - Metodo ");
    IO_print("\n8 - Metodo ");
    IO_print("\n9 - Metodo");
    IO_print("\n10 - Metodo ");
    IO_print("\n11 - Metodo ");
    IO_print("\n12 - Metodo ");

    IO_print("\nDigite uma opcao: ");
    opcao = IO_readint("");

    // Menu de opcoes do usuario
    switch (opcao)
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
}
// Funcoes do programa

void method_00(void)
{
    // identificar
    IO_id("Metodo 0411\n");

    // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

void method_01(void)
{
    // identificar
    IO_id("\n\tMetodo 0411 - v1.0\n");

    // declaracao de variaveis
    double limite[2];
    limite[1] = 0;
    limite[2] = 0;
    int quantidade = 0;
    int i = 0;
    int count = 0;
    double numeroTemporario = 0.0;

    // perguntar o numero de testes e o limite das funcoes
    IO_print("Digite a quantidade de numeros a testar no intervalo: ");
    quantidade = IO_readint("");
    IO_print("\nDigite o limite inferior: ");
    limite[1] = IO_readdouble("");
    IO_print("\nDigite o limite superior: ");
    limite[2] = IO_readdouble("");

    // atualizar o scan da variaável
    for (i = 0; i < quantidade; i = i + 1)
    {
        numeroTemporario = IO_readdouble("\nDigite um numero a ser testado: ");

        if (numeroTemporario >= limite[1] && numeroTemporario <= limite[2])
        {
            IO_print("Pertence ao intervalo\n");
            count = count + 1; // contar quantos numeros pertencem ao intervalo
        }
        else
        {
            IO_print("Nao pertence ao intervalo\n");
        }
    }
    // mostrar o numero de testes dentro do intervalo digitado
    IO_print("\nA quantidade de numeros que pertencem ao intervalo e: ");
    printf("%d", count);

    // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

void method_02(void)
{
    // Identificar
    printf("%s\n", "\nMetodo 0412\n");

    // Declarar variaveis
    char frase[100] = "";
    int contador = 0;

    // Ler uma sequencia de caracteres do teclado
    IO_print("Digite uma sequencia de ate 100 caracteres: ");
    fgets(frase, sizeof(frase), stdin); // Le a string
    frase[strcspn(frase, "\n")] = '\0'; // Remove o caractere de nova linha (\n)

    // Percorrer a sequencia e contar letras minusculas no intervalo ('c', 'p')
    for (int i = 0; i < strlen(frase); i++)
    {
        // Verificar se o caractere e minusculo
        if (frase[i] >= 'a' && frase[i] <= 'z')
        {
            // Verificar se esta no intervalo ('c', 'p')
            if (frase[i] > 'c' && frase[i] < 'p')
            {
                contador++;
                printf("Caractere '%c' esta no intervalo ('c', 'p')\n", frase[i]);
            }
        }
    }

    // Exibir letras maiusculas diretamente
    IO_print("\nLetras maiusculas encontradas na sequencia:\n");
    for (int i = 0; i < strlen(frase); i++)
    {
        // Verificar se o caractere e maiusculo
        if (frase[i] >= 'A' && frase[i] <= 'Z')
        {
            printf("Caractere '%c' e uma letra maiuscula\n", frase[i]);
        }
    }

    // Mostrar a quantidade total
    printf("\nTotal de letras minusculas no intervalo ('c', 'p'): %d\n", contador);

    // Encerrar
    printf("\nAperte ENTER para continuar");
    getchar();
}

void receberString(char *frase)
{
    // Ler uma sequencia de caracteres do teclado
    printf("Digite uma frase: ");
    fgets(frase, 100, stdin);           // Limitar a leitura a 100 caracteres
    frase[strcspn(frase, "\n")] = '\0'; // Remove o caractere de nova linha (\n)
}

void method_03(void)
{
    // Identificar
    printf("%s\n", "\nMetodo 0413\n");

    // Declarar variaveis
    char frase[100] = "";
    int contador = 0;

    // Chamar a funcao para receber a string
    receberString(frase);

    // Percorrer a sequencia e contar letras minusculas no intervalo ('c', 'p')
    for (int i = 0; i < strlen(frase); i++)
    {
        // Verificar se o caractere e minusculo
        if (frase[i] >= 'a' && frase[i] <= 'z')
        {
            // Verificar se esta no intervalo ('c', 'p')
            if (frase[i] > 'c' && frase[i] < 'p')
            {
                contador++;
                printf("Caractere '%c' (posicao %d) esta no intervalo ('c', 'p')\n", frase[i], i + 1);
            }
        }
    }

    // Exibir letras maiusculas diretamente
    printf("\nLetras maiusculas encontradas na sequencia:\n");
    for (int i = 0; i < strlen(frase); i++)
    {
        // Verificar se o caractere e maiusculo
        if (frase[i] >= 'A' && frase[i] <= 'Z')
        {
            printf("Caractere '%c' (posicao %d) e uma letra maiuscula\n", frase[i], i);
        }
    }

    // Mostrar a quantidade total
    printf("\nTotal de letras minusculas no intervalo ('c', 'p'): %d\n", contador);

    // Encerrar
    printf("\nAperte ENTER para continuar");
    getchar();
}

void caracteresReijeitados(char *resultado, char caractere)
{
    int tamanho = strlen(resultado);
    resultado[tamanho] = caractere; // Adiciona o caractere ao final da string
    resultado[tamanho + 1] = '\0';  // Finaliza a string com o caractere nulo
}

void method_04(void)
{
    // Identificar
    printf("Metodo 0414\n");

    // Declarar variaveis
    char frase[100] = "";
    char caracteresintervalo[100] = "";
    char caracteresrejeitados[100] = "";
    int contador = 0;

    // Ler uma sequencia de caracteres do teclado
    IO_print("Digite uma sequencia de ate 100 caracteres: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0'; // Remove o caractere quando ENTER e' apertado

    // Percorrer a sequencia e classificar os caracteres
    for (int i = 0; i < strlen(frase); i++)
    {
        if (frase[i] >= 'a' && frase[i] <= 'z')
        {
            // Verificar se esta no intervalo
            if (frase[i] > 'c' && frase[i] < 'p')
            {
                contador++;
                caracteresReijeitados(caracteresintervalo, frase[i]);
            }
            else
            {
                caracteresReijeitados(caracteresrejeitados, frase[i]);
            }
        }
        else if (frase[i] >= 'A' && frase[i] <= 'Z')
        {
            // Processar letras maiusculas como rejeitadas
            caracteresReijeitados(caracteresrejeitados, frase[i]);
        }
        else
        {
            // Qualquer outro caractere tambem e rejeitado
            caracteresReijeitados(caracteresrejeitados, frase[i]);
        }
    }

    // Mostra os caracteres que estao no intervalo
    printf("\nCaracteres no intervalo: %s\n", caracteresintervalo);

    // Mostra os caracteres rejeitados
    printf("\nCaracteres rejeitados: %s\n", caracteresrejeitados);

    // Mostrar a quantidade total
    printf("\nTotal de letras minusculas no intervalo: %d\n", contador);

    // Encerrar
    IO_print("\nAperte ENTER para continuar");
    getchar();
}

int contaLetras(char *frase)
{
    int contador = 0;
    int i=0;
    int tamanho = strlen(frase);
    for (i = 0; i < tamanho; i++) {
        if ((frase[i] > 'c' && frase[i] < 'p') || (frase[i] > 'C' && frase[i] < 'P')) {
            contador++;
        }
    }
    return contador;
}

void method_05(void)
{
    // identificar
    IO_id("\nMetodo 05\n");

    // Declaracao de variaveis
    char frase[100] = "";
    int contador=0;

    // Leitura da cadeia de caracteres
    IO_print("\nDigite a frase digitada: ");
    fgets(frase, 100, stdin);

    // Recebe o numero de letras dentro do conjunto
    contador=contaLetras(frase);

    // Recebe o numero de letras dentro do conjunto
    IO_print("\nNumero de caracteres dentro do conjunto maiores que o conjunto ('c','C') e menores que ('P', 'p'): ");
    printf("%d", contador);

    // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

void exibeLetras(char *frase, char *letras, int *contador)
{
    int i = 0;
    int j = 0;
    int tamanho = strlen(frase);

    // Percorrer a string
    for (i = 0; i < tamanho; i++) {
        // Verificar se esta no conjunto especificado
        if ((frase[i] > 'c' && frase[i] < 'p') || (frase[i] > 'C' && frase[i] < 'P')) {
            letras[j++] = frase[i];
            (*contador)++;
        }
    }
    letras[j] = '\0';
}

void method_06(void) {
    // Mostrar identificacao
    printf("\nMetodo 06\n");

    // Declaracao de variaveis
    char frase[100] = "";
    char letras[100] = "";
    int contador = 0;

    // Ler a string do usuario
    printf("\nDigite a frase: ");
    fgets(frase, 100, stdin);
    frase[strcspn(frase, "\n")] = '\0'; // Remover quebra de linha

    // Processar a string
    exibeLetras(frase, letras, &contador);

    // Mostrar resultados
    printf("\nCaracteres no conjunto ('c'-'p' e 'C'-'P'): %s\n", letras);
    printf("\nNumero de caracteres: %d\n", contador);

    // Finalizar
    printf("\nApertar ENTER para continuar");
    getchar();
}

// Funcao para retornar quantidade de digitos pares
int contadorPares (char *frase)
{
    // Declarar variaveis
    int i=0;
    int tamanho=0;
    int contador=0;

    // Definicao do tamanho do for
    tamanho=strlen(frase);

    // Procurar caractere por caractere
    for(i=0; i<tamanho; i=i+1)
    {
        if(frase[i]%2==0)
        {
            contador=contador+1;
        }
    }
    return contador;
}

void method_07(void)
{
    // identificar
    printf("%s\n", "\nMetodo 07\n");

    // Declarar variaveis
    char frase[100]="";
    int numerosPares=0;

    // Requisicao da frase
    IO_print("Digite a frase desejada: ");

    // Ler a frase
    fgets(frase, 100, stdin);
    frase[strcspn(frase, "\n")] = '\0'; // Remover quebra de linha

    // Chamar a funcao para ler a quantidade de caracteres pares
    numerosPares=contadorPares(frase);

    // Exibir a quantidade de caracteres pares
    IO_print("\nA quantidade de caracteres pares digitados e: ");
    printf("%d", numerosPares);

    // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

// Funcao para exibir os numeros nao alfanumericos
void naoAlfaNumericos(char *frase, char *caracteresFiltrados)
{
    // Declaracao de variaveis
    int i = 0;
    int j = 0;
    int tamanho = strlen(frase);

    // Filtragem dos caracteres nao alfanumericos
    for(i = 0; i < tamanho; i++)
    {
        // Verificacao de caracteres nao alfanumericos
        if( !( (frase[i] >= 'a' && frase[i] <= 'z') || 
               (frase[i] >= 'A' && frase[i] <= 'Z') || 
               (frase[i] >= '0' && frase[i] <= '9') ))
        {
            // Adiciona o caracter nao alfanumerico ao array
            caracteresFiltrados[j] = frase[i];
            j++;
        }
    }

    // Garantir que a string de caracteres filtrados termine corretamente
    caracteresFiltrados[j] = '\0';
}


void method_08(void)
{
    // Identificar
    printf("%s\n", "\nMetodo 08\n");

    // Declaracao de variaveis
    char frase[100] = "";
    char naoAlfaNum[100] = "";

    // Requisicao da frase ao usuario
    IO_print("Digite a frase desejada: ");

    // Leitura da frase
    fgets(frase, 100, stdin);
    frase[strcspn(frase, "\n")] = '\0';

    // Chamada da funcao de caracteres
    naoAlfaNumericos(frase, naoAlfaNum);

    // Listagem dos caracteres nao alfanumericos
    IO_print("\nOs caracteres nao alfanumericos sao: ");
    printf("%s", naoAlfaNum);

    // Encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

// Funcao para exibir os numeros nao alfanumericos
void AlfaNumericos(char *frase, char *caracteresFiltrados)
{
    // Declaracao de variaveis
    int i = 0;
    int j = 0;
    int tamanho = strlen(frase);

    // Filtragem dos caracteres nao alfanumericos
    for(i = 0; i < tamanho; i++)
    {
        // Verificacao de caracteres nao alfanumericos
        if( (  (frase[i] >= 'a' && frase[i] <= 'z') || 
               (frase[i] >= 'A' && frase[i] <= 'Z') || 
               (frase[i] >= '0' && frase[i] <= '9') ))
        {
            // Adiciona o caracter nao alfanumerico ao array
            caracteresFiltrados[j] = frase[i];
            j++;
        }
    }

    // Garantir que a string de caracteres filtrados termine corretamente
    caracteresFiltrados[j] = '\0';
}


void method_09(void)
{
    // Identificacao
    printf("%s\n", "\nMetodo 09\n");

    // Declaracao de variaveis
    char frase[100] = "";
    char naoAlfaNum[100] = "";

    // Requisicao da frase ao usuario
    IO_print("Digite a frase desejada: ");

    // Leitura da frase
    fgets(frase, 100, stdin);
    frase[strcspn(frase, "\n")] = '\0';

    // Chamada da funcao de caracteres
    AlfaNumericos(frase, naoAlfaNum);

    // Listagem dos caracteres nao alfanumericos
    IO_print("\nOs caracteres alfanumericos sao: ");
    printf("%s", naoAlfaNum);

    // Encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

int contarAlfaNumericos(char *frase) 
{
    int i = 0;
    int count = 0;
    int tamanho = strlen(frase);

    // Filtra os caracteres alfanumericos
    for(i = 0; i < tamanho; i++) {
        if( (frase[i] >= 'a' && frase[i] <= 'z') || 
            (frase[i] >= 'A' && frase[i] <= 'Z') || 
            (frase[i] >= '0' && frase[i] <= '9') ) {
            count++;
        }
    }
    
    return count;
}

void method_10(void)
{
    // identificar
    printf("%s\n", "\nMetodo 10\n");

    // Declaracao de variaveis
    int numeroCadeias=0;
    int total=0;

    // Requisicao do numero de cadeias de caracteres
    IO_print("Digite o numero de cadeias de caracteres: ");
    numeroCadeias=IO_readint("");

    // Ler a(s) cadeia(s) de caractere(s)
    for (int i = 0; i < numeroCadeias; i++) 
    {
        char palavra[100];
        printf("\nDigite a cadeia %d: ", i + 1);
        fgets(palavra, sizeof(palavra), stdin);

        int qtd = contarAlfaNumericos(palavra);
        printf("\nCadeia %d: %s - Alfanumericos: %d\n", i + 1, palavra, qtd);
        total += qtd;
    }

    IO_print("\nTotal de alfanumericos em todas as palavras digitadas: ");
    printf("%d", total);

    // encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

int contarAlfaNumericosEspacos(char *frase) 
{
    int i = 0;
    int count = 0;
    int tamanho = strlen(frase);

    // Filtra os caracteres alfanumericos e espacos em branco
    for(i = 0; i < tamanho; i++) {
        // Verifica se o caractere e alfanumerico ou um espaco
        if( (frase[i] >= 'a' && frase[i] <= 'z') || 
            (frase[i] >= 'A' && frase[i] <= 'Z') || 
            (frase[i] >= '0' && frase[i] <= '9') || 
            (frase[i] == ' ') ) {
            count++;
        }
    }
    
    return count;
}

void method_11(void)
{
    // Identificar
    printf("%s\n", "\nMetodo 04E1\n");

    // Declaracao de variaveis
    int numeroCadeias = 0;
    int total = 0;

    // Requisicao do numero de cadeias de caracteres
    numeroCadeias=IO_readint("Digite o numero de cadeias de caracteres: ");

    getchar();

    for (int i = 0; i < numeroCadeias; i++) {
        char palavra[100];
        printf("\nDigite a cadeia %d: ", i + 1);
        fgets(palavra, sizeof(palavra), stdin);

        int qtd = contarAlfaNumericosEspacos(palavra);
        
        if (qtd > 3) {
            total += qtd;
            printf("\nCadeia %d: %s - Alfanumericos e Espacos: %d\n", i + 1, palavra, qtd);
        }
    }

    // Exibir o total de simbolos alfanumericos e espacos das palavras com mais de 3 simbolos
    IO_print("\nTotal de alfanumericos e espacos em todas as palavras com mais de 3 simbolos: ");
    printf("%d\n", total);

    // Encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();  // Aguarda o usuario apertar ENTER antes de continuar
}

// Funcao para contar a quantidade de digitos em uma cadeia
int contarDigitos(char *frase) {
    int i = 0;
    int count = 0;
    int tamanho = strlen(frase);

    // Filtra os digitos
    for(i = 0; i < tamanho; i++) {
        if( frase[i] >= '0' && frase[i] <= '9') {
            count++;
        }
    }
    
    return count;
}

// Funcao para contar a quantidade de digitos em uma cadeia
int calcularQuantidadeDigitos(char *frase) 
{
    int count = 0;
    int tamanho = strlen(frase);
    
    // Percorre a string verificando os digitos
    for (int i = 0; i < tamanho; i++) {
        if (frase[i] >= '0' && frase[i] <= '9') {
            count++;
        }
    }
    return count;
}


void method_12(void)
{
    // Identificar
    printf("%s\n", "\nMetodo 04E2\n");

    // Declaracao de variaveis
    char cadeia1[100], cadeia2[100];
    int qtd1, qtd2;

    // Ler a primeira cadeia de caracteres
    printf("Digite a primeira cadeia de caracteres: ");
    fgets(cadeia1, sizeof(cadeia1), stdin);
    cadeia1[strcspn(cadeia1, "\n")] = '\0';

    // Ler a segunda cadeia de caracteres
    printf("Digite a segunda cadeia de caracteres: ");
    fgets(cadeia2, sizeof(cadeia2), stdin);
    cadeia2[strcspn(cadeia2, "\n")] = '\0';

    // Contar os digitos em cada cadeia
    qtd1 = calcularQuantidadeDigitos(cadeia1);
    qtd2 = calcularQuantidadeDigitos(cadeia2);

    // Comparar e exibir o resultado
    if (qtd1 > qtd2) {
        printf("A primeira cadeia possui mais digitos. Digitos numericos: %d\n", qtd1);
    } else if (qtd2 > qtd1) {
        printf("A segunda cadeia possui mais digitos. Digitos numericos: %d\n", qtd2);
    } else {
        printf("Ambas as cadeias possuem a mesma quantidade de digitos. Digitos numericos: %d\n", qtd1);
    }

    // Encerrar
    printf("%s\n", "\nApertar ENTER para continuar\n");
    getchar();
}

/*
---------------------------------------------------------------------------------------------------
DOCUMENTACAO
---------------------------------------------------------------------------------------------------

1.0 - DOCUMENTACAO COMPLEMENTAR

- Sem observacoes

---------------------------------------------------------------------------------------------------

2.0 - TESTES

*Method_00: OK
- Sem observacoes

*Method_01: OK
-

*Method_02: OK
-

*Method_03: OK
-

*Method_04: OK
-

*Method_05: OK
-

*Method_06: OK
-

*Method_07: OK
-

*Method_08: OK
-

*Method_09: OK
-

*Method_10: OK
-

*Method_11: OK
-

*Method_12: OK
-
---------------------------------------------------------------------------------------------------
*/
