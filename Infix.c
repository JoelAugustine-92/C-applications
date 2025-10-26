#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 100

char stack[max];
int top = -1;

void push(char c) {
    if (top == max - 1)
        printf("Stack is full\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int main() {
    char infix[max], postfix[max];
    char ch, temp;
    int i = 0, j = 0;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0') {
        if (isalpha(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && (temp = pop()) != '(') {
                postfix[j++] = temp;
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';

    printf("The postfix expression is: %s\n", postfix);
    return 0;
}
