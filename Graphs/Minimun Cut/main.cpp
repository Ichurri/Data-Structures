#include "Graph.h"
#include <iostream>
#include <math.h>

using namespace std;

int minCutIteration(Graph g)
{
    string v1;
    while (g.getNumNodes() > 2)
    {
        v1 = g.randomNodeSource();
        g.contract(v1);
    }
    return g.tree().buscar(v1, g.tree().root())->list().getCant();
}

int minCut(Graph g)
{
    int minimun = INT_MAX;
    int result;
    int nTimesIterated = pow(g.getNumNodes(), 2) * log10(g.getNumNodes());
    for (int i = 0; i < nTimesIterated; i++)
    {
        cout << "Iteracion: " << i << " ";
        result = minCutIteration(g);
        cout << "Resultado: " << result << endl;
        if (result < minimun)
            minimun = result;
    }
    return minimun;
}

int main()
{
    Graph g;
    g.readFile("fileTest.txt");
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    int minimun = minCut(g);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    double seconds = elapsed_seconds.count();

    std::cout << "Tiempo transcurrido: " << seconds << " minutos" << std::endl;
    cout << "Resutado: " << minimun << endl;
}

