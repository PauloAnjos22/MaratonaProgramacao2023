#include <iostream>
#include <sstream>

int main()
{
    int n, a, B = 0, C = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a;
        if (a > 0)
        {
            B += a;
        }
        else
        {
            C += a;
        }
    }
    std::cout << B - C << std::endl;

    return 0;
}