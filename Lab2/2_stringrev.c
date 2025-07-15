#include <stdio.h>
#define MAX 32

char a[MAX];
int top=-1;

void push(char item)
{
	if(top != MAX-1)
	{
		a[++top]=item;
	}
}

char pop()
{
	char item;
	if(top>=0)
	{
		item=a[top--];
		return item;
	}
}

void reverse(char s[], int n)
{
	for(int i=0; i<n; i++)
	{
		push(s[i]);
	}
	for(int i=0; i<n; i++)
	{
		s[i] = pop();
	}
}

void main()
{
	int len=0, i=0;
	char s[MAX+1];
	printf("Enter string: ");
	scanf("%s", s);
	while(s[i]!='\0')
	{
		len++;
		i++;
	}
	reverse(s, len);
	printf("%s\n", s);
}
