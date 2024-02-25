#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//environment;
//cell declaration
struct cell {
    int val;
    struct cell *adr;
};
// cell pointer
typedef struct cell *ptr;

//Modules;

void allocate(ptr *p);
void Free(ptr p);
void ass_val(ptr p, int v);
void ass_adr(ptr p, ptr q);
int Value(ptr p);
ptr Next(ptr p);
void create_list(ptr *p, int n);
void display_list(ptr p, int n);
int length_list(ptr p);
int freqV(ptr p, int V);
int gfreqV(ptr p);
ptr AccessV(ptr p, int V);
ptr AccessP(ptr p, int P);
void PAccessV(ptr p, ptr *q, ptr *r, int V);
void delete_val(ptr *p, int V);


//delete the first occurance
// void delete_val(ptr *p, int V){
//     int l = length_list(*p);
//     ptr q,r;
//     if ( (l == 0) || (l == 1  &&  Value(*p)==V)){
//         Free(*p);
//     }
//     else{
//         if (Value(*p) == V){
//             *p = Next(*p);
//         }
//         else{
//             PAccessV(*p,&q,&r,V);
//             ass_adr(r,Next(q));
//             Free(q);
//         }
//     }
// }

//Main;
int main(){
    printf("Enter the number of cells: ");
    int n;
    scanf("%d", &n);
    ptr p;
    create_list(&p,n);
    ptr q, r;
    delete_val(&p,5);
    n = length_list(p);
    printf("%d\n",n);
    display_list(p,n);
}

//allocating a cell in the memory
void allocate(ptr *p){
    *p = malloc( sizeof(struct cell) );
}

void Free(ptr p){
    free( p );
}

void ass_val(ptr p, int v){
    (p)->val = v;
}

void ass_adr(ptr p, ptr q){
    (p)->adr = q;
}

int Value(ptr p){
    return p->val;
}

ptr Next(ptr p){
    return p->adr;
}

void create_list(ptr *H, int n){
    ptr p=NULL,q=NULL;
    int val;
    if (n == 0){
        H = NULL;
    }
    else{
        allocate(&p);
        printf("Enter the first cell's value: ");
        scanf("%d",&val);
        ass_val(p,val);
        *H = p;
        for (int i = 1; i < n; i++)
        {
            allocate(&q);
            printf("Enter the cell n~:%d value:",i+1);
            scanf("%d",&val);
            ass_val(q,val);
            ass_adr(p,q);
            p = q;
        }
        ass_adr(p,NULL);
    }
}

void display_list(ptr p, int n){
    for (int i = 1; i <= n; i++)
    {
        printf("The cell %d's value is: %d \n",i,p->val);
        p = Next(p);
    }   
}

int length_list(ptr p){
    int cpt = 0 ;
    while(p != NULL){
        cpt++;
        p = Next(p);
    }
    return cpt;
}

int freqV(ptr p, int V){
    int cpt = 0;
    int l = length_list(p);
    for (int i = 0; i < l ; i++){
        if (Value(p) == V ){
            cpt++;
        }
        p = Next(p);
    }
    return cpt;
}

int gfreqV(ptr p){
    int g = 0, l=length_list(p) , sauv;
    for (int i = 0; i < l ; i++){
        if ( freqV(p,Value(p)) > g ){
            g = freqV(p,Value(p));
            sauv = Value(p);
        }
        p = Next(p);
    }
    return sauv;
}

ptr AccessV(ptr p, int V){
    int l = length_list(p);
    ptr q = NULL;
    for (int i = 0; i < l; i++)
    {
        if ( Value(p) == V){
            q = p;
        }
        p = Next(p);
    }
    return q;
}

ptr AccessP(ptr p, int P){
    ptr q = NULL;
    for (int i = 0; i < P ; i++){
        q = p;
        p = Next(p);
    }
    return q;
}

void PAccessV(ptr p, ptr *q, ptr *r, int V){
    int l = length_list(p);
    ptr m;
    *q = NULL;
    *r = NULL;
    m = NULL;
    for (int i = 0; i < l; i++)
    {
        if ( Value(p) == V){
            *q = p;
            *r = m;
        }
        m = p;
        p = Next(p);
    }
}

void delete_val(ptr *p, int V){
    int l = length_list(*p);
    ptr q,r;
    if ( (l == 0) || (l == 1  &&  Value(*p)==V)){
        *p = NULL;
    }
    else{
        for (int i = 0; i < l-1; i++)
        {
            if (Value(*p) == V){
                *p = Next(*p);
            }
            else{
                PAccessV(*p,&q,&r,V);
                if (q != NULL && r != NULL){
                ass_adr(r,Next(q));
                Free(q);
                }
            }
        }
    }
}
