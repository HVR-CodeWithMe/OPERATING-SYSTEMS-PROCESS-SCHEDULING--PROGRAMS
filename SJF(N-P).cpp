#include<iostream>
using namespace std;
#define M 10
int minbt(int n,int p[],int bt[],int wt[],int t[],int at[],int ct[])
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
				if(bt[k]>bt[l])
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
	cout<<"SCHEDULING PROCESS (S.J.F  NON-PREEMPTIVE)\n\n\n";
	cout<<"PROCESS\t\tARIVAL_TIME\tBURST_TIME\tCOMP_TIME\tTART\tWAIT_TIME\t\n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<p[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<ct[i]<<"\t\t"<<t[i]<<"\t"<<wt[i]<<"\t"<<endl;
	}
	awt/=n;
	atat/=n;
	cout<<"\n\nAVG WAITING TIME=="<<awt<<endl<<"AVG TRUN_A_TIME=="<<atat<<endl;
}
int main()
{
	int x,n,p[M],bt[M],wt[M],t[M],at[M],ct[M];
	cout<<"ENTER THE NO.OF PROCESS\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"ENTER THE ARIVAL_TIME AND BURST_TIME FOR PROCESS "<<(i+1)<<endl;
		cout<<"ARIVAL_TIME::";
		cin>>at[i];
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
			}
			if(at[i]==at[j]) //if times are arival times are equal ... sorting based on burst time.
			{
				if(bt[i]>bt[j])
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
					
				}
			}
		}
	}
	//wt[0]=0;
	//t[0]=bt[0];
	ct[0]=at[0]+bt[0];
	t[0]=ct[0]-at[0];
	wt[0]=t[0]-bt[0];
	cout<<"ARIVAL_TIME\tPROCESS\tBURST_TIME\n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<at[i]<<"\t\t"<<p[i]<<"\t"<<bt[i]<<endl;
	}
	minbt(n,p,bt,wt,t,at,ct);	
}
