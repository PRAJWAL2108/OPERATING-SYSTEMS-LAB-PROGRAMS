// C program to simulate the following CPU scheduling algorithms : ROUND ROBIN
#include<stdio.h>
int main()
{
	int wt[10],tat[10],rbt[10],bt[30],ts,n,i,x=0,tot=0;
	float totwt=0, totat=0;
	printf("Enter the no of processes:");
	scanf("%d",&n);
	printf("Enter the time quantum:");
	scanf("%d",&ts);
	for(i=0;i<n;i++)
	{
		printf("enter burst  time for process %d:",i+1);
		scanf("%d",&bt[i]);
		rbt[i]=bt[i];
	}
	for(i=0;i<n;i++)
		tot=tot+bt[i];
		while(x!=tot)
		{
			for(i=0;i<n;i++)
			{
				if(rbt[i]>ts)
				{
					x=x+ts;
					rbt[i]=rbt[i]-ts;
				}
				else if((rbt[i]<=ts)&&rbt[i]!=0)
				{
					x=x+rbt[i];
					wt[i] = x - bt[i];
					tat[i] = bt[i] + wt[i]; 
					rbt[i]=0;
				}
			}
		}
	printf("Process_no\t Burst time\tWait time\tTurn around time\n");
	for (i=0;i<n;i++) 
		printf("%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i], tat[i]);
	for (i=0;i<n;i++) 
		totat=totat+tat[i];
	for (i=0;i<n;i++) 
		totwt = totwt + wt[i];
	printf("average waiting time=%f",totwt/n);
	printf("\naverage turnaround time=%f",totat/n);
	return 0;
}
