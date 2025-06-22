/*
0870863_Gabriel_Matos_Nogueira
ED15
*/

/*
DEPENDENCIAS/BIBLIOTECAS
*/
#include "io.hpp"
using namespace std;

// Declaracao de funcoes
char* str_push_back(char *s, char c);
char* str_pop_back(char *s);
char* str_push_front(char c, char *s);
char* str_pop_front(char *s);
char* str_push_mid(char *s, char c);
char* str_pop_mid(char *s);
char* str_insert(char *s, char c, int index);
char* str_remove(char *s, int index);
char* str_chr(char *s, char c);
char* str_tok(char *s, char delimiter);
char* str_prefix(char *prefix, char *s);
char* str_suffix(char *s, char *suffix);

/**
 * METODO 01
 * @brief
 * Usuario deve digitar uma cadeia de caracteres e realizar
 * manipulacao de caracteres por meio de ponteiros.
 * 
 * @param
 * @return
 */
void metodo01(void)
{
    IO_println("Metodo 01");
    char *s = new char[1];
    s[0] = '\0'; // Inicializa a string vazia

    string frase="";
    frase=IO_readstring("Digite uma frase: ");

    for (int i = 0; i < frase.length(); ++i) 
    {
        s = str_push_back(s, frase[i]);
    }

    IO_println("Frase armazenada:");
    IO_println(s);

    char c = IO_readchar("Digite um caractere para adicionar ao final: ");
    s = str_push_back(s, c);

    IO_println("Frase apos str_push_back:");
    IO_println(s);

    delete[] s;

    IO_println("Aperte ENTER para continuar...");
    cin.get();
}

/**
 * Funcao para acrescentar caractere ao final
 * de uma cadeia de caracteres, por meio de apontador.
 * @return  apontador para a cadeia atualizada
     @param s - apontador para cadeia de caracteres 
     @param c - caractere a ser inserido 
  */ 
char* str_push_back ( char *s, char c )
{
    char *new_str = new char[strlen(s) + 2];
    strcpy(new_str, s);
    new_str[strlen(s)] = c;
    new_str[strlen(s) + 1] = '\0';
    delete[] s;
    return new_str;
}

/**
 * Funcao para remover caractere do final
 * de uma cadeia de caracteres, por meio de apontador.
 * @return  apontador para a cadeia atualizada, ou vazia,
 * @param s - apontador para cadeia de caracteres
 */
char* str_pop_back ( char *s )
{
    if (strlen(s) == 0) {
        return s;
    }
    
    char *new_str = new char[strlen(s)];
    strncpy(new_str, s, strlen(s) - 1);
    new_str[strlen(s) - 1] = '\0';
    delete[] s;
    return new_str;
}

/**
 * METODO 02
 * @brief
 *
 * @param
 * @return
 */
void metodo02(void)
{
    IO_println("Metodo 02 - Exemplo de uso de ponteiros");
    char *s = new char[1];
    s[0] = '\0';

    string frase = IO_readstring("Digite uma frase: ");
    for (int i = 0; i < frase.length(); ++i)
    {
        s = str_push_back(s, frase[i]);
    }

    IO_println("Frase armazenada:");
    IO_println(s);

    s = str_pop_back(s);
    cout<<endl;
    IO_println("Frase apos str_pop_back:");
    IO_println(s);

    delete[] s;

    IO_println("Aperte ENTER para continuar...");
    cin.get();
}

/**  
    Funcao para acrescentar caractere ao início 
    de uma cadeia de caracteres, por meio de apontador. 
    @return  apontador para a cadeia atualizada 
    @param c - caractere a ser inserido 
    @param s - apontador para cadeia de caracteres 
  */ 
char* str_push_front ( char c, char *s ) 
{
    char *new_str = new char[strlen(s) + 2];
    new_str[0] = c; // Coloca o novo caractere no início
    strcpy(new_str + 1, s); // Copia a cadeia original para após o novo caractere
    delete[] s; // Libera a memória da cadeia original
    return new_str; // Retorna a nova cadeia
}

/**
 * METODO 03
 * @brief   
 * O usuario deve digitar uma frase e ela sera armazenada usando str_push_front,
 * ou seja, um caractere escolhido pelo usuario sera inserido no inicio da frase.
 *
 * @param
 * @return
 */
