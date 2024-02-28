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
    if(newnode == NULL) {
        printf("Memory allocation failed");
        exit(0);
    }
    return newnode;
}
void display(node *head){
    node *temp;
    if(head->next==head)