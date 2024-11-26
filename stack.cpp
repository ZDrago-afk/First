#include<iostream>
#define max 10
using namespace std;
class stack
{
    public:
    int *arr;
    int top=-1;
    stack()
    {
        arr = new int[max];
    }
};
void push(stack* &s, int data)
{
    if(s->top==max)
    {
        cout<<"stack overflow"<<endl;
    }
    else
    {
        s->top++;
        s->arr[s->top]=data;
    }
}
int pop(stack* &s)
{
    if(s->top==-1)
    {
        cout<<"stack underflow"<<endl;
        return -1;
    }
    else
    {
        int popped = s->arr[s->top];
        s->top--;
        return popped;
    }
}
void display(stack* &s)
{
    for(int i=0;i<=s->top;i++)
    {
        cout<<s->arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    stack* s =new stack();
    push(s, 10);
    push(s, 101);
    push(s, 1);
    push(s, 0);
    display(s);
    int popper;
    popper = pop(s);
    display(s);
    return 0;
}