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
void search(BST *,int);
BST *del(BST*, int);
BST *findmin(BST *);
BST *findmax(BST *);
void destroy(BST *);
void internal(BST *);
void external(BST *);
void child(BST *);

int main() {
    BST *temp;
    int ch, num;
    printf("\n\t 1. Insert an element ");
    printf("\n\t 2. Preorder traversal");
    printf("\n\t 3. Inorder traversal");
    printf("\n\t 4. Postorder traversal");
    printf("\n\t 5. Search a value");
    printf("\n\t 6. Delete a node");
    printf("\n\t 7. Find min node");
    printf("\n\t 8. Find max node");
    printf("\n\t 9. Destroy binary tree");
    printf("\n\t 10. Display internal nodes");
    printf("\n\t 11. Display external nodes");
    printf("\n\t 12. Display nodes with single child");
    printf("\n\t 13. Exit");
    while(1){
        printf("\n Enter option: ");
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
            else{
                printf("Elements in preorder traversal are :- \n");
                preorder(root);
            }
            break;
        case 3:
            if (root==NULL)
                printf("Empty tree");
            else{
                printf("Elements in inorder traversal are :- \n");
                inorder(root);
            }
            break;
        case 4:
            if (root==NULL)
                printf("Empty tree");
            else{
                printf("Elements in postorder traversal are :- \n");
                postorder(root);
            }
            break;
        case 5:
            if (root==NULL)
                printf("Empty tree");
            else{
            	printf("Enter a number to search : ");
            	scanf("%d",&num);
            	search(root,num);
			}
            break;
        case 6:
            if (root==NULL)
                printf("Empty tree");
            else{
            	printf("Enter a number to delete : ");
            	scanf("%d",&num);
            	root=del(root,num);
			}
            break;
        case 7:
            temp=findmin(root);
            if (temp==NULL)
                printf("Empty tree");
            else
            	printf("The minimum node is : %d",temp->info);
            break;
        case 8:
        	temp=findmax(root);
            if (temp==NULL)
                printf("Empty tree");
            else
            	printf("The maximum node is : %d",temp->info);
            break;
        case 9:
        	destroy(root);
        	root=NULL;
            printf("\n\t The tree is now empty");
            break;
        case 10:
            if(root==NULL)
                printf("Empty tree");
            else{
                printf("The internal roots are :- \n");
                internal(root);
            }
            break;
        case 11:
            if(root==NULL)
                printf("Empty tree");
            else{
                printf("The external roots are :- \n");
                external(root);
            }
            break;
        case 12:
            if(root==NULL)
                printf("Empty tree");
            else{
                printf("The nodes with single child are :- \n");
                child(root);
            }
            break;
        case 13:
            printf("Program ended successfully !!!");
            break;
        default:
            printf("Please enter correct choice !!!\n");
            break;
        }
        if(ch==13)
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
        printf("The node already exist \n");
    }
    return r;
}
void preorder(BST *root){
    if(root!=NULL){
        printf("\t%d", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(BST *root){
    if(root!=NULL){
        inorder(root->left);
        printf("\t%d", root->info);
        inorder(root->right);
    }
}
void postorder(BST *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("\t%d", root->info);
    }
}
void search(BST *root,int num){
	if(root==NULL)
		printf("\t Search unsuccesful !!!");
	else if(num==root->info)
		printf("\t Search successful !!! \n\t Number %d is found",root->info);
	else if(num < root->info)
		search(root->left,num);
	else
		search(root->right,num);
}
BST *del(BST *r, int num){
	BST *temp, *root=r;
	if(root==NULL){
		printf("No such node available");
		return root;
	}
    else if(num<root->info)
        root->left=del(root->left,num);
    else if(num>root->info)
        root->right=del(root->right,num);
    else if(root->left!=NULL && root->right!=NULL){
        temp=findmin(root->right);
        root->info=temp->info;
        root->right=del(root->right,root->info);
    }
    else{
        temp=root;
        if(root->left==NULL)
            root=root->right;
        else if(root->right=NULL)
            root=root->left;
        free(temp);
    }
    return root;
}
BST *findmin(BST *root){
    BST *temp=root;
    if(temp==NULL)
        return NULL;
    if(temp->left==NULL)
        return temp;
    else
        return findmin(temp->left);
}
BST *findmax(BST *root){
    BST *temp=root;
    if(temp==NULL)
        return NULL;
    if(temp->right==NULL)
        return temp;
    else
        return findmax(temp->right);
}
void destroy(BST *root){
    BST *t=root;
    if(t!=NULL){
        destroy(t->left);
        destroy(t->right);
        printf("\n Value %d is deleted",t->info);
        free(t);
    }
}
void internal(BST *root){
    if(root!=NULL){
        if(root->left!=NULL || root->right!=NULL)
            printf("\t%d",root->info);
        internal(root->left);
        internal(root->right);
    }
}
void external(BST *root){
    if(root!=NULL){
        if(root->left==NULL && root->right==NULL)
            printf("\t%d",root->info);
        external(root->left);
        external(root->right);
    }
}
void child(BST *root){
    if(root!=NULL){
        if(root->left==NULL){
            if(root->right!=NULL)
                printf("\t%d",root->info);
        }
        else if(root->right==NULL){
            if(root->left!=NULL)
                printf("\t%d",root->info);
        }
        child(root->left);
        child(root->right);
    }
}
