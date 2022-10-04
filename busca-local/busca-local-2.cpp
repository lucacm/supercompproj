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
    // lógica para ler as entradas
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

    // cria uma váriavel que atualiza a melhor distância e o melhor caminho
    double melhor_dist = INFINITY;
    vector<Cidade> melhor_caminho;

    // cria um generator com seed = 10 para fazer o shuffle do vetor
    default_random_engine generator(10);
    shuffle(begin(cidades), end(cidades), generator);

    // distância total do caminho do vetor
    double total_dist;

    for (int i = 0; i < 10 * N; i++)
    {
        // for para fazer os swaps e calcular nova distância
        for (int position = 0; position < N - 1; position++)
        {
            total_dist = distanceTotal(cidades);

            // atualiza variáveis de resultado
            if (total_dist < melhor_dist)
            {
                melhor_dist = total_dist;
                melhor_caminho = cidades;
            }

            // faz o swap entre cidades e vizinhos
            iter_swap(cidades.begin() + position, cidades.begin() + position + 1);
        }

        // printa o erro
        cerr << "local: " << total_dist << " ";
        for (int i = 0; i < N; i++)
        {
            cerr << cidades[i].id << " ";
        }
        cerr << endl;
    }

    // printa o resultado
    cout << melhor_dist << " " << 0 << endl;
    for (int i = 0; i < N; i++)
    {
        cout << melhor_caminho[i].id << " ";
    }
    cout << endl;

    return 0;
}