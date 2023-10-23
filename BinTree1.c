#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *lch;
    int data;
    struct Node *rch;
};

void Inorder(struct Node * root){
    if(root){
        Inorder(root->lch);
        printf("%d -> ", root->data);
        Inorder(root->rch);
    }
}

void Preorder(struct Node* root) {
  if (root == NULL) return;
  printf("%d ->", root->data);
  Preorder(root->lch);
  Preorder(root->rch);
}

// Postorder traversal
void Postorder (struct Node* root) {
  if (root == NULL) return;
  Postorder(root->lch);
  Postorder(root->rch);
  printf("%d ->", root->data);
}
struct Node *Create(int data){
    struct Node* temp= (struct Node *)malloc(sizeof(struct Node));
    temp->lch=temp->rch=NULL;
    temp->data=data;
    return temp;
}

// Insert on the left of the Node
struct Node* insertLeft(struct Node* root, int value) {
    root->lch = Create(value);
    return root->lch;
}

// Insert on the right of the Node
struct Node* insertRight(struct Node* root, int value) {
    root->rch = Create(value);
    return root->rch;
}

int main() {
    struct Node* root = Create(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->lch, 4);

    printf("Inorder traversal \n");
    Inorder(root);

    printf("\nPreorder traversal \n");
    Preorder(root);

    printf("\nPostorder traversal \n");
    Postorder(root);
}