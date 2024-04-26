#include "BinarySearchTree.h"
#include <conio.h>

void menu()
{
    BinarySearchTree<int> bst;
    int choice, data;

    do 
    {
        cout << "-------------Menu----------------" << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Count nodes" << endl;
        cout << "3. Calculate height" << endl;
        cout << "4. Find the smallest" << endl;
        cout << "5. Find the largest" << endl;
        cout << "6. InOrder traversal" << endl;
        cout << "7. PreOrder traversal" << endl;
        cout << "8. PostOrder traversal" << endl;
        cout << "9. Delete" << endl;
        cout << "10. Read file" << endl;
        cout << "11. Mirror" << endl;
        cout << "12. Show array" << endl;
        cout << "13. Exit program" << endl;
        cout << "Enter your option: ";
        cin >> choice;

        system("cls");

        switch (choice) 
        {
        case 1:
            cout << "Enter the data to insert: ";
            cin >> data;
            bst.insertData(data);
            break;

        case 2:
            cout << "Nodes in the tree: " << bst.countNode() << endl;
            break;

        case 3:
            cout << "Height of the tree: " << bst.calculateHeight() << endl;
            break;

        case 4:
            cout << "Smallest element in the tree: " << bst.findMinor() << endl;
            break;

        case 5:
            cout << "Largest element in the tree: " << bst.findGreater() << endl;
            break;

        case 6:
            cout << "InOrder traversal: ";
            bst.inOrderTraversal();
            cout << endl;
            break;

        case 7:
            cout << "PreOrder traversal: ";
            bst.preOrderTraversal();
            cout << endl;
            break;

        case 8:
            cout << "PostOrder traversal: ";
            bst.postOrderTraversal();
            cout << endl;
            break;

        case 9:
            cout << "Enter data to delete: ";
            cin >> data;
            bst.deleteData(data);
            break;

        case 10:
            bst.readFile(bst, "MilNumeros.txt");
            break;

        case 11:
            bst.mirror();
            break;

        case 12:
            bst.displayArray();
            break;

        case 13:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "THIS OPTION DOES NOT EXIST." << endl;
            break;
        }
        _getch();
    } while (choice != 13);
}

int main() 
{
    menu();
}
