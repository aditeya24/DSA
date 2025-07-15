#include <stdio.h>
#define MAX 10

int a[MAX];
int top = -1;

void push(int item)
{
	if(top == MAX-1)
	{
		printf("Stack overflow");
	}
	else
	{
		a[++top]=item;
	}
}

void pop()
{
	int item;
	if(top<0)
	{
		printf("Stack underflow");
	}
	else
	{
		printf("Removed: %d",a[top--]);
	}
}

int peek()
{
	if(top==-1)
	{
		printf("Stack empty");
	}
	return a[top];
}

void display()
{
	for(int i=0; i<=top; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void main()
{
	int choice, item, removed, value;
	while(1)
	{
		printf("\n1: Push\n2: Pop\n3: Peek\n4: Display\n0: Exit\n");
		printf("Enter choice[1,2,3,0]: ");
		scanf("%d",&choice);
		if(choice==0)
			break;
		else if(choice==1)
		{
			printf("Enter value to push: ");
			scanf("%d",&item);
			push(item);
			display();
		}
		else if(choice==2)
                {
                        pop(item);
			display();
                }
		else if(choice==3)
                {
                        value = peek(item);
			printf("%d\n",value);
                }
		else if(choice==4)
		{
			display();
		}
    else
    {
      printf("ERROR: Invalid choice");
    }
	}
}
