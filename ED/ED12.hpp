#include <iostream>


template < typename T >
class matriz
{
    private:
    int colunas;
    int linhas;
    T** data;
    T temp;

    public:
    //CONSTRUTOR
    matriz ( )
    {
        this->colunas=0;
        this->linhas=0;
        data=nullptr;
    }

    ~matriz ( )
    {
        int i=0;
        if (data != nullptr)
        {
            for(x=0; x<rows; x=x+1)
            {
                delete ( data [ x ] );
            }
        }
    }
};
