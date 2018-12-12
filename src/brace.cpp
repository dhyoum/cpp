#include <stdio.h>
#include <vector>

struct Data
{
    Data(int x_=0, int y_=0):x{x_}, y{y_}{}

    int x, y;
};

int main()
{
    int x = 7.9;
    // int x{7.9};
    // int x = int{7};
    printf("x = %d\n", x);

    // Data a = 10;
    Data a1{}; printf("a1.x = %d\n", a1.x);
    Data a2{10}; printf("a2.y = %d\n", a2.y);
    Data a3{10, 20}; printf("a3.y = %d\n", a3.y);

    Data array[2] = {{1,2}, {2,3}};
    printf("array[1] = %d\n", array[1].x);

    // std::vector<Data> vec = {{1,2}, {4,20}};
    std::vector<Data> vec{{1,2}, {4,20}};
    printf("size of vec = %lu\n", vec.size());
    printf("vec[1] = %d\n", vec[0].y);


    return 0;
}
