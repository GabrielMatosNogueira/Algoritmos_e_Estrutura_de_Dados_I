#include "io.hpp"
using namespace std;
class Array
{
private:
    int capacity;
    int index;
    int *data;

public:

    Array()
    {
        this->capacity = 0;
        this->data = nullptr;
        this->index=0;
    }

    Array(const int length)
    {
        int i = 0;
        this->index=0;
        if (length >= 0)
        {
            this->capacity = length;
            this->data = new int[length];
            for (i = 0; i < this->capacity; i = i + 1)
            {
                data[i] = 0;
            }
        }
        else
        {
            this->capacity = 0;
            this->data = nullptr;
        }
    };

    ~Array()
    {
        if(this->data != nullptr)
        {
            this->capacity=0;
            delete[] this->data;
        }
    }

    void print_Array()
    {
        if(this->capacity>0 && this->data!=nullptr)
        {
            int i=0;
            for(i=this->index; i<this->capacity; i=i+1)
            {
                cout<< "[" << data[i] << "] " << endl;
            }
        }
        else
        {
            cout<< "Tamanho do array invalido ou nao foi possivel criar a area de dados" << endl;
        }
    }

    int* array_Fill(void)
    {
        int i=0;
        int number=0;
        if(this->capacity>0 && this->index < this->capacity)
        {
            while(this->index < this->capacity)
            {
                IO_printf("Type number %d of array: ",index+1);
                number=IO_readint("");
                this->data[i]=number;
                this->index=index+1;
                IO_printf("\nO valor do index: [%d]\n", this->index);
            }
            return data;
        }
        else
        {
            IO_println("Erro ao preencher o array, o valor de capacidade e menor que zero ou o array nao possui mais espaco");
            this->data=nullptr;
            return data;
        }
    }
    
    /**
     * Pop back
     * Pop front
     * Push back
     * Push front
     * at
     * peek
     */

    
    void pop_back()
    {
        int i=0;
        int copied=5;
        if(this->data!=nullptr)
        {
            IO_printf("\nO o index ai o %d \n", this->index);
            copied= this->data[this->index];
            data[this->index]=0;
        }
        IO_printf("Removed item: [%d]", copied);
    }
};
