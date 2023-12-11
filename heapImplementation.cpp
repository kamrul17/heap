#include <iostream>
using namespace std;

class heapImplementation
{
public:
    int arr[100];
    int size;

    heapImplementation()
    {
        arr[0] = -1;
        size = 0;
    }

    //   insertion
    void insert(int val)
    {

        // step1: insert at end
        size++;
        int index = size;
        arr[index] = val;
        // step2: take node it to its correct position
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[parentIndex] < arr[index])
            {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            }
            else
            {
                return;
            }
        }
    }

    // deletion

    void deletionNode()
    {
        if (size == 0)
        {
            return;
        }
        // step1:swap first (root)node with last node
        arr[1] = arr[size];
        // step2: remove last node
        size--;
        // step3: take root node to its correct position
        int i = 1;
        while (i < size)
        {
            // left node
            int leftIndex = 2 * i;
            // right node
            int rightIndex = 2 * i + 1;
            if (i < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (i < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    // print
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    heapImplementation h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletionNode();
    h.print();
    return 0;
}