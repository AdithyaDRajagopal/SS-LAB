#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
int check[100] = { 0 };
struct sym{
int sym_addr;
char sym_name[10];
}hash[100];
int key_generate(char name[10]){
int key,key2;
key = (int)name[0];
key2 = (int)name[1];
key = key+key2;
printf("%s\n",name);
//key = atoi(name);
printf("uni id %d \n",key);
key = key%size;
printf("Key is %d \n",key);
return key;
}
void insert(int address,char name[10]){
int key;
key = key_generate(name);
if (check[key]!=1){
hash[key].sym_addr = address;
strcpy(hash[key].sym_name,name);
check[key]=1;
}
else{
printf("Hash full\n");
}
}
void search(char name[10]){int key;
key = key_generate(name);
if(check[key]!=1){
printf("Lable is absent\n");
}
else{
if(strcmp(name,hash[key].sym_name)==0)
printf("label present address is %d\n",hash[key].sym_addr);
else
printf("Lable is absent\n");
}
}
void main(){
int choice,address;
char name[10];
while(1){
printf("Enter :1.Add a symbol 2.Search symtab 3.exit: ");
scanf("%d",&choice);
if(choice == 3)
break;
else if(choice == 1){
printf("Enter the Name: ");
scanf("%s",name);
printf("Enter the address: ");
scanf("%d",&address);
insert(address,name);
}
else if(choice == 2){
 printf("Enter the Name: ");
 scanf("%s",name);
 search(name);
 }
 }
}
