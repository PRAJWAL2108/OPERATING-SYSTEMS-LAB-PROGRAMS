#include<stdio.h>
int main()
{
	int bt[10], at[10], tat[10],wt[10],ct[10]={0};
	int n,sum=0;
	float avgwt=0.0;
	float avgtat=0.0;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	printf("Enter arrival time and burst time for each process\n");
	for(int i=0;i<n;i++)
	{
		printf("Arrival time:\n");
		scanf("%d",&at[i]);
		printf("Burst time:\n");
		scanf("%d",&bt[i]);
		sum=sum+bt[i];
		ct[i]=ct[i]+sum;
		tat[i]=ct[i]-at[i];
		avgtat=avgtat+tat[i];
		wt[i]=tat[i]-bt[i];
		avgwt=avgwt+wt[i];
	}	
	printf("P#\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("Average Turn Around time:%lf\nAverage Waiting time:%lf\n",avgtat/n,avgwt/n);
	return 0;
}