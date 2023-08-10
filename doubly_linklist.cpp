#include <iostream>
using namespace std;

class d_list
{
    public:
    int data;
    d_list *left,*right;

    public:
    d_list * create_list(d_list*,int&);
    void free_space(d_list*);
};

d_list* d_list :: create_list(d_list *obj,int &data)
{
    int size =0;
    cout << "Enter number of nodes you want to insert " << endl;
    cin >> size;

    cout << "Enter data" << endl;
    for(int i=0;i<size;i++)
    {
        cin >> data;
        if(obj == NULL)
        {
            obj = new d_list;
            obj->data = data;
            obj->left = obj->right = NULL;
            
        }

        else
        {
            obj->right = new d_list;
            obj->right->data = data;
            obj->right->left = obj;
            obj = obj->right;
            obj->right = NULL;
        }
    }

    return obj;
} 

void d_list :: free_space(d_list *obj)
{
    d_list *temp = NULL;
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
    d_list * obj = NULL;
    int data =0;

    obj = obj->create_list(obj,data);

   
    cout << "Printing from right to left " << endl;
    while(obj != NULL)
    {
        cout << obj->data << endl;
        if(obj->left == NULL)
        break;

        obj = obj->left;
    }

    // cout << "Printing from left to right " << endl;
    // while(obj!= NULL)
    // {
    //     cout << obj->data << endl;
    //     obj = obj->right;
    // }
    

    //Free space
    obj->free_space(obj);

    cout << "Printing from right to left " << endl;
    while(obj != NULL)
    {
        cout << obj->data << endl;
        if(obj->left == NULL)
        break;

        obj = obj->left;
    }


    
    
    

    return 0;
}