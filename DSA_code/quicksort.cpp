#include <bits/stdc++.h>
using namespace std;
//working of quick sort
//first find a pivot value and the elements greater than the pivot shd be right of it and the elements less than it shd be left of it 
//keep partioning the left and right array with the above condition 
//then backtrack until all the sub arrays are sorted resulting in the entire array sorting 
int partition_value(int A[],int low,int high)
{
  
  int pivot_element=A[high];
  int i=(low-1);
  
  for(int j=low;j<=high-1;j++)
  {
    if(A[j]<pivot_element)
    {
      i++;
      swap(A[i],A[j]);
    }
  }
  swap(A[i+1],A[high]);
  return (i+1);
}

           
void QuickSort(int A[],int low,int high)
{
  if(low<high)
  {

    int pi=partition_value(A,low,high);
    QuickSort(A,low,pi-1);
    QuickSort(A,pi+1,high);
  }
}
             
 
int main() {
  int A[]={10,7,8,9,1,5};
  int n=sizeof(A)/sizeof(A[0]);
  QuickSort(A,0,n-1);
  for(int i=0;i<n;i++)
  {
    cout<<A[i]<<",";
  }
  return 0;
}
