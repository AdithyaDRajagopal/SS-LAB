//Simulate the following file organization techniques (a) Single level directory (b) Two level directory (c) Hierarchical

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int dcount=0;

struct directory
{
 char dname[10],fname[10][10];
 int count;
}dir,d[10];

void reset()
{
 for(int i=0;i<9;i++)
 d[i].count=0;
}

void Createdir()
{
 printf("Enter the name of directory:");
 scanf("%s",d[dcount].dname);
 printf("Directory created\n");
 dcount++;
}

void Create(int a)
{
 int i,pos=-1;
 char dirname[10];
 if(a==1)
 {
  printf("Enter the name of the file:");
  scanf("%s",dir.fname[dir.count]);
  dir.count++;
 }
 else if(a==2)
 {
  printf("Enter the name of directory:");
  scanf("%s",dirname);
  for(i=0;i<dcount;i++)
  if(!strcmp(dirname,d[i].dname))
  {
   pos=i;
   break;
  }
  if(pos==-1)
  printf("Directory %s not found\n",dirname);
  else
  {
   printf("Enter the name of the file:");
   scanf("%s",d[pos].fname[d[pos].count]);
   d[pos].count++;
   printf("File created\n");
  }
 }
}

void Delete(int a)
{
 int i,j,pos=-1;
 char f[10],dirname[10];
 if(a==1)
 {
  printf("Enter the file to be deleted:");
  scanf("%s",f);
  for(i=0;i<dir.count;i++)
  if(!strcmp(f,dir.fname[i]))
  {
   pos=i;
   break;
  }
  if(pos==-1)
  printf("File %s not found\n",f);
  else
  {
   dir.count--;
   for(i=pos;i<dir.count;i++)
   strcpy(dir.fname[i],dir.fname[i+1]);
   printf("File %s is deleted\n",f);
  }
 }
 else if(a==2)
 {
  printf("Enter the name of the directory:");
  scanf("%s",dirname);
  for(i=0;i<dcount;i++)
  if(!strcmp(dirname,d[i].dname))
  {
   pos=i;
   break;
  }
  if(pos==-1)
  printf("Directory not found\n");
  else
  {
   printf("Enter the name of the file:");
   scanf("%s",f);
   for(i=0;i<d[pos].count;i++)
   if(!strcmp(f,d[pos].fname[i]))
   break;
   if(i==d[pos].count)
   printf("File not found\n");
   else
   {
    d[pos].count--;
    for(j=i;j<d[pos].count;j++)
    strcpy(d[pos].fname[j],d[pos].fname[j+1]);
    printf("File %s is deleted\n",f);
   }
  }
 }
}

void Search(int a)
{
 int i,pos=-1;
 char f[10],dirname[10];
 if(a==1)
 {
  printf("Enter the file to be searched:");
  scanf("%s",f);
  for(i=0;i<dir.count;i++)
  if(!strcmp(f,dir.fname[i]))
  {
   pos=i;
   break;
  }
  if(pos==-1)
  printf("File %s not found\n",f);
  else
  printf("File %s at position %d in %s\n",f,pos,dir.dname);
 }
 else if(a==2)
 {
  printf("Enter the name of the directory:");
  scanf("%s",dirname);
  for(i=0;i<dcount;i++)
  if(!strcmp(dirname,d[i].dname))
  {
   pos=i;
   break;
  }
  if(pos==-1)
  printf("Directory not found\n");
  else
  {
   printf("Enter the name of the file:");
   scanf("%s",f);
   for(i=0;i<d[pos].count;i++)
   if(!strcmp(f,d[pos].fname[i]))
   break;
   if(i==d[pos].count)
   printf("File not found\n");
   else
   printf("File %s at position %d in %s\n",f,i,d[pos].dname);
  }
 }
}

