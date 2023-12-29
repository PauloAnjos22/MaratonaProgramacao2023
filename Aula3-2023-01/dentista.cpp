#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

// Definição da struct
struct Consulta
{
    int X; // Inicio da consulta
    int Y; // Término da consulta
};

// Função de comparação do inicio da consulta (X) para ordenação
bool compareX(const Consulta &a, const Consulta &b)
{
    return a.X < b.X;
}

// Função de comparação do término da consulta (Y) para ordenação
bool compareY(const Consulta &a, const Consulta &b)
{
    return a.Y < b.Y;
}

int main()
{
    int N, X, Y, count = 0, lastY;
    std::cin >> N;
    std::vector<Consulta> array_consulta; // Vetor de consultas
    for (int i = 0; i < N; i++)
    {
        std::cin >> X >> Y;
        Consulta consulta;
        consulta.X = X;
        consulta.Y = Y;
        array_consulta.push_back(consulta);
    }
    std::sort(array_consulta.begin(), array_consulta.end(), compareX);
    std::sort(array_consulta.begin(), array_consulta.end(), compareY);

    count++;
    lastY = array_consulta[0].Y;
    for (int i = 1; i < N; i++)
    {
        if (array_consulta[i].X >= lastY) // Compara se o inicio coincide com o término de outra consutla
        {
            count++;
            lastY = array_consulta[i].Y;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
