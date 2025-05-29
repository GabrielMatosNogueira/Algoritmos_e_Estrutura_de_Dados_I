#include <iostream>   // Para entrada/saída (cout, cin)
#include <string>     // Para manipulação de strings (embora não tão usada aqui)
#include <fstream>    // Para operações com arquivos (ofstream, ifstream)
#include <random>     // Para geração de números aleatórios de alta qualidade
#include <limits>     // Para std::numeric_limits (usado na limpeza do buffer de entrada)
#include <vector>     // Uma alternativa mais moderna para matrizes dinâmicas

// Usar namespace std para simplificar (coloquei aqui para abranger todo o código)
using namespace std;

// ---

// Função para limpar o buffer de entrada (melhor que getchar() solto)
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ---

template <typename T>
class matriz {
private:
    int colunas;
    int linhas;
    T** data; // Usando ponteiro para ponteiro para representar a matriz 2D

public:
    // Construtor: Agora inicializa a matriz com as dimensões
    matriz(int numLinhas = 0, int numColunas = 0) : linhas(numLinhas), colunas(numColunas) {
        if (linhas > 0 && colunas > 0) {
            data = new T*[linhas];
            for (int i = 0; i < linhas; ++i) {
                data[i] = new T[colunas];
            }
        } else {
            data = nullptr; // Garante que data seja nullptr se as dimensões forem inválidas
        }
    }

    // Destrutor: Libera a memória alocada dinamicamente
    ~matriz() {
        if (data != nullptr) {
            for (int i = 0; i < linhas; ++i) {
                delete[] data[i]; // Libera cada linha
            }
            delete[] data; // Libera o array de ponteiros para linhas
            data = nullptr; // Evita ponteiro pendurado
        }
    }

    // Método para imprimir a matriz
    void print() const 
        { // Passar por referência constante é mais eficiente e seguro
        if (data == nullptr) 
        {
            cout << "Matriz vazia." << endl;
            return;
        }

        cout << "Conteudo da Matriz:" << endl;
        for (int i = 0; i < linhas; ++i) 
        {
            for (int j = 0; j < colunas; ++j) 
            {
                cout << data[i][j] << "\t"; // Imprime o elemento e um tab
            }
            cout << endl; // Nova linha após cada linha da matriz
        }
    }

    // Método para preencher a matriz com números inteiros aleatórios
    void randomIntGenerate(int inferior, int superior) {
        if (data == nullptr) {
            cout << "Erro: Matriz nao inicializada. Nao e possivel gerar numeros aleatorios." << endl;
            return;
        }

        // Configuração para geração de números aleatórios de alta qualidade
        random_device rd;     // Obtém uma semente do hardware
        mt19937 gen(rd());    // Semeia o gerador Mersenne Twister
        // Define a distribuição para inteiros uniformes no intervalo [inferior, superior]
        uniform_int_distribution<> distrib(inferior, superior);

        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j < colunas; ++j) {
                data[i][j] = distrib(gen); // Preenche a matriz com números aleatórios
            }
        }
    }

    // Métodos para obter os dados da matriz (se precisar de acesso externo)
    int getLinhas() const { return linhas; }
    int getColunas() const { return colunas; }
    T getElemento(int linha, int coluna) const {
        if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas) {
            return data[linha][coluna];
        }
        // Retorne um valor padrão ou lance uma exceção para índices inválidos
        return T(); // Retorna um valor default para o tipo T
    }
};

void end() 
{
    cout << endl << "Aperte ENTER para terminar" << endl;
    cin.get(); // Usa cin.get() para capturar o ENTER
}
