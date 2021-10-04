#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	cout<<"Enter no of tasks and no of servers\n";
	cin>>m>>n;
	int ect[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>ect[i][j];
		}
	}
	int scheduled[m],busy_wait[n];
	memset(scheduled,0,sizeof(scheduled));
	memset(busy_wait,0,sizeof(busy_wait));
	int jobs_assigned = 0;
	while(jobs_assigned<m)
	{
		int min_t[m],assigned_server[m];
		for(int i=0;i<m;i++)
		{
			if(scheduled[i]==0)
			{
				int min_time=ect[i][0] + busy_wait[0];
				assigned_server[i] = 0;
				for(int j=1;j<n;j++)
				{
					if(ect[i][j]+busy_wait[j] < min_time)
					{
						min_time = ect[i][j]+busy_wait[j];
						assigned_server[i] = j;
					}
				}
				min_t[i] = min_time;
			}
			else
			{
				min_t[i] = INT_MAX;
			}
		}
		int overall_max = -1;
		int task =0;
		for(int i=0;i<m;i++)
		{
			if(scheduled[i]==0)
			{
				if(overall_max < min_t[i])
					{overall_max = min_t[i];task =i;}
			}
		}
		cout<<"task "<<task+1<<" is assigned to server "<<assigned_server[task]+1<<"\n";
		scheduled[task] =1;
		busy_wait[assigned_server[task]]+=ect[task][assigned_server[task]];
		jobs_assigned++;
	}
	int max_t = busy_wait[0];
	for(int i=0;i<n;i++)
	{
		//cout<<busy_wait[i]<<" ";
		if(max_t < busy_wait[i])
			max_t=busy_wait[i];
	}
	cout<<"total time = "<<max_t;
}