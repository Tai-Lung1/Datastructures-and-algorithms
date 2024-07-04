#include<stdio.h>
#include<stdlib.h>
#define ms 5
typedef struct 
{
	int front,rear;
	float item[5];
}cqueue;
cqueue cq;
void cqinsert(float value)
{
	if(cq.front==(cq.rear+1)%ms)
	{
		printf("Cqeueue is FULL");
	}
	else
	{
		cq.rear=(cq.rear+1)%ms;
		cq.item[cq.rear]=value;
	}
}
float cqdelete()
{
	float val=-1;
	if(cq.front==cq.rear)
	{
		printf("Cqueue is Empty");
	}
	else
	{
		cq.front=(cq.front+1)%ms;
		val=cq.item[cq.front];
		printf("Deleted queue is:%f",val);
		
	}
}
void display()
{
	int i;
	if(cq.front==cq.rear)
	{
		printf("Queue is full");
	}
	else
	{
		for(i=cq.front+1;(i%ms)!=(cq.rear+1)%ms;i++)
		{
			printf("%f\t",cq.item[i%ms]);
		}
	}
}
int main()
{
	cq.front=ms-1;
	cq.rear=ms-1;
	int ch;
	float m;
	while(1)
	{
		printf("1.cqinsert\n2.cqdelete\n3.display\n4.exit\n");
		printf("Enter the choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the value:");
			       scanf("%f",&m);
			       cqinsert(m);
			       break;
			case 2:cqdelete();
			       break;
			case 3:display();
			      break;
			case 4:exit(0);
			default:printf("Invalid");
			
		}
	}
	
}
