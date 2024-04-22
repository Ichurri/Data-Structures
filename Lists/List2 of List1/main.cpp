#include "L2L1.h"
#include <fstream>
#include <conio.h>

template<class T>
void fileFunction(L2L1<T> list, string data, string crit)
{
    //L2L1<T> newList;
    ifstream file("ContestantsWorld.txt"); 
    int count = 0;
    while (!file.eof())
    {
        if (count == 0 || count % 5 == 0)
        {
            file >> crit;
        }
        else
        {
            file >> data;
            list.insertLast(crit, data);
            //newList.insertFirst(data, crit);

        }
        count++;

    }
    file.close();
    list.show();
    cout << endl;
    //newList.show();
    /*
    int i = list.getFirst();
    while (i != list.getLast()) 
    {
        cout << "Country: " << list.critArray[i].getCrit() << endl;
        cout << "Years of participation: ";
        list.critArray[i].getList().show();
        cout << endl;

        if (i == TAM - 1)
            i = 0;
        else
            i++;
    }

    cout << "Country: " << list.critArray[i].getCrit() << endl;
    cout << "Years of participation: ";
    list.critArray[i].getList().show();
    cout << endl;
    */
}

int main()
{
    int option, search;
    string data, crit;
    L2L1<string> list;

    do
    {
        system("CLS");
        cout << "1. InsertFirst" << endl;
        cout << "2. InsertLast" << endl;
        cout << "3. DeleteFirst" << endl;
        cout << "4. DeleteLast" << endl;
        cout << "5. Show All" << endl;
        cout << "6. Show Criterion" << endl;
        cout << "7. Search in the list" << endl;
        cout << "8. World File." << endl;
        cout << "0. EXIT" << endl;
        cin >> option;
        system("CLS");

        switch (option)
        {
        case 0:
            cout << "Exiting the program" << endl;
            break;
        case 1:
            cout << "Enter the criterion: ";
            cin >> crit;
            cout << "Enter the element to add: ";
            cin >> data;
            if (list.insertLast(crit, data) == 0)
                cout << "Data " << data << " added to the list." << endl;
            break;
        case 2:
            cout << "Enter the criterion: ";
            cin >> crit;
            cout << "Enter data: ";
            cin >> data;
            if (list.insertLast(crit, data) == 0)
                cout << "Data " << data << " added to the list." << endl;
            break;
        case 3:
            if (list.deleteFirst() == 0)
                cout << "The first element has been deleted." << endl;
            break;
        case 4:
            if (list.deleteLast() == 0)
                cout << "The last element has been deleted." << endl;
            break;
        case 5:
            list.show();
            break;
        case 6:
            cout << "Enter the criterion: ";
            cin >> crit;
            list.showCriterio(crit);
            break;
        case 7:
            cout << "Enter the element you wish to search for:" << endl;
            cin >> data;
            cout << "Enter the criterion: ";
            cin >> crit;
            search = list.search(crit, data);
            if (search == -1)
                cout << "Data not found" << endl;
            else
                cout << "The search is located at position " << search << endl;
            break;
        case 8:
            fileFunction(list, data, crit);
            break;
        default:
            cout << "This option does not exist." << endl;
            break;
        }
        _getch();
    } while (option != 0);
}
