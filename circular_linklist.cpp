#include <iostream>
using namespace std;

class cir_list
{
    public:
    int data;
    cir_list *left,*right;

    public:
    cir_list * create_list(cir_list*,int&);
    void free_space(cir_list*);
};

cir_list* cir_list :: create_list(cir_list *obj,int &data)
{
    int size =0;
    cout << "Enter number of nodes you want to insert " << endl;
    cin >> size;
    cir_list * temp = NULL;
    cout << "Enter data" << endl;
    for(int i=0;i<size;i++)
    {
        cin >> data;
        if(obj == NULL)
        {
            obj = new cir_list;
            obj->data = data;
            obj->left = obj->right = NULL;
            temp = obj;
            
        }

        else
        {
            obj->right = new cir_list;
            obj->right->data = data;
            obj->right->left = obj;
            obj = obj->right;
            obj->right = NULL;
        }
    }
    //This piece of code is to connect last node pointer of the list to the first node 
    //to make it circular linklist
    obj->right = temp;
    temp->left = obj;

    return obj;
} 

void cir_list :: free_space(cir_list *obj)
{
    cir_list *temp = NULL;
    temp = obj;

    while(obj != NULL)
    {
        obj = obj->right;
        delete temp;
        temp = obj;
    }
}

int main()
{
    cir_list * obj = NULL;
    int data =0;

    obj = obj->create_list(obj,data);

   //Free space
     // obj->free_space(obj);


    //This loop will print the list infinite time 
    while(obj != NULL)
    {
        cout << obj->data << endl;
        if(obj->left == NULL)
        break;

        obj = obj->left;
    }

    
    
    return 0;
}