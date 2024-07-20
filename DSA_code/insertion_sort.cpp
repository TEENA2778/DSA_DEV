#include<iostream>
#include<array>
using namespace std;


void insertion(int a[],int n)
{
    int key;
    int j;
    for(int i=1;i<n;i++)
{
    key=a[i];
    j=i-1;
    while(j>=0 && a[j]>key)
    {
        a[j+1]=a[j];
        a[j]=key;
        j=j-1;
    }
    a[j+1]=key;
    
}
}


int main()
{
    int a[50],n;
    cout<<"enter the no of elements";
    cin>>n;
    cout<<"enter the elements";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    insertion(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}