#include<iostream>
using namespace std;
#define M 10
int main()
{
	int x,n,p[M],pp[M],bt[M],wt[M],t[M];
	float awt,atat;
	cout<<"ENTER THE NO.OF PROCESS\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"ENTER THE BURST TIME AND PRIORITY FOR PROCESS "<<(i+1)<<endl;
		cout<<"BURST_TIME::";
		cin>>bt[i];
		cout<<"PRIORITY::";
		cin>>pp[i];
		p[i]=i+1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(pp[i]>pp[j])     //BUBBLE SORTING
			{
				x=pp[i];
				pp[i]=pp[j];
				pp[j]=x;
				
				x=bt[i];
				bt[i]=bt[j];
				bt[j]=x;
				
				x=p[i];
				p[i]=p[j];
				p[j]=x;
			}
		}
	}
	wt[0]=0;
	awt=0;
	t[0]=bt[0];
	atat=t[0];
	for(int i=1;i<n;i++)
	{
		wt[i]=t[i-1];
		awt+=wt[i];
		t[i]=wt[i]+bt[i];
		atat+=t[i];
	}
	cout<<"PROCESS\tBURST_TIME\tWAITING_TIME\tTART\tPRIORITY\n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<p[i]<<"\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<t[i]<<"\t"<<pp[i]<<"\t"<<endl;
	}
	awt/=n;
	atat/=n;
	cout<<"AVG WAITING TIME=="<<awt<<endl<<"AVG TIME=="<<atat<<endl;
}
