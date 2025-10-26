#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define size 5

int queue[size],front =-1,rear=-1;

void enqueue(int val){
  if(rear == size -1 )
    printf("Queue is full");
  else
    {
      if(front == -1){
        front=0;
      }
      rear++;
      queue[rear]=val;
    }
}

void dequeue(){
  if(front == -1 || front>rear)
    printf("The queue is empty");
  else
    {
      printf("The dequeue element is: %d",queue[front]);
      front++;
    }
}
void isempty(){
  if(front == -1 || front>rear)
    printf("The queue is empty");
}
void isfull(){
  if(rear == size -1)
    printf("The queue is full");
}
void display(){
  if(front == -1 || front>rear)
    printf("The queue is empty");
  else
    {
      printf("The elements are : ");
      for(int i=front;i<=rear;i++)
        printf("%d\n",queue[i]);
    }
}

int main(){

  int val,choice;
  while(1){
    printf("************Linear queue**************\n");
    printf("1)Enqueue\n");
    printf("2)Dequeue\n");
    printf("3)Is_full\n");
    printf("4)Is_empty\n");
    printf("5)Display\n");
    printf("6)Exit\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        printf("The enqueue element is : ");
        scanf("%d",&val);
        enqueue(val);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        isfull();
        break;
      case 4:
        isempty();
        break;
      case 5:
        display();
        break;
      case 6:
        printf("Exiting....");
        exit(0);
        return 0;
        break;
    }
  }
  return 0;
}


