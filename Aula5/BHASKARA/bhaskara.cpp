#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

int main()
{
    double A, B, C, DELTA;
    std::cin >> A >> B >> C;

    DELTA = (B * B) - 4 * A * C;
    if (DELTA < 0 || A == 0)
    {
        std::cout << "Impossivel calcular" << std::endl;
        return 0;
    }
    else
    {
        std::cout << "R1 = " << std::fixed << std::setprecision(5) << (-B + sqrt(DELTA)) / (2 * A) << std::endl;
        std::cout << "R2 = " << std::fixed << std::setprecision(5) << (-B - sqrt(DELTA)) / (2 * A) << std::endl;
    }
    return 0;
}
