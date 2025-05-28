/*
    ED11 - v0.0 - 25/05/2024
    Author: Gabriel Matos Nogueira
*/

// Dependencias
#include <iostream> // std::cin, std::cout, std::endl
#include <limits>   // std::numeric_limits
#include <string>   // para cadeias de caracteres
#include <cstdlib>  // std::rand, std::srand
#include <ctime>    // std::time
#include <fstream>  // para manipulação de arquivos

// ----------------------------------------------- definicoes globais

void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl
              << text;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, dummy);
    std::cout << std::endl
              << std::endl;
} // end pause ( )

// ----------------------------------------------- classes / pacotes

// Definicao minima de MyArray para evitar erro de identificador indefinido
template <typename T>
class MyArray
{
protected:
    T *data;
    int size;

public:
    MyArray(int n) : size(n) { data = new T[n]; }
    virtual ~MyArray() { delete[] data; }
    void set(int i, T value) { data[i] = value; }
    T get(int i) const { return data[i]; }
    int length() const { return size; }
};


template <>
class MyArray<int>
{
    int *data;
    int size;

public:
    MyArray(int n) : size(n) { data = new int[n]; }

    MyArray(const MyArray<int>& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    MyArray<int>& operator=(const MyArray<int>& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    ~MyArray() { delete[] data; }
    void set(int i, int value) { data[i] = value; }
    int get(int i) const { return data[i]; }
    int length() const { return size; }

    int searchFirstOdd() const
    {
        int maior = std::numeric_limits<int>::min();
        bool found = false;
        for (int i = 0; i < size; i = i + 1)
        {
            int v = data[i];
            if (v % 2 != 0)
            {
                if (!found)
                {
                    maior = v;
                    found = true;
                }
                else if (v > maior)
                {
                    maior = v;
                }
            }
        }
        if (found)
        {
            return maior;
        }
        else
        {
            return std::numeric_limits<int>::min();
        }
    }
};

using namespace std;

// ----------------------------------------------- metodos

/**
    Method_00 - nao faz nada.
 */
void method_00()
{
    // nao faz nada
} // end method_00 ( )

/**
 * Preenche um arranjo de inteiros com valores aleatorios no intervalo [min, max].
 * @param n Tamanho do arranjo.
 * @param min Valor minimo.
 * @param max Valor maximo.
 * @return O arranjo preenchido.
 */
MyArray<int> arranjo_randomintFill(int n, int min, int max)
{
    MyArray<int> arr(n);
    int valor = 0;
    int i = 0;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (i = 0; i < arr.length(); i++)
    {
        valor = min + std::rand() % (max - min + 1);
        arr.set(i, valor);
    }
    return arr;
}

/**
 * Method_01 - Gerar N valores aleatorios e gravar em arquivo DADOS.TXT.
 */
void method_01()
{
    // identificar
    cout << endl << "Method_01 - v0.0" << endl;

    int n = 0;
    int min = 0;
    int max = 0;
    int i = 0;

    // ler quantidade de valores a serem gerados
    cout << "Entrar com a quantidade de valores a serem gerados: ";
    cin >> n;
    while (n <= 0)
    {
        cout << "ERRO: Valor invalido. Deve ser maior que zero." << endl;
        cout << "Entrar com a quantidade de valores a serem gerados: ";
        cin >> n;
    }

    // ler valor minimo
    cout << "Entrar com o valor minimo: ";
    cin >> min;
    while (min < 0)
    {
        cout << "ERRO: Valor invalido. Deve ser maior ou igual a zero." << endl;
        cout << "Entrar com o valor minimo: ";
        cin >> min;
    }

    // ler valor maximo
    cout << "Entrar com o valor maximo: ";
    cin >> max;
    while (max <= min || max > 1000000)
    {
        cout << "ERRO: Valor invalido. Deve ser maior que o valor minimo e menor que 1000000." << endl;
        cout << "Entrar com o valor maximo: ";
        cin >> max;
    }

    // gerar arranjo de inteiros aleatorios
    MyArray<int> arr = arranjo_randomintFill(n, min, max);

    // gravar no arquivo
    std::ofstream outfile;
    outfile.open("method_01.txt");
    if (!outfile)
    {
        std::cerr << "ERRO: Nao foi possivel criar o arquivo DADOS.TXT." << std::endl;
    }
    else
    {
        outfile << n << std::endl;
        for (i = 0; i < n; i = i + 1)
        {
            outfile << arr.get(i) << std::endl;
        }
        outfile.close();

        // Exibir os valores gerados
        cout << "Valores gerados: ";
        for (i = 0; i < n; i = i + 1)
        {
            cout << arr.get(i) << " ";
        }
        cout << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_01 ( )

/**
    Method readArrayFromFile
 */
MyArray<int> readArrayFromFile(const std::string& filename)
{
    std::ifstream infile(filename);
    if (!infile)
    {
        std::cerr << "ERRO: Nao foi possivel abrir o arquivo " << filename << "." << std::endl;
        return MyArray<int>(0);
    }
    int n = 0;
    infile >> n;
    if (n <= 0)
    {
        std::cerr << "ERRO: Tamanho invalido no arquivo." << std::endl;
        return MyArray<int>(0);
    }
    MyArray<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        int valor = 0;
        infile >> valor;
        arr.set(i, valor);
    }
    infile.close();
    return arr;
}

/**
    Method_02 - Procurar o maior valor ímpar em um arranjo lido de arquivo.
 */
void method_02()
{
    // identificar
    cout << endl
         << "Method_02 - Procurar maior valor impar em arquivo" << endl;

    std::string filename;
    cout << "Digite o nome do arquivo: ";
    cin >> filename;

    MyArray<int> arr = readArrayFromFile(filename);
    if (arr.length() == 0)
    {
        cout << "Arranjo vazio ou erro ao ler arquivo." << endl;
    }
    else
    {
        int maior = arr.searchFirstOdd();
        if (maior == std::numeric_limits<int>::min())
        {
            cout << "Nao ha valores impares no arranjo." << endl;
        }
        else
        {
            cout << "Maior valor impar encontrado: " << maior << endl;
        }
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_02 ( )

/**
 * Adiciona metodo para procurar o maior valor ímpar múltiplo de 3.
 */
class MyArrayIntWithOddx3 : public MyArray<int> {
public:
    using MyArray<int>::MyArray;
    int searchFirstOddx3() const
    {
        int maior = std::numeric_limits<int>::min();
        bool found = false;
        for (int i = 0; i < this->length(); ++i)
        {
            int v = this->get(i);
            if (v % 2 != 0 && v % 3 == 0)
            {
                if (!found)
                {
                    maior = v;
                    found = true;
                }
                else if (v > maior)
                {
                    maior = v;
                }
            }
        }
        if (found)
            return maior;
        else
            return std::numeric_limits<int>::min();
    }
};

/**
    Method_03 - Procurar o maior valor ímpar múltiplo de 3 em um arranjo lido de arquivo.
 */
void method_03()
{
    // identificar
    cout << endl
         << "Method_03 - Maior valor impar multiplo de 3 em arquivo" << endl;

    std::string filename;
    cout << "Digite o nome do arquivo: ";
    cin >> filename;

    MyArray<int> baseArr = readArrayFromFile(filename);
    if (baseArr.length() == 0)
    {
        cout << "Arranjo vazio ou erro ao ler arquivo." << endl;
    }
    else
    {
        MyArrayIntWithOddx3 arr(baseArr.length());
        for (int i = 0; i < baseArr.length(); i = i + 1)
        {
            arr.set(i, baseArr.get(i));
        }
        int maior = arr.searchFirstOddx3();
        if (maior == std::numeric_limits<int>::min())
        {
            cout << "Nao ha valores impares multiplos de 3 no arranjo." << endl;
        }
        else
        {
            cout << "Maior valor impar multiplo de 3 encontrado: " << maior << endl;
        }
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_03 ( )

/**
 * Adiciona metodo para somar valores em um intervalo [inicio, fim] do arranjo.
 */
class MyArrayIntWithAddInterval : public MyArray<int> {
public:
    using MyArray<int>::MyArray;
    int addInterval(int inicio, int fim) const
    {
        if (inicio < 0) inicio = 0;
        if (fim >= this->length()) fim = this->length() - 1;
        if (inicio > fim || this->length() == 0) return 0;
        int soma = 0;
        for (int i = inicio; i <= fim; i = i + 1)
        {
            soma = soma + this->get(i);
        }
        return soma;
    }
};

/**
    Method_04 - Somar valores em intervalo do arranjo lido de arquivo.
 */
void method_04()
{
    // identificar
    cout << endl
         << "Method_04 - Somar valores em intervalo do arranjo" << endl;

    std::string filename;
    cout << "Digite o nome do arquivo: ";
    cin >> filename;

    MyArray<int> baseArr = readArrayFromFile(filename);
    if (baseArr.length() == 0)
    {
        cout << "Arranjo vazio ou erro ao ler arquivo." << endl;
    }
    else
    {
        int inicio, fim;
        cout << "Digite a posicao inicial (0.." << baseArr.length() - 1 << "): ";
        cin >> inicio;
        cout << "Digite a posicao final (0.." << baseArr.length() - 1 << "): ";
        cin >> fim;

        MyArrayIntWithAddInterval arr(baseArr.length());
        for (int i = 0; i < baseArr.length(); ++i)
        {
            arr.set(i, baseArr.get(i));
        }
        int soma = arr.addInterval(inicio, fim);
        cout << "Soma dos valores no intervalo [" << inicio << ", " << fim << "]: " << soma << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_04 ( )

/*
 * Adiciona metodo para calcular a média dos valores em um intervalo [inicio, fim] do arranjo.
 */
class MyArrayIntWithAverageInterval : public MyArray<int> {
public:
    using MyArray<int>::MyArray;
    double averageInterval(int inicio, int fim) const
    {
        if (inicio < 0) inicio = 0;
        if (fim >= this->length()) fim = this->length() - 1;
        if (inicio > fim || this->length() == 0) return 0.0;
        int soma = 0;
        int count = 0;
        for (int i = inicio; i <= fim; ++i)
        {
            soma += this->get(i);
            ++count;
        }
        if (count == 0) return 0.0;
        return static_cast<double>(soma) / count;
    }
};

/*
    Method_05 - Calcular média dos valores em intervalo do arranjo lido de arquivo.
 */
void method_05()
{
    // identificar
    cout << endl
         << "Method_05 - Calcular media dos valores em intervalo do arranjo" << endl;

    std::string filename;
    cout << "Digite o nome do arquivo: ";
    cin >> filename;

    MyArray<int> baseArr = readArrayFromFile(filename);
    if (baseArr.length() == 0)
    {
        cout << "Arranjo vazio ou erro ao ler arquivo." << endl;
    }
    else
    {
        int inicio, fim;
        cout << "Digite a posicao inicial (0.." << baseArr.length() - 1 << "): ";
        cin >> inicio;
        cout << "Digite a posicao final (0.." << baseArr.length() - 1 << "): ";
        cin >> fim;

        MyArrayIntWithAverageInterval arr(baseArr.length());
        for (int i = 0; i < baseArr.length(); ++i)
        {
            arr.set(i, baseArr.get(i));
        }
        double media = arr.averageInterval(inicio, fim);
        cout << "Media dos valores no intervalo [" << inicio << ", " << fim << "]: " << media << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_05 ( )

class arranjo_negatives : public MyArray<int> {
public:
    using MyArray<int>::MyArray;
    bool allPositiveAbove100() const
    {
        for (int i = 0; i < this->length(); ++i)
        {
            int v = this->get(i);
            if (v <= 100 || v <= 0)
                return false;
        }
        return this->length() > 0;
    }
};

/**
    Method_06 - Verificar se todos os valores são positivos e maiores que 100 em um arranjo lido de arquivo.
 */
void method_06()
{
    // identificar
    cout << endl
         << "Method_06 - Verificar se todos os valores sao positivos e maiores que 100" << endl;

    MyArray<int> baseArr = readArrayFromFile("method_01.txt");
    if (baseArr.length() == 0)
    {
        cout << "Arranjo vazio ou erro ao ler arquivo." << endl;
    }
    else
    {
        arranjo_negatives arr(baseArr.length());
        for (int i = 0; i < baseArr.length(); ++i)
        {
            arr.set(i, baseArr.get(i));
        }
        bool teste = arr.allPositiveAbove100();
        if (teste)
            cout << "Todos os valores sao positivos e maiores que 100." << endl;
        else
            cout << "Nem todos os valores sao positivos e maiores que 100." << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_06 ( )

class MyArrayIntWithIsDecrescent : public MyArray<int> {
public:
    using MyArray<int>::MyArray;
    bool isDecrescent() const
    {
        bool decrescente = true;
        for (int i = 0; i < this->length() - 1; ++i)
        {
            if (this->get(i) < this->get(i + 1))
                decrescente = false;
        }
        return decrescente && this->length() > 1;
    }
};

/**
    Method_07 - Verificar se arranjo está em ordem decrescente.
 */
void method_07()
{
    // identificar
    cout << endl
         << "Method_07 - Verificar se arranjo esta em ordem decrescente" << endl;

    std::string filename;
    cout << "Digite o nome do arquivo: ";
    cin >> filename;

    MyArray<int> baseArr = readArrayFromFile(filename);
    if (baseArr.length() == 0)
    {
        cout << "Arranjo vazio ou erro ao ler arquivo." << endl;
    }
    else
    {
        MyArrayIntWithIsDecrescent arr(baseArr.length());
        for (int i = 0; i < baseArr.length(); ++i)
        {
            arr.set(i, baseArr.get(i));
        }
        bool teste = arr.isDecrescent();
        if (teste)
            cout << "Arranjo esta em ordem decrescente." << endl;
        else
            cout << "Arranjo NAO esta em ordem decrescente." << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_07 ( )

/**
 * Classe para busca de valor em intervalo do arranjo.
 */
class arranjo_searchInterval : public MyArray<int> {
public:
    using MyArray<int>::MyArray;
    bool searchInterval(int valor, int inicio, int fim) const
    {
        if (inicio < 0) inicio = 0;
        if (fim >= this->length()) fim = this->length() - 1;
        if (inicio > fim || this->length() == 0) return false;
        for (int i = inicio; i <= fim; ++i)
        {
            if (this->get(i) == valor)
                return true;
        }
        return false;
    }
};

/**
    Method_08 - Procurar valor em intervalo do arranjo lido de arquivo.
 */
void method_08()
{
    // identificar
    cout << endl
         << "Method_08 - Procurar valor em intervalo do arranjo" << endl;

    // Ler arquivo
    MyArray<int> baseArr = readArrayFromFile("method_01.txt");
    if (baseArr.length() == 0)
    {
        cout << "Arranjo vazio ou erro ao ler arquivo." << endl;
    }
    else
    {
        int procurado, inicio, fim;
        cout << "Digite o valor a ser procurado: ";
        cin >> procurado;
        cout << "Digite a posicao inicial (0.." << baseArr.length() - 1 << "): ";
        cin >> inicio;
        cout << "Digite a posicao final (0.." << baseArr.length() - 1 << "): ";
        cin >> fim;

        arranjo_searchInterval arr(baseArr.length());
        for (int i = 0; i < baseArr.length(); ++i)
        {
            arr.set(i, baseArr.get(i));
        }
        bool existe = arr.searchInterval(procurado, inicio, fim);
        if (existe)
            cout << "O valor " << procurado << " existe no intervalo [" << inicio << ", " << fim << "]." << endl;
        else
            cout << "O valor " << procurado << " NAO existe no intervalo [" << inicio << ", " << fim << "]." << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_08 ( )

/**
 * Classe para escalar valores em um intervalo do arranjo.
 */
class arranjo_scalar : public MyArray<int> {
public:
    using MyArray<int>::MyArray;
    MyArray<int> scalar(int constante, int inicio, int fim) const
    {
        MyArray<int> result(this->length());
        for (int i = 0; i < this->length(); ++i)
        {
            if (i >= inicio && i <= fim)
                result.set(i, this->get(i) * constante);
            else
                result.set(i, this->get(i));
        }
        return result;
    }
};

/**
    Method_09 - Escalar valores do arranjo em intervalo.
 */
void method_09()
{
    // identificar
    cout << endl
         << "Method_09 - Escalar valores do arranjo em intervalo" << endl;

    // Ler arquivo
    MyArray<int> baseArr = readArrayFromFile("method_01.TXT");
    if (baseArr.length() == 0)
    {
        cout << "Arranjo vazio ou erro ao ler arquivo." << endl;
    }
    else
    {
        int constante, inicio, fim;
        cout << "Digite a constante para escalar: ";
        cin >> constante;
        cout << "Digite a posicao inicial (0.." << baseArr.length() - 1 << "): ";
        cin >> inicio;
        cout << "Digite a posicao final (0.." << baseArr.length() - 1 << "): ";
        cin >> fim;

        arranjo_scalar arr(baseArr.length());
        for (int i = 0; i < baseArr.length(); ++i)
        {
            arr.set(i, baseArr.get(i));
        }
        MyArray<int> novo = arr.scalar(constante, inicio, fim);

        cout << "Arranjo escalado: ";
        for (int i = 0; i < novo.length(); ++i)
        {
            cout << novo.get(i) << " ";
        }
        cout << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_09 ( )

/**
 * Classe para ordenar arranjo em ordem decrescente.
 */
class arranjo_sortDown : public MyArray<int> {
public:
    using MyArray<int>::MyArray;
    void sortDown()
    {
        // Bubble sort decrescente
        for (int i = 0; i < this->length() - 1; ++i)
        {
            for (int j = 0; j < this->length() - i - 1; ++j)
            {
                if (this->get(j) < this->get(j + 1))
                {
                    int temp = this->get(j);
                    this->set(j, this->get(j + 1));
                    this->set(j + 1, temp);
                }
            }
        }
    }
};

/**
    Method_10 - Ordenar arranjo em ordem decrescente.
 */
void method_10()
{
    // identificar
    cout << endl
         << "Method_10 - Ordenar arranjo em ordem decrescente" << endl;

    MyArray<int> baseArr = readArrayFromFile("method_01.txt");
    if (baseArr.length() == 0)
    {
        cout << "Arranjo vazio ou erro ao ler arquivo." << endl;
    }
    else
    {
        arranjo_sortDown arr(baseArr.length());
        for (int i = 0; i < baseArr.length(); ++i)
        {
            arr.set(i, baseArr.get(i));
        }
        arr.sortDown();
        cout << "Arranjo ordenado em ordem decrescente: ";
        for (int i = 0; i < arr.length(); ++i)
        {
            cout << arr.get(i) << " ";
        }
        cout << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_10 ( )

/**
 * Classe para comparar se dois arranjos são diferentes em pelo menos uma posição.
 */
class arranjo_compare : public MyArray<int> {
public:
    using MyArray<int>::MyArray;
    // Retorna true se houver pelo menos uma posição diferente
    bool isDifferent(const MyArray<int>& other) const
    {
        if (this->length() != other.length())
            return true;
        for (int i = 0; i < this->length(); ++i)
        {
            if (this->get(i) != other.get(i))
                return true;
        }
        return false;
    }
};

/**
    Method_11 - Verificar se dois arranjos sao diferentes em pelo menos uma posicao.
 */
void method_11()
{
    // identificar
    cout << endl
         << "Method_11 - Verificar se dois arranjos sao diferentes em pelo menos uma posicao" << endl;

    std::string file1, file2;
    cout << "Digite o nome do primeiro arquivo: ";
    cin >> file1;
    cout << "Digite o nome do segundo arquivo: ";
    cin >> file2;

    MyArray<int> arr1 = readArrayFromFile(file1);
    MyArray<int> arr2 = readArrayFromFile(file2);

    if (arr1.length() == 0 || arr2.length() == 0)
    {
        cout << "Erro ao ler um dos arquivos ou arranjo vazio." << endl;
    }
    else
    {
        arranjo_compare cmp1(arr1.length()), cmp2(arr2.length());
        for (int i = 0; i < arr1.length(); ++i)
            cmp1.set(i, arr1.get(i));
        for (int i = 0; i < arr2.length(); ++i)
            cmp2.set(i, arr2.get(i));

        // Pode comparar cmp1 com arr2 ou cmp2 com arr1, ambos funcionam
        if (cmp1.isDifferent(arr2))
            cout << "Os arranjos sao diferentes em pelo menos uma posicao." << endl;
        else
            cout << "Os arranjos sao iguais em todas as posicoes." << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_11 ( )

/**
 * Classe para calcular as diferenças entre dois arranjos de mesmo tamanho.
 */
class arranjo_diff : public MyArray<int> {
public:
    using MyArray<int>::MyArray;
    // Retorna um novo arranjo com as diferenças posição a posição
    MyArray<int> diff(const MyArray<int>& other) const
    {
        if (this->length() != other.length())
            return MyArray<int>(0); // retorna arranjo vazio se tamanhos diferentes
        MyArray<int> result(this->length());
        for (int i = 0; i < this->length(); ++i)
        {
            result.set(i, this->get(i) - other.get(i));
        }
        return result;
    }
};

/**
    Method_12 - Calcular diferencas entre dois arranjos.
 */
void method_12()
{
    // identificar
    cout << endl
         << "Method_12 - Calcular diferencas entre dois arranjos" << endl;

    std::string file1, file2;
    cout << "Digite o nome do primeiro arquivo: ";
    cin >> file1;
    cout << "Digite o nome do segundo arquivo: ";
    cin >> file2;

    MyArray<int> arr1 = readArrayFromFile(file1);
    MyArray<int> arr2 = readArrayFromFile(file2);

    if (arr1.length() == 0 || arr2.length() == 0)
    {
        cout << "Erro ao ler um dos arquivos ou arranjo vazio." << endl;
    }
    else if (arr1.length() != arr2.length())
    {
        cout << "Os arranjos possuem tamanhos diferentes, não é possível calcular as diferenças." << endl;
    }
    else
    {
        arranjo_diff diffArr(arr1.length());
        for (int i = 0; i < arr1.length(); ++i)
            diffArr.set(i, arr1.get(i));
        MyArray<int> resultado = diffArr.diff(arr2);

        cout << "Diferencas (arr1 - arr2): ";
        for (int i = 0; i < resultado.length(); ++i)
        {
            cout << resultado.get(i) << " ";
        }
        cout << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_12 ( )

// ----------------------------------------------- acao principal

/*
  Funcao principal.
  @return codigo de encerramento
*/
int main(int argc, char **argv)
{
    // definir dado
    int x = 0; // definir variavel com valor inicial

    // repetir até desejar parar
    do
    {
        // identificar
        cout << "EXEMPLO1101 - Programa - v0.0\n"
             << endl;
            // mostrar opcoes
            cout << "Opcoes:" << endl;
            cout << " 0 - Parar" << endl;
            cout << " 1 - Gerar valores aleatorios e gravar em arquivo" << endl;
            cout << " 2 - Procurar maior valor impar em arquivo" << endl;
            cout << " 3 - Procurar maior valor impar multiplo de 3 em arquivo" << endl;
            cout << " 4 - Somar valores em intervalo do arranjo" << endl;
            cout << " 5 - Calcular media dos valores em intervalo do arranjo" << endl;
            cout << " 6 - Verificar se todos os valores sao positivos e maiores que 100" << endl;
            cout << " 7 - Verificar se arranjo esta em ordem decrescente" << endl;
            cout << " 8 - Procurar valor em intervalo do arranjo" << endl;
            cout << " 9 - Escalar valores do arranjo em intervalo" << endl;
            cout << "10 - Ordenar arranjo em ordem decrescente" << endl;
            cout << "11 - Verificar se dois arranjos sao diferentes em pelo menos uma posicao" << endl;
            cout << "12 - Calcular diferencas entre dois arranjos" << endl;

        // ler do teclado
        cout << endl
             << "Entrar com uma opcao: ";
        cin >> x;

        // escolher acao
        switch (x)
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
        default:
            cout << endl
                 << "ERRO: Valor invalido." << endl;
        }
    } while (x != 0);

    // encerrar
    pause("Apertar ENTER para terminar");
    return 0;
} // end main ( )
