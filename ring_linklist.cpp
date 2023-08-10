#include <iostream>
using namespace std;

// In this code, I am creating multiple circular doubly linked lists.
// A circular doubly linked list is a linked list where each node
// points to the next node and the previous node. The last node
// points back to the first node, creating a circle.
// I am connecting the multiple circular doubly linked lists together
// to create a structure that resembles a flexible pipe. The start
// of the pipe is connected to the end of the pipe, creating a loop.
// The number of nodes in the pipe and the length of the pipe are both user-defined..

class ring_list
{
public:
    int data;
    ring_list *left, *right, *next;
};

class ring_list2
{
public:
    ring_list *Node;
};
int main()
{

    ring_list *obj = NULL, *temp = NULL;
    int size1 = 0, size2 = 0, data = 0;
    cout << "Enter number of rings you want to create " << endl;
    cin >> size1;
    cout << "Enter number of nodes in each ring " << endl;
    cin >> size2;

    ring_list2 *arr = new ring_list2[size1];

    // This loop is used to create circular linklists
    for (int i = 0; i < size1; i++)
    {
        cout << "Enter data for ring " << i + 1 << endl;
        for (int j = 0; j < size2; j++)
        {
            cin >> data;
            if (obj == NULL)
            {
                obj = new ring_list;
                obj->data = data;
                obj->left = obj->right = obj->next = NULL;
                arr[i].Node = obj;
            }

            else
            {
                obj->right = new ring_list;
                obj->right->data = data;
                obj->right->left = obj;
                obj = obj->right;
                obj->right = NULL;
            }
        }
        obj->right = arr[i].Node;
        arr[i].Node->left = obj;
        obj = NULL;
    }

    // This loops are used to connect all the circular list created
    for (int i = 0; i < size1; i++)
    {
        if (i < size1 - 1)
        {
            obj = arr[i].Node;
            temp = arr[i + 1].Node;
        }
        for (int j = 0; j < size2 - 1; j++)
        {
            obj->next = temp;
            obj = obj->right;
            temp = temp->right;
        }
    }

    // Printing every list one by one
    for (int i = 0; i < size1; i++)
    {

        cout << "printed data of ring " << i + 1 << endl;
        for (int j = 0; j < size2; j++)
        {
            if (i % 2 == 0)
            {
                cout << arr[i].Node->data << endl;
                arr[i].Node = arr[i].Node->right;
            }
            else
            {
                cout << arr[i].Node->data << endl;
                arr[i].Node = arr[i].Node->left;
            }
        }
    }

    return 0;
}