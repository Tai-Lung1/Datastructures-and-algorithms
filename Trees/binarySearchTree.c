#include<stdio.H>
#include<stdlib.H>
#include<string.H>
struct node{
    char name[25],phno[15];
    struct node *lc,*rc;
};
typedef struct node *NODE;
int delflag;
NODE createnode(){
    NODE temp;
    temp= (NODE)malloc(sizeof(struct node));
    printf("Enter the Name : ");
    scanf( "%s",temp->name);
    printf("Enter the phone:");
    scanf("%s",temp->name);
    temp->lc=NULL;
    temp->rc=NULL;
    return temp;
}
void insertBST(NODE root,NODE newnode){
    if(strcmp(newnode->name,root->name)<0){
        if(root->lc==NULL)
            root->lc=newnode;
        else
            insertBST(root->lc,newnode);
    }
    else{
        if(root->rc==NULL)
            root->rc=newnode;
        else
            insertBST(root->rc,newnode);
    }
}
void inorder(NODE r) {
    if()
}
 