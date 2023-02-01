#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct BST{
    int info;
    struct BST *right, *left;
};

typedef struct BST BST;

BST *root;

BST *insert(BST *root, int num);
void preorder(BST *);
void inorder(BST *);
void postorder(BST *);

int main() {
    int ch, num;
    printf("\n1. Insert an element ");
    printf("\n2. Preorder traversal");
    printf("\n3. Inorder traversal");
    printf("\n4. Postorder traversal");
    printf("\n5. Exit");
    while(1){
        
        printf("\nEnter option: ");
            scanf("%d",&ch);
        switch (ch){
        case 1:
            printf("Enter element to insert: ");
            scanf("%d",&num);
            root = insert(root,num);
            break;
        case 2:
            if (root==NULL)
                printf("Empty tree");
            else
                preorder(root);
            break;
        case 3:
            if (root==NULL)
                printf("Empty tree");
            else
                inorder(root);
            break;
        case 4:
            if (root==NULL)
                printf("Empty tree");
            else
                postorder(root);
            break;
        case 5:
            printf("Program ended successfully");
            break;
        default:
            printf("Please enter correct choice!!!\n");
            break;
        }
        if(ch==5)
            break;
    }
}

BST *insert(BST *r, int num){
    if(r==NULL){
        r=(BST*)malloc(sizeof(BST));
        r->info=num;
        r->left=NULL;
        r->right=NULL;
    }
    else if(num<r->info)
        r->left=insert(r->left,num);
    else if(num>r->info)
        r->right=insert(r->right,num);
    else if(r->info==num){
        printf("The node already exist");
    }
    return r;
}
void preorder(BST *root){
    if(root!=NULL){
        printf("%d\n", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(BST *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\n", root->info);
        inorder(root->right);
    }
}
void postorder(BST *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->info);
    }
}