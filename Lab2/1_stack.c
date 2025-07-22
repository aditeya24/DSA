#include <stdio.h>
#define MAX 10

int a[MAX];
int top = -1;

int full()
{
  if(top == MAX-1)
    return 1;
  return 0;
}

int empty()
{
  if(top==0)
    return 1;
  return 0;
}

void display()
{
	for(int i=0; i<=top; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void push(int item)
{
	if(full())
	{
		printf("Stack overflow\n");
	}
	else
	{
		a[++top]=item;
		display();
	}
}

void pop()
{
	int item;
	if(empty())
	{
		printf("Stack underflow\n");
	}
	else
	{
		printf("Removed: %d\n",a[top--]);
		display();
	}
}

void peek()
{
	if(empty())
	{
		printf("Stack empty\n");
	}
	else
	{
		printf("%d\n", a[top]);
	}
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
		}
		else if(choice==2)
                {
                        pop(item);
                }
		else if(choice==3)
                {
                        peek(item);
                }
		else if(choice==4)
		{
			display();
		}
    else
    {
      printf("ERROR: Invalid choice\n");
    }
	}
}
