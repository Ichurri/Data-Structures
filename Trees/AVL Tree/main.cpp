#include "AVLTree.h"
#include <conio.h>

using namespace std;

void test()
{
    AVLTree<int> avlTree; 

    avlTree.insertData(50);
    avlTree.insertData(30);
    avlTree.insertData(70);
    avlTree.insertData(20);
    avlTree.insertData(40);
    avlTree.insertData(60);
    avlTree.insertData(80);

    int searchValue = 40;
    if (avlTree.searchData(searchValue)) 
        cout << "The element " << searchValue << " is in the tree." << endl;
    else 
        cout << "The element " << searchValue << " is not in the tree." << endl;

    int deleteValue = 30;
    avlTree.deleteData(deleteValue);
    cout << "Element " << deleteValue << " deleted from the tree." << endl;

    cout << "Smallest element: " << avlTree.findMinor() << endl;
    cout << "Largest element: " << avlTree.findGreater() << endl;

    cout << "Number of nodes in the tree: " << avlTree.countNode() << endl;

    cout << "Height of the tree: " << avlTree.calculateHeight() << endl;

    cout << "InOrder traversal: ";
    avlTree.inOrderTraversal();
    cout << endl;

    cout << "PreOrder traversal: ";
    avlTree.preOrderTraversal();
    cout << endl;

    cout << "PostOrder traversal: ";
    avlTree.postOrderTraversal();
    cout << endl;
}

void menu()
{
    AVLTree<int> avlTree;

    int choice, value;
    while (true) 
    {
        cout << "AVL Tree Menu:" << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Search for element" << endl;
        cout << "3. Delete element" << endl;
        cout << "4. Show number of nodes" << endl;
        cout << "5. Show height of the tree" << endl;
        cout << "6. InOrder traversal" << endl;
        cout << "7. PreOrder traversal" << endl;
        cout << "8. PostOrder traversal" << endl;
        cout << "9. Read file" << endl;
        cout << "10. Calculate height differences" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        system("cls");

        switch (choice) 
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            avlTree.insertData(value);
            cout << "Element " << value << " inserted in the tree." << endl;
            break;

        case 2:
            cout << "Enter the value to search for: ";
            cin >> value;
            if (avlTree.searchData(value)) 
                cout << "Element " << value << " found in the tree." << endl;
            else 
                cout << "Element " << value << " not found in the tree." << endl;
            break;

        case 3:
            cout << "Enter the value to delete: ";
            cin >> value;
            avlTree.deleteData(value);
            cout << "Element " << value << " deleted from the tree." << endl;
            break;

        case 4:
            cout << "Number of nodes in the tree: " << avlTree.countNode() << endl;
            break;
        
        case 5:
            cout << "Height of the tree: " << avlTree.calculateHeight() << endl;
            break;

        case 6:
            cout << "InOrder traversal: ";
            avlTree.inOrderTraversal();
            cout << endl;
            break;

        case 7:
            cout << "PreOrder traversal: ";
            avlTree.preOrderTraversal();
            cout << endl;
            break;

        case 8:
            cout << "PostOrder traversal: ";
            avlTree.postOrderTraversal();
            cout << endl;
            break;

        case 9:
            avlTree.readFile(avlTree,"ThousandNumbers.txt"); // Assuming readFile method only requires file name.
            break;

        case 10:
            cout << "Height differences:" << endl;
            int balanceMinusOne = 0;
            int balanceZero = 0;
            int balancePlusOne = 0;
            avlTree.countBalanceFactors(balanceMinusOne, balanceZero, balancePlusOne);

            cout << "Nodes with balance factor -1: " << balanceMinusOne << endl;
            cout << "Nodes with balance factor 0: " << balanceZero << endl;
            cout << "Nodes with balance factor +1: " << balancePlusOne << endl;
            break;
        case 11:
            cout << "Exiting the program." << endl;
            return;

        default:
            cout << "Invalid option. Try again." << endl;
        }
        _getch();
    }
}

int main()
{
    menu();
}
