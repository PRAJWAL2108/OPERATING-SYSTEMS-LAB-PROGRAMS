// a C program to simulate deadlock detection
#include<stdio.h>  
int main()
{
  int n, m, i, j, instanc, k=0,count1=0,count2=0; //count, k variables are taken for counting purpose 
  printf("\n\t Enter No. of Process:-\n");
  printf("\t\t");
  scanf("%d",&n);                            //Entering No. of Processes
  printf("\n\tEnter No. of Resources:-\n");
  printf("\t\t");
  scanf("%d",&m);                       //No. of Resources
  int   avail[m], allot[n] [m], request[n][m],completed[n];
  for(i=0;i<n;i++)
  completed[i]=0;                   //Setting Flag for uncompleted Process
  printf("\n\tEnter No. of Available Instances\n");
  for(i=0;i<m;i++)
  {
    printf("\t\t");
    scanf("%d",&instanc);
    avail[i]=instanc;                        // Storing Available instances
  }
  printf("\n\tEnter number of resources of each type requested by a Process :\n");
  for(i=0;i<n;i++)
  {
    printf("\n\t For P[%d]",i);
    for(j=0;j<m;j++)
     {
        printf("\t");
        scanf("%d",&instanc);
        request[i][j]=instanc;              
     }
  }    
  printf("\n\t Enter no. of instances already allocated to process of a resource:\n");
  for(i=0;i<n;i++)
  {
    printf("\n\t For P[%d]\t",i);
    for(j=0;j<m;j++)
     {
        printf("\t\t");
        scanf("%d",&instanc);
        allot[i][j]=instanc;
     } 
 }
	printf("\n safe sequence");
	while(count1!=n)
 	{
  	count2=count1;
  	for(i=0;i<n;i++)
  	{
    	for(j=0;j<m;j++)
    	{
      	  if(request[i][j]<=avail[j])
       	   {
       	     k++;
       	   }  
    	}    
   	 if(k==m && completed[i]==0 )
   	  {
    	   printf("P[%d]\t",i);
    	   completed[i]=1;
    	   for(j=0;j<m;j++)
    	     {
    	       avail[j]=avail[j]+allot[i][j];
    	      } 
    	     count1++;
    	 }
   	  k=0;
   	}
   	if(count1==count2)
   	{
   	  printf("\t\t Deadlock detected \n");
   	  break;
   	} 
	 }
 	return 0;
}   
