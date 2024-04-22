#include "List1.h"

int main() 
{
    List1<int> intList;

    intList.insert(5);
    intList.insert(10);
    intList.insert(15);

    cout << "Elementos en la lista: ";
    intList.show();  

    intList.deleteList1();

    cout << endl;
    cout << "Despues de eliminar un elemento: ";
    intList.show();

    return 0;
}
