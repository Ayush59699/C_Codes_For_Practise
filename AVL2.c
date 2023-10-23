// AVL Tree implementation in C
#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node *lch;
    int data;
    int height;
    struct Node *rch;
};

int height(struct Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b){
    return (a>b) ? a : b ;
}

struct Node *newNode(int data){
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->lch=temp->rch=NULL;
    temp->height=1;
    return temp;
}

struct Node * rightRotate(struct Node *root){
    struct Node *x=root->lch;
    struct Node *T2=x->rch;

    x->rch=root;
    root->lch=T2;

    root->height=max(height(root->lch), height(root->rch)) +1;
    x->height= max(height(x->lch),height(x->rch)) +1;
    return x;
}

struct Node * leftRotate(struct Node *root){
    struct Node *y=root->rch;
    struct Node *T2=y->lch;

    y->lch=root;
    root->rch=T2;

    root->height= max(height(root->lch), height(root->rch))+1;
    y->height=max(height(y->lch), height(y->rch)) +1;
    return y;
}
int getBalance(struct Node *p){
    if(p==NULL){
        return 0;
    }
    return height(p->lch) - height(p->rch);
}

struct Node * insertNode(struct Node *root, int data){
    if(root==NULL)
        return newNode(data);
    
    if(data<root->data)
        root->lch=insertNode(root->lch,data);
    else if( data > root->data)
        root->rch=insertNode(root->rch,data);
    else
        return root;
    
    //Updating balance factor of all Nodes and balancing Tree
    root->height= max(height(root->lch), height(root->rch)) +1;
    int balance=getBalance(root);
    if(balance>1 && data<root->lch->data)
        return rightRotate(root);
    if(balance <-1 && data> root->rch->data)
        return leftRotate(root);
    if(balance>1 && data > root->lch->data){
        root->lch=leftRotate(root->lch);
        return rightRotate(root);
    }
    if(balance<-1 && data< root->rch->data){
        root->rch=rightRotate(root->rch);
        return leftRotate(root);
    }

    return root;
}
struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;

  while (current->lch != NULL)
    current = current->lch;

  return current;
}

struct Node *deleteNode(struct Node *root, int x){
    if(root==NULL)
        return root;
    
    if( x< root->data)
        root->lch=deleteNode(root->lch,x);
    
    else if(x>root->data)
        root->rch=deleteNode(root->rch,x);

    else{
        if((root->lch==NULL) || (root->rch==NULL)){
            struct Node *temp=root->rch ? root->lch : root->rch;

            if(temp==NULL){
                temp=root;
                root=NULL;
            }else
                *root=*temp;
            free(temp);
        } else{
            struct Node *temp=minValueNode(root->rch);
            root->data=temp->data;
            root->rch=deleteNode(root->rch, temp->data);
        }
    }
    if(root==NULL)
        return root;
    
    //Updating BF and Balance tree
    root->height= max(height(root->lch),height(root->rch)) +1;
    int balance =getBalance(root);

    if (balance > 1 && getBalance(root->lch) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->lch) < 0) {
        root->lch = leftRotate(root->lch);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->rch) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->rch) > 0) {
        root->rch = rightRotate(root->rch);
        return leftRotate(root);
    }
    
    return root;
}
void Inorder(struct Node *p){
    if(p){
        Inorder(p->lch);
        printf("%d -> ",p->data);
        Inorder(p->rch);
    }
}
// Print the tree
void printPreOrder(struct Node *root) {
  if (root != NULL) {
    printf("%d -> ", root->data);
    printPreOrder(root->lch);
    printPreOrder(root->rch);
  }
}

int main(){
    struct Node *root=NULL;
    
    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 7);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 8);
    
    printf("Original PREORDER:\n");
    printPreOrder(root);
    
    printf("\nOriginal Inorder:\n");
    Inorder(root);
    
    root = deleteNode(root, 3);

    printf("\nAfter deletion of 3: ");
    
    printf("\nNew PreOrder:\n");
    printPreOrder(root);
    
    printf("\nNew Inorder:\n");
    Inorder(root);

    return 0;
}


