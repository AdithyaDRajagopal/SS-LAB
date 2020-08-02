/*Simulate the following non-preemptive CPU scheduling algorithms to find turnaround time and waiting time. (a) FCFS (b) SJF
  (c)Round Robin (pre-emptive) (d) Priority*/

#include<stdio.h>
int w[10],t[10],p[10],z[10];

void sort(int n,int a[])
{
 int i,j,temp,pos;
 for(i=0;i<n-1;i++)
 {
  pos=i;
  for(j=i+1;j<n;j++)
  if(a[j]<a[pos])
  pos=j;
  temp=a[pos];
  a[pos]=a[i];
  a[i]=temp;
  temp=p[pos];
  p[pos]=p[i];
  p[i]=temp;
 }
}

void table(int n,int b[],int c[])
{
 int i;
 if(c[0]==0)
 {
  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for(i=0;i<n;i++)
  printf("P%d\t%d\t\t%d\t\t%d\n",p[i],b[i],w[i],t[i]);
 }
 else
 {
  printf("Process\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for(i=0;i<n;i++)
  printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",p[i],c[i],b[p[i]],w[p[i]],t[p[i]]);
 }
}

void table2(int n,int b[],int c[])
{
  printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for(i=0;i<n;i++)
  printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",p[i],c[i],b[p[i]],w[p[i]],t[p[i]]);
}

void average(int n)
{
 int i;
 float tt=0,tw=0;
 float aw,at;
 for(i=0;i<n;i++)
 {
  tw=tw+w[i];
  tt=tt+t[i];
 }
 aw=tw/n;
 at=tt/n;
 printf("Average Waiting Time=%f\n",aw);
 printf("Average Turnaround Time=%f\n",at);
}

void fcfs(int n,int b[])
{
 int i,a[10];
 for(i=0;i<n;i++)
 {
  printf("Enter the arrival time of P%d:",i);
  scanf("%d",&a[i]);
 }
 sort(n,a);
 w[p[0]]=0;
 t[p[0]]=b[p[0]];
 for(i=1;i<n;i++)
 {
  w[p[i]]=t[p[i-1]];
  t[p[i]]=w[p[i]]+b[p[i]];
 }
 table2(n,b,a);
 average(n);
}

void sjf(int n,int b[])
{
 int i;
 sort(n,b);
 w[0]=0;
 t[0]=b[0];
 for(i=1;i<n;i++)
 {
  w[i]=w[i-1]+b[i-1];
  t[i]=w[i]+b[i];
 }
 table(n,b,z);
 average(n);
}

void rr(int n,int b[])
{
 int i,q,rt[10],tt=0,done;
 printf("Enter the time quantum:");
 scanf("%d",&q);
 for(i=0;i<n;i++)
 rt[i]=b[i];
 do
 {
  done=1;
  for(i=0;i<n;i++)
  if(rt[i]>0)
  {
   done=0;
   if(q<rt[i])
   {
    tt=tt+q;
    rt[i]=rt[i]-q;
   }
   else
   {
    tt=tt+rt[i];
    rt[i]=0;
    w[i]=tt-b[i];
    t[i]=tt;
   }
  }
 }while(done!=1);
 table(n,b,z);
 average(n);
}

void priority(int n,int b[])
{
 int i,pr[10];
 for(i=0;i<n;i++)
 {
  printf("Enter the priority of process P%d:",i);
  scanf("%d",&pr[i]);
 }
 sort(n,pr);
 w[p[0]]=0;
 t[p[0]]=b[p[0]];
 for(i=1;i<n;i++)
 {
  w[p[i]]=w[p[i-1]]+b[p[i-1]];
  t[p[i]]=w[p[i]]+b[p[i]];
 }
 table(n,b,pr);
 average(n);
}

void main()
{
 int n,b[10],i,ch;
 printf("Enter the number of processes:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter the burst time of P%d:",i);
  scanf("%d",&b[i]);
  p[i]=i;
  z[i]=0;
 }
 printf("Enter\n1.FCFS Scheduling\n2.SJF Scheduling\n3.Round Robin Scheduling\n4.Priority Scheduling\n");
 printf("Enter your choice:");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
	 fcfs(n,b);
  	 break;
  case 2:
  	 sjf(n,b);
	 break;
  case 3:
	 rr(n,b);
	 break;
  case 4:
	 priority(n,b);
	 break;
  default:
	  printf("CHOICE INVALID!!!\n");
 }
}


