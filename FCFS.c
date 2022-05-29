//FCFS CPU_Scheduling.

//First in, first out (FIFO), also known as first come, first served (FCFS), is the simplest Processes scheduling algorithm. 
//FIFO/FCFS simply queues processes in the order that they arrive in the ready queue.
//In this algorithm, the process that comes first will be executed first and next process starts only after the previous gets fully executed. 
//Our task is to find average waiting time and average turn around time using FCFS scheduling algorithm. 

//IMPORTANT FORMULA's : -
/*	Completion Time: Time at which process completes its execution.
	Turn Around Time(T.A.T): Completion Time – Arrival Time
	Waiting Time(W.T): Turn Around Time – Burst Time.   */

// Using this approach the Avg TAT for the System is high.So, its create a problem which is known as "CONVOY EFFECT".(Resolve using Shortest-Job-First Algo)

/* ------------------------------------------------------   LET'S START OUR C/C++ PROGRAM   ----------------------------*/

#include<stdio.h>
#include<stdlib.h>

struct Process
{
	int id;
	int AT;
	int BT;
	int wt;
	int TT;
	
};

void sort(struct Process list[10], int s)
{
    int i, j;
    struct Process temp;
    
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (list[j].AT > list[j + 1].AT)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            } 
        }
    }
}

int main()
{
	printf("\n******************FCFS scheduling*******************\n");
	
	struct Process p[10];
	int n,count = 0,Twt=0,TotalTT=0;
	printf("Enter the no. of processes : ");
	scanf("%d",&n);
	printf("Enter Arrival Time and Burst Time for each Processes\n");
	for(int i=0;i<n;i++)
	{
		p[i].id = i+1;
		printf("\nProcess-%d :-\n",i+1);
		printf("AT : ");
		scanf("%d",&p[i].AT);
		printf("BT : ");
		scanf("%d",&p[i].BT);
	}
	
	sort(p , n);   //sort the Processes in terms of arrival time
	
	p[0].wt = 0;
	p[0].TT = p[0].BT+p[0].wt;
	count = count + p[0].BT;   //count contain the start time of execution
	
	TotalTT = p[0].TT;
	
	for(int i=1;i<n;i++)
	{
		if(p[i].AT <= count)
		{
			p[i].wt = count - p[i].AT;
			p[i].TT = p[i].BT + p[i].wt;
			count = count + p[i].BT;
			
			Twt += p[i].wt;
			TotalTT += p[i].TT;
		}
		else
		{
			count += p[i].AT - p[i-1].BT;
			i--;
		}
	}

	printf("\nProcess AT\tBT\tWT\tTotalTT\n");
	for(int i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].AT , p[i].BT,p[i].wt,p[i].TT);
	}
	
	printf("\n Total waiting time :%d", Twt );
	printf("\n Average waiting time :%f",(double)Twt/n);
	printf("\n Total turn around time :%d",TotalTT);
	printf("\n Average turn around time: :%f",(double)TotalTT/n);
	return 0;
}
