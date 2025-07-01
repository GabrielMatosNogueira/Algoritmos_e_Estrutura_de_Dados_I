#include "array.hpp"

int main(void)
{
    Array *array01 = new Array(5);
    array01->array_Fill();
    array01->print_Array();
    array01->pop_back();
    array01->print_Array();
    return 0;
}