void Display(int a)
{
 int i,j;
 if(a==1)
 {
  printf("The files are : ");
  for(i=0;i<dir.count;i++)
  printf("%s\t",dir.fname[i]);
  printf("\n");
 }
 else if(a==2)
 {
  printf("Directory\tFiles\n");
  for(i=0;i<dcount;i++)
  {
   printf("%s\t\t",d[i].dname);
   for(j=0;j<d[i].count;j++)
   printf("%s\t",d[i].fname[j]);
   printf("\n");
  }
 }
}

void sld()
{
 int ch;
 printf("Enter the name of directory:");
 scanf("%s",dir.dname);
 dir.count=0;
 do
 {
  printf("1.Create File\t\t2.Delete File\t\t3.Search File\t\t4.Display Files\t\t5.Exit\n");
  printf("Enter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
	  Create(1);
	  break;
   case 2:
	  Delete(1);
	  break;
   case 3:
	  Search(1);
	  break;
   case 4:
	  Display(1);
	  break;
   case 5:
	  printf("Exiting!!!\n");
	  break;
   default:
	   printf("CHOICE INVLAID!!!\n");
  }
 }while(ch!=5);
}

void tld()
{
 int ch;
 reset();
 do
 {
  printf("1.Create Directory\t\t2.Create File\t\t3.Delete File\t\t4.Search File\t\t5.Display Files\t\t6.Exit\n");
  printf("Enter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
	  Createdir();
	  break;
   case 2:
          Create(2);
          break;
   case 3:
          Delete(2);
          break;
   case 4:
          Search(2);
          break;
   case 5:
          Display(2);
          break;
   case 6:
          printf("Exiting!!!\n");
          break;
   default:
           printf("CHOICE INVLAID!!!\n");
  }
 }while(ch!=6);
}

struct tree
{
 char name[20];
 int type,nc;
 struct tree *link[5];
};

void create(struct tree *root,struct tree *ptr,int l,char *dname)
{
 int i;
 if(ptr==NULL)
 {
  ptr=(struct tree *)malloc(sizeof(struct tree));
  printf("Enter name of dir/file(under %s) :",dname);
  scanf("%s",ptr->name);
  printf("Enter 1 for Dir/2 for file :");
  scanf("%d",&ptr->type);
  root->link[l]=ptr;
  for(i=0;i<5;i++)
  ptr->link[i]=NULL;
  if(ptr->type==1)
  {
   printf("No of sub directories/files(for %s):",ptr->name);
   scanf("%d",&ptr->nc);
   for(i=0;i<ptr->nc;i++)
   create(ptr,ptr->link[i],i,ptr->name);
  }
  else
  ptr->nc=0;
 }
}

void display(struct tree *root)
{
 int i;
 if(root!=NULL)
 {
  if(root->type==1)
  {
   printf("%s\t\t",root->name);
   for(i=0;i<root->nc;i++)
   {
    printf("%s",root->link[i]->name);
    if(root->link[i]->type==1)
    printf(" (sd) \t");
    else
    printf(" (f) \t");
   }
   printf("\n");
   for(i=0;i<root->nc;i++)
   display(root->link[i]);
  }
 }
}

void hd()
{
 int i;
 struct tree *root;
 root=(struct tree *)malloc(sizeof(struct tree));
 printf("Enter name of dir/file(under root) :");
 scanf("%s",root->name);
 printf("Enter 1 for Dir/2 for file :");
 scanf("%d",&root->type);
 for(i=0;i<5;i++)
 root->link[i]=NULL;
 if(root->type==1)
 {
  printf("No of sub directories/files(for %s):",root->name);
  scanf("%d",&root->nc);
 }
 else
 root->nc=0;
 for(i=0;i<root->nc;i++)
 create(root,root->link[i],i,root->name);
 printf("Directory\tSubdirectories/Files\n");
 display(root);
}

void main()
{
 int ch;
 printf("Enter\n1.Single Level Directory\n2.Two Level Directory\n3.Hierarchical Directory\n4.Exit\n");
 printf("Enter your choice:");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
	 sld();
	 break;
  case 2:
	 tld();
	 break;
  case 3:
	 hd();
	 break;
  default:
	  printf("CHOICE INVALID!!!\n");
 }
}
