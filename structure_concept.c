//Program to input and display the details of 3 students using structure


// #include<stdio.h>
// struct students{
//     char student_id[10];
//     char name[50];
//     float marks;
// };
// void main()
// {
//     struct students s[3];
//     for(int i=0;i<3;i++)
//     {
//     printf("enter name");
//     scanf("%s",s[i].name);
//     printf("enter id");
//     scanf("%s",s[i].student_id);
//     printf("enter marks");
//     scanf("%f",&s[i].marks);
//     }

//     printf("displaying the details of the three students");
//         for(int i=0;i<3;i++)
//     {
//     printf("displaying name");
//     printf("%s",s[i].name);
//     printf("displaying  id");
//     printf("%s",s[i].student_id);
//     printf("displaying  marks");
//     printf("%f",s[i].marks);
//     }
// }


//using pointers
// #include<stdio.h>
// struct student{

// char student_id[10];
// char name[30];
// float marks;
// };
// void accept_details(struct student *ptr ){
// for(int i=0;i<3;i++){
//     printf("enter name");
//     scanf("%s",ptr->name);
//     printf("enter student id");
//     scanf("%s",ptr->student_id);
//     printf("enter marks");
//     scanf("%f",&ptr->marks);
// }
// }
// void print_details(struct student *ptr)
// {
//     for(int i=0;i<3;i++){
//     printf("%s",ptr->name);
//     printf("%s",ptr->student_id);
//     printf("%f",ptr->marks);
// }
// }
// void main()
// {
//     struct student *ptr;
//     ptr=NULL;
//     struct student s[3];
//     ptr=s;
//     accept_details(ptr);
//     print_details(ptr);
// }

//DYNAMIC MEMORY ALLOCATION OF STRUCTURE 
#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[15];
    int id;
    int age;
};
void main()
{
    struct student *ptr;
    int n;
    printf("enter the number of persons");
    scanf("%d",&n);
    ptr=(struct student *)malloc(n*sizeof(struct student));
    if(ptr==NULL)
    {
        printf("no space available");
        exit(1);
    }
    int j=0;
    for(int i=0;i<n;i++)
    {
        printf("enter the details of student(%d)",j+1);
        printf("enter name");
        scanf("%s",(ptr+i)->name);
        printf("enter age");
        scanf("%d",&(ptr+i)->age);
        printf("enter id");
        scanf("%d",&(ptr+i)->id);
        j++;
    
    
    printf("displaying the elements");
    for(int i=0;i<n;i++)
    {
        printf("%s",(ptr+i)->name);
         printf("%d",(ptr+i)->age);
          printf("%d",(ptr+i)->id);
    }
}
}