void metodo03(void)
{
    IO_println("Metodo 03 - Exemplo de uso de ponteiros");
    char *s = new char[1];
    s[0] = '\0';

    string frase = IO_readstring("Digite uma frase: ");
    for (int i = 0; i < frase.length(); ++i)
    {
       s = str_push_back(s, frase[i]);
    }

    char c = IO_readchar("Digite um caractere para adicionar ao inicio da frase: ");
    s = str_push_front(c, s);

    IO_println("Frase armazenada (com caractere no inicio):");
    IO_println(s);

    cout<<endl;
    IO_println("Frase apos str_push_front:");
    IO_println(s);

    delete[] s;

    IO_println("Aperte ENTER para continuar...");
    cin.get();
}

/**  
    Funcao para remover caractere do início 
    de uma cadeia de caracteres, por meio de apontador. 
    @return  apontador para a cadeia atualizada, ou vazia, 
    @param s - apontador para cadeia de caracteres 
  */ 
char* str_pop_front ( char *s ) 
{
    if (strlen(s) == 0) 
    {
       return s; // Retorna a cadeia vazia se já estiver vazia
    }

    char *new_str = new char[strlen(s)];
    strcpy(new_str, s + 1); // Copia a cadeia original, ignorando o primeiro caractere
    delete[] s;
    return new_str;
}

/**
 * METODO 04
 * @brief
 * O usuario pode digitar uma frase, que será armazenada normalmente,
 * e depois pode remover o primeiro caractere usando str_pop_front.
 *
 * @param
 * @return
 */
void metodo04(void)
{
    IO_println("Metodo 04 - Exemplo de uso de ponteiros");
    char *s = new char[1];
    s[0] = '\0';

    string frase = IO_readstring("Digite uma frase: ");
    for (int i = 0; i < frase.length(); ++i)
    {
       s = str_push_back(s, frase[i]);
    }

    IO_println("Frase armazenada:");
    IO_println(s);

    s = str_pop_front(s);
    cout<<endl;
    IO_println("Frase apos remover o primeiro caractere:");
    IO_println(s);

    delete[] s;

    IO_println("Aperte ENTER para continuar...");
    cin.get();
}

/**
 * Funcao para inserir caractere no meio (aproximadamente)
 * de uma cadeia de caracteres, por meio de apontador,
 * se houver pelo menos dois caracteres.
 * @return  apontador para a cadeia atualizada
 * @param s - apontador para cadeia de caracteres
 * @param c - caractere a ser inserido
 */
char* str_push_mid(char *s, char c)
{
    if (strlen(s) < 2)
    {
        return s; // Retorna a cadeia original se tiver menos de dois caracteres
    }

    int mid = strlen(s) / 2; // Calcula o índice do meio
    char *new_str = new char[strlen(s) + 2]; // Aloca memória para a nova cadeia

    strncpy(new_str, s, mid); // Copia a primeira metade
    new_str[mid] = c; // Insere o novo caractere no meio
    strcpy(new_str + mid + 1, s + mid); // Copia a segunda metade

    delete[] s; // Libera a memória da cadeia original
    return new_str; // Retorna a nova cadeia
}

/**
 * METODO 05
 * @brief
 * O usuário digita uma frase, e um caractere é inserido no meio dela.
 * @param
 * @return
 */
void metodo05(void)
{
    IO_println("Metodo 05 - Exemplo de uso de ponteiros");
    char *s = new char[1];
    s[0] = '\0'; // Inicializa a string vazia

    string frase = IO_readstring("Digite uma frase: ");
    for (int i = 0; i < frase.length(); ++i)
    {
        s = str_push_back(s, frase[i]);
    }

    IO_println("Frase armazenada:");
    IO_println(s);

    if (strlen(s) < 2)
    {
        IO_println("A frase precisa ter pelo menos dois caracteres para inserir no meio.");
    }
    else
    {
        char c = IO_readchar("Digite um caractere para inserir no meio da frase: ");
        s = str_push_mid(s, c);

        cout<<endl;
        IO_println("Frase apos inserir caractere no meio:");
        IO_println(s);
    }

    delete[] s;

    IO_println("Aperte ENTER para continuar...");
    cin.get();
}

/**  
    Funcao para remover caractere do meio (aproximadamente) 
    de uma cadeia de caracteres, por meio de apontador. 
    Se houver ao menos dois caracteres, remover o do meio. 
    @return  apontador para a cadeia atualizada 
    @param s - apontador para cadeia de caracteres 
  */ 
