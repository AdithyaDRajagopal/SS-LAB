#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
 FILE *f1,*f2,*f3,*f4;
 int locctr,sa,op,flag,length,size,check,ins;
 char opcode[20],label[20],operand[20],symbol[20],addr[10];
 f1=fopen("sample.txt","r");
 f2=fopen("output.txt","w");
 fscanf(f1,"%s %s %d",label,opcode,&op);
 if(strcmp(opcode,"START")==0)
 {
  sa=op;
  locctr=sa;
  fprintf(f2,"%d\t%s\t%s\t%d\n",locctr,label,opcode,op);
  fscanf(f1,"%s %s %s",label,opcode,operand);
 }
 else
 locctr=0;
 while(strcmp(opcode,"END")!=0)
 {
  ins=locctr;
  if(strcmp(label,"-")!=0)
  {
   f4=fopen("symtab.txt","r+");
   while(!feof(f4))
   {
    check=0;
    fscanf(f4,"%s\t%s",symbol,addr);
    if(strcmp(label,symbol)==0)
    {
     check=1;
     break;
    }
   }
   if(check==1)
   {
    fprintf(f2,"***Duplicate symbol***\n");
    fprintf(f2,"%s\n",label);
   }
   else
   fprintf(f4,"%s %d\n",label,locctr);
   fclose(f4);
  }
  f3=fopen("optab.txt","r");
  while(!feof(f3))
  {
   flag=0;
   fscanf(f3,"%s %s",symbol,addr);
   if(strcmp(opcode,symbol)==0)
   {
    flag=1;
    break;
   }
  }
  fclose(f3);
  if(flag==1)
  locctr=locctr+3;
  else if(strcmp(opcode,"WORD")==0)
  locctr=locctr+3;
  else if(strcmp(opcode,"BYTE")==0)
  {
   size=sizeof(operand);
   locctr=locctr+size;
  }
  else if(strcmp(opcode,"RESW")==0)
  {
   op=atoi(operand);
   locctr=locctr+3*op;
  }
  else if(strcmp(opcode,"RESB")==0)
  {
   op=atoi(operand);
   locctr=locctr+op;
  }
  else
  {
   fprintf(f2,"OPCODE NOT FOUND\n");
   flag=2;
  }
  if(check!=1&&flag!=2)
  fprintf(f2,"%d\t%s\t%s\t%s\n",ins,label,opcode,operand);
  fscanf(f1,"%s %s %s",label,opcode,operand);
 }
 fprintf(f2,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
 length=locctr-sa;
 printf("The program length is %d\n",length);
 fclose(f1);
 fclose(f2);
}
