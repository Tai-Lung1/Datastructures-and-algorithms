#include<stdio.h>
int arr[20],n,fr[20],visited=-1;
void getdata(){
    int i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
void printdata(){
    int i;
    if(n==0)
    printf("array is empty");
    else{
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
    }
}
void makefrequency(){
    int count,j;
    for(int i=0;i<n;i++){
        count=1;
        for(j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
                fr[j]=visited;
            }
        }
        if(fr[i]!=visited)
        fr[i]=count;
    }
}
void makehistogram(){
    printf("\n Element | Frequency\n");
    printf("---------|-----------\n");
    for(int i=0;i<n;i++){
        if(fr[i]!=visited){
            printf("\n");
            printf("%d",arr[i]);
            printf("/");
        }
        for(int j=0;j<fr[i];j++){
            if(fr[i]!=visited)
            printf("*");
        }
    }
}
int main(){
    getdata();
    printdata();
    makefrequency();
    makehistogram();
}
