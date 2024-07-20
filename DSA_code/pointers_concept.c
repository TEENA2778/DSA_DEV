//why do we need pointers actually??
//look at this pgm without pointers
// #include<stdio.h>
// int add(int n);
// void main()
// {
//     int num=10;
//     printf("value before function call \n");
//     printf("%d",num);
//     add(num);
//     printf("value after function call \n");
//     printf("%d",num);

// }
// int add(int n)
// {
//     n=n+10;
//     printf("\n  value inside the function is %d \n",n);
// }
//so basically after calling the function and performing the operation there is no change to num .
//here pointers play a role 
#include<stdio.h>
int add(int *n);
void main()
{
    int num=10;
    printf("value before function call \n");
    printf("%d",num);
    add(&num);
    printf("value after function call \n");
    printf("%d",num);

}
int add(int *n)
{
    *n=*n+10;
    printf("\n  value inside the function is %d \n",*n);
}
//with the use of pointers changes are made to num (which is local to add function)