#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

int my_stack[STACK_LENGTH];
int top = EMPTY;

bool push(int value) {
    if(top == STACK_LENGTH - 1) return false;
    my_stack[++top] = value;
    return true;
}

int pop() {
    if(top == EMPTY) return STACK_EMPTY;
    return my_stack[top--];
}

int main() {
    push(1);
    push(2);
    push(3);
     
    int t;
    while((t = pop()) != STACK_EMPTY) {
        printf("%d\n",t);
    }
    return 0;
}