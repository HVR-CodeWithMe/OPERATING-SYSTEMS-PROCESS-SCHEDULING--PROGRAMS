#include<iostream>
using namespace std;
# define M 10
int main()
{
	int x,n,i,p[M],bt[M],wt[M],t[M],at[M],ct[M],tm=0,ti,pc=0,st[M],tbt[M];
	float awt=0,tat=0;
	cout<<"ENTER THE NO.OF PROCESS\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"ENTER THE ARIVAL_TIME AND BURST_TIME FOR PROCESS "<<(i+1)<<endl;
		cout<<"ARIVAL_TIME::";
		cin>>at[i];
		cout<<"BURST_TIME::";
		cin>>bt[i];
		tbt[i]=bt[i];
		p[i]=i+1;
		st[i]=0;
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
				
				x=tbt[i];
				tbt[i]=tbt[j];
				tbt[j]=x;
				
				x=p[i];
				p[i]=p[j];
				p[j]=x;
				
				x=at[i];
				at[i]=at[j];
				at[j]=x;
			}
		
		}
	}
	cout<<"\n\nENTER THE TIME SLICE FOR EACH PROCESS\n\t";
	cin>>ti;
	while(pc!=n)
	for(i=0;(i<n);i++)
	{
		do
		{
			if(bt[i]>0 && st[i]!=1)
			{
				bt[i]--;
			    if(bt[i]==0)
			    {
				    pc++;
				    st[i]=1;
				    ct[i] = tm+1;
                    wt[i] = (tm+1) - at[i] - tbt[i];
                    t[i] = (tm+1) - at[i];
				}
			    tm++;
			}
			else
			break;	
		}while((tm%ti!=0)&&(st[i]!=1));	
	}
	cout<<"\t\t\tROUND ROBIN-SCHEDULING\n\n";
	cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P"<<i+1<<"\t\t"<<tbt[i]<<"\t\t"<<at[i]<<"\t\t"<<wt[i]<<"\t\t"<<t[i]<<"\t\t"<<ct[i]<<endl;
        awt = awt + wt[i];
        tat= tat + t[i];
    }
    awt/=n;
	tat/=n;
	cout<<"\n\nAVG WAITING TIME=="<<awt<<endl<<"AVG TRUN_A_TIME=="<<tat<<endl;
	
}
