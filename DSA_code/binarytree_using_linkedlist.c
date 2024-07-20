#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;

};
struct node *create()
{
    int x;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the value of x(-1 for no node)");
    scanf("%d",&x);
    if(x==-1)
    {
        return 0;
    }
    newnode->data=x;
    printf("enter the left child of x");
    newnode->left=create();
    printf("enter the right child of x");
    newnode->right=create();
    return newnode;
}
void display(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

int main()
{
    struct node *root;
    root = NULL;
    root = create();
    printf("Binary Tree: ");
    display(root);
    return 0;
}
