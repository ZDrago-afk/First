#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data = data;
        this->next= NULL;
    }
};
void insert(node* &start, int data)
{
    node* temp;
    temp= new node(data);
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        node* ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next = temp;
    }
}
void pop(node* &start)
{
    if(start==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else if (start->next==NULL)
    {
        start=NULL;
        delete start;
    }
    else
    {
        node* ptr=start;
        while(ptr->next->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next = NULL;
    }
}
void display(node* &start)
{
    node* ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
int main()
{
    node* start= new node(10);
    insert(start,20);
    insert(start,30);
    display(start);
    return 0;
}