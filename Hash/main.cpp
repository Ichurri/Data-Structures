#include <iostream>
#include <conio.h>
#include "Hash.h"

using namespace std;

int main()
{
    Hash<string> hashTable;

    int opcion;
    string dato;
    do
    {
        cout << "Menu de Operaciones:" << endl;
        cout << "1. Insertar dato" << endl;
        cout << "2. Eliminar dato" << endl;
        cout << "3. Buscar dato" << endl;
        cout << "4. Mostrar datos" << endl;
        cout << "5. Archivo Mundial" << endl;
        cout << "6. Archivo Diccionario" << endl;
        cout << "7. Mostrar colisiones" << endl;
        cout << "8. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        system("cls");

        switch (opcion)
        {
        case 1:
            // Insertar dato
            cout << "Ingrese el dato a insertar: ";
            cin >> dato;
            hashTable.insertData(dato);
            break;
        case 2:
            // Eliminar dato
            cout << "Ingrese el dato a eliminar: ";
            cin >> dato;
            hashTable.deleteData(dato);
            break;
        case 3:
            // Buscar dato
            cout << "Ingrese el dato a buscar: ";
            cin >> dato;
            //int posicion = hashTable.searchData(datoABuscar);
            if (hashTable.searchData(dato) != -1)
                cout << "El dato se encontro en la posicion " << hashTable.searchData(dato) << endl;
            else
                cout << "El dato no se encontro en la tabla hash." << endl;
            break;
        case 4:
            // Mostrar datos
            hashTable.showAll();
            break;
        case 5:
            hashTable.readFile("Concursantes mundial.txt");
            hashTable.showAll();
            break;
        case 6:
            hashTable.readFile("Diccionario.txt");
            hashTable.showAll();
            break;
        case 7:
            hashTable.countCollisions();
            break;
        case 8:
            // Salir del programa
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
        }
        _getch();
    } while (opcion != 9);

}