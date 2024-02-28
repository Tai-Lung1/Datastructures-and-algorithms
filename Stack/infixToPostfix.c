#include<stdio.h>
#include<stdlib.h>
#define MS 5
char infix[50],postfix[50],item;
void convert();
struct stack{
    int top;
    char item[MS];
}s;
void push(char value){
    if(s.top==(MS-1)){
        printf("Stack is full\n");
    }
    else{
        s.item[++s.top]=value;
    }
}
char pop(){
    if(s.top==-1){
        printf("Stack is empty\n");
        exit(0);
    }
    else{
        return s.item[s.top--];
    }
}
int empty(){
    if(s.top==-1)
    return 1;
    return 0;
}
int precedence(char c){
    switch(c){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}
void convert(){
    int i=0,pos=0;
    char symb ;
    for(i=0;infix[i]!=NULL;i++){
        symb=infix[i];
        if(symb>='a' && symb<='z' || symb>='A' && symb<='Z'){
            postfix[pos++]=symb;
        }
        else if(symb=='('){
            push(symb);
        }
        else if(symb==')'){
            while(s.item[s.top]!='('){
                postfix[pos++]=pop();
            }
            item=pop();
        }
        else{
            while((!empty()) && precedence(symb)<=precedence(s.item[s.top])&&!empty()){
                postfix[pos++]=pop();
            }
            push(symb);
        }
    }
    while(!empty()){
        postfix[pos++]=pop();
    }
    postfix[pos]='\0';
}

void main(){
    s.top=-1;
    printf("Enter the infix expression: ");
    gets(infix);
    convert();
    printf("The postfix expression is: ");
    puts(postfix);
}