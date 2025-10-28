#include<stdio.h>
int main(){
  int a[10][10],b[10][10],s[10][10],i,j,k=0,m,n;
  printf("Enter the (row,column): \n");
  scanf("%d%d",&m,&n);
  printf("Enter the elements of matrix 1: \n");
  for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
        {
          scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the elements of matrix 2: \n");
  for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
        {
          scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
      {
        s[i][j]=a[i][j]+b[i][j];
        if(s[i][j] !=0)
          k=k+1;
      }
    }
  printf("Sum of sparse matrix is: %d\t%d\t%d\n",m,n,k);
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    if(s[i][j] !=0)
    {
      printf("%d\t%d\t%d\n",i,j,s[i][j]);
    }
  }
  return 0;
}
