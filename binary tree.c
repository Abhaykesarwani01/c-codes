#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *left,*right;
};

struct node* creat(){
    int x;
    printf("Enter the value :");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
    }
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=x;
    printf("Enter the left child of %d:\n",x);
    new->left=creat();
    printf("Enter the right child of %d:\n",x);
    new->right=creat();
    return new;
}
void postorder(struct node *r){
    if(r!=NULL){
        postorder(r->left);
        postorder(r->right);
        printf("%d ",r->data);
    }
}
void inorder(struct node *r){
    if(r!=NULL){
        inorder(r->left);
        printf("%d ",r->data);
        inorder(r->right);
    }
}
void preorder(struct node *r){
    if(r!=NULL){
        printf("%d ",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}
void main(){
    struct node *root;
    int ch;
    printf("implementation of binary tree\n");
    do{
        printf("\n1.creat\n2.inorder\n3.preorder\n4.postorder\n5.exit");
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:root=creat();
            break;
        case 2:inorder(root);
            break;
        case 3:preorder(root);
            break;
        case 4:postorder(root);
            break;
        case 5:
            break;
        default:printf("invalid input");
            break;
        }
    }while(ch!=5);
}   
