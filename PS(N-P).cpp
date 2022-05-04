#include<iostream>
using namespace std;
#define M 10
int pps(int n,int p[],int bt[],int wt[],int t[],int at[],int ct[],int pp[])
{
	int x;
	float awt=0,atat=t[0];
	for(int i=1;i<n;i++)
	{
		int nop=0;
		for(int j=i;j<n;j++)
		{
			if(at[j]<=ct[i-1])
			{
				nop++;
			}	
		}
		int k=i,s=i+nop;
		for(k;k<s;k++)
		{
			for(int l=k+1;l<s;l++)
			{
				if(pp[k]>pp[l])
				{
					x=bt[k];
					bt[k]=bt[l];
					bt[l]=x;
				
					x=p[k];
					p[k]=p[l];
					p[l]=x;
				
					x=at[k];
					at[k]=at[l];
					at[l]=x;
					
					x=pp[k];
					pp[k]=pp[l];
					pp[l]=x;
					
				}
			}
		}
		
		ct[i]=ct[i-1]+bt[i];
		t[i]=ct[i]-at[i];
		wt[i]=t[i]-bt[i];
		/*wt[i]=ct[i-1]-at[i];          
		ct[i]=wt[i]+at[i]+bt[i];       
		t[i]=bt[i]+wt[i]; */             
		awt=awt+wt[i];
		atat=atat+t[i];
	}
	cout<<"\n\n\n";
	cout<<"SCHEDULING PROCESS (PRIORITY  NON-PREEMPTIVE)\n\n\n";
	cout<<"PROCESS\t\tPRIORITY\tARIVAL_TIME\tBURST_TIME\tCOMP_TIME\tTART\tWAIT_TIME\t\n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<p[i]<<"\t\t"<<pp[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<ct[i]<<"\t\t"<<t[i]<<"\t"<<wt[i]<<"\t"<<endl;
	}
	awt/=n;
	atat/=n;
	cout<<"\n\nAVG WAITING TIME=="<<awt<<endl<<"AVG TRUN_A_TIME=="<<atat<<endl;
}
int main()
{
	int x,n,p[M],bt[M],wt[M],t[M],at[M],ct[M],pp[M];
	cout<<"ENTER THE NO.OF PROCESS\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"ENTER THE ARIVAL_TIME , PRIORITY AND BURST_TIME FOR PROCESS "<<(i+1)<<endl;
		cout<<"ARIVAL_TIME::";
		cin>>at[i];
		cout<<"ENTER PRIORITY::";
		cin>>pp[i];
		cout<<"BURST_TIME::";
		cin>>bt[i];
		p[i]=i+1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(at[i]>at[j])     //BUBBLE SORTING
			{
				x=bt[i];
				bt[i]=bt[j];
				bt[j]=x;
				
				x=p[i];
				p[i]=p[j];
				p[j]=x;
				
				x=at[i];
				at[i]=at[j];
				at[j]=x;
				x=pp[i];
				pp[i]=pp[j];
				pp[j]=x;
			}
			if(at[i]==at[j]) //if times are arival times are equal ... sorting based on Priority of Process.
			{
				if(pp[i]>pp[j])
				{
					x=bt[i];
				    bt[i]=bt[j];
				    bt[j]=x;
				
				    x=p[i];
				    p[i]=p[j];
				    p[j]=x;
				
				    x=at[i];
				    at[i]=at[j];
				    at[j]=x;
					
					x=pp[i];
					pp[i]=pp[j];
					pp[j]=x;	
				}
			}
		}
	}
	//wt[0]=0;
	//t[0]=bt[0];
	ct[0]=at[0]+bt[0];
	t[0]=ct[0]-at[0];
	wt[0]=t[0]-bt[0];
	cout<<"ARIVAL_TIME\tPRIORITY\tPROCESS\tBURST_TIME\n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<at[i]<<"\t\t"<<pp[i]<<"\t\t"<<p[i]<<"\t"<<bt[i]<<endl;
	}
	pps(n,p,bt,wt,t,at,ct,pp);	
}
