#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listADT.h"

//intializing
void init(List *A){
A->head=NULL;
A->length=0;
}

int length(List L) {
  return L.length;
}
//adding to list
void add(List *L, char *v){
 NodeType *new;
  new=(NodeType *) malloc(sizeof(NodeType));

  new->val=v;
  new->next=L->head;
  L->head=new;
  L->length++;
}




//is marked checks to see if something is marked by checking to see if they have three characters
int isMarked(char *val){
{if (strlen(val)==3){return 1;}}
return 0;
}

//all functions below check row,column, or corner by using isMarked
int checkRow1(List L){
int i; NodeType *p;

for (i=0,p=L.head; i<5; i++,p=p->next) {
if(isMarked(p->val)==0){return 0;}
}
return 1;
}

int checkRow2(List L){
int i; NodeType *p;

for (i=0,p=L.head; i<L.length; i++,p=p->next) {
if(i==5||i==6||i==7||i==8||i==9){
if (isMarked(p->val)==0){return 0;}


}

}return 1;}



int checkRow3(List L){
int i; NodeType *p;

for (i=0,p=L.head; i<L.length; i++,p=p->next) {
if(i==10||i==11||i==12||i==13||i==14){

if (isMarked(p->val)==0){return 0;}
}

}return 1;}



int checkRow4(List L){
int i; NodeType *p;

for (i=0,p=L.head; i<L.length; i++,p=p->next) {
if(i==15||i==16||i==17||i==18||i==19){
if (isMarked(p->val)==0){return 0;}
}

}return 1;}

int checkRow5(List L){
int i; NodeType *p;

for (i=0,p=L.head; i<L.length; i++,p=p->next) {
if(i==20||i==21||i==22||i==23||i==24){

if (isMarked(p->val)==0){return 0;}
}

}return 1;}

int checkCorner(List L){
int i; NodeType *p;

for (i=0,p=L.head; i<L.length; i++,p=p->next) {
if(i==0||i==4||i==20||i==24){

if (isMarked(p->val)==0){return 0;}
}

}return 1;}

int checkColumn1(List L){
int i; NodeType *p;

for (i=0,p=L.head; i<L.length; i++,p=p->next) {
if(i==0||i==5||i==10||i==15||i==20){

if (isMarked(p->val)==0){return 0;}
}

}return 1;}


int checkColumn2(List L){
int i; NodeType *p;

for (i=0,p=L.head; i<L.length; i++,p=p->next) {
if(i==1||i==6||i==11||i==16||i==21){

if (isMarked(p->val)==0){return 0;}
}

}return 1;}

int checkColumn3(List L){
int i; NodeType *p;

for (i=0,p=L.head; i<L.length; i++,p=p->next) {
if(i==2||i==7||i==12||i==17||i==22){

if (isMarked(p->val)==0){return 0;}
}

}return 1;}




int checkColumn4(List L){
int i; NodeType *p;

for (i=0,p=L.head; i<L.length; i++,p=p->next) {
if(i==3||i==8||i==13||i==18||i==23){

if (isMarked(p->val)==0){return 0;}
}

}return 1;}

int checkColumn5(List L){
int i; NodeType *p;

for (i=0,p=L.head; i<L.length; i++,p=p->next) {
if(i==4||i==9||i==14||i==19||i==24){

if (isMarked(p->val)==0){return 0;}
}

}return 1;}


int check(List L){
if (checkRow1(L)==1 || checkRow2(L)==1 || checkRow3(L)==1 || checkRow4(L)==1 || checkRow5(L)==1 || checkColumn1(L)==1 || checkColumn2(L)==1 || checkColumn3(L)==1 || checkColumn4(L)==1 || checkColumn5(L)==1 || checkCorner(L)==1){return 1;}

return 0;
}

//prints helps us print lists;u=1 is for when we want to print the list of random nums
//u=2 is for when we want to print the list of numbers in the matrix
void print(List L,int u) {
 int i; NodeType *p;

if(u==2){
printf("Called list: \n");

for (i=0,p=L.head; i<L.length; i++,p=p->next) {
        printf("%s ", p->val);

}}
else{
 printf("L   I   N   U   X\n");
 for (i=0,p=L.head; i<L.length; i++,p=p->next) {
        if (i==4 || i==9 || i == 14 || i == 19){printf("%s ", p->val);putchar('\n');}
else{
if (strlen(p->val)==3){printf("%s ",p->val);}
else{printf("%s  ", p->val);}
 }}}

 printf("\n");
}

//isinside checks to see if c is already in L. if it is it marks it
void isInside(List *L, char *c){
 int i; NodeType *p;
for (i=0,p=L->head; i<L->length; i++,p=p->next) {
        if (strcmp(c,p->val)==0){
char *n = (char *)malloc(512);
char *m = "m";//adding an m to the end of it
strcat(n,p->val);

strcat(n,m);

p->val=n; }//changing the value to have an m at the end

}

}
//already In is similar to isInside
//however, it is meant to check if an input file has duplicate numbers
//if there are duplicates, it return 1
int alreadyIn(List *L,char *c){
 int i; NodeType *p;
for (i=0,p=L->head; i<L->length; i++,p=p->next) {
        if (strcmp(c,p->val)==0){
return 1;
}
}
return 0;
}

//this is the function that moves the elements of one list to another
void atob(List *A,List *L){
 int i; NodeType *p;
for (i=0,p=A->head; i<A->length; i++,p=p->next) {
add(L,p->val);

}
}