//Write a program to sort a list of numbers in descending order using bubble, selection and insertion sort.
#include <stdio.h>
void bubblesort(int a[], int n)
{
  int temp;
  for(int i=0; i<n-1; i++)
  {
    for(int j=0; j<n-i-1; j++)
    {
      if(a[j]<a[j+1])
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
}

void selectionsort(int a[], int n)
{
  int temp, index=0;
  for(int i=0; i<n; i++)
  {
    index=i;
    for(int j=i; j<n; j++)
    {
      if(a[j]>a[index])
      {
        index=j;
      }
    }
    temp=a[i];
    a[i]=a[index];
    a[index]=temp;
  }
}

void insertionsort(int a[], int n)
{
  int key, j;
  for(int i=1; i<n; i++)
  {
    key=a[i];
    j=i-1;
    while(j>=0 && a[j]<key)
    {
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=key;
  }
}

void main()
{
  int n, ch, flag=0;
  printf("Enter n: ");
  scanf("%d",&n);
  int a[n];
  printf("Enter elements:\n");
  for(int i=0; i<n; i++)
  {
    scanf("%d",&a[i]);
  }
  printf("1: Bubble Sort\n2: Selection Sort\n3: Insertion Sort\nEnter sorting choice[1,2,3]: ");
  scanf("%d",&ch);
  if(ch==1)
    bubblesort(a, n);
  else if(ch==2)
    selectionsort(a, n);
  else if(ch==3)
    insertionsort(a, n);
  else
  {
    printf("ERROR: Invalid Choice");
    flag=1;
  }

  if(flag==0)
  {
    for(int i=0; i<n; i++)
    {
      printf("%d ",a[i]);
    }
  }
  printf("\n");
}
