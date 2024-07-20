#include<stdio.h>
int main(){
int no_queries,size_left,bucket_size,input,output,buffer,storage,i;

storage=0;

bucket_size=12;

no_queries=4;

input=4;

output=2;

for(i=0;i<no_queries;i++)
{
    size_left=bucket_size-storage;
    if (input<=size_left)
    {
        storage+=input;
    }
    else
    {
        printf("packet losss :%d",input);
    }
        printf("buffer size %d out of bucket size %d",storage,bucket_size);

        storage-=output;
    
}
return 0;
}