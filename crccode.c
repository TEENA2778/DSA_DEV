#include<stdio.h>
#include<string.h>
#define N strlen(gen_poly)


char data[28];
char check_value[28];
char gen_poly[28];
int datal,i,j;

void XOR1()
{
    for(j=1;j<N;j++)
    {
        check_value[j]=((check_value[j]==gen_poly[j])? '0':'1');
    }
}
void crc()
{

    for(i=0;i<N;i++)
    {
        check_value[i]=data[i];
    }
    do{

    if (check_value[0]=='1')
    {
        XOR1();
    }
    for(j=0;j<N-1;j++)
    {
        check_value[j]=check_value[j+1];
    }
    check_value[j]=data[i++];
    
     } while(i<=datal+N-1);
}
void receiver()
{
    printf("enter the received data");
    scanf("%s",data);
    printf("data received is %s",data);
    crc();
    int error_detected=0;

    for(i=0;i<N-1 && !error_detected;i++)
    {
        if (check_value[i]=='1')
        {
            error_detected=1;
        }
    
    }
    if (error_detected)
    {
        printf("error");

    }
    else
    {
        printf("no error");
    }
}


int main()
{
    printf("enter the  data");
    scanf("%s",data);
    
    printf("data to be transmitted is :%s",data);
    datal=strlen(data);
    printf("ENTER THE GEN POLY");
    scanf("%s",gen_poly);
    for(i=datal;i<datal+N-1;i++)
    {
        data[i]='0';
    }
    printf("final data:%s",data);

    crc();
    printf("checksum value is %s",check_value);

    for(i=datal;i<datal+N-1;i++)
    {
        data[i]=check_value[i-datal];
    }
    printf("the final data transmiteed after checksum is: %s",data);
    receiver();
    return 0;
}