
//Certainly! You can use a 1D array of structures to represent the sparse matrix. Here's the modified code using a 1D array:


#include <stdio.h>

struct Element {
    int row;
    int col;
    int value;
};

int main() {
    struct Element a[100], b[100];
    int n, i, j, currentb = 1, p, q;
    int numcols,numrows;
    printf("Enter the number of values in the sparse matrix: ");
    scanf("%d", &n);
    printf("Enter the number of rows of matrix: ");
    scanf("%d", &numrows);
    printf("Enter the number of columns of matrix: ");
    scanf("%d", &numcols);

    printf("Enter the elements of the sparse matrix:\n");
    for (i = 1; i <=n; i++) {
        printf("Enter row, column, and value for element %d (space-separated): ", i + 1);
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }
    printf("printing original matrix");
    
        for(i=1;i<=n;i++){
            printf("%d %d %d " ,a[i].row,a[i].col,a[i].value);
            printf("\n");
        }
b[0].row = numcols;
b[0].value = n;
b[0].col = numrows;
    // b[0].row=a[0].col;
    // b[0].col=a[0].row;
    // b[0].value=a[0].value;
    //now lets find the transpose 
    //set currentb=1 as we are going to find the transpose according to the columns.we r going to check if the value from the second column(index=1)
    //is equal to 0 or not .The first column has no of columns so we dont consider that 
    if(n>0)//if its a non zero matrix
    {
        currentb=1;
        //for value of i=0 do all operation and then do it for the value of i=1,2,...no of columns as no of columns in a sparse matrix is
        //to the no of non zero elements in the column of sparse matrix .
        for(i=0;i<numcols;i++)
        {
            for(j=1;j<=n;j++){
                if(a[j].col==i){
                    b[currentb].row=a[j].col;
                    b[currentb].col=a[j].row;
                    b[currentb].value=a[j].value;
                    currentb++;
                }

            }
        }
    }

    printf("print the matrix");
    for(i=1;i<=b[0].value;i++)
    {
        
      printf("%d %d %d" ,b[i].row,b[i].col,b[i].value);
      printf("\n");
}
return 0;
}