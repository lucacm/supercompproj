#include <iostream>
#include <vector>
#include <math.h>
#include <limits>

using namespace std;

struct Cidade
{
    int id;
    double x; // coordenada em x
    double y; // coord/* code */enada em y
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

// função que calcula a cidade mais próxima
Cidade menorDistância(Cidade cidade, vector<Cidade> cidades, int verificados[])
{
    double min_dist = INFINITY;
    double dist;
    Cidade menor_cidade;
    for (Cidade i : cidades)
    {
        if (!verificados[i.id])
        {
            dist = distanceCalculate(cidade.x, cidade.y, i.x, i.y);
            if (dist < min_dist)
            {
                min_dist = dist;
                menor_cidade = i;
            }
        }
    }
    return menor_cidade;
}

int main()
{
    // leitura de entradas e armazenamento em vetor
    int N;
    cin >> N;
    vector<Cidade> cidades;
    for (int i = 0; i < N; i++)
    {
        Cidade node;
        node.id = i;
        cin >> node.x;
        cin >> node.y;
        cidades.push_back(node);
    }

    // lógica
    Cidade cidade_atual = cidades[0];
    int verificados[cidades.size()] = {0};
    vector<Cidade> caminho;
    caminho.push_back(cidade_atual);
    verificados[cidade_atual.id] = 1;
    double L = 0;
    int O = 0;
    while (caminho.size() != cidades.size())
    {
        Cidade mp = menorDistância(cidade_atual, cidades, verificados);
        caminho.push_back(mp);
        L += distanceCalculate(cidade_atual.x, cidade_atual.y, mp.x, mp.y);
        cidade_atual = mp;
        verificados[cidade_atual.id] = 1;
    }

    // calcula distancia até a volta e guarda de volta em L
    L += distanceCalculate(cidade_atual.x, cidade_atual.y, cidades[0].x, cidades[0].y);

    // print dos resultados
    cout << L << " " << O << endl; // 0 porque não é uma solução ótima
    for (int i = 0; i < caminho.size(); i++)
    {
        cout << caminho[i].id << " ";
    }
    cout << endl;

    return 0;
}
