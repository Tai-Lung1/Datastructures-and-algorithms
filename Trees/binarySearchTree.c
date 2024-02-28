#include<stdio.H>
#include<stdlib.H>
#include<string.H>
struct node{
    char name[25],phno[15];
    struct node *lc,*rc;
};
typedef struct node *NODE;
void create(){
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    printf("Enter the Name : ");
    scanf( "%s",temp->name);
    printf("Enter the phone:");
    scanf("%s",temp->name);
    temp->lc=NULL;
    temp->rc=NULL;
    return temp;
    }
