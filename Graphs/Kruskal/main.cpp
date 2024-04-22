#include "Graph.h"
#include <fstream>
#include <conio.h>

void prueba()
{
    // Crear un grafo
    Graph<string> myGraph;

    // Insertar aristas en el grafo
    myGraph.insert("A", "B", 2);
    myGraph.insert("A", "C", 1);
    myGraph.insert("B", "C", 3);

    // Mostrar el grafo original
    cout << "Grafo Original:" << endl;
    myGraph.printGraph();
    cout << endl;

    // Calcular y mostrar el corte m�nimo
    int minCut = myGraph.minCut();
    cout << "Corte Minimo: " << minCut << endl;
}

void menu()
{
    cout << "Menu:" << endl;
    cout << "1. Insertar vertice" << endl;
    cout << "2. Print Graph" << endl;
    cout << "3. Mostrar adyacentes de un nodo" << endl;
    cout << "4. Leer Tiempos Bol" << endl;
    cout << "5. Kruskal" << endl;
    cout << "6. Min Cut" << endl;
    cout << "7. Salir" << endl;
    cout << "Ingrese una opcion: ";
}

int main() 
{
    prueba();
    /*
    Graph<string> graph, kruskal;

    int choice, total = 0;
    while (true)
    {
        menu();
        cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
        {
            string source, destiny;
            int weight;
            cout << "Ingresar nodo origen: ";
            cin >> source;
            cout << "Ingresar nodo destino: ";
            cin >> destiny;
            cout << "Ingresar peso: ";
            cin >> weight;
            graph.insert(source, destiny, weight);
            break;
        }
        case 2:
            cout << "Grafo:" << endl;
            graph.printGraph();
            break;
        case 3:
        {
            string nodeName;
            cout << "Ingrese el nombre del nodo: ";
            cin >> nodeName;
            cout << "Lista de adyacencia del nodo: " << nodeName << ":" << endl;
            graph.showAdjacencyList(nodeName);
            break;
        }
        case 4:
        {
            graph.loadFromFile("TiemposBol.txt");
            cout << "Archivo cargado" << endl;
            break;
        }
        case 5:
        {
            cout << "Kruskal" << endl;
            graph.kruskal(kruskal, total);
            kruskal.printGraph();
            cout << endl;
            cout << "Total del kruskal: " << total << endl;
            break;
        }
        case 6:
            cout << "Min cut" << graph.minCut() << endl;
            break;
        case 7:
            cout << "Saliendo del programa." << endl;
            break;

        default:
            cout << "Opcion no valida" << endl;
            break;
        }
        _getch();

    }
 */

}
