#include<stdio.h>
#define N 100;

void maxheapify(int a[],int n,int i)
{
    int largest=i;
    int l=2*i;
    int r=2*i+1;

    while(l<=n && a[l]>largest)
    largest=l;
        while(r<=n && a[r]>largest)
    largest=r;

    while(largest!=i)
    {
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        maxheapify(a,n,largest);
    }
}

void insert(int a[],int *n,int value)
{

    (*n)++;
    a[*n]=value;
    int i=*n;
    while(i>1)
    {
        int parent=i/2;
 if (a[i]>a[parent])
 {
    int temp=a[i];
    a[i]=a[parent];
    a[parent]=temp;
    parent=i;

 }  
 else
 {
    break;

 }  
    }
}


void delete(int a[],int *n)
{
    (*n)--;
    a[1]=a[*n];
    maxheapify(a,*n,1);
}
void display(int a[],int n)
{
    for(int i=1;i<=n;i++)
    {
        printf("%d",a[i]);
    }
}
int main() {
    int a[100], n = 0, choice, value;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(a, &n, value);
                break;
            case 2:
                if (n == 0) {
                    printf("Heap is empty\n");
                } else {
                    delete(a, &n);
                }
                break;
            case 3:
                if (n == 0) {
                    printf("Heap is empty\n");
                } else {
                    display(a, n);
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}