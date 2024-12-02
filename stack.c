#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;  // Pointer to array containing elements of stack
    int top;    // Index of top element
    int capacity;   // Maximum capacity of stack
} Stack;

Stack *init_stack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) {
        perror("Cannot allocate memory for stack");
        exit(EXIT_FAILURE);
    }
    stack->data = (int)malloc(sizeof(int)*capacity);
    if (stack->data == NULL) {
        perror("Cannot allocate memory for data");
        free(stack);
        exit(EXIT_FAILURE);
    }
    stack->capacity = capacity;
    stack->top = -1;    // Begin = -1, because have 1 element -> index = 0, have 2 element -> index = 1
    return stack;
}

bool is_empty(Stack *stack) {
    return stack->top == -1;
}

bool is_full(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int push(Stack *stack, int value) {
    if (is_full(stack)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;  // value default while cannot pop
    }
    return stack->data[stack->top--];
}

int top(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack empty! Cannot get top value\n");
        return;
    }
    return stack->data[stack->top];
}

int size(Stack *stack) {
    return stack->top + 1;
}

void free_stack(Stack *stack) {
    if (stack) {
        free(stack->data);
        free(stack);
    }
}

int main() {
    Stack *stack = init_stack(5);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element: %d\n", top(stack));
    printf("Stack size: %d\n", size(stack));

    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));

    printf("Size after popping: %d\n", size(stack));
    printf("Top element: %d\n", top(stack));

    free_stack(stack);
    return 0;
}