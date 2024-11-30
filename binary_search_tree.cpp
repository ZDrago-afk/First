#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
node* makebst(node* &n,int data)
{
    if(n==NULL)
    {
        n=new node(data);
        return n;
    }
    if(data>n->data)
    {
        makebst(n->right,data);
    }
    else
    {
        makebst(n->left,data);
    }
    return n;
}
void takeinput(node* &n)
{
    int data;
    cout<<"enter the data : ";
    cin>>data;
    while(data!=-1)
    {
        makebst(n,data);
        cout<<"enter the data : ";
        cin>>data;
    }
}
void inorder(node* &n)
{
    if(n==NULL)
    {
        return ;
    }
    inorder(n->left);
    cout<<n->data<<" ";
    inorder(n->right);
}
int main()
{
    node* root=NULL;
    takeinput(root);
    cout<<"inorder traversal : ";
    inorder(root);
    cout<<endl;
    return 0;
}