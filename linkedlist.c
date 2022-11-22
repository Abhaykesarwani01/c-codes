#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
struct node *new_node;
struct node *head=NULL;
struct node *temp=NULL;
struct node *prev=NULL;

void insert(){
    int ch=1 ;
    while (ch==1)
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value :");
        scanf("%d",&new_node->data);
        new_node->next=NULL;
        if(head==NULL)
            head=temp=new_node;
        else{
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=new_node;
            temp=new_node;
        }

        printf("Do you want to enter again 1.YES 2.NO :");
        scanf("%d",&ch);
    }
}

void display(){
    temp=head;
    if(head==NULL)
        printf("List is empty!!!\n");
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
        
}



void delete_val(){
    int num,found=0;
    printf("Enter the element to be deleted :");
    scanf("%d",&num);
    temp=prev=head;
    while(temp!=NULL){
        if(temp->data==num){
            if(head->data==num){
                head=temp->next;
            }
            else{
                prev->next=temp->next;
            }
            free(temp);
            found=1;
        }
        else{
            prev=temp;
            temp=temp->next;
        }
    }
    if(found==1){
        printf("Element deleted !!!\n");
    }
    else{
        printf("Element not found !!!\n");
    }
}

void insert_pos(){
    int pos;
    printf("Enter the position to insert :");
    scanf("%d",&pos);
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value :");
    scanf("%d",&new_node->data);
    if(pos==1){
        new_node->next=head;
        head=new_node;
    }
    else{
        temp=head;
        for (int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
    
}

void main(){
    int choice;
    do
    {
        printf("\n1.insert elements\n2.display\n3.\n4.Delete any element\n5.insert at any position\nzero to exit");
        printf("\nEnter your choice :");
        scanf("%d",&choice);
    
        switch (choice)
        {
            case 1:insert();
                break;
            case 2:display();
                break;
            case 3:
                break;
            case 4:delete_val();
                break;
            case 5:insert_pos();
                break;
            default:
                break;
        }
    }while(choice!=0);
}
