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

// corrigindo calculo da distancia
double distanceCalculate(Cidade first, Cidade second)
{
    double distancia = sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2));
    return distancia;
}

// corrigindo funcao distanciaTotal
double distanceTotal(vector<Cidade> cidades)
{
    // define variável de tamanho das cidades
    int N = cidades.size();
    // distância total do caminho da cidade
    double total_dist = 0;
    // faz um loop para calcular a distância de todas as cidades
    for (int i = 0; i < N-1; i++)
    {
        total_dist += distanceCalculate(cidades[i], cidades[i+1]);
    }
    // calcula a volta da ultima cidade até a cidade original
    total_dist += distanceCalculate(cidades[N-1], cidades[0]);
    return total_dist;
}

int main()
{
    // lógica para ler as entradas
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

    // variável que calcula a distância do caminho de cidades atual
    double atual_distance = 0;
    // variável de resultado que guarda a maior distância começando em inifito por ser um valor alto
    double melhor_distance = INFINITY;
    // cria vetores de resultado e iteração de cidades
    vector<Cidade> melhor_caminho = cidades;
    vector<Cidade> nova_cidade = cidades;
    // número de vezes que entra em um if (caminho o qual descobre a melhor distância)
    int numleaf = 0;

    // do while para usar a lógica de next_permutation ao invés de recursão
    do
    {
        // cria um novo vetor organizando o de cidades com base na permutação
        for (int i = 0; i < id_cidades.size(); i++)
        {
            nova_cidade[i] = cidades[id_cidades[i]];
        }

        // calcula a distancia total do novo caminho
        atual_distance = distanceTotal(nova_cidade);

        // atualiza resposta
        if (atual_distance < melhor_distance)
        {
            melhor_distance = atual_distance;
            melhor_caminho = nova_cidade;
            numleaf++;
        }

    } while (std::next_permutation(id_cidades.begin(), id_cidades.end()));
    
    // print de erros e de resultados
    cerr << "num_leaf " << numleaf << endl;
    cout << melhor_distance << " " << 1 << endl;
    for (int i = 0; i < melhor_caminho.size(); i++)
    {
        cout << melhor_caminho[i].id << " ";
    }
    cout << endl;
}