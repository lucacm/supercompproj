#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct Cidade
{
    int id;
    double x;
    double y;
};

//corrigindo calculo da distancia
double distanceCalculate(Cidade first, Cidade second)
{
    return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2));
}

//corrigindo funcao distanciaTotal
double distanceTotal(vector<Cidade> cidades)
{
    double total_dist = 0;
    for (int i = 0; i < cidades.size() - 1; i++)
    {
        total_dist += distanceCalculate(cidades[i], cidades[i + 1]);
    }
    total_dist += distanceCalculate(cidades[cidades.size() - 1], cidades[0]);
    return total_dist;
}

int main()
{
    int N;
    cin >> N;
    vector<Cidade> cidades;
    vector<int> id_cidades; // vetor de indices
    for (int i = 0; i < N; i++)
    {
        Cidade cidade;
        cidade.id = i;
        cin >> cidade.x;
        cin >> cidade.y;
        cidades.push_back(cidade);
        id_cidades.push_back(cidade.id);
    }

    double atual_distance;
    double melhor_distance = INFINITY;
    vector<Cidade> melhor_caminho = cidades;
    vector<Cidade> nova_cidade = cidades;
    int numleaf = 0;

    do
    {
        for (int i = 0; i < id_cidades.size(); i++)
        {
            nova_cidade[i] = cidades[id_cidades[i]];
        }

        //calcula a distancia total do novo caminho
        atual_distance = distanceTotal(nova_cidade);

        if (atual_distance < melhor_distance)
        {
            melhor_distance = atual_distance;
            melhor_caminho = nova_cidade;
            numleaf++;
        }

    } while (std::next_permutation(id_cidades.begin(), id_cidades.end()));

    cerr << "num_leaf " << numleaf << endl;
    cout << melhor_distance << " " << 1 << endl;
    for (int i = 0; i < melhor_caminho.size(); i++)
    {
        cout << melhor_caminho[i].id << " ";
    }
    cout << endl;
}