#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

int main()
{
    int N;
    while (true)
    {
        std::cin >> N;
        int matrix[N][N];
        if (N == 0)
        {
            return 0;
        }
        else
        {
            if (N == 1)
            {
                std::cout << 1 << std::endl;
                std::cout << std::endl;
            }
            else
            {
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        if (j == 0 && i == 0)
                        {
                            matrix[i][j] = i + 1;
                            std::cout << matrix[i][j];
                        }
                        else if (j == 0)
                        {
                            matrix[i][j] = matrix[i - 1][j] * 2;
                            std::cout << matrix[i][j];
                        }
                        else
                        {
                            matrix[i][j] = matrix[i][j - 1] * 2;
                            std::cout << " " << matrix[i][j];
                        }
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
            }
        }
    }
}