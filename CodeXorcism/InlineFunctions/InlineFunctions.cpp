//This experiment to see see how fast a normal & inline function been executed. The purpose is to proof that calling an inline
//function....I have no idea what Im trying to understand but the speed is one of the cons, on the side it improves performance
// & utilization...Im not sure how it is, for know this experiment is paused.
// 

#include <iostream>
#include <chrono>

int x = 0;

inline int x1()
{
    if (x != 50)
    {
        x = x + 1;
        return x;
    }
}

int x2()
{
    {
        x = x + 1;
        return x;
    }
}

int main()
{

    for (;;)
    {
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < 1000000; ++i)
        {
            x1();
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto durationInline = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        double seconds = durationInline.count() / 1000000.0;
        std::cout << "It took this amount of time to excute inline function: " << seconds << std::endl;
        x = 0;
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000000; ++i)
        {
            x2();
        }
        end = std::chrono::high_resolution_clock::now();
        durationInline = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        seconds = durationInline.count() / 1000000.0;
        std::cout << "It took this amount of time to excute normal function: " << seconds << std::endl;

        break;
    }

}




