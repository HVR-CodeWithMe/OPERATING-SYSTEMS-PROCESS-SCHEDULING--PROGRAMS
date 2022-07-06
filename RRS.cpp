#include<iostream>
#include<vector>
using namespace std;
# define M 10
int main()
{
	int x,n,i,p[M],bt[M],wt[M],t[M],at[M],ct[M],tm=0,ti,pc=0,st[M],tbt[M],ld[M],r,idl=0;
	float awt=0,tat=0;
	vector<int> v;
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
		ld[i]=0;
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
	v.push_back(0);
	ld[0]=1;
	tm=at[0];
	idl=at[0];
	cout<<"\n\nENTER THE TIME SLICE FOR EACH PROCESS\n\t";
	cin>>ti;
	while(pc!=n)
	for(i=0;(i<v.size());i++)
	{
		int stm=0;
		r=v.at(i);
		
		do
		{
			if(bt[r]>0 && st[r]!=1)
			{
				bt[r]--;
				cout<<"\ncurrent process =====P"<<p[r]<<endl;
				cout<<"current time ========="<<tm+1<<endl;
			    if(bt[r]==0)
			    {
				    pc++;
				    st[r]=1;
				    ct[r] = tm+1;
                    wt[r] = (tm+1) - at[r] - tbt[r];
                    t[r] = (tm+1) - at[r];
				}
				stm++;
			    tm++;
			}
			else
			{
				tm++;
				idl++;
				break;
			}
				
		}while((stm%ti!=0)&&(st[r]!=1));	
		for(int l=i+1;l<n;l++)
		{
			if((at[l]<=tm )&& (ld[l]==0))
			{
				v.push_back(l);
				ld[l]=1;
			}
		}
		if(bt[r]!=0)
		{
			v.push_back(r);
			cout<<"rem bt of P"<<p[r]<<"=="<<bt[r]<<endl;	
		}
		
	}
	cout<<"\t\t\tROUND ROBIN-SCHEDULING\n\n";
	cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<< "\t"<<"completion-time"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"P"<<p[i]<<"\t\t"<<tbt[i]<<"\t\t"<<at[i]<<"\t\t"<<wt[i]<<"\t\t"<<t[i]<<"\t\t"<<ct[i]<<endl;
        awt = awt + wt[i];
        tat= tat + t[i];
    }
    awt/=n;
	tat/=n;
	cout<<"\n\nAVG WAITING TIME=="<<awt<<endl<<"AVG TRUN_A_TIME=="<<tat<<endl;
	cout<<"\nCPU IDLE TIME=="<<idl<<endl;
}

