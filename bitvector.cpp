// Atchemyany gavnacotd dzum enq
// Reviwed by Narek Hovhannisyan and Tigran Kharatyan 2023.06.19 9:34 AM

#include <iostream>
#include <string>
#include "functions.h"

int main() {
    int size_of_bitvector = 0;
    std::cout << "Enter bitvector size (bits): ";
    std::cin >> size_of_bitvector;

    if (size_of_bitvector < 1) {
        return 0;
    }

    int length = (size_of_bitvector - 1) / 32 + 1;
    int* bit_arr = new int[length];

    std::cout << "Which bit do you want to change? --> ";
    int input_number = 0;

    while (true) {
        std::cin >> input_number;

        if (input_number < 0) {
            return 0;
        }

        std::cout << "Set or Reset? (Set -> 1, Reset -> 0): ";
        std::string rs;
        std::cin >> rs;

        int index = input_number / 32; // block index
        int bias = input_number % 32; // bit index

        if (rs.length() != 1 || (rs[0] != '0' && rs[0] != '1')) {
            std::cout << "Please enter 0 or 1." << std::endl;
            std::cout << "Which bit do you want to change? --> ";
            continue;
        }

        if (rs[0] == '0') {
            *(bit_arr + index) = reset(bias, *(bit_arr + index));
        } else if (rs[0] == '1') {
            *(bit_arr + index) = set(bias, *(bit_arr + index));
        }

        std::cout << "Bitvector's block's binary code: ";
        show(*(bit_arr + index)); // binary code. Function in functions.h
        std::cout << "Which bit do you want to change? --> ";
    }

    delete[] bit_arr;
    return 0;
}
