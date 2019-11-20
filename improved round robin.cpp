




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

   int sum=0;
   for(int i=0;i<p;i++)
   {
       cout<<"enter the name of process"<<endl;
       cin>>processes[i].name;
        cout<<"enter the burst_time"<<endl;
        cin>>processes[i].burst_time;


        sum=sum+processes[i].burst_time;
   }

     for(int i=0;i<p;i++)
   {
       for(int j=0;j<p-1;j++)
       {
           if(processes[j].burst_time>processes[j+1].burst_time)
           {
               swap(processes[j],processes[j+1]);
           }
       }
   }
   cout<<"sorted processes"<<endl;
   for(int i=0;i<p;i++)
   {
      cout<<i<<"= th the name of processs = "<<processes[i].name<<endl;
     // cout<<i<<"= th the burst of processs = "<<processes[i].burst_time<<endl;
     // cout<<i<<"= th the priority of processs = "<<processes[i].priority<<endl;

   }
   int mean=sum/p;
   int median=0;
   if (p%2!=0)
   {
       median=processes[p/2].burst_time;
   }
   else if(p%2==0)
   {
      median=(processes[p/2].burst_time+processes[(p/2)-1].burst_time)/2;
   }
   cout<<"mean is:"<<mean<<endl;
   cout<<"median is:"<<median<<endl;

int time_slice;
time_slice=sqrt(mean*median);
cout<<"time slice is:"<<time_slice<<endl;
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
cout<<"above is gannt chart"<<endl;
}
