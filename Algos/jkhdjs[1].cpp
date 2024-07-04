#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define ms 5
struct student 
{
	char name[20],usn[20];
	float mark1,mark2,mark3,totel,avg;
	struct student*prev;
	struct student*next;
};
typedef struct student node;

int countnode(node*head)
	{
		node*ptr;
		int c=0;
		ptr=head;
		while(ptr != NULL)
		{
			ptr=ptr->next;
			c++;
		}
		return c;
	}
node*getnode(node*head)
{
	node*nn=(node*)malloc(sizeof(node));
	printf("NAME:");
	scanf("%s",nn->name);
	printf("USN");
	scanf("%s",nn->usn);
	printf("Entre your Engneering Three Suject Marks:");
	scanf("%f%f%f",&nn->mark1,&nn->mark2,&nn->mark3);
	nn->next=NULL;
	nn->prev=NULL;
	return nn;
}
	
node*create(node*head)
{
	node*nn,*ptr;
	ptr=head;
	int i,n;
	printf("Enter the no of student you want?");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		if(head==NULL)
		{
			nn=getnode(head);
			head=nn;
		}
		else
		{
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			nn=getnode(head);
			ptr->next=nn;
			nn->prev=ptr;
			
		}
		ptr=head;
	}
	return head;
}
node*insertfrount(node*head)
{
	node*nn;
	if(countnode(head)==ms)
	{
		printf("Student List Is full plase Enter 4 or 5");
	}
	else
	{
		nn=getnode(head);
		if(head==NULL)
		{
			head=nn;
		}
		else
		{
			nn->next=head;
			head->prev=nn;
			head=nn;
		}
	}
	return head;
	
}
node*insertrear(node*head)
{
	node*nn,*ptr;
	if(countnode(head)==ms)
	{
		printf("Student List Is full plase Enter 4 or 5");
	}
	else
	{
	  head=create(head);
	}
	return head;
}
node*deletefrount(node*head)
{
	node*ptr;
	if(head==NULL)
	{
		printf("No student data plase Enter 1 or 2 or 3 :");
	}
	else
	{
		ptr=head;
		head=head->next;
		if(head != NULL)
		{
			head->prev=NULL;
		}
		free(ptr);
	}
	return head;
}
node*deleterear(node*head)
{
	node*ptr;
	if(head==NULL)
	{
		printf("No student data plase Enter 1 or 2 or 3 :");
	}
	else
	{
		while(ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		if(ptr->prev != NULL)
		{
			ptr->prev->next=NULL;
		}
		else
		{
			head=NULL;
		}
		free(ptr);
	}
	return head;
	
}
node*display(node*head)
{
	node*ptr;
	ptr=head;
if(head==NULL)
{
	printf("No student data please any choice : ");
	
}
else
{
	printf("NAME|\t USN|\t MARKS1|\t MARKS2|\t MARKS3|\t TOTEL|\t AVARAGE|\n");
	while(ptr != NULL)
	{
		ptr->totel=ptr->mark1+ptr->mark2+ptr->mark3;
		ptr->avg=ptr->totel/3;
		printf("%s\t  %s \t %2.f \t %2.f \t %2.f \t %2.f \t %2.f\n",ptr->name,ptr->usn,ptr->mark1,ptr->mark2,ptr->mark3,ptr->totel,ptr->avg);
		ptr=ptr->next;
	}
}
return head;
}

int main()
{
	node*head=NULL;
	int ch;
	do{
		printf("\n<<<<<<<<<<<Student details>>>>>>>>>>>>\n");
		printf(" 1.Add Studen?\n");
		printf("2.Insert frount?\n");
		printf("3.Insert rear?\n");
		printf("4.Delete frount?\n");
		printf("5.Delete rear?\n");
		printf("6.disply\n");
		printf("7.exit !!\n");
		printf("Please Enter the choice 1 to 6 :\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:head=create(head);
			      break;
			      
			case 2:head=insertfrount(head);
			      break;
			      
			case 3:head=insertrear(head);
			      break;
			      
			case 4:head=deletefrount(head);
		          break;
		          
		    case 5:head=deleterear(head);
		          break;
		          
		    case 6:head=display(head);
		          break;
		          
		    case 7:exit(0);
	              break;
	        default:
	              	printf("Please choice the 1 to 6 only:THANK YOU");
		}
	}while(ch>=1&& ch<=7);
}

