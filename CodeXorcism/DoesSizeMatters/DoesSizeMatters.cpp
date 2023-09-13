// Size comparion of uint16_t & int, but obviously you theres has value limitations, 65535 for uint16_t & 2147483647 for int.
// So chose the correct datatype for your program, this can help for memory management.

#include <iostream>

int main()
{
    for (;;)
    {
        uint16_t s;
        int x;
        std::cout << "Enter a number :";
        std::cin >> s, x;

        while (!NULL)
        {

            std::cout << "The size of int is : " << sizeof(x) << std::endl;
            std::cout << "The size of uint16_t is : " << sizeof(s) << std::endl;
            break;

        }
    }

}




