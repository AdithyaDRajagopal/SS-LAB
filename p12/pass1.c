#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
 FILE *f1,*f2,*f3;
 char opcode[20],operand[20],label[20];
 f1=fopen("minp2.txt","r");
 f2=fopen("ntab2.txt","w+");
 f3=fopen("dtab2.txt","w+");
 fscanf(f1,"%s%s%s",label,opcode,operand);
 while(strcmp(opcode,"MEND")!=0)
 {
  if(strcmp(opcode,"MACRO")==0)
  {
   fprintf(f2,"%s\n",label);
   fprintf(f3,"%s\t%s\n",label,operand);
  }
  else
  fprintf(f3,"%s\t%s\n",opcode,operand);
  fscanf(f1,"%s%s%s",label,opcode,operand);
 }
 fprintf(f3,"%s\n",opcode);
 fclose(f1);
 fclose(f2);
 fclose(f3);
}
