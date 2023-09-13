//To Experiment static, from what I understand....static means, the address is fixed, redefining the variable inside a function
// will not change the address will be re-used, but can modify value. calling in main() will redefine as the main is 
// already in gloabal
//

#include <iostream>
#include <chrono>


int globalVariable = 0;
int normalVariable = 0;
static int staticVariable = 0;

void staticTest() {

    static int staticVariable = 0;

    globalVariable++;
    staticVariable++;

    std::cout << "globalVariable: " << globalVariable << std::endl;
    std::cout << "staticVariable: " << staticVariable << std::endl;
}

void normalTest()
{

    int normalVariable = 0;

    globalVariable++;
    normalVariable++;

    std::cout << "globalVariable: " << globalVariable << std::endl;
    std::cout << "normalVariable: " << normalVariable << std::endl;
}

int main() {

    std::cout << "Now Testing static int" << std::endl;


    staticTest();
    staticTest();
    staticTest();

    std::cout << "Now Testing normal int" << std::endl;

    normalTest();
    normalTest();
    normalTest();

}
