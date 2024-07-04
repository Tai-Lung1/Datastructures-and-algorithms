#include<stdio.h>
#include<stdlib.h>

#define ms 20

typedef struct {
    int front, rear;
    int item[20];
} queue;

queue q1, q2, q3, q4;
int a[50], no = 0, no2 = 1;

void insert(queue *q, int n) {
    if (q->rear == ms) {
        printf("Queue is Full Not insert:");
    } else {
        q->item[++q->rear] = n;
    }
}

int deleteelem(queue *q) {
    if (q->rear < q->front) {
        printf("is empty");
        return -1;
    } else {
        return q->item[q->front++];
    }
}

void display(queue *q) {
    if (q->rear < q->front) {
        printf("Is empty");
    } else {
        no++;
        printf("Group %d: Contets array is:%d:", no, no);
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d\t", q->item[i]);
        }
        printf("\n");
    }
}

void display2(int a[]) {
    no2++;
    printf("Group %d sorted arrry is:", no2);
    for (int i = 0; a[i] != -1; i++) { // Changed sentinel value to -1
        printf("%d\t", a[i]);
        a[i] = '\0';
    }
    printf("\n");
}

void insertsort(int a[]) {
    for (int i = 1; a[i] != -1; i++) { // Changed sentinel value to -1
        int ele = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > ele) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = ele;
    }
}

void delesort(queue *q) {
    for (int i = 0; q->rear >= q->front; i++) { // Fixed condition
        a[i] = deleteelem(q);
    }
    a[q->rear - q->front + 1] = -1; // Set sentinel value
    insertsort(a);
    display2(a);
}

int main() {
    q1.front = 0, q2.front = 0, q3.front = 0, q4.front = -1;
    q1.rear = -1, q2.rear = -1, q3.rear = -1, q4.rear = -1;
    int n;
    printf("Enter the number of value is:");
    scanf("%d", &n);
    printf("Enter the element:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0 && a[i] < 10) {
            insert(&q1, a[i]);
        } else if (a[i] >= 10 && a[i] < 20) {
            insert(&q2, a[i]);
        } else if (a[i] >= 20 && a[i] < 30) {
            insert(&q3, a[i]);
        } else if (a[i] >= 30) {
            insert(&q4, a[i]);
        }
    }
    printf("Categorized data into different groups:\n");
    display(&q1);
    display(&q2);
    display(&q3);
    display(&q4);
    printf("Sorted\n");
    delesort(&q1);
    delesort(&q2);
    delesort(&q3);
    delesort(&q4);
    return 0;
}

