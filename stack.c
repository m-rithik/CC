#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Stack {
    int* data;
    int* minStack;
    int* maxStack;
    int top;
    int capacity;
} Stack;
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->minStack = (int*)malloc(capacity * sizeof(int));
    stack->maxStack = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int x) {
    if (stack->top >= stack->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = x;

    // Update min stack
    if (stack->top == 0 || x <= stack->minStack[stack->top - 1])
        stack->minStack[stack->top] = x;
    else
        stack->minStack[stack->top] = stack->minStack[stack->top - 1];

    // Update max stack
    if (stack->top == 0 || x >= stack->maxStack[stack->top - 1])
        stack->maxStack[stack->top] = x;
    else
        stack->maxStack[stack->top] = stack->maxStack[stack->top - 1];
}

void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return;
    }
    stack->top--;
}

int top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->data[stack->top];
}

int getMin(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->minStack[stack->top];
}int getMax(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->maxStack[stack->top];
}
void freeStack(Stack* stack) {
    free(stack->data);
    free(stack->minStack);
    free(stack->maxStack);
    free(stack);
}

int main() {
    Stack* stack = createStack(100);

    push(stack, 10);
    push(stack, 5);
    push(stack, 20);
    push(stack, 3);
    printf("Top: %d\n", top(stack));       
    printf("Min: %d\n", getMin(stack));     
    printf("Max: %d\n", getMax(stack));     
    pop(stack);
    printf("\nAfter popping:\n");
    printf("Top: %d\n", top(stack));        
    printf("Min: %d\n", getMin(stack));     
    printf("Max: %d\n", getMax(stack));     

    freeStack(stack);
    return 0;
}
