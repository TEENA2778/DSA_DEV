#include<stdio.h>
int main(){
int data[7];

int datatrec[7],c,c1,c2,c3,i;

printf("enter the 4 bits of the message\n");
scanf("%d %d %d %d", &data[0], &data[1], &data[2], &data[4]);
data[6] = data[0] ^ data[2] ^ data[4];
data[5] = data[0] ^ data[1] ^ data[4];
data[3] = data[0] ^ data[1] ^ data[2];

printf("encoded data is,");

for(i=0;i<7;i++)
{
    printf("%d",data[i]);
}
printf("received data is\n");
    for (i = 0; i < 7; i++) {
        scanf("%d", &datatrec[i]);
    }
c1=datatrec[6]^datatrec[4]^datatrec[2]^datatrec[0];
c2=datatrec[5]^datatrec[4]^datatrec[1]^datatrec[0];
c3=datatrec[3]^datatrec[2]^datatrec[1]^datatrec[0];

c=c3*4+c2*2+c1;

if(c==0)
{
    printf("no eror");
}
else
{
    printf("error detected at poition %d",c);

    printf("enter the data sent\n");
    for(i=0;i<7;i++)
    {
        printf("%d",data[i]);
    }
    printf("enter the received data");
    for(i=0;i<7;i++)
    {
        printf("%d",datatrec[i]);
    }
    if (datatrec[7-c]=='0')
    {
        datatrec[7-c]='1';
    }
    else{
       datatrec[7-c]='0'; 
    }
    for(i=0;i<7;i++)
    {
        printf("%d",datatrec[i]);
    }

}
return 0;
}