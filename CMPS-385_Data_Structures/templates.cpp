#include <iostream>
#include <string>


template <class T>
void print(T x[], int len)
{
    for(int i = 0; i < len; ++i)
    {
        std::cout << x[i] << '\t';
    }
    std::cout << '\n';
}



int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    float b[4] = {0.1, 0.2, 0.3, 0.4};
    char c[3] = {'a', 'b', 'c'};
    std::string d[2] = {"hello", "world"};

    print(a, 5);
    print(b, 4);
    print(c, 3);
    print(d, 2);

    system("pause");
    return 0;
}