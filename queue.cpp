#include <iostream>
using namespace std;

class queue
{
    public:
    string data;
    queue *next;

    queue* push(string,queue*);
    queue* pop(queue*);
};
queue *temp = NULL;
queue* queue :: push(string data,queue *node)
{
    
    if(node == NULL){
        
        
        node = new queue;
        node->data = data;
        node->next = NULL;
        temp = node;
    }

    else{

        node->next = new queue;
        node->next->data = data;
        node = node->next;
        node->next = NULL;
    }

    return node;

}

queue * queue :: pop(queue *node)
{
    queue *temp = node;
    node = node->next;
    delete temp;
    return node;
}

int main()
{
    queue *node = NULL;
    
    string data;
    
    
    
    node = node->push("saud",node);
    node = node->push("sm",node);
    node = node->push("sah",node);
    node = node->push("sa",node);
    node = node->push("sorry",node);
    
    node = temp;
    while(node != NULL)
    {
        cout << node->data << endl;
        node = node->next;
    }
}