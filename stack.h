#ifndef STACK_H
#define STACK_H

#include <stdbool.h> // For boolean data type

// Author: KHANH NGUYEN DUY
// Email: khanhnguyenduy.cv@gmail.com
// Created Date: 02/12/2024
// Description: Stack struct.


/**
 * Stack structure definition
 * - `data`: Pointer to dynamically allocated array for storing elements.
 * - `top`: Index of the top element in the stack.
 * - `capacity`: Maximum number of elements the stack can hold.
 */
typedef struct {
    int *data;      // Pointer to array containing elements of stack
    int top;        // Index of the top element
    int capacity;   // Maximum capacity of the stack
} Stack;

/**
 * Initializes a new stack with a given capacity.
 * @param capacity Maximum number of elements the stack can hold.
 * @return Pointer to the newly created stack.
 */
Stack *init_stack(int capacity);

/**
 * Checks if the stack is empty.
 * @param stack Pointer to the stack.
 * @return `true` if the stack is empty, otherwise `false`.
 */
bool is_empty(Stack *stack);

/**
 * Checks if the stack is full.
 * @param stack Pointer to the stack.
 * @return `true` if the stack is full, otherwise `false`.
 */
bool is_full(Stack *stack);

/**
 * Pushes a new value onto the stack.
 * @param stack Pointer to the stack.
 * @param value The value to push.
 * @return `0` on success, or `-1` if the stack is full.
 */
int push(Stack *stack, int value);

/**
 * Pops the top value from the stack.
 * @param stack Pointer to the stack.
 * @return The popped value, or `-1` if the stack is empty.
 */
int pop(Stack *stack);

/**
 * Gets the value of the top element without removing it.
 * @param stack Pointer to the stack.
 * @return The value of the top element, or `-1` if the stack is empty.
 */
int top(Stack *stack);

/**
 * Gets the current size of the stack.
 * @param stack Pointer to the stack.
 * @return Number of elements in the stack.
 */
int size(Stack *stack);

/**
 * Frees the memory allocated for the stack.
 * @param stack Pointer to the stack.
 */
void free_stack(Stack *stack);

#endif // STACK_H
