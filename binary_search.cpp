#include<iostream>
using namespace std;
void binary_search(int arr[], int h, int l, int key)
{
    int mid;
    while(l<=h)
    {
        mid=(h+l)/2;
        if(arr[mid]==key)
        {
            cout<<"key found at index "<<mid<<endl;
            return;
        }
        else if(arr[mid]<key)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
}
int main()
{
    int arr[10]={23,44,55,66,77,87,98,99,100,101};
    int key=77;
    binary_search(arr,9,0,key);
    return 0;
}