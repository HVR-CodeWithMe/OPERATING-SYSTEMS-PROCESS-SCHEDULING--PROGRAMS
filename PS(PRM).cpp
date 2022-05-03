#include<iostream>
using namespace std;
#define M 10
int n,p[M],pp[M],bt[M],wt[M],t[M],at[M],ct[M],tbt[M],st[M],tm=0,i,j;
float pc=0,tat,awt;
int check(int min,int tm);
//int print(int id);
void pps()
{
	
	while(pc!=n)
	{
		int min=999;
		min=check(min,tm);
		bt[min]--;
        if(bt[min]==0)
        {
            pc++;
            //print(min);
            st[min]=1;
            ct[min] = tm+1;
            wt[min] = (tm+1) - at[min] - tbt[min];
            t[min] = (tm+1) - at[min];
        }
        tm++;
	}
}
int check(int min,int tm)
{
	int id=min;
        for(i=0; i<n; i++)
        {
            if(at[i]<=tm && pp[i]<min && st[i]==0 )
            {
            	min=pp[i];
            	id=i;
			}          
        }
        /*if(min!=id)
        print(id);*/
	return id;
}
/*int print(int id)
{
	cout<<" "<<p[id]<<"\t\t"<<bt[id]<<"\t\t"<<tm<<endl;
}*/
int main()
{
	
	cout<<"ENTER THE NO.OF PROCESS\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"ENTER THE ARIVAL_TIME AND BURST_TIME FOR PROCESS "<<(i+1)<<endl;
		cout<<"ARIVAL_TIME::";
		cin>>at[i];
		cout<<"ENTER PRIORITY::";
		cin>>pp[i];
		cout<<"BURST_TIME::";
		cin>>bt[i];
		tbt[i]=bt[i];
		p[i]=i+1;
		st[i]=0;
	}
	pps();
	cout<<"\n\n\t\t(PRIORITY SCHEDULING PREEMPTIVE)\n\n";
	cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<tbt[i]<<"\t\t"<<at[i]<<"\t\t"<<wt[i]<<"\t\t"<<t[i]<<"\t\t"<<ct[i]<<endl;
        awt = awt + wt[i];
         tat= tat + t[i];
    }
    awt/=n;
	tat/=n;
	cout<<"\n\nAVG WAITING TIME=="<<awt<<endl<<"AVG TRUN_A_TIME=="<<tat<<endl;
}
