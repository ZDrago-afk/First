#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* prev;
    node* next;
    node(int data)
    {
        this->prev=NULL;
        this->next=NULL;
        this->data=data;
    }
};
void startinsert(node* &start, int data)
{
    node* temp = new node(data);
    temp->next = start;
    if (start != NULL) 
    {
        start->prev = temp;
    }
    start = temp;
}
void insertatend(node* &start,int data)
{
    node* temp = new node(data);
    temp->next=NULL;
    node* ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
}
void display(node* &start)
{
    node* ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
void pop(node* &start)
{
    node* ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->prev->next=NULL;
    delete ptr;
}
int main()
{
    node* start= new node(19);
    startinsert(start,20);
    startinsert(start,26);
    startinsert(start,23);
    display(start);
    cout<<endl;
    insertatend(start,24);
    insertatend(start,25);
    display(start);
    cout<<endl;
    pop(start);
    pop(start);
    pop(start);
    display(start);
    return 0;
}