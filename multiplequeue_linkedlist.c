#include<stdio.h>
#define N 100
struct node
{
    int data;
    struct node *link;
};
struct node *front[N];
struct node *rear[N];

void push(int item,int i)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    if(front[i]==0 && rear[i]==0)
        {
front[i]=rear[i]=newnode;
    }
    newnode->data=item;
    newnode->link=NULL;
    rear[i]->link=newnode;
    rear[i]=newnode;
}

int pop(int i)
{
    struct node *temp;
    temp=front[i];
    if(temp==NULL)

    {
        printf("empty");
        return;
    }
    int value=temp->data;
    front[i]=front[i]->link;
    free(temp);
    return value;

}

void display(int i)
{
    struct node *temp;
    temp = front[i];
  
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}



void main()
{
    int choice;
    int j;
for(int i=0;i<N;i++)
{


front[i]=NULL;
rear[i]=NULL;
}
while(1)
{
printf("enter choice");
scanf("%d",&choice);
switch(choice)
{
    case 1:
    int item;
    printf("enter the element to be inserted");
    scanf("%d",&item);
    printf("enter the pos");
    scanf("%d",&j);
    push(item,j);
    break;
    case 2:
    printf("enter the pos");
    scanf("%d",&j);
    int item1=pop(j);
    break;
    case 3:
    printf("enter the pos");
    scanf("%d",&j);
    display(j);
    break;
}
}
}
