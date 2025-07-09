#include <stdio.h>
void main()
{
  int S1[]={1,2,3,4}, S2[]={3,4,5};
  int intersection[10];
  int index=0;
  for(int i=0; i<4; i++)
  {
    for(int j=0; j<3; j++)
    {
      if(S1[i]==S2[j])
      {
        intersection[index]=S1[i];
        index++;
      }
    }
  }
  for(int i=0; i<index; i++)
  {
    printf("%d ",intersection[i]);
  }
  printf("\n");
}