char* str_pop_mid ( char *s ) 
{
    if (strlen(s) < 2) 
    {
       return s; // Retorna a cadeia original se tiver menos de dois caracteres
    }

    int mid = strlen(s) / 2;
    char *new_str = new char[strlen(s)];

    strncpy(new_str, s, mid);
    strcpy(new_str + mid, s + mid + 1);

    delete[] s;
    return new_str;
}

/**
 * METODO 06
 * @brief
 * O usuário digita uma frase, e o caractere do meio é removido.
 * @param
 * @return
 */
void metodo06(void)
{
    IO_println("Metodo 06 - Exemplo de uso de ponteiros");
    char *s = new char[1];
    s[0] = '\0'; // Inicializa a string vazia

    string frase = IO_readstring("Digite uma frase: ");
    for (int i = 0; i < frase.length(); ++i)
    {
       s = str_push_back(s, frase[i]);
    }

    IO_println("Frase armazenada:");
    IO_println(s);

    if (strlen(s) < 2)
    {
       IO_println("A frase precisa ter pelo menos dois caracteres para remover o do meio.");
    }
    else
    {
       s = str_pop_mid(s);
       IO_println("Frase apos remover o caractere do meio:");
       IO_println(s);
    }

    delete[] s;

    IO_println("Aperte ENTER para continuar...");
    cin.get();
}

/**
 * Funcao para inserir caractere em certa posição válida 
 * de uma cadeia de caracteres, por meio de apontador. 
 * @return  apontador para a cadeia atualizada 
 * @param s        - apontador para cadeia de caracteres 
 * @param c - caractere a ser inserido 
 * @param index - posicao onde inserir 
 */ 
char* str_insert ( char *s, char c, int index ) 
{
    if (index < 0 || index > strlen(s))
    {
        return s;
    }
    char *new_str = new char[strlen(s) + 2];
    strncpy(new_str, s, index);
    new_str[index] = c;
    strcpy(new_str + index + 1, s + index);
    delete[] s;
    return new_str;
}

/**
 * METODO 07
 * @brief
 * O usuário digita uma frase, um caractere e a posição onde deseja inserir.
 * O caractere é inserido na posição desejada da frase.
 * @param
 * @return
 */
void metodo07(void)
{
    IO_println("Metodo 07 - Inserir caractere em posicao especifica");
    char *s = new char[1];
    s[0] = '\0'; // Inicializa a string vazia

    string frase = IO_readstring("Digite uma frase: ");
    for (int i = 0; i < frase.length(); ++i)
    {
        s = str_push_back(s, frase[i]);
    }

    IO_println("Frase armazenada:");
    IO_println(s);

    char c = IO_readchar("Digite o caractere a ser inserido: ");
    int index = IO_readint("Digite a posicao onde inserir (0 a tamanho da frase): ");

    if (index < 0 || index > strlen(s)) {
        IO_println("Posicao invalida.");
    } else {
        s = str_insert(s, c, index);
        IO_println("Frase apos insercao:");
        IO_println(s);
    }

    delete[] s;
    IO_println("Aperte ENTER para continuar...");
    cin.get();
}

/**
 * Funcao para remover caractere de certa posição válida 
 * de uma cadeia de caracteres, por meio de apontador. 
 * @return  apontador para a cadeia atualizada 
 * @param s        - apontador para cadeia de caracteres 
 * @param index - posicao de onde remover 
 */ 
char* str_remove ( char *s, int index )
{
    if (index < 0 || index >= strlen(s))
    {
        return s; // Retorna a cadeia original se o índice for inválido
    }
    char *new_str = new char[strlen(s)]; // Aloca memória para a nova cadeia
    strncpy(new_str, s, index); // Copia a parte antes do índice
    strcpy(new_str + index, s + index + 1); // Copia a parte após o índice, ignorando o caractere a ser removido
    delete[] s; // Libera a memória da cadeia original
    return new_str; // Retorna a nova cadeia
}

/**
 * METODO 08
 * @brief
 * O usuário pode digitar a frase, e depois escolher a posição de um caractere para remover.
 * @param
 * @return
 */
