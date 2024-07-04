#include <stdio.h>
int SIZE;

int hash(int key)
{
    return key % SIZE;
}

int probe(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 0)
    {
        i++;
    }
    return (index + i) % SIZE;
}

void insert(int H[], int key)
{
    int index = hash(key);

    if (H[index] != 0)
    {
        index = probe(H, key);
    }
    H[index] = key;
}

void display(int H[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", H[i]);
    }
    printf("\n");
}

int main()
{
    printf("enter the size:");
    scanf("%d",&SIZE);
    int HT[SIZE] = {0};



    display(HT);

    return 0;
}
