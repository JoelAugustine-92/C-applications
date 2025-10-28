#include<stdio.h>
#include<stdlib.h>
#define size 5

int queue[size],front=-1,rear=-1;

void enqueue(int val){
  if((rear+1)%size == front)
  {
    printf("The queue is full");
    return;
    }
  else if(front == -1 && rear == -1)
    front = rear = 0;
  else{
    rear=(rear+1)%size;
  }
  queue[rear]=val;
}

void dequeue(){
  if(front == -1 && rear == -1){
    printf("The queue is empty");
    return;
    }
  else if(front == rear){
    front = rear = -1;
  }
  else{
    front=(front+1)%size;
  }
}

void isfull()
  {
    if((rear+1)%size == front )
      {
        printf("The queue is full");
        return;
      }
  }
void isempty()
  {
    if(front == -1 )
      {
        printf("The is empty");
        return;
      }
  }
  void display()
    {
       if(front == -1 )
      {
        printf("The is empty");
        return;
      }
      else
      {
        int i = front;
        while(1)
        {
        printf("%d",queue[i]);
        if(i == rear)
          break;
        i= (i+1)%size;
        }
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


