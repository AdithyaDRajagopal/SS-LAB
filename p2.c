//Simulate the following disk scheduling algorithms (a)FCFS (b)SCAN (c)C-SCAN
#include<stdio.h>
#include<stdlib.h>

int rear=0,range,q[20],head,order[20];

int check(int n)
{
 for(int i=1;i<n;i++)
 if((q[i]==0&&q[i+1]==range)||(q[i+1]==0&&q[i]==range))
 return 0;
 else
 return 1;
}

void sortasc(int a[],int n)
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
 }
}

void sortdesc(int a[],int n)
{
 int i,j,temp,pos;
 for(i=0;i<n-1;i++)
 {
  pos=i;
  for(j=i+1;j<n;j++)
  if(a[j]>a[pos])
  pos=j;
  temp=a[pos];
  a[pos]=a[i];
  a[i]=temp;
 }
}

void Enqueue(int data)
{
 order[rear]=data;
 rear++;
}

void findseek(int n)
{
 int diff,i;
 float seek=0,avgseek;
 for(i=0;i<rear-1;i++)
 {
  if((order[i]==0&&order[i+1]==range)||(order[i+1]==0&&order[i]==range))
  if(check(n))
  {
   printf("Move from %d to %d with seek 0\n",order[i],order[i+1]);
   continue;
  }
  diff=abs(order[i+1]-order[i]);
  printf("Move from %d to %d with seek %d\n",order[i],order[i+1],diff);
  seek=seek+diff;
 }
 printf("Total Seek Time=%.2f\n",seek);
 avgseek=seek/n;
 printf("Average Seek Time=%.2f\n",avgseek);
}

void fcfs(int n)
{
 int i;
 for(i=0;i<=n;i++)
 Enqueue(q[i]);
 findseek(n);
}

void scan(int n)
{
 int i,q1[20],q2[20],n1=0,n2=0;
 for(i=1;i<=n;i++)
 if(head<q[i])
 {
  q1[n1]=q[i];
  n1++;
 }
 else
 {
  q2[n2]=q[i];
  n2++;
 }
 sortasc(q1,n1);
 sortdesc(q2,n2);
 Enqueue(head);
 if(head<range/2)
 {
  for(i=0;i<n2;i++)
  Enqueue(q2[i]);
  Enqueue(0);
  for(i=0;i<n1;i++)
  Enqueue(q1[i]);
 }
 else
 {
  for(i=0;i<n1;i++)
  Enqueue(q1[i]);
  Enqueue(range);
  for(i=0;i<n2;i++)
  Enqueue(q2[i]);
 }
 findseek(n);
}

void c_scan(int n)
{
 int i,q1[20],q2[20],n1=0,n2=0;
 for(i=1;i<=n;i++)
 if(head<q[i])
 {
  q1[n1]=q[i];
  n1++;
 }
 else
 {
  q2[n2]=q[i];
  n2++;
 }
 Enqueue(head);
 if(head<range/2)
 {
  sortasc(q1,n1);
  sortasc(q2,n2);
  for(i=0;i<n1;i++)
  Enqueue(q1[i]);
  Enqueue(range);
  Enqueue(0);
  for(i=0;i<n2;i++)
  Enqueue(q2[i]);
 }
 else
 {
  sortdesc(q1,n1);
  sortdesc(q2,n2);
  for(i=0;i<n2;i++)
  Enqueue(q2[i]);
  Enqueue(0);
  Enqueue(range);
  for(i=0;i<n1;i++)
  Enqueue(q1[i]);
 }
 findseek(n);
}

void main()
{
 int i,noc,n,ch;
 printf("Enter the total number of cylinders:");
 scanf("%d",&noc);
 range=noc-1;
 printf("Enter the size of queue:");
 scanf("%d",&n);
 printf("Enter the queue:");
 for(i=1;i<=n;i++)
 scanf("%d",&q[i]);
 printf("Enter the initial head position:");
 scanf("%d",&head);
 q[0]=head;
 printf("Enter\n1.FCFS Disk Scheduling\n2.SCAN Disk Scheduling\n3.C-SCAN Disk Scheduling\n");
 printf("Enter your choice:");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
	 fcfs(n);
	 break;
  case 2:
	 scan(n);
	 break;
  case 3:
	 c_scan(n);
	 break;
  default:
	  printf("CHOICE INVALID!!!\n");
 }
}
