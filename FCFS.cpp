#include<stdio.h>
#define M 100
int waitT(int p[],int np,int bt[],int wt[])
{
	wt[0]=0;
	for(int i=1;i<np;i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
	}
}
int trt(int p[],int np,int bt[],int wt[],int tat[])
{
	for(int i=0;i<np;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
}
void avgT(int p[],int np,int bt[])
{
	int wt[np]={0},tat[np]={0};
	float totwt=0,ttat=0;
	waitT(p,np,bt,wt);
	trt(p,np,bt,wt,tat);
	printf("PROCESS\tBURST_TIME\tWAIT_TIME\tTURN_AROUND_TIME\n");
	for(int i=0;i<np;i++)
	{
		totwt=totwt+wt[i];
		ttat=ttat+tat[i];
		printf("%d\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
		printf("\n");
	}
	printf("\nAverage Waiting Time==%f",totwt/np);
	printf("\nAverage Turn Around Time==%f",ttat/np);

}
int main()
{
	int p[M],np,bt[M];
	printf("Enter the NO.OF process\n");
	scanf("%d",&np);
	for(int i=0;i<np;i++)
	{
		printf("Enter the BURST TIME of process P%d\n",i+1);
		p[i]=i+1;
		scanf("%d",&bt[i]);
	}
	printf("\n\n\t\tFIRST COME FIRST SERVE\n\n");
	avgT(p,np,bt);
}
