//Simulate the following page replacement algorithms (a)FIFO (b)LRU (c)LFU

#include<stdio.h>
int rear=0,n,fault=0,len,q[20];

int min_freq(int f[])
{
 int i,j,min;
 for(i=0;i<rear-1;i++)
 {
  min=f[q[i]];
  for(j=i+1;j<rear;j++)
  if(f[q[j]]<min)
  min=f[q[j]];
 }
 return min;
}

void Enqueue(int data)
{
 if(rear<n)
 {
  q[rear]=data;
  rear++;
 }
}
void Dequeue()
{
 int i;
 for(i=0;i<rear-1;i++)
 q[i]=q[i+1];
 rear--;
}
void Delete(int x)
{
 int i,j;
 for(i=0;i<rear;i++)
 if(q[i]==x)
 break;
 for(j=i;j<rear-1;j++)
 q[j]=q[j+1];
 rear--;
}

void fifo(int a[])
{
 int i,j,flag;
 for(i=0;i<len;i++)
 {
  flag=0;
  for(j=0;j<rear;j++)
  if(a[i]==q[j])
  {
   flag=1;
   break;
  }
  if(flag==0)
  {
   if(rear==n)
   {
    Dequeue();
    Enqueue(a[i]);
   }
   else
   Enqueue(a[i]);
   fault++;
  }
  for(j=0;j<rear;j++)
  printf("%d ",q[j]);
  printf("\n");
 }
 printf("Number of Page Faults=%d\n",fault);
}

void lru(int a[])
{
 int i,j,flag;
 for(i=0;i<len;i++)
 {
  flag=0;
  for(j=0;j<rear;j++)
  if(a[i]==q[j])
  {
   flag=1;
   break;
  }
  if(flag==0)
  {
   if(rear==n)
   {
    Dequeue();
    Enqueue(a[i]);
   }
   else
   Enqueue(a[i]);
   if(flag==0)
   fault++;
  }
  else
  {
   Delete(a[i]);
   Enqueue(a[i]);
  }
  for(j=0;j<rear;j++)
  printf("%d ",q[j]);
  printf("\n");
 }
 printf("Number of Page Faults=%d\n",fault);
}

void lfu(int a[])
{
 int i,j,flag,f[10],min,x;
 for(i=0;i<10;i++)
 f[i]=0;
 for(i=0;i<len;i++)
 {
  flag=0;
  min=min_freq(f);
  for(j=0;j<rear;j++)
  if(a[i]==q[j])
  {
   flag=1;
   break;
  }
  if(flag==0)
  {
   if(rear==n)
   {
    for(int k=0;k<rear;k++)
    if(f[q[k]]==min)
    {
     x=q[k];
     break;
    }
    Delete(x);
    Enqueue(a[i]);
    f[a[i]]++;
   }
   else
   {
    Enqueue(a[i]);
    f[a[i]]++;
   }
   fault++;
  }
  else
  f[a[i]]++;
  for(j=0;j<rear;j++)
  printf("%d ",q[j]);
  printf("\n");
 }
 printf("Number of Page Faults=%d\n",fault);
}

void main()
{
 int ch,a[50];
 printf("Enter the number of frames:");
 scanf("%d",&n);
 printf("Enter the length of page reference sting:");
 scanf("%d",&len);
 printf("Enter the page reference string:");
 for(int i=0;i<len;i++)
 scanf("%d",&a[i]);
 printf("Enter\n1.FIFO Page Replacement\n2.LRU Page Replacement\n3.LFU Page Replacement\n");
 printf("Enter your choice:");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
	 fifo(a);
	 break;
  case 2:
	 lru(a);
	 break;
  case 3:
	 lfu(a);
	 break;
  default:
	  printf("CHOICE INVALID!!!\n");
 }
}
