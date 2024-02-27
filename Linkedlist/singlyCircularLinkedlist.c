#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
struct poly{
    int coeff,px,py,pz,flag;
    struct poly *next;
};
typedef struct poly node;
node *getnode(){
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed");
        exit(0);
    }
    return newnode;
}
node *readpoly(node *head){
    node *newnode,*temp;
    int n;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        newnode=getnode();
        printf("Enter the coefficient of the term: ");
        scanf("%d",&newnode->coeff);
        printf("Enter the power of x in the term: ");
        scanf("%d",&newnode->px);
        printf("Enter the power of y in the term: ");
        scanf("%d",&newnode->py);
        printf("Enter the power of z in the term: ");
        scanf("%d",&newnode->pz);
        newnode->flag=0;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    return head;
}
void display(node *head){
    node *temp;
    temp=head;
    while(temp!=NULL){
        if(temp->coeff>0){
            printf("+");
        }
        printf("%dx^%dy^%dz^%d",temp->coeff,temp->px,temp->py,temp->pz);
        temp=temp->next;
    }
    printf("\n");
}
node *insertrear(node *head,int c,int x,int y,int z){
    node *newnode,*temp;
    newnode=getnode();
    newnode->coeff=c;
    newnode->px=x;
    newnode->py=y;
    newnode->pz=z;
    newnode->flag=0;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
}
node *addpoly(node *n1,node *n2,node *n3){
    node *temp1,*temp2;
    temp1=n1;
    while(temp1!=NULL){
        temp2=n2;
        while(temp2!=NULL){
            if(temp1->px==temp2->px && temp1->py==temp2->py && temp1->pz==temp2->pz){
                n3=insertrear(n3,temp1->coeff+temp2->coeff,temp1->px,temp1->py,temp1->pz);
                temp1->flag=1;
                temp2->flag=1;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    temp1=n1;
    while(temp1!=NULL){
        if(temp1->flag==0){
            n3=insertrear(n3,temp1->coeff,temp1->px,temp1->py,temp1->pz);
        }
        temp1=temp1->next;
    }
    temp2=n2;
    while(temp2!=NULL){
        if(temp2->flag==0){
            n3=insertrear(n3,temp2->coeff,temp2->px,temp2->py,temp2->pz);
        }
        temp2=temp2->next;
    }
    return n3;
}
void evaluate(node* head){
    node *temp;
    int x,y,z,result=0;
    printf("Enter the value of x: ");
    scanf("%d",&x);
    printf("Enter the value of y: ");
    scanf("%d",&y);
    printf("Enter the value of z: ");
    scanf("%d",&z);
    temp=head;
    while(temp!=NULL){
        result+=temp->coeff*pow(x,temp->px)*pow(y,temp->py)*pow(z,temp->pz);
        temp=temp->next;
    }
    printf("The result is: %d\n",result);
}
void main(){
    node *n1=NULL,*n2=NULL,*n3=NULL;
    int ch;
    n1 = getnode();
    n2 = getnode();
    n3 = getnode();
    n1->next=n1;
    n2->next=n2;
    n3->next=n3;
    while(1){
        printf("1. Read polynomial\n2. Display polynomial\n3. Add polynomials\n4. Evaluate polynomial\n5. Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: n1=readpoly(n1);
                    n2=readpoly(n2);
                    break;
            case 2: display(n1);
                    display(n2);
                    break;
            case 3: n3=addpoly(n1,n2,n3);
                    display(n3);
                    break;
            case 4: evaluate(n3);
                    break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}