void metodo08(void)
{
    IO_println("Metodo 08 - Remover caractere de posicao especifica");
    char *s = new char[1];
    s[0] = '\0'; // Inicializa a string vazia

    string frase = IO_readstring("Digite uma frase: ");
    for (int i = 0; i < frase.length(); ++i)
    {
        s = str_push_back(s, frase[i]);
    }

    IO_println("Frase armazenada:");
    IO_println(s);

    int index = IO_readint("Digite a posicao do caractere a ser removido (0 a tamanho-1): ");
    if (index < 0 || index >= strlen(s)) 
    {
        IO_println("Posicao invalida.");
    }

    else 
    {
        s = str_remove(s, index);
        cout << endl;
        IO_println("Frase apos remocao:");
        IO_println(s);
    }

    delete[] s;

    IO_println("Aperte ENTER para continuar...");
    cin.get();
}

/**  
    Funcao para procurar pela primeira ocorrencia de certo símbolo 
    em uma cadeia de caracteres, por meio de apontador. 
    @return apontador para a primeira ocorrência; nullptr (NULL), caso contrario 
    @param s - apontador para cadeia de caracteres 
    @param c - caractere a ser procurado 
  */ 
char* str_chr ( char *s, char c )
{
    while (s != nullptr && *s != '\0')
    {
       if (*s == c)
       {
          return s; // Retorna o ponteiro para a ocorrência encontrada
       }
       s++;
    }
    return nullptr; // Retorna nullptr se não encontrar a ocorrência
}

/**
 * METODO 09
 * @brief
 * O usuario pode digitar a frase e um caractere, e o programa mostra a primeira ocorrencia do caractere.
 * @param
 * @return
 */
void metodo09(void)
{
    IO_println("Metodo 09 - Procurar primeira ocorrencia de caractere");
    char *s = new char[1];
    s[0] = '\0'; // Inicializa a string vazia

    string frase = IO_readstring("Digite uma frase: ");
    for (int i = 0; i < frase.length(); ++i)
    {
       s = str_push_back(s, frase[i]);
    }

    IO_println("Frase armazenada:");
    IO_println(s);

    char c = IO_readchar("Digite o caractere a ser procurado: ");
    char* pos = str_chr(s, c);

    if (pos != nullptr)
    {
       int index = pos - s;
       IO_printf("Primeira ocorrencia de '%c' encontrada na posicao: %d\n", c, index);
    }
    else
    {
       IO_printf("Caractere '%c' nao encontrado na frase.\n", c);
    }

    delete[] s;
    IO_println("Aperte ENTER para continuar...");
    cin.get();
}

/**  
    Funcao para separar caracteres ate' a ocorrencia de delimitador 
    em uma cadeia de caracteres, por meio de apontador. 
    @return apontador para caracteres; nullptr (NULL), caso contrario 
    @param s             - apontador para cadeia de caracteres 
    @param delimiter - caractere a ser procurado 
*/ 
char* str_tok ( char *s, char delimiter ) 
{
    static char *last = nullptr; // Ponteiro estático para a última posição
    if (s != nullptr)
    {
        last = s; // Atualiza a última posição
    }
    if (last == nullptr)
    {
        return nullptr; // Retorna nullptr se não houver mais tokens
    }
    char *token = last; // Salva o início do token
    while (*last != '\0' && *last != delimiter)
    {
        last++;
    }
    if (*last == delimiter)
    {
        *last = '\0'; // Substitui o delimitador por '\0'
        last++; // Avança para o próximo caractere
    }
    else if (*last == '\0')
    {
        last = nullptr; // Fim da string, não há mais tokens
    }
    return token; // Retorna o token encontrado
}

/**
 * METODO 10
 * @brief
 * O usuario pode digitar a frase e um delimitador, e o programa mostra os tokens separados.
 * @param
 * @return
 */
void metodo10(void)
{
    IO_println("Metodo 10 - Separar frase em tokens usando delimitador");
    char *s = new char[1];
    s[0] = '\0'; // Inicializa a string vazia

    string frase = IO_readstring("Digite uma frase: ");
    for (int i = 0; i < frase.length(); ++i)
    {
        s = str_push_back(s, frase[i]);
    }

    char delimiter = IO_readchar("Digite o delimitador: ");

    IO_println("Tokens encontrados:");
    char *token = str_tok(s, delimiter);
    int count = 0;
    while (token != nullptr && *token != '\0')
    {
        IO_printf("Token %d: %s\n", ++count, token);
        token = str_tok(nullptr, delimiter);
    }

    delete[] s;
    IO_println("Aperte ENTER para continuar...");
    cin.get();
}

