#include <iostream>
#include "MinHeap.h"

using namespace std;

void readFile(MinHeap<int> heap, const string& fileName)
{
    int number;
    fstream file(fileName);
    vector<int> unSortedVector;
    while (file >> number)
        unSortedVector.push_back(number);
    vector<int> sortedVector = heap.heapSort(unSortedVector);
    for (const int& i : sortedVector)
        cout << i << " ";
    cout << endl;
}

int main()
{
    MinHeap<int> minHeap;

    int option;
    int value;

    do
    {
        cout << "MinHeap Menu:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Show" << endl;
        cout << "4. Count nodes" << endl;
        cout << "5. Calculate height" << endl;
        cout << "6. Heap Sort" << endl;
        cout << "7. Exit" << endl;
        cout << "Select an option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter a value: ";
            cin >> value;
            minHeap.insert(value);
            break;
        case 2:
            value = minHeap.remove();
            if (value != NULL)
                cout << "Value removed: " << value << endl;
            else
                cout << "Heap is empty." << endl;
            break;
        case 3:
            minHeap.show();
            break;
        case 4:
            cout << "Number of nodes of heap: " << minHeap.countNodes(1) << endl;
            break;
        case 5:
            cout << "Heap height: " << minHeap.calculateHeight(1) << endl;
            break;
        case 6:
            readFile(minHeap, "ThousandNumers.txt");
            break;
        case 7:
            cout << "Exit from program." << endl;
            break;
        default:
            cout << "This option doesn't exist." << endl;
            break;
        }

    } while (option != 7);

}
