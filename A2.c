#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>//used to help determine if seed is an integer
#include "listADT.h"




int main(int argc, char *argv[]) {




//a function to check if we have an interger; used to ensure the seed is an integer

//also to check if all numbers on card are integer
int isInt(char seed[]){

//returns 1 if integer;0 if not

for (int i=0;i<seed[i]!=0;i++){

if (!isdigit(seed[i])){return 0;}
}
return 1;

}
  char  *one,*two,*three,*four,*five;
  List tempL;
  List tempM;
  List L;//holds all numbers from input file
  List M;//holds all called random numbers
  List C;//temporarily used to ensure no duplicates in input file
  //init(&tempL,&tempM,&L,&M,&C);
  init(&tempL);
  //init(&tempM);
  init(&L);
  init(&M);
  init(&C);
  int mainCond = 1;


char *str = malloc(16);
if (argc != 3){fprintf(stderr,"Usage: %s seed cardFile\n",argv[0]);exit(1);}
if (isInt(argv[1])==0){fprintf(stderr,"Expected integer seed, but got %s\n",argv[1]);exit(2);}
int seed = atoi(argv[1]);
srand(seed);


int count=0;//helps us ensure file has 25 numbers and that all numbers are in the range they are supposed to be


if  ((fopen(argv[2],"r")) == NULL) {
   fprintf(stderr,"%s: is nonexistent or unreadable\n",argv[2]);
   exit(3);}


FILE *aFile = fopen(argv[2], "r");


while (fscanf(aFile, "%s ", str) == 1) {

// checking to see if there a field in the input is not integer

if (isInt(str)==0){fprintf(stderr,"%s has bad format\n",argv[2]);exit(4);}





// checking to see all numbers are in the correct range
int n=atoi(str);//helps us convert string to number to check the ranges
if (count == 0 ||  count == 5 || count == 10 || count ==  15 || count == 20){

    if (n<1 || n>15) {fprintf(stderr,"%s has bad format\n",argv[2]);exit(4);}
}

if (count == 1 ||  count == 6 || count == 11 || count == 16  || count == 21){

    if (n<16 || n>30) {fprintf(stderr,"%s has bad format\n",argv[2]);exit(4);}
}

if (count == 2 ||  count == 7 || count == 12 || count ==  17 || count == 22){

    if ( n!=0 && (n<30 || n>45)) {fprintf(stderr,"%s has bad format\n",argv[2]);exit(4);}
}

if (count == 3 ||  count == 8 || count == 13 || count ==  18 || count == 23){

    if (n<45 || n>60) {fprintf(stderr,"%s has bad format\n",argv[2]);exit(4);}
}

if (count == 4 ||  count == 9 || count == 14 || count ==  19 || count == 24){

    if (n<60 || n>75) {fprintf(stderr,"%s has bad format\n",argv[2]);exit(4);}
}


char * copy = malloc(512);//copying the number to the list
strcpy(copy,str);//making a copy so as not to move the pointer to the list
//checking to see if we already have a number in the list; if we do, that's a format error

if (alreadyIn(&C,copy)==1){fprintf(stderr,"%s %s has bad format dup\n",argv[2],copy);exit(4);}
add(&C,copy);
add(&tempL,copy);
count++;
}
if (count!=25){fprintf(stderr,"%s has bad format\n",argv[2]);exit(4);}
isInside(&L,"00");


atob(&tempL,&L);
isInside(&L,"00");
void randomgen(){

char *thel = malloc(512); strcat(thel,"L");
char *i = malloc(512); strcat(i,"I");
char *n = malloc(512); strcat(n,"N");
char *u = malloc(512);strcat(u,"U");
char *x = malloc(512); strcat(x,"X");


int randnum = rand() % 75 + 1;

char *strnum=malloc(512);//string version of random number
if (randnum >= 1 && randnum<= 9) {strcat(strnum,"0");}
char *mid=malloc(512);
sprintf(mid, "%d", randnum);
strcat(strnum,mid);

char *strnew = (char *)malloc(512);//with prefi

char * copy = malloc(512);

if ( randnum >= 1 && randnum <= 15){ strcat(strnew,strnum);;strcat(thel,strnew);strcpy(copy,thel);add(&M,copy);}

if ( randnum >= 16 && randnum <= 30){ strcat(strnew,strnum);strcat(i,strnew);strcpy(copy,i);
add(&M,copy);}
if ( randnum >= 31 && randnum <= 45){ strcat(strnew,strnum);strcat(n,strnew);strcpy(copy,n);
add(&M,copy);}
if ( randnum >= 46 && randnum <= 60){ strcat(strnew,strnum);strcat(u,strnew);strcpy(copy,u);
add(&M,copy);}
if ( randnum >= 61 && randnum <= 75){ strcat(strnew,strnum);strcat(x,strnew);strcpy(copy,x);
add(&M,copy);}






//checking to see if a number is inside the list so we can mark it
isInside(&L,strnum);





}

printf("\n");
char c[10];
while (mainCond == 1){
randomgen();
init(&tempM);
atob(&M,&tempM);
print(tempM,2);
print(L,1);
printf( "Enter a value : \n");
scanf("%s",c);
if (check(L)==1){mainCond=0;system("clear");print(M,2);print(L,1);printf("WINNER\n");}
system("clear");

if (strcmp(c,"q")==0){mainCond=0;print(M,2);}

}
return 0;