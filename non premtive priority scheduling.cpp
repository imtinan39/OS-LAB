



#include<bits/stdc++.h>
using namespace std;

struct process
    {
        string name;
    int burst_time;
    int priority;
    int arrival_time;
    };


int main()

{

   cout<<"enter the number of process"<<endl;
   int p;
   cin>>p;
   struct process processes[p];

   for(int i=0;i<p;i++)
   {
       cout<<"enter the name of process"<<endl;
       cin>>processes[i].name;
        cout<<"enter the burst_time"<<endl;
        cin>>processes[i].burst_time;
         cout<<"enter the priority"<<endl;
         cin>>processes[i].priority;
          cout<<"enter the arrival"<<endl;
           cin>>processes[i].arrival_time;

   }

   for(int i=0;i<p;i++)
   {
       for(int j=0;j<p-1;j++)
       {
           if(processes[j].priority>processes[j+1].priority)
           {
               swap(processes[j],processes[j+1]);
           }
       }
   }

    for(int i=0;i<p;i++)
   {
      cout<<i<<"= th the name of processs = "<<processes[i].name<<endl;
     // cout<<i<<"= th the burst of processs = "<<processes[i].burst_time<<endl;
     // cout<<i<<"= th the priority of processs = "<<processes[i].priority<<endl;

   }

int gannt[p+1];
//cout<<"enter arrival time"<<endl;
//int arrival_time;
//cin>>arrival_time;
memset(gannt, 0, sizeof(gannt));
gannt[0]=processes[0].arrival_time;
for(int i=1;i<p+1;i++)
{

        gannt[i]=processes[i-1].burst_time;

    gannt[i]=gannt[i]+gannt[i-1];
}
cout<<"gannt chart"<<endl;
for(int i=0;i<p+1;i++)
{
    cout<<gannt[i]<<endl;
}
int waiting_time[p];
//waiting_time[0]=0;
cout<<"waiting time"<<endl;
for(int i=0;i<p;i++)
{
    waiting_time[i]=gannt[i]-processes[i].arrival_time;
    cout<<waiting_time[i]<<endl;
}
float avg_waiting_time=0;
for(int i=0;i<p;i++)

{
    avg_waiting_time=avg_waiting_time+waiting_time[i];
}

cout<<"average waiting time"<<avg_waiting_time/p<<endl;
int complt_time[p];
float average_complt_time=0;
for(int i=1;i<p+1;i++)
{
    complt_time[i-1]=gannt[i];
    average_complt_time=average_complt_time+ complt_time[i-1];
}
cout<<"average completion time"<<endl;
cout<<average_complt_time/p<<endl;
int turn_around_time[p];
float average_turn_around_time=0;
for(int i=0;i<p;i++)
{
    turn_around_time[i]=waiting_time[i]+processes[i].burst_time;
    average_turn_around_time=average_turn_around_time+ turn_around_time[i];
}
cout<<"average turn around time"<<endl;
cout<<average_turn_around_time/p<<endl;



}