/**  
    Funcao para procurar por certo prefixo ( "iniciar por" ) 
    em cadeia de caracteres, por meio de apontador. 
    @return apontador para a primeira ocorrência; nullptr (NULL), caso contrario 
    @param prefix - prefixo a ser procurado 
    @param s        - apontador para cadeia de caracteres 
*/ 
char* str_prefix ( char *prefix, char *s )
{
    while (*prefix != '\0' && *s != '\0')
    {
       if (*prefix != *s)
       {
          return nullptr; // Retorna nullptr se os caracteres não coincidirem
       }
       prefix++;
       s++;
    }
    return s;
}

/**
 * METODO 015E1
 * @brief
 * O usuario pode digitar a frase e um prefixo, e o programa verifica se a frase inicia com o prefixo.
 * @param
 * @return
 */
void metodo_015E1(void)
{
    IO_println("Metodo 015E1 - Verificar prefixo em frase");
    char *s = new char[1];
    s[0] = '\0'; // Inicializa a string vazia

    string frase = IO_readstring("Digite uma frase: ");
    for (int i = 0; i < frase.length(); ++i)
    {
       s = str_push_back(s, frase[i]);
    }

    string prefixo = IO_readstring("Digite o prefixo a ser procurado: ");
    char *prefix = new char[prefixo.length() + 1];
    strcpy(prefix, prefixo.c_str());

    char *result = str_prefix(prefix, s);

    if (result != nullptr)
    {
       IO_println("A frase comeca com o prefixo informado.");
    }
    else
    {
       IO_println("A frase NAO comeca com o prefixo informado.");
    }

    delete[] s;
    delete[] prefix;
    IO_println("Aperte ENTER para continuar...");
    cin.get();
}

/**  
    Funcao para procurar por certo sufixo ( "terminar em" ) 
    em cadeia de caracteres, por meio de apontador. 
    @return apontador para a primeira ocorrência; nullptr (NULL), caso contrario 
    @param s        - apontador para cadeia de caracteres 
    @param suffix - sufixo a ser procurado 
  */ 
char* str_suffix ( char *s, char *suffix )
{
    int s_len = strlen(s);
    int suffix_len = strlen(suffix);
    if (suffix_len > s_len)
    {
       return nullptr;
    }
    char *s_start = s + s_len - suffix_len;
    while (*s_start != '\0' && *suffix != '\0')
    {
       if (*s_start != *suffix)
       {
          return nullptr;
       }
       s_start++;
       suffix++;
    }
    return s_start;
}

/**
 * METODO 015E2
 * @brief
 * O usuario pode digitar a frase e um sufixo, e o programa verifica se a frase termina com o sufixo.
 * @param
 * @return
 */
void metodo_015E2(void)
{
    IO_println("Metodo 015E2 - Verificar sufixo em frase");
    char *s = new char[1];
    s[0] = '\0'; // Inicializa a string vazia

    string frase = IO_readstring("Digite uma frase: ");
    for (int i = 0; i < frase.length(); ++i)
    {
       s = str_push_back(s, frase[i]);
    }

    string sufixo = IO_readstring("Digite o sufixo a ser procurado: ");
    char *suffix = new char[sufixo.length() + 1];
    strcpy(suffix, sufixo.c_str());

    char *result = str_suffix(s, suffix);

    if (result != nullptr)
    {
       IO_println("A frase termina com o sufixo informado.");
    }
    else
    {
       IO_println("A frase NAO termina com o sufixo informado.");
    }

    delete[] s;
    delete[] suffix;
    IO_println("Aperte ENTER para continuar...");
    cin.get();
}

/**
 * METODO PRINCIPAL
 * @brief
 *
 * @param
 * @return
 */
int main(void)
{
    {
        int opcao = 0;
        do
        {
            IO_methods(15);
            opcao = IO_readint("\nDigite a opcao desejada: ");

            switch (opcao)
            {
            case 0:
                break;
            case 1:
                metodo01();
                break;

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
                metodo_015E1();
                break;

            case 12:
                metodo_015E2();
                break;
            }

        } while (opcao != 0);

        return 0;
    }
} // end main ( )
