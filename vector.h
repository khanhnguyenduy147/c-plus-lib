#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Author: KHANH NGUYEN DUY
// Email: khanhnguyenduy.cv@gmail.com
// Created Date: 30/11/2024
// Description: Library supporting dynamic linked lists with generic data types.

// Check if SIZE_MAX is already defined, if not define it based on the architecture.
#ifndef SIZE_MAX
    #if defined(__x86_64__) || defined(_M_X64) || defined(__aarch64__) // 64-bit architecture
        #define SIZE_MAX 18446744073709551615ULL // 2^64 - 1
    #else // 32-bit architecture
        #define SIZE_MAX 4294967295U // 2^32 - 1
    #endif
#endif

/**
 * @struct Vector
 * @brief A simple dynamic array implementation.
 * 
 * This structure represents a vector (dynamic array) that holds integers.
 * It maintains the size of the vector and its capacity.
 */
typedef struct {
    int *data;      /**< Pointer to the data (array) */
    int size;       /**< Current number of elements in the vector */
    int capacity;   /**< Current capacity of the vector */
} Vector;

/**
 * @brief Initializes a vector with a given capacity.
 * 
 * This function allocates memory for the vector and sets the initial size to 0.
 * 
 * @param v A pointer to the vector.
 * @param capacity The initial capacity of the vector.
 */
void init_vector(Vector *v, int capacity);

/**
 * @brief Adds an element to the end of the vector.
 * 
 * This function appends a new element to the vector, resizing it if necessary.
 * 
 * @param v A pointer to the vector.
 * @param value The value to be added to the vector.
 */
void push_back(Vector *v, int value);

/**
 * @brief Removes the last element of the vector.
 * 
 * This function decreases the size of the vector by one.
 * If the vector is empty, it prints an error message.
 * 
 * @param v A pointer to the vector.
 */
void pop_back(Vector *v);

/**
 * @brief Returns a pointer to the first element in the vector.
 * 
 * This function provides access to the first element of the vector.
 * 
 * @param v A pointer to the vector.
 * @return A pointer to the first element in the vector.
 */
int* begin(Vector *v);

/**
 * @brief Returns a pointer to the last element in the vector.
 * 
 * This function provides access to the last element of the vector.
 * If the vector is empty, it returns NULL.
 * 
 * @param v A pointer to the vector.
 * @return A pointer to the last element in the vector, or NULL if empty.
 */
int* back(Vector *v);

/**
 * @brief Assigns a value to all elements in the vector.
 * 
 * This function sets all elements in the vector to the specified value.
 * It also adjusts the size of the vector to match the given count.
 * 
 * @param v A pointer to the vector.
 * @param value The value to assign to all elements.
 * @param count The number of elements to assign.
 */
void assign(Vector *v, int value, int count);

/**
 * @brief Reserves memory for the vector to fit a new capacity.
 * 
 * This function increases the capacity of the vector to the specified size.
 * If the new capacity is larger than the current capacity, memory is reallocated.
 * 
 * @param v A pointer to the vector.
 * @param new_capacity The new capacity for the vector.
 */
void reserve(Vector *v, int new_capacity);

/**
 * @brief Resizes the vector to a new size.
 * 
 * This function adjusts the size of the vector, allocating or freeing memory as needed.
 * If the new size is larger than the current size, the extra elements are set to 0.
 * 
 * @param v A pointer to the vector.
 * @param new_size The new size for the vector.
 */
void resize(Vector *v, int new_size);

/**
 * @brief Returns the current size of the vector.
 * 
 * This function returns the number of elements currently stored in the vector.
 * 
 * @param v A pointer to the vector.
 * @return The current size of the vector.
 */
int size(Vector *v);

/**
 * @brief Returns the maximum possible size of the vector.
 * 
 * This function returns the maximum size the vector can hold based on the system's architecture.
 * 
 * @return The maximum size of the vector.
 */
size_t max_size();

/**
 * @brief Frees the memory allocated for the vector.
 * 
 * This function releases all memory associated with the vector, including the data array.
 * 
 * @param v A pointer to the vector.
 */
void free_vector(Vector *v);

/**
 * @brief Moves data from source array to destination array.
 * 
 * This function copies data from one array to another.
 * 
 * @param source A pointer to the source array.
 * @param destination A pointer to the destination array.
 * @param size The number of elements to copy.
 */
void move_data(int *source, int *destination, int size);

#endif // VECTOR_H
