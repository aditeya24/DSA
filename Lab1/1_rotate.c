//Write a funcion to rotate a given array's elements
#include <stdio.h>
void rotate(int a[], int n, char d, int cr)
{
	int i, j, temp;
	cr=cr%n;
	for(i=0; i<cr; i++)
	{
		if(d=='L')
		{
			temp=a[0];
			for(j=1;j<n;j++)
			{
				a[j-1]=a[j];
			}
			a[n-1]=temp;
		}
		else if(d=='R')
		{
			temp=a[n-1];
			for(j=n-1;j>0;j--)
			{
			a[j]=a[j-1];
			}
			a[0]=temp;
		}
	}
}
void main()
{
	int n, cr, i;
	char d;
	printf("Enter n: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter direction of rotation[L,R]: ");
	scanf(" %c",&d);
	printf("Enter count of rotation: ");
	scanf("%d",&cr);
	
	rotate(a,n,d,cr);
	
	for(i=0; i<n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
