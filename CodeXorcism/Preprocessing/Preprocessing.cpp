//To learn and experiment preprocessor directives.
//To be continue learning
//

#include <iostream>
#include <chrono>

//int x;

#define x  10
#define SOLOMON
int c;

int main()
{

    //It will never print as its wrong value been define
#if x == 1

    c = x;
    std::cout << c << std::endl;

#endif

    //It will print but not going through the condition, it means if the value is correct/wrong it will print whatever defined 
    //at the begining at the code

#ifdef x == 1

    c = x;
    std::cout << "Im printing wrong value : " << c << std::endl;

#endif

    //This will print since the condition is met
#if x == 5 

    c = x;
    std::cout << "My if was right, so im printing value : " << c << std::endl;

#endif

    //Trying elseif, set the value 10, at defination
#if x == 5

    c = x;
    std::cout << "My if was right, so im printing value : " << c << std::endl;

#elif x == 10

    c = x;
    std::cout << "My if was right, so im printing value : " << c << std::endl;


#endif

    //What about else ? Weirdly, else execute even provide wrong value;
#if x == 5

    c = x;
    std::cout << "My if was right, so im printing value : " << c << std::endl;

#else x == 10

    //c = x;
    //std::cout << "My if was right, so im printing value : " << c << std::endl;


#endif


//The proper way to use #ifdef & #else
#ifdef ABRAHAM


    std::cout << "My name is Abraham " << std::endl;

#else SOLOMON

    std::cout << "My name is Solomon " << std::endl;

#endif


}

