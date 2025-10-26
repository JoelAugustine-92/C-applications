#include<stdio.h>
struct poly{
  float coeff;
  int exp;
}a[10],b[10],sum[10];

int main()
{
  int d1,d2,i=0;
  float c1,c2;
  int maxdegree;
  printf("The degree of the first polynomial is: \n");
  scanf("%d",&d1);
  printf("The polynomial expression is : \n");
  for(i=0;i<=d1;i++)
  {
    printf("the coefficient is x^%d: ",i);
    scanf("%f",&a[i].coeff);
    a[i].exp=i;
  }
  printf("The degree of the second polynomial is: \n");
  scanf("%d",&d2);
  printf("The polynomial expression is : \n");
  for(i=0;i<=d2;i++)
  {
    printf("the coefficient is x^%d: ",i);
    scanf("%f",&b[i].coeff);
    b[i].exp=i;
  }
  
  maxdegree=(d1>d2)?d1:d2;
  for(i=0;i<=maxdegree;i++)
  {
  c1=(i<=d1)?a[i].coeff:0;
  c2=(i<=d2)?b[i].coeff:0;
  sum[i].coeff=c1+c2;
  sum[i].exp=i;
  }
  printf("the polynomial is : ");
  for(i=maxdegree;i>=0;i--)
  {
    printf("%fx^%d",sum[i].coeff,sum[i].exp);
    if(i != 0)
      printf("+");
    }
  printf("\n");
  return 0;
  
}



