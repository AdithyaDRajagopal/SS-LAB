#include<stdio.h>

int m,n;
int allocation[10][10],max[10][10],need[10][10],available[10],resource[10];

void safe()
{
 int i,j,flag,work[10][10],finish[10],count=n;
 for(i=0;i<n;i++)
 finish[i]=0;
 for(i=0;i<m;i++)
 work[i]=available[i];
 while(count!=0)
 for(i=0;i<n;i++)
 {
  
  if(finish[i]==0)
  {
   flag=1;
   for(j=0;i<m;i++)
   if(need[i][j]>work[j])
   {
    flag=0;
    break;
   }
   if(flag==1)
   {
    for(j=0;j<m;j++)
    work[j]=work[j]+allocation[i][j];
    finish[i]=1;
    count=n;
   }
   if(flag==0)
   count--;
  }
 }
}

void main()
{
 int i,j,s;
 char x='a';
 printf("Enter the number of resources:");
 scanf("%d",&m);
 printf("Enter the maximum instances of each resources:\n");
 for(i=0;i<m;i++)
 {
  printf("%c = ",x);
  scanf("%d",&resource[i]);
  x++;
 }
 printf("Enter the number of processes:");
 scanf("%d",&n);
 x='a';
 printf("Enter the ALLOCATION Matrix:\n\t");
 for(i=0;i<m;i++)
 {
  printf("%c\t",x);
  x++;
 }
 printf("\n");
 for(i=0;i<n;i++)
 {
  printf("P[%d]:\t",i);
  for(j=0;j<m;j++)
  scanf("%d",&allocation[i][j]);
 }
 x='a';
 printf("Enter the MAX Matrix:\n\t");
 for(i=0;i<m;i++)
 {
  printf("%c\t",x);
  x++;
 }
 printf("\n");
 for(i=0;i<n;i++)
 {
  printf("P[%d]:\t",i);
  for(j=0;j<m;j++)
  scanf("%d",&max[i][j]);
 }
 for(i=0;i<m;i++)
 {
  s=0;
  for(j=0;j<n;j++)
  s=s+alloaction[i][j];
  available[i]=resource[i]-s;
 }
 for(i=0;i<n;i++)
 for(j=0;j<m;j++)
 need[i][j]=max[i][j]-allocation[i][j];
 safe();
}
