// a C program to simulate page replacement algorithm : FIFO
#include<stdio.h>
int main()
{
int nof, pf=0,rs[20], m[10], n, count=0, i,j,k;
printf("\n Enter the length of the reference string:");
scanf("%d", &n);
printf("\nEnter the reference string:");
for(i=0;i<n;i++)
scanf("%d", &rs[i]);
printf("\nEnter the number of frames:");
scanf("%d", &nof);
for( i=0; i<nof;i++)
m[i]=-1;
for (i=0;i<n;i++)
{
  for (k=0;k<nof;k++)
 {
	if(m[k]==rs[i])
               break;
}
if(k==nof)
{
 	   m[count++]=rs[i];
   pf++;
}
for (j=0;j<nof;j++)
printf("\t %d",m[j]);
if(k==nof)
printf("\t Page Fault no %d \n", pf);
printf("\n");
if(count==nof)
count=0;
}
printf("\n The number of page faults using FIFO are %d",pf);
return 0;
}

