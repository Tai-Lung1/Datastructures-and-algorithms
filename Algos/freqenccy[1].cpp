#include<stdio.h>

#define MAX_ELEMENTS 20

int arr[MAX_ELEMENTS], n, fr[MAX_ELEMENTS], visited = -1;

void getdata();
void printdata();
void makefrequency();
void makehistogram();

int main() {
    getdata();
    printdata();
    makefrequency();
    makehistogram();
    return 0;
}

void getdata() {
    int i;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void printdata() {
    int i;
    if (n == 0) {
        printf("Array is empty");
    } else {
        printf("Array elements:\n");
        for (i = 0; i < n; i++) {
            printf("%d\t", arr[i]);
        }
    }
    printf("\n");
}

void makefrequency()
 {
    int count, j;
    for (int i = 0; i < n; i++) 
	{
        count = 1;
        for (j = i + 1; j < n; j++) 
		{
            if (arr[i] == arr[j]) 
			{
                count++;
                fr[j] = visited;
            }
        }
        if (fr[i] != visited)
            fr[i] = count;
    }
}

void makehistogram() {
    printf("\nElement / Frequency\n");
    printf("......................\n");
    for (int i = 0; i < n; i++) 
	
	{
        if (fr[i] != visited) 
		{
            printf("%d", arr[i]);
            printf("!");
            for (int j = 0; j < fr[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
}

