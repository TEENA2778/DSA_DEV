//Write a program to print all the LEADERS in the array.
//An element is a leader if it is greater than all the elements to its right side. And the rightmost element is always a leader. 
#include<iostream>
#include<array>

using namespace std;


int main()
{

    int a[]={16, 17, 4, 3, 5, 2};

   int j;
    int len = sizeof(a)/4;
    for(int i=0;i<len;i++)
    {
        
       for(j=i+1;j<len;j++)
       {
        if (a[i]<=a[j])
        break;
       }
        
        if(j==len)
        cout<<"leaders is"<<a[i];
        }
}
