// BIBLIOTECA/DEPENDENCIAS
#include "io.hpp"

class ref_intStack
{
    private:
    int length;
    int *data;

    public:
    /**
     * @brief CONSTRUCTOR
     */
    ref_intStack(void)
    {
        this->length=0;
        this->data=nullptr;
    }

    /**
     * 
     */
    ~ref_intStack(void)
    {
        this->length=0;
        delete []data;
    }
    /**
     * 
     */
    int set_Length(int size)
    {
        if(size>0)
        {
            this->length=size;
            this->data=new int [size];
        }
        else
        {
            IO_println("Erro ao configurar tamanho do arranjo");
            this->length=0;
        }
        return this->length;
    }
}intStack;
