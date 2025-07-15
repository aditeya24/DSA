#include <stdio.h>
#define MAX 10

int a[MAX];
int top1 = -1, top2 = MAX+1;

void push1(int item)
{
	if(top1 == top2 - 1)
	{
		printf("Stack overflow");
	}
	else
	{
		a[++top1]=item;
	}
}

void push2(int item)
{
	if(top2 == top1 + 1)
	{
		printf("Stack overflow");
	}
	else
	{
		a[--top2]=item;
	}
}

void pop1()
{
	if(top1 == -1)
	{
		printf("Stack underflow");
	}
	else
	{
		printf("Removed: %d",a[top1--]);
	}
}

void pop2()
{
	if(top2 == MAX+1)
	{
		printf("Stack underflow");
	}
	else
	{
		printf("Removed: %d", a[top2++]);
	}
}

void display1()
{
	for(int i=0; i<=top1; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void display2()
{
	for(int i=MAX; i>=top2; i--)
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
		printf("\n1: Push1\n2: Push2\n3: Pop1\n4: Pop2\n5: Display1\n6: Display2\n0: Exit\n");
		printf("Enter choice[1,2,3,4,5,6,0]: ");
		scanf("%d",&choice);
		if(choice==0)
			break;
		else if(choice==1)
		{
			printf("Enter value to push: ");
			scanf("%d",&item);
			push1(item);
			display1();
		}
		else if(choice==2)
		{
			printf("Enter value to push: ");
			scanf("%d",&item);
			push2(item);
			display2();
		}
		else if(choice==3)
		{
                        pop1(item);
                        display1();
                }
		else if(choice==4)
		{
                        pop2(item);
                        display2();
                }
		else if(choice==5)
		{
			display1();
		}
		else if(choice==6)
		{
			display2();
		}
		else
		{
			printf("ERROR: Invalid choice");
		}
	}
}
