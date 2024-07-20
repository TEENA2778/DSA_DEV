#include<stdio.h>
#include<stdlib.h>
#define MALLOC(x,size,type)(x=(type*)malloc(size*sizeof(type)))
typedef struct {
    int n;
}element;

element *queue;
int front=0,rear=0,capacity;

void copy(element *start ,element *end,element *newqueue)
{
    element *i;
    element *j;
    i=newqueue;
    j=start;
    for(;j<end;j++,i++)
    {
        *i=*j;
    }
}

void queueFull()
{
element* newQueue;
MALLOC(newQueue, capacity*2, element);
int start=(front+1)%capacity;
if(start < 2) //either 1 or 0, 1 when front at 0, 0 when front at capacity - 1
copy(queue+start, queue+start+capacity-1, newQueue);
else
{
copy(queue+start, queue+capacity , newQueue);
copy(queue, queue+rear+1, newQueue+capacity-start);
}
front=2*capacity-1;
rear=capacity-1;
capacity*=2;
free(queue);
queue=newQueue;
}

void addq(element item)
{
rear=(rear+1)%capacity;
if(front==rear)
queueFull();
queue[rear]=item;

}
element deleteq()
{
    element item;
    if(front==rear)
    {
        item.n=-1;
        return item;
    }
    front=(front+1)%capacity;
    return queue[front];
}


void display()
{
    int i;
    if(front==rear)
    {
        printf("queue is empty");
        return;
    }
    for(i=(front+1)%capacity;i!=rear;i=(i+1)%capacity)
    {
        printf("%d\t",queue[i].n);
    }
    printf("\n");

}


void main()
{
    element item1;
    int cap,choice;
    printf("enter cap");
    scanf("%d",&cap);
    
   
    MALLOC(queue,cap,element);
while(1){

printf("enter choice\n");
 scanf("%d",&choice);
    switch(choice){



        case 1:
        printf("enter the element to add");
        scanf("%d",&item1.n);
        addq(item1);
        break;
        case 2:
        item1=deleteq();
        if(item1.n==-1)
        {
            printf("queue is empty");
            return;
        }
        printf("removed item is %d",item1.n);
        break;
        case 3:
        display();
        break;
        

    }
}
}
