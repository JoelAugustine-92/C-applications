#include <stdio.h>
#include <stdlib.h>

#define size 5

int deque[size];
int front = -1, rear = -1;

// Insert at rear end
void insertRear(int val) {
    if ((rear + 1) % size == front) {
        printf("Deque is full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    deque[rear] = val;
    printf("%d inserted at rear\n", val);
}

// Insert at front end
void insertFront(int val) {
    if ((rear + 1) % size == front) {
        printf("Deque is full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = size - 1;  // wrap to end
    } else {
        front--;
    }
    deque[front] = val;
    printf("%d inserted at front\n", val);
}

// Delete from front end
void deleteFront() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from front: %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

// Delete from rear end
void deleteRear() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from rear: %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = size - 1;
    } else {
        rear--;
    }
}

// Check full
void isFull() {
    if ((rear + 1) % size == front)
        printf("Deque is full\n");
    else
        printf("Deque is not full\n");
}

// Check empty
void isEmpty() {
    if (front == -1)
        printf("Deque is empty\n");
    else
        printf("Deque is not empty\n");
}

// Display contents
void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int val, choice;
    while (1) {
        printf("\n************ CIRCULAR DEQUE **************\n");
        printf("1) Insert Front\n");
        printf("2) Insert Rear\n");
        printf("3) Delete Front\n");
        printf("4) Delete Rear\n");
        printf("5) Is_Full\n");
        printf("6) Is_Empty\n");
        printf("7) Display\n");
        printf("8) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                isFull();
                break;
            case 6:
                isEmpty();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
