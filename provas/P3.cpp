#include "io.hpp"

class Poly
{
private:
    int n;
    int *data;

public:
    /**
     * @brief Construtor com passagem de parametro
     * @param void
     */
    Poly(void)
    {
        this->n = 0;
        this->data = nullptr;
    }

    Poly(string filename)
    {
        int n=0;
        if (!(filename.empty()))
        {
            ifstream file;
            file.open(filename);
            if(file)
            {
                file >> n;
                this->n = n;
            }
            if(n>0)
            {
                for(int i=0; i<this->n+1; i=i+1)
                {
                    file >> this->data[i];
                }
            }
        }
    }
};
/**
 * @brief ESTRUTURA DA EQUAÇÃO
 * a(n) * x^(n) + a(n-1) * x^(n-1) + ... + a(2) * x^(2) + a(1) * x^(1) + a(0)
 * -------------------------------------------------------------------------------------
 * @brief ESTRUTURA DO ARQUIVO
 * x : valor ja fornecido (lido)
 * L1: (N) valor do maior expoente
 * L2: (A(n))
 * L3: (A(n-1))
 * L4: (A(n-2))
 */
/**
 * 01 - Criar construtor para ler dados (valor de n) e os valores das de um arquivo e salvar em objeto
 * 02 - Converter dados do arranjo em string (a * x^n + a(n-1) * x^(n-1) + ... + a(2) * x^2 + a(1) * x^1 + a(0))
 * 03 - Testar se os polinômios, em uma determinada posição, são iguais a zero
 * 04 - Testar se dois polinômios são iguais
 * 05 - Fazer derivada da primeira do polinômio
 * 06 - Fazer derivada da segunda do polinômio
 * 07 - Salvar dados em um arquivo
 */
int main(void)
{
    int opcao = 0;
    do
    {
        printf("\n01-Construtor para ler dados de um arquivo\n02-Converter os dados para string\n03-Teste se em certa posicao o polinomio e' zero\n04-Testar se os polinomios sao iguais\n05-Derivada da primeira \n06-Derivada da segunda \n07-Salvar dados em um arquivo\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            /* code */
            break;

        default:
            break;
        }
    } while (opcao != 0);
}