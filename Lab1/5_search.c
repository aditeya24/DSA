#include <stdio.h>
int linearsearch(int a[], int n, int sk)
{
  for(int i=0; i<n; i++)
  {
    if(a[i]==sk)
    {
      return i;
      break;
    }
  }
  return -1;
}

void main()
{
  int n, sk;
  printf("Enter n: ");
  scanf("%d",&n);
  int a[n];
  printf("Enter elements:\n");
  for(int i=0; i<n; i++)
  {
    scanf("%d",&a[i]);
  }
  printf("Enter search key: ");
  scanf("%d", &sk);
  int index = linearsearch(a, n, sk);
  if(index!=-1)
    printf("Search key found at index %d\n", index);
  else
    printf("Search key not found\n");
}
