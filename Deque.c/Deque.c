#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 5

int deque[size],front=-1,rear=-1;

void insertfont(int val)
{
  if((rear+1)%size == front)
    printf("The queue is full");
  else if(front == -1)
    front = rear = -1;
  else
    rear=(rear+1)%size;
  deque[rear]=val;
}

void insertend(int val)
{
  if((rear+1)%size == front)
    printf("The queue is full");
  else if(front == -1)
    front = rear = -1;
  else if(front == 0)
    front = size -1;
  else
    front--;
  deque[front]=val;
}

void deletefront(){
  if(front == -1 && rear == -1)
    printf("The queue is empty");
  else if(front == rear)
    front=(front+1)%size; 
}
void deleteend(){
  if(front == -1 && rear == -1)
    printf("The queue is empty");
  else if(front== rear)
    front = rear = -1;
  else if(rear == 0)
    rear= size -1;
  else
    rear--;
}
void isfull(){
  if((rear+1)%size == -1)
    printf("The queue is full");
  else
    printf("The queue is not empty");
}
void isempty(){
  if(front == -1 && rear == -1)
    printf("The queue is empty");
  else
  {
    printf("The queue has space");
  }
}
void display()
{
  if(front == -1 && rear == -1)
    printf("The queue is empty");
  else
    {
      printf("The queue is: \n");
      int i;
      i=front;
      while(1){
        printf("%d",deque[i]);
        if(i == rear)
          break;
        i=(i+1)%size;
      }
    }
}
int main(){
  int val,choice;
  while(1){
    printf("***********doubly linked list ************************\n");
    printf("1)Insert at front\n");
    printf("2)Insert at end\n");
    printf("3)Delete from front\n");
    printf("4)Delete from end\n");
    printf("5)Is full\n");
    printf("6)Is empty\n");
    printf("7)display\n");
    printf("8)exit");
    printf("\n Enter ur choice");
    scanf("%d",&choice);
    switch(choice){
      case 1:
            printf("Enter the element: \t");
            scanf("%d",&val);
            insertfont(val);
            break;
      case 2:
            printf("Enter the element: \t");
            scanf("%d",&val);
            insertend(val);
             break;
      case 3:
            deletefront();
             break;
      case 4:
            deleteend();
             break;
      case 5:
            isfull();
             break;
      case 6:
            isempty();
             break;
      case 7:
            display();
             break;
      case 8:
            printf("Exiting...");
            exit(0);
            return 0;
             break;
      default:
            printf("Invalid choice!");
             break;
    }
  }
  return 0;
}

