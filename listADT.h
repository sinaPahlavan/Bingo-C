typedef struct node NodeType;
struct node {
        char *val;//the value eg:25
        NodeType *next;//next element

   };
typedef struct {
        int length;
        NodeType *head;
    } List;



//void init(List *A,List *B,List *L,List *M,List *C) ;
//all functions
void init(List *A);
void add(List *L, char *ch) ;
void print(List L,int i) ;
int length(List L) ;
void isInside(List *L, char *ch);
int check(List L);
int isMarked(char *ch);
int printMarked(List *M);
int checkRow1(List L);
int checkRow2(List L);
int checkRow3(List L);
int checkRow4(List L);
int checkRow5(List L);

int checkCorner(List L);
int alreadyIn(List *L,char *ch);
void atob(List *A,List *B);




int checkColumn1(List L);
int checkColumn2(List L);
int checkColumn3(List L);
int checkColumn4(List L);
int checkColumn5(List L);