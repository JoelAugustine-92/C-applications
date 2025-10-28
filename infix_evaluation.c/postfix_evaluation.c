#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define max 100

int main(){
  char p[max];
  int  s[max];
  int  t=-1;
  int  i,o1,o2,r;
  printf("The infix expression is: \n");
  scanf("%s",p);
  for(i=0;i<strlen(p);i++)
  {
    if(isdigit(p[i]))
      {
      t++;
      s[t]=p[i]-'0';
      }
    else
      {
      o2=s[t];
      t--;
      o1=s[t];
      t--;
      switch(p[i]){
        case '+':
              r=o1+o2;
              break;
        case '-':
              r=o1-o2;
              break;
        case '*':
              r=o1*o2;
              break;
        case '/':
              r=o1/o2;
              break;
      }
      t++;
      s[t]=r;
    }
  }
  printf("The postfix is : %d ",s[t]);
  return 0;
}
