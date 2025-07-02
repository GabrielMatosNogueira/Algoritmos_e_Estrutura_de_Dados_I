#include <iostream>

#define null nullptr
#define intCell int

class intStack 
{ 
  private: 
    int      length; 
    intCell *data; 
  public: 
    intStack ( )
    {
        length = 0; data = null;
    }
    void push ( int value ) 
    { } 
    int  pop  ( ) 
    { return ( 0 ); }
    void dup  ( ) 
    { }
    void swap ( ) 
    { }
    void test ( )
    {
        intStack   a;
        intStack * b = null;
        
        std::cout << "\nTest intStack\n" << std::endl;
        
        std::cout << std::endl;
    }
};

using ref_intStack = intStack*;

int main ( )
{
    std::cout << "\nTest intStack\n" << std::endl;
    std::cout << std::endl;
    return ( EXIT_SUCCESS );
}
