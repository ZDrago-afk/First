#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* right;
    node* left;
    node(int data)
    {
        this->data=data;
        this->right=NULL;
        this->left=NULL;
    }
};
node* createnode(node* &n)
{
    int data;
    cout<<"Enter data (-1 to stop): ";
    cin>>data;
    n= new node(data);
    if(data==-1)
    {
        return NULL;
    }
    cout<<"Enter left child of "<<data<<": ";
    n->left=createnode(n->left);
    cout<<"Enter right child of "<<data<<": ";
    n->right=createnode(n->right);
    return n;
}
void inorder(node* &n)
{
    if(n==NULL)
    {
        return;
    }
    else
    {
        inorder(n->left);
        cout<<n->data<<" ";
        inorder(n->right);
    }
}
void preorder(node* &n)
{
    if(n==NULL)
    {
        return;
    }
    else
    {
        cout<<n->data<<" ";
        preorder(n->left);
        preorder(n->right);
    }
}
void postorder(node* &n)
{
    if(n==NULL)
    {
        return;
    }
    else
    {
        postorder(n->left);
        postorder(n->right);
        cout<<n->data<<" ";
    }
}
int main()
{
    node* root=NULL;
    root=createnode(root);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}