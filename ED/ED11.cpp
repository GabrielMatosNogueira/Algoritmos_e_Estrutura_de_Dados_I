#include "io.hpp"
using namespace std;

class Array
{
    private:
    int n;
    int *data;

    public:
    /**
     * @brief CONSTRUTOR PADRAO
     * 
     * @param void
     */
    Array(void)
    {
        this->n=0;
        this->data=nullptr;
    }

    /**
     * @brief CONSTRUTOR SOFISTICADO
     * @details Passagem de parametro para alterar os atributos do objeto
     * @param void
     */
    Array(const int n)
    {
        this->n=n;
        this->data = new int[this->n];
        for(int i=0; i<this->n; i=i+1)
        {
            this->data[i]=0;
        }
    }

    /**
     * @brief DESTRUTOR PADRAO
     * 
     * @param void
     */
    ~Array()
    {
        this->n=0;
        delete[]data;
    }

    /**
     * @brief ARRAY PRINT
     */
    void print_Array(void)
    {
        if(this->n>0 && this->data!=nullptr)
        {
            for(int i=0; i<this->n; i=i+1)
            {
                printf("[%d] ", this->data[i]);
            }
            cout << endl;
        }
    }

    /**
     * @brief GERADIR DE NUMEROS INTEIROS
     * @details
     * @param limite_Inferior
     * @param limite_Superior
     */
    int* randomIntGenerate(int limite_Inferior, int limite_Superior)
    {
        if(this->n>0)
        {
            if(limite_Inferior < limite_Superior && limite_Inferior!=limite_Superior)
            {
                for(int i=0; i<this->n; i=i+1)
                {
                    this->data[i]=rand()%(limite_Superior-limite_Inferior+1)+limite_Inferior;
                }
            }
        }
    }

    /**
     * @brief veriiicar o maior valor impar dentro de um arranko
     */
    int maior_Valor_Impar(void)
    {
        int maior_Valor_Impar=0;
        for(int i=0; i<this->n; i=i+1)
        {
            if(this->data[i]>maior_Valor_Impar && this->data[i]%2!=0 && this->data[i]%3!=0 && this->data[i]%5!=0 && this->data[i]%7!=0 && this->data[i]%11!=0 && this->data[i]%13!=0)
            {
                maior_Valor_Impar=this->data[i];
            }
        }
        return maior_Valor_Impar;
    }
};

/**
 * @brief METODO 01
 * @details Metodo para gerar 'n' valores aleatórios dentro de um intervalo fechado
 * @param void
 */
void metodo01(void)
{
    int n=0;
    int limite_Inferior=0;
    int limite_Superior=0;

    IO_println("Metodo 01");
    srand(0);

    cout << endl << "Digite o numero de valores aleatorios que deseja gerar" << endl;
    cin >> n;

    cout << endl << "Digite o limite inferior do intervalo de numeros que deseja gerar: " << endl;
    cin >> limite_Inferior;

    cout << endl << "Digite o limite superior do intervalo dos numeros que deseja gerar: " << endl;
    cin >> limite_Superior;

    if(n>0)
    {
        Array array01(n);
        array01.print_Array();
        array01.randomIntGenerate(limite_Inferior, limite_Superior);
        array01.print_Array();
    }

    IO_println("Aperte ENTER para terminar");
    cin.get();
}

/**
 * @brief METODO 02
 * @details procurar o maior valor impar de um arranjo
 */
void metodo02(void)
{
    int n=0;
    IO_println("Metodo 02");
    cout << endl << "Digite o tamanho do array: ";
    cin >> n;
    cin.get();
    Array array02(n);
    array02.randomIntGenerate(0, 100);
    array02.print_Array();
    cout << array02.maior_Valor_Impar();
    getchar();
}

/**
 * @brief METODO 03
 * @details
 * @param
 * @return 
 */

/**
 * @brief METODO PRINCIPAL
 * @details metodo para selecionar metodos
 */
int main(void)
{
    int opcao=0;
    do
    {
        IO_println("01-Gerar 'n' valores aleatorios dentro de um intervalo\n02-Procurar o maior valor impar dentro de um array\n03-Procurar um valor multiplo de 3 em um arranjo\n04-Somar todos os valores de um arranjo entre duas posicoes\n05-Calcular a media dos valores dentro de dois limites em um arranjo\n06-Verificar se todos os valores sao positivos e maiores que 100\n07-Dizer se o vetor esta ordenado\n08-Dizer se um valor 'x' esta dentro de um arranjo\n09-Multiplicar por um escalar os elementos em determinado intervalo([])\n10-Colocar valores em arranjo em ordem crescente");
        IO_println("Digite o metodo desejado: ");
        cin>>opcao;
        cin.get();

        switch (opcao)
        {
            case 1:
            metodo01();
            break;
            
            case 2:
            metodo02();
            break;
        }
    }while(opcao!=0);
    
    return 0;
}