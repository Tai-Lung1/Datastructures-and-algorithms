#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MS 50
char postfix[50];
struct stack{
    int top;
    int item[MS];
}s;
void push(int x) {
    if(s.top==MS-1) {
        printf("Stack is full\n");
        return;
    }
    s.item[++s.top]=x;
}
int pop() {
    if(s.top==-1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s.item[s.top--];
}
int empty(){
    if(s.top==-1)
    return 1;
    return 0;
}
int operation(int a,int b,char c){
    switch(c){
        case '^': return pow(a,b);
        case '*': return a*b;
        case '/': return a/b;
        case '+': return a+b;
        case '-': return a-b;
    }
}
int evaluate(){
    int i,a,b,ans,value;
    char symb;
    for(i=0;postfix[i]!=NULL;i++){
        symb=postfix[i];
        if(symb>='0'&&symb<='9'){
            value=symb-'0';
            push(value);
        }
        else{
            b=pop();
            a=pop();
            value=operation(a,b,symb);
            push(value);
        }
    }
    ans = pop();
    return ans;
}
void main(){
    int result;
    s.top=-1;
    printf("Enter the postfix expression: ");
    gets(postfix);
    result=evaluate();
    printf("The result is: %d",result);
}