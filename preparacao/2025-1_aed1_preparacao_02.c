
void metodo01(void)
{
    int array[MAX];
    int quantidade = 0;              // Quantidade real de valores lidos
    bool verificacation = false;     // Controle de sucesso na escrita

    ofstream arquivoEscrita("metodo01.txt");
    srand(static_cast<unsigned int>(time(0)));

    if (arquivoEscrita)
    {
        cout << "Gerando valores aleatorios e salvando no arquivo..." << endl;
        for (int i = 0; i < MAX; i++)
        {
            int valor = rand() % 101;
            arquivoEscrita << valor << endl;
        }
        arquivoEscrita.close();
        verificacation = true;
    }
    else
    {
        cout << "Erro ao abrir o arquivo para escrita." << endl;
    }

    if (verificacation)
    {
        ifstream arquivoLeitura("metodo01.txt");

        if (arquivoLeitura)
        {
            // Leitura dos dados e contagem real
            while (quantidade < MAX && arquivoLeitura >> array[quantidade])
            {
                quantidade++;
            }

            arquivoLeitura.close();

            // Ordenação manual (bubble sort em ordem decrescente)
            for (int i = 0; i < quantidade - 1; i++)
            {
                for (int j = 0; j < quantidade - 1 - i; j++)
                {
                    if (array[j] < array[j + 1])
                    {
                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }

            // Exibição dos valores ordenados
            cout << "Valores ordenados de forma decrescente:" << endl;
            for (int i = 0; i < quantidade; i++)
            {
                cout << array[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Erro ao abrir o arquivo para leitura." << endl;
        }
    }
}
