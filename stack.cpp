#include <iostream>
using namespace std;

class stack
{
    public:
    int data;
    stack *next;

    stack* push(int data,stack *);
    stack* pop(stack *);
};

stack* stack :: push(int data,stack *node)
{
    stack *temp = NULL;
    if(node == NULL){
        node = new stack;
        node->data = data;
        node->next = NULL;
    }

    else{

        temp = new stack;
        temp->data = data;
        temp->next = node;
        node = temp;
       
    }

    return node;
}

stack*stack :: pop(stack *node)
{
    stack * temp = NULL;
    temp = node;
    node = node->next;
    delete temp;

    return node;
}

int main()
{

    stack *node = NULL;
    node = node->push(20,node);
    node = node->push(10,node);
    node = node->push(30,node);
    node = node->push(40,node);
    
    node = node->pop(node);
    while(node != NULL)
    {
        cout << node->data << endl;
        node = node->next;
    }

    return 0;
}