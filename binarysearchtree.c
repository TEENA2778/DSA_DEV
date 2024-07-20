#include<stdio.h>
typedef struct node
{
    int item;
    struct node *rlink;
    struct node *llink;

};
typedef struct node *treeptr;
void insert(treeptr *root,int data)
{
    if(!(*root))
    {
        *root=(treeptr)malloc(sizeof(struct node));
        (*root)->item=data;
        (*root)->rlink=NULL;
        (*root)->llink=NULL;
        return;
    }
    else if ((*root)->item > data)
    insert(&(*root)->llink,data);
    else
    insert(&(*root)->rlink,data);

    
}

void inorder(treeptr root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->llink);
    printf("%d",root->item);
    inorder(root->rlink);

}

void search(treeptr root,int value)
{
    if (root==NULL)
    {
        printf("emoty");
        return ;
    }
    else if (root->item==value)
    printf("found");
    else if (root->item>value)
    search(root->llink,value);
     else if (root->item<value)
    search(root->rlink,value);
    
}

void main()
{
    treeptr root;
    root=NULL;
    int choice;
    while(1)
    {
        printf("enter ur choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            int ele;
            printf("enter the element to be inserted");
            scanf("%d",&ele);
            insert(&root,ele);
            break;
            case 2:
            inorder(root);
break;
            case 3:
            int search1;
            printf("enter the element to search");
            scanf("%d",&search1);
            search(root,search1);
            break;
           

        }
    }
}