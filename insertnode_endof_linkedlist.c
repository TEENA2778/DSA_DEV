//inserting anode at the end
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
void insert(struct node *head,int element)
{
   struct node *ptr=head;
   struct node *temp= (struct node*)malloc(sizeof(struct node));
   temp->data=element;
   temp->link=NULL;

//    if(head==NULL)
//    {
//     head=temp;
//    }
//    else{
    while (ptr->link !=NULL)//because only if the link of that node is null i can insert the node at the end
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
   }
  //}
void print(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d %p", ptr->data, (void*)ptr->link);
        ptr = ptr->link;
    }
}
void count (struct node *head)
{
int count=0;
struct node *ptr=head;
while(ptr!=NULL)
{
    count++;
    ptr=ptr->link;
}
printf("no of nodes=%d",count);

}

int main()
{
 
   struct node *head = (struct node *)malloc(sizeof(struct node));
   int element = 62;

   if (head != NULL) { //. If malloc fails to allocate memory (for example, due to insufficient memory), it returns NULL. By
       head->data = 42;
       head->link = NULL;//what if it contains some random value ??? so thats why assign NULL to it 

       insert(head, element);  // Assuming you want to insert another node
       print(head);
     count(head);
       // Don't forget to free the memory when you're done
       free(head);
   }

   return 0;
}
