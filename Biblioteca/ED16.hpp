#include "io.h"
using namespace std;
#define MAX 5
class ED16
{
private:
    int data[MAX];
    int lenght;
    bool has_capacity;
    int index;

public:
    /**
     * */
    ED16() // Assumindo que o valor inicial seja 0
    {
        this->lenght = MAX;
        this->used = 0;
        this->index = 0;

        for (int i = 0; i < MAX; i = i + 1)
        {
            this->data[i] = 0;
        }
    }

    /**
     * */
    ~ED16()
    {
    }

    /**
     * */
    void print_Array()
    {
        IO_println("Arranjo:");
        if (used == 0)
        {
            IO_println("[]");
        }
        for (int i = 0; i < this->used; i = i + 1)
        {
            IO_printf("[%d] ", this->data[i]);
        }
        IO_println("");
    }

    /**
     * Funcao para acrescentar valor ao final
     * de um arranjo, por meio de apontador.
     * @return apontador para arranjo atualizado
     * @param array - apontador para arranjo
     * @param value - valor a ser inserido
     **/
    int ED16_array_push_back(int value)
    {
        if (this->used < this->lenght)
        {
            this->data[this->used] = value;
            this->used = this->used + 1;
        }
        else
        {
            IO_println("ERRO: Nao e' possivel adicionar. Arranjo cheio.");
        }
        return data[MAX];
    }

    /**
     * 
     */
    bool full_Array()
    {
        if(this->leng)
        {
            this->has_capacity=true;
        }
    }

    /**
     * Funcao para remover valor do final
     * de um arranjo, por meio de apontador
     * @return apontador para arranjo atualizado, ou NULL,
     * @param array - apontador para arranjo
     */
    int ED16_pop_back(int value)
    {
        int copy = 0;
        this->index = this->used;
        if (this->used != 0)
        {
            copy = data[this->index];
            data[this->index] = 0;
            this->used = used - 1;
        }
        return copy;
    }
};
