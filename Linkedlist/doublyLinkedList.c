#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MS 5
int c;
struct student{
    char name[25],USN[10],dept[10],phno[11];
    float marks1,marks2,marks3,total,average;
    struct student *next,*prev;
};
typedef struct student node;
node *getnode(node *head){
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter the name of the student: ");
    scanf("%s",newnode->name);
    printf("Enter the USN of the student: ");
    scanf("%s",newnode->USN);
    printf("Enter the department of the student: ");
    scanf("%s",newnode->dept);
    printf("Enter the phone number of the student: ");
    scanf("%s",newnode->phno);
    printf("Enter the marks of the student in subject 1: ");
    scanf("%f",&newnode->marks1);
    printf("Enter the marks of the student in subject 2: ");
    scanf("%f",&newnode->marks2);
    printf("Enter the marks of the student in subject 3: ");
    scanf("%f",&newnode->marks3);
    newnode->total=newnode->marks1+newnode->marks2+newnode->marks3;
    newnode->average=newnode->total/3;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
int countnodes(node *head) {
    node *temp;
    int c=0;
    temp=head;
    while(temp!=NULL) {
        c++;
        temp=temp->next;
    }
    return c;
}
node *create(node *head){
    node *temp,*newnode;
    temp = head;
    if(head==NULL){
        head=getnode(head);
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        newnode=getnode(head);
        temp->next=newnode;
        newnode->prev=temp;
    }
    return head;
}
node *insertfront(node *head){
    node *newnode;
    if(countnodes(head)==MS){
        printf("full\n");
    }
    else{
        newnode=getnode(head);
        if(head==NULL){
            head=newnode;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    }
    return head;
}
node *insertrear(node *head){
    node *newnode,*temp;
    if(countnodes(head)==MS){
        printf("full\n");
    }
    else{
        newnode=getnode(head);
        if(head==NULL){
            head=newnode;
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
        }
    }
    return head;
}
node *deletefront(node *head){
    node *temp;
    if(head==NULL){
        printf("empty\n");
    }
    else{
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    return head;
}
node *deleterear(node *head){
    node *temp;
    if(head==NULL){
        printf("empty\n");
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
    }
    return head;
}
node *display(node *head){
    node *temp;
    if(head==NULL){
        printf("empty\n");
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("Name: %s\n",temp->name);
            printf("USN: %s\n",temp->USN);
            printf("Department: %s\n",temp->dept);
            printf("Phone number: %s\n",temp->phno);
            printf("Marks in subject 1: %f\n",temp->marks1);
            printf("Marks in subject 2: %f\n",temp->marks2);
            printf("Marks in subject 3: %f\n",temp->marks3);
            printf("Total marks: %f\n",temp->total);
            printf("Average marks: %f\n",temp->average);
            temp=temp->next;
        }
    }
    return head;
}
int main(){
    node *head=NULL;
    int ch;
    while(1){
        printf("1. Create\n2. Insert front\n3. Insert rear\n4. Delete front\n5. Delete rear\n6. Display\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: head=create(head);
                    break;
            case 2: head=insertfront(head);
                    break;
            case 3: head=insertrear(head);
                    break;
            case 4: head=deletefront(head);
                    break;
            case 5: head=deleterear(head);
                    break;
            case 6: head=display(head);
                    break;
            case 7: exit(0);
                    break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}