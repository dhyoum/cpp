#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    std::cout << []{ return 20; }() << std::endl;
    return 0;
}
