#include<stdio.h>
#include<string.h>

void main()
{
 int i;
 char name[20];
 strcpy(name,"COPY");
 for(i=0;i<strlen(name)||i<6;i++)
 printf("%c",name[i]);
 for(i=0;i<6-strlen(name);i++)
 printf(" ");
 printf("s\n");
}
