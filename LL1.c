#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;

}*first=NULL;

void createLL(int arr[], int n){
    struct Node *t, *last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first-> data=arr[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *p){
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}
void RDisplay(struct Node *p){ //prints reverse
    if(p){
        RDisplay(p->next);
        printf("%d ",p->data);
        //RDisplay(p->next);  //for correct display
    }
}

int count(struct Node *p){
    int c=0;
    while(p){
        c++;
        p=p->next;

    }
    return c;
}


int Add(struct Node *p){
    int s=0;
    while(p){
        s=s+p->data;
        p=p->next;
    }
    return s;
}

int RecAdd(struct Node *p){
    if(p==0){return 0;}
    else{
        return RecAdd(p->next) +p->data ;
    }
}

int Max(struct Node *p){
    int m=-32768, MIN_INT;
    while(p){
        if(p->data>m){
            m=p->data;
        }
        p=p->next;
    }
    return(m);
}

int main(){
    struct Node *temp;
    int A[]={3,5,4,9,8,7,6,2,12,54,87,6,65,4,35,12,1};
    createLL(A,17);

    printf("L.L. :");  Display(first);
    printf("\n");

    printf("R.L.L. :");  RDisplay(first);
    printf("\n");

    int l=count(first);
    int b=Add(first);
    int rs=RecAdd(first);
    printf("Count= %d\n",l);
    printf("Sum= %d\n",b);
    printf("Recursive Sum= %d\n",rs);
    printf("Max= %d\n",Max(first));
    return 0;

}





















