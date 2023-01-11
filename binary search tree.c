#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *new;


struct node *insert(struct node *ptr,int item){
    if(ptr==NULL){
        new=(struct node*)malloc(sizeof(struct node));
        new->left=new->right=NULL;
        new->data=item;
        return new;
    }
    else if(item < ptr->data){
        ptr->left = insert(ptr->left,item);
        return ptr;
    }
    else if(item > ptr->data){
        ptr->right =insert(ptr->right,item);
        return ptr;
    }
    else{
        printf("dublicate values not allowed");
        return ptr;
    }
   
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
    int ch,x;
    struct node *root=NULL;
    printf("\nimplementation of binary search tree");
    do{
        printf("\n1.creat\n2.inorder\n3.preorder\n4.postorder\n5.exit");
        printf("enter your choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                int choice;
                do{
                    printf("Enter the value to be inserted :");
                    scanf("%d",&x);
                    root=insert(root,x);
                    printf("\nDo you want to insert again 1.for yes :");
                    scanf("%d",&choice);
                }while(choice==1);   
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