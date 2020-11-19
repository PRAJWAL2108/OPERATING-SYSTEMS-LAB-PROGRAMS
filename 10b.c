// a C program to simulate page replacement algorithm : LRU
#include<stdio.h>
int find_min(int count[], int size)
{
       int pos,i;
       pos=0;
       for(i=1;i<size;i++)
      {
          if(count[i]<count[pos])
                  pos=i;
      }
return pos;
}
int main()
{
int page[100],frame[10],i,j,count[10],pfault=0,n,fsize,min,t=1,status=0;
printf("Enter Total number of pages (MAX-100):");
scanf("%d",&n);
printf("\nEnter pages\n");
for(i=0;i<n;i++)
{
scanf("%d",&page[i]);
}
printf("Enter frame size (MAX 10):");
scanf("%d",&fsize);
for(i=0;i<fsize;i++)
{
frame[i]=-1;
count[i]=0;
}
for(i=0;i<n;i++) 
{
       status=0;
       for(j=0;j<fsize;j++)
      {
           if(page[i]==frame[j]) 
            {
                    count[j]=t;
                     t++;
                    status=1;
             }
       }
      if(status==1)
          goto A;
      min=find_min(count,fsize);
      count[min]=t++;
      pfault++;
    frame[min]=page[i];
    A: for(j=0;j<fsize;j++)
         printf("%d\t",frame[j]);
printf("\n"); 
}
printf("\nPAGE FAULT is %d",pfault);
return 0;}

