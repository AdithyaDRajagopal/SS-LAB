#include<stdio.h>

void main()
{
 FILE *f;
 char c;
 f=fopen("sample.txt","r");
 fscanf(f,"%c",&c);
 printf("%c\n",c);
}
