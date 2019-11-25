#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int a[6];

void digits(int data)
{
 int i,digit;
 for(i=5;i>=0;i--)
 {
  digit=data%10;
  data=data/10;
  a[i]=digit;
 }
}

void main()
{
 FILE *f1,*f2,*f3,*f4;
 int start,i,len,flag;
 char symbol[20],addr[10],add[10];
 char address[4],label[20],opcode[20],operand[20],opr[10];
 f1=fopen("inner.txt","r");
 f2=fopen("output.txt","w");
 fscanf(f1,"%s %s %s %s",address,label,opcode,operand);
 fprintf(f2,"H^");
 if(strcmp(opcode,"START")==0)
 {
  start=atoi(address);
  fprintf(f2,"%s",label);
  fscanf(f1,"%s %s %s %s",address,label,opcode,operand);
 }
 fprintf(f2,"  ");
 fprintf(f2,"^");
 digits(start);
 len=18;
 for(i=0;i<6;i++)
 fprintf(f2,"%d",a[i]);
 fprintf(f2,"^");
 digits(len);
 for(i=0;i<6;i++)
 fprintf(f2,"%d",a[i]);
 fprintf(f2,"\n");
 fprintf(f2,"T^");
 digits(start);
 for(i=0;i<6;i++)
 fprintf(f2,"%d",a[i]);
 fprintf(f2,"^0%d",len/2);
 while(strcmp(opcode,"END")!=0)
 {
  f3=fopen("optab.txt","r");
  while(!feof(f3))
  {
   flag=0;
   fscanf(f3,"%s %s",opr,addr);
   if(strcmp(opcode,opr)==0)
   {
    flag=1;
    break;
   }
  }
  if(flag==1)
  {
   f4=fopen("symtab.txt","r");
   while(!feof(f4))
   {
    fscanf(f4,"%s %s",symbol,add);
    if(strcmp(operand,symbol)==0)
    {
     fprintf(f2,"^%s%s",addr,add);
     break;
    }
   }
   fclose(f4);
   fclose(f3);
  }
  fscanf(f1,"%s %s %s %s",address,label,opcode,operand);
 }
 fprintf(f2,"\nE^");
 digits(start);
 for(i=0;i<6;i++)
 fprintf(f2,"%d",a[i]);
 fprintf(f2,"\n");
 fclose(f1);
 fclose(f2);
}
