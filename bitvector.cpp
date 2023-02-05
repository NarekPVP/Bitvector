#include <iostream>
#include "functions.h"
#include <string>
int main(){
    int size_of_bitvector = 0;
    std::cout << "Enter bitvector size(bits) " << "\n";
    std::cin >> size_of_bitvector;
    
    if (size_of_bitvector < 1)
    {
        return 0;
    }
    
    int lenght = size_of_bitvector / 32 + 1; 
    int* bit_arr = new int[lenght]; 
    std::cout << "Which bit you want to change --> ";
    int input_number = 0;
    while (true)        
    {
    std::cin >> input_number;
    if (input_number < 0)
    {
        return 0;
    }
    
    std::cout << "Set or Reset?(Set --> 1, Reset -- > 0) ";
    std::string rs;
    std::cin >> rs;
    int index = input_number / 32 ; //which block    00...000|00..000 (1 block(32 bit), 2 block (32 bit))
    int bias = input_number % 32; // which bit
    
    if (rs[1])
    {
        std::cout << "Please, write (0 or 1)" << std::endl;
        std::cout << "Which bit you want to change --> " << std::endl;
        continue;
    }
    

    if (rs[0] == '0')
        *(bit_arr + index) = reset(bias, *(bit_arr + index));

    else if (rs[0] == '1')
        *(bit_arr + index) = set(bias, *(bit_arr + index));
    else{
        std::cout << "Please, write (0 or 1)" << std::endl;
        std::cout << "Which bit you want to change --> " << std::endl;
        continue;
    }
    
    std::cout << "Bitvector's block's binar code --> " << "\n";
    show(*(bit_arr + index)); //binar code. Function in functions.h
    std::cout << "Which bit you want to change --> ";
  
    }

return 0;
}