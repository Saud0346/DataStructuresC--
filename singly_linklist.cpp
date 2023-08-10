#include <iostream>
using namespace std;
class my_list
{
    public:
    int data;
    my_list *next;

    
    friend ostream &operator<<(ostream &,const my_list *obj);
  //  friend istream &operator>>(istream&,my_list *obj);

    public:
    my_list* create_list(my_list*,int&,int&);
    my_list* input_data(my_list*);
    void free_space(my_list*);
    

};


my_list* my_list :: create_list(my_list *obj,int &data,int &size)
{
    my_list *temp = NULL;

    for(int i=0;i<size;i++)
    {
        cin >> data;
        if(obj==NULL)
        {
            obj = new my_list;
            obj->data = data;
            temp = obj;
            obj->next = NULL;
        }

        else
        {
            obj->next = new my_list;
            obj->next->data = data;
            obj = obj->next;
            obj->next = NULL;
        }
    }

return temp;
}

my_list* my_list :: input_data(my_list *obj)
{
    int size=0,data=0;
    cout << "Enter number of nodes you want to insert " << endl;
    cin >> size;
    cout << "Enter data" << endl;
    obj = create_list(obj,data,size);

return obj;

}

void my_list :: free_space(my_list *obj)
{
    my_list *temp = NULL;
    temp = obj;

    while(obj != NULL)
    {
        obj = obj->next;
        delete temp;
        temp = obj;
    }
}

// istream &operator>>(istream &input,my_list *obj)
// {
//     int size=0,data=0;
//     cout << "Enter number of nodes you want to insert " << endl;
//     input >> size;
//     cout << "Enter data" << endl;
//     obj = obj->create_list(obj,data,size);

//     return input;

// }

ostream &operator<<(ostream &output,const my_list *obj)
{
    cout << "The data stored " << endl;
    while(obj != NULL)
    {
        output << obj->data << endl;
        obj = obj->next;
    }

    return output;
}
int main()
{

    my_list *obj = NULL;
    obj = obj->input_data(obj);
    cout << obj;
    //Free space
    obj->free_space(obj);
    cout << obj;
    
    return 0;
}