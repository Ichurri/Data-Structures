#include "List8.h"

int main()
{
    List8<int> myList;  
    int choice, data, position;

    cout << "Menu:" << endl;
    cout << "1. Insertar al principio" << endl;
    cout << "2. Insertar al final" << endl;
    cout << "3. Eliminar al principio" << endl;
    cout << "4. Eliminar al final" << endl;
    cout << "5. Mostrar lista" << endl;
    cout << "6. Ordenar lista" << endl;
    cout << "7. Buscar en la lista" << endl;
    cout << "8. Buscar posicion elemento" << endl;
    cout << "9. Delete all." << endl;
    cout << "10. Salir" << endl;
    do
    {
        cout << "Seleccione una opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Ingrese el valor a insertar: ";
            cin >> data;
            myList.insertFirst(data);
            break;

        case 2:
            cout << "Ingrese el valor a insertar: ";
            cin >> data;
            myList.insertLast(data);
            break;

        case 3:
            if (myList.deleteFirst())
                cout << "Elemento eliminado del principio." << endl;
            else
                cout << "La lista está vacía." << endl;
            break;

        case 4:
            if (myList.deleteLast())
                cout << "Elemento eliminado del final." << endl;
            else
                cout << "La lista está vacía." << endl;
            break;

        case 5:
            cout << "Lista actual: ";
            myList.show();
            break;

        case 6:
            myList.bubbleSort();
            cout << "LISTA ORDENADA." << endl;
            myList.show();
            break;

        case 7:
            cout << "Ingrese el valor a buscar: ";
            cin >> data;
            myList.search(data);
            break;
        case 8:
            cout << "Search pos: ";
            cin >> position;
            cout << "Dato en la posicion " << position << ": " << myList[position];
            break;
        case 9:
            myList.deleteAll();
            break;
        case 10:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
        }

    } while (choice != 8);

    return 0;
}
