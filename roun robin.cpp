



#include<bits/stdc++.h>
using namespace std;
struct process
    {
        string name;
    int burst_time;

    };

int main()
{
     cout<<"enter the number of process"<<endl;
   int p;
   cin>>p;
   struct process processes[p];
   //vector<gannt>gannt_chart;

   for(int i=0;i<p;i++)
   {
       cout<<"enter the name of process"<<endl;
       cin>>processes[i].name;
        cout<<"enter the burst_time"<<endl;
        cin>>processes[i].burst_time;


   }
cout<<"enter the time slice"<<endl;
int time_slice;
cin>>time_slice;
int cnt=0;
int cnt1=0;

while(cnt<p)
{
    for(int i=0;i<p;i++)
    {
        if(processes[i].burst_time!=0&&processes[i].burst_time>time_slice)
        {
            cnt1=cnt1+time_slice;
            cout<<processes[i].name<<" "<<cnt1<<endl;
        processes[i].burst_time= processes[i].burst_time-time_slice;
        }
         else if(processes[i].burst_time!=0&&processes[i].burst_time<time_slice)
        {
            cnt1=cnt1+processes[i].burst_time;
             cout<<processes[i].name<<" "<<cnt1<<endl;
        processes[i].burst_time=0;
        cnt=cnt+1;
        }
         else if(processes[i].burst_time!=0&&processes[i].burst_time==time_slice)
        {
            cnt1=cnt1+processes[i].burst_time;
             cout<<processes[i].name<<"  " <<cnt1<<endl;
        processes[i].burst_time=0;
        cnt=cnt+1;
        }
        else if(processes[i].burst_time==0)
        {
            continue;
        }

    }
}
cout<<"ending"<<endl;
}

