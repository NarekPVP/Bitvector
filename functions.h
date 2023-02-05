#include <iostream>
int set (int bias, int x){
    x = (1 << bias) | x;
    return x;
}
int reset(int bias, int y){
    y &= ~(1 << bias);
    return y;
}
//Binar code Function
void show(unsigned int num){
    unsigned int copy = num;
    unsigned int counter = 0;
    if (num == 0)
    {
        std::cout << "All bits are 0" << std::endl;
    }
    
    while (copy != 0)
    {
        copy /= 2;
        counter++;
    }
    
    unsigned int arr[counter];
    copy = num;
   
    unsigned int i = 0;
    while (copy!= 0)
    {
        int tmp = copy % 2;
        copy /= 2;
        arr[i] = tmp;
        i++;
    }
    for (int i = counter - 1; i >= 0; i--)
    {
        std::cout << arr[i];
    }
    std::cout << "\n";
}

