// Trying to learn how throw,try catch works for handling exception
//

#include <iostream>
#include <random>
#include <time.h>


int add(int num)
{
    if (num % 2)
    {
        throw "Not Divisible by 2";
    }
    else
        return NULL;
}

int main()

{


while (!NULL)
{
    int* s = new int;

    std::cout << "Enter the number :";
    std::cin >> *s;

    try
    {
        add(*s);
    }
    catch (const char* p)
    {
        std::cout << p << std::endl;
    }

    delete s;
}




}

