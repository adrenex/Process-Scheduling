#include<bits/stdc++.h>
using namespace std;

struct process
{
    int pid, arr_time, burst_time, temp_b_time;
    int wt, tat;
};
void queue_update(int n, vector<process> p, int time, deque<int> &q);
int main()
{
    int n;
    cin>>n;

    vector<process> p(n);

    for(int i=0; i<n;i++)
    {
        cin>>p[i].arr_time>>p[i].burst_time;
        p[i].pid = i+1;
        p[i].temp_b_time = p[i].burst_time;
        
    }
    int tq;
    cin>>tq;
    deque<int> q;
    int time=0;
    int count = 0;
    while(p[0].arr_time>time)
    time++;
    while(count<n)
    {   
        queue_update(n,p,time,q);
        
        int id = q.front();
        for(int j=1; j<=tq; j++)
        {   
            // cout<<"j = "<<j<<endl;
            time++;
            queue_update(n,p,time,q);
            p[id].temp_b_time--;
            if(p[id].temp_b_time==0)
            {   
                count++;
                p[id].wt = time-p[id].arr_time-p[id].burst_time;
                p[id].tat = time - p[id].arr_time;

                cout<<p[id].pid<<" "<<p[id].wt<<" "<<p[id].tat<<endl;
                break;
            }
        }
        q.pop_front();
    }
}

void queue_update(int n, vector<process> p, int time, deque<int> &q)
{
    for(int j=0; j<n;j++)
        {
            if(p[j].arr_time<=time && p[j].temp_b_time>0)
            {  
                //  cout<<"process is "<<p[j].pid<<endl;
                auto itr = find(q.begin(), q.end(), j);
                if(itr == q.end())
                    q.push_back(j);
                
            }
        }
}
