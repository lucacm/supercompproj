#include <iostream>
#include <vector>
#include <math.h>
#include <limits>
#include <algorithm>

using namespace std;

struct Cidade
{
    int id;
    double x;
    double y;
};

double distanceCalculate(double x1, double y1, double x2, double y2)
{
    double x = x1 - x2; // calculating number to square in next step
    double y = y1 - y2;
    double dist;

    dist = pow(x, 2) + pow(y, 2); // calculating Euclidean distance
    dist = sqrt(dist);

    return dist;
}

double distanciaTotal(vector<Cidade> cidades)
{
    int N = cidades.size();
    double total_dist;

    int i = 0;
    while (i < N-1)
    {
        total_dist += distanceCalculate(cidades[i].x, cidades[i].y, cidades[i+1].x, cidades[i+1].y);
        i++;
    }

    total_dist += distanceCalculate(cidades[i].x, cidades[i].y, cidades[0].x, cidades[0].x);
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

    for (int i = 0; i < N * 10; i++)
    {
        for (int position = 0; position < N-1; position++)
        {        
            double total_dist = distanciaTotal(cidades);
            if (total_dist < melhor_dist)
            {
                melhor_dist = total_dist;
                melhor_caminho = cidades;
            }
            iter_swap(cidades.begin() + position, cidades.begin() + position+1);
        }

        //debug
        cerr << "local: " << melhor_dist << " ";
        for (int i = 0; i < N; i++)
        {
            cerr << melhor_caminho[i].id << " ";
        }
        cerr << endl;

        random_shuffle(cidades.begin(), cidades.end());
    }

    cout << melhor_dist << " " << 0 << endl;
    for (int i = 0; i < N; i++)
    {
        cout << melhor_caminho[i].id << " ";
    }
    cout << endl;
    return 0;
}