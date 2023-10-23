#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*head ;
void createCLL(int A[],int n){
    struct Node *t, *last;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void DisplayCLL(struct Node *h){
    do{
        printf("%d ", h->data);
        h=h->next;
    }while(h!=head);
    printf("\n");
}
void RecDisplayCLL(struct Node *p){
    static int flag=0;
    if(p!=head || flag==0){
        flag=1;
        printf("%d ",p->data);
        RecDisplayCLL(p->next);
    }
    flag=0;
}
int Length(struct Node *p){
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}

void InsertCLL(struct Node *p,int index, int x)
{
    struct Node *t;
    int i;
    if(index<0 || index > Length(p))
        return;
    if(index==0)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            while(p->next!=head)p=p->next;
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else
    {   
        for(i=0;i<index-1;i++)p=p->next;
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}



int Delete(struct Node *p, int pos){
    struct Node *q;
    int x;
    if(pos<0 || pos> Length(p)){return -1;}
    if(pos==1){
        while (p->next!=head)
        {
            p=p->next;
        }
        x=head->data;
        if(head==p){
            free(head);
            head=NULL;
        }
        else{
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    else{
        for(int i=0;i<pos-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}
      
int main(){
    int A[]={2,3,4,5,6,7,9,11,13,15,14};
    createCLL(A,11);
    //Delete(head,8);
    //DisplayCLL(head);
    //RecDisplayCLL(head);
    InsertCLL(head,5,66);
    return 0;
}