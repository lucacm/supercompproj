#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <algorithm>
#include <random>

using namespace std;

struct Cidade
{
    int id;
    double x;
    double y;
};

// corrigindo calculo da distancia
double distanceCalculate(Cidade first, Cidade second)
{
    double distancia = sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2));
    return distancia;
}

// corrigindo funcao distanciaTotal
double distanceTotal(vector<Cidade> cidades)
{
    int N = cidades.size();
    double total_dist = 0;
    for (int i = 0; i < N - 1; i++)
    {
        total_dist += distanceCalculate(cidades[i], cidades[i + 1]);
    }
    total_dist += distanceCalculate(cidades[N - 1], cidades[0]);
    return total_dist;
}

int main()
{
    int N;
    cin >> N;
    vector<Cidade> cidades;
    for (int i = 0; i < N; i++)
    {
        Cidade cidade;
        cidade.id = i;
        cin >> cidade.x;
        cin >> cidade.y;
        cidades.push_back(cidade);
    }

    double melhor_dist = INFINITY;
    vector<Cidade> melhor_caminho;

    default_random_engine generator(10);
    shuffle(begin(cidades), end(cidades), generator);

    melhor_dist = INFINITY;
    double total_dist;

    for (int i = 0; i < 10 * N; i++)
    {
        for (int position = 0; position < N - 1; position++)
        {
            total_dist = distanceTotal(cidades);

            if (total_dist < melhor_dist)
            {
                melhor_dist = total_dist;
                melhor_caminho = cidades;
            }

            iter_swap(cidades.begin() + position, cidades.begin() + position + 1);
        }

        cerr << "local: " << total_dist << " ";
        for (int i = 0; i < N; i++)
        {
            cerr << cidades[i].id << " ";
        }
        cerr << endl;
    }

    cout << melhor_dist << " " << 0 << endl;
    for (int i = 0; i < N; i++)
    {
        cout << melhor_caminho[i].id << " ";
    }
    cout << endl;

    return 0;
}