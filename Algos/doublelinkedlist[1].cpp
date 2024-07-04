#include <stdio.h>
#include <stdlib.h>

#define MS 5

struct student 
{
    char usn[10], name[25], dept[12], phon[11];
    float marks1, marks2, marks3, totel, average;
    struct student* next;
    struct student* prev;
};

typedef struct student node;

int countnodes(node* head)
{
    node* ptr;
    ptr = head;
    int c = 0;
    while (ptr != NULL) 
    {
        ptr = ptr->next;
        c++;
    }
    return c;
}
		
node* getnode() 
{
    node* nn = (node*)malloc(sizeof(node));
    printf("Enter student details \n");
    printf("USN: ");
    scanf("%s", nn->usn);
    printf("Name: ");
    scanf("%s", nn->name);
    printf("Department: ");
    scanf("%s", nn->dept);
    printf("Phone No: ");
    scanf("%s", nn->phon);
    printf("Enter the 3 subject Marks:\n");
    scanf("%f%f%f", &nn->marks1, &nn->marks2, &nn->marks3);
    nn->next = nn->prev = NULL;
    return nn;
}


node* create(node* head)  
{
    node* nn, * ptr;
    ptr = head;
    int n, i;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        if (head == NULL)
        {
            nn = getnode();
            head = nn;
        } 
        else
           
        {
        	
        	
            while (ptr->next != NULL) 
            {
                ptr = ptr->next;
            }
            nn = getnode();
            ptr->next = nn;
            nn->prev = ptr;
        }
        ptr = head; 
    }
    return head;
}

node* insertfront(node* head)
{
    node* nn;
    if (countnodes(head) == MS) 
    {
        printf("Insertion is not possible\n");
    }
    else 
    {
        nn = getnode();
        if (head == NULL)
        {
            head = nn;
        } 
        else
        {
            nn->next = head;
            head->prev = nn;
            head = nn;
        }
    }
    return head;
}


node* insertrear(node* head) 
{
    if (countnodes(head) == MS) 
    {
        printf("Insertion is not possible\n");
    }
    else 
    {
        node* nn = getnode();
        if (head == NULL)
        {
            head = nn;
        } 
        else 
        {
            node* ptr = head;
            while (ptr->next != NULL) 
            {
                ptr = ptr->next;
            }
            ptr->next = nn;
            nn->prev = ptr;
        }
    }
    return head;
}

node* deletefront(node* head) 
{
    if (head == NULL)
    {
        printf("No list is empty\n");
    }
    else 
    {
        node* ptr = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(ptr);
    }
    return head;
}

node* deleterear(node* head)
{
    if (head == NULL)
    {
        printf("No list is empty\n");
    } 
    else 
    {
        node* ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr->prev != NULL)
        {
            ptr->prev->next = NULL;
        }
        else 
        {
            head = NULL;
        }
        free(ptr);
    }
    return head;
}

node* display(node* head) 
{
    node* ptr;
    if (head == NULL) 
    {
        printf("No data\n");
    } 
    else
    {
        ptr = head;
        printf("USN\tNAME\tDEPARTMENT\tPhone No\tMARKS1\tMARKS2\tMARKS3\tTOTEL\tAVERAGE\n");
        while (ptr != NULL) 
        {
            ptr->totel = ptr->marks1 + ptr->marks2 + ptr->marks3;
            ptr->average = ptr->totel / 3;
            printf("%s\t%s\t%s\t%s\t   %.2f\t  %.2f\t  %.2f\t  %.2f\t  %.2f \n", 
                ptr->usn, ptr->name, ptr->dept, ptr->phon, 
                ptr->marks1, ptr->marks2, ptr->marks3, 
                ptr->totel, ptr->average);
            ptr = ptr->next;
        }
    }
    printf("The number of nodes in the list is %d\n", countnodes(head));
    return head;
}

int main()
{
    node* head = NULL;
    int choice;

    do 
    {
        printf("\n\t....... Student Data......\n");
        printf("1. Add Student\n");
        printf("2. Insert Front\n");
        printf("3. Insert Rear\n");
        printf("4. Delete Front\n");
        printf("5. Delete Rear\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                head = create(head);
                break;
            case 2:
                head = insertfront(head);
                break;
            case 3:
                head = insertrear(head);
                break;
            case 4:
                head = deletefront(head);
                break;
            case 5:
                head = deleterear(head);
                break;
            case 6:
                head = display(head);
                break;
            case 7:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } 
    while (choice >= 1 && choice <= 7);

    return 0;
}

