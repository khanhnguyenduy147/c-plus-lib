#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Author: KHANH NGUYEN DUY
// Email: khanhnguyenduy.cv@gmail.com
// Created Date: 30/11/2024
// Description: Library supporting dynamic linked lists with generic data types.

// Node structure for linked list
typedef struct Node {
    void *data;             // Pointer to the data
    struct Node *next;      // Pointer to the next node
} Node;

// List structure
typedef struct List {
    Node *head;             // Pointer to the first node in the list
    size_t size;            // Number of elements in the list
} List;

// Function prototypes

/**
 * @brief Get the last node of the list.
 * 
 * @param list Pointer to the list.
 * @return Pointer to the last node, or NULL if the list is empty.
 */
Node *get_end_node(List *list);

/**
 * @brief Initialize an empty list.
 * 
 * @return Pointer to the initialized list.
 */
List *init_empty_list();

/**
 * @brief Initialize a list with n elements, all set to a specific value.
 * 
 * @param n Number of elements to initialize.
 * @param val Pointer to the value to set for each element.
 * @param data_size Size of the data type.
 * @return Pointer to the initialized list.
 */
List *init_value_list(size_t n, void *val, size_t data_size);

/**
 * @brief Assign values from an array to the list.
 * 
 * @param list Pointer to the list.
 * @param array Pointer to the array.
 * @param n Number of elements in the array.
 * @param data_size Size of the data type.
 */
void assign_from_range(List *list, void *array, size_t n, size_t data_size);

/**
 * @brief Get the data at the front of the list.
 * 
 * @param list Pointer to the list.
 * @return Pointer to the data at the front, or NULL if the list is empty.
 */
void *front(List *list);

/**
 * @brief Get the data at the back of the list.
 * 
 * @param list Pointer to the list.
 * @return Pointer to the data at the back, or NULL if the list is empty.
 */
void *back(List *list);

/**
 * @brief Add an element to the front of the list.
 * 
 * @param list Pointer to the list.
 * @param val Pointer to the value to add.
 * @param data_size Size of the data type.
 */
void push_front(List *list, void* val, size_t data_size);

/**
 * @brief Add an element to the back of the list.
 * 
 * @param list Pointer to the list.
 * @param val Pointer to the value to add.
 * @param data_size Size of the data type.
 */
void push_back(List *list, void* val, size_t data_size);

/**
 * @brief Sort the list in ascending order (integer data only).
 * 
 * @param list Pointer to the list.
 */
void sort(List *list);

/**
 * @brief Reverse the order of elements in the list.
 * 
 * @param list Pointer to the list.
 */
void reverse(List *list);

/**
 * @brief Insert an element at a specific position in the list.
 * 
 * @param list Pointer to the list.
 * @param val Pointer to the value to insert.
 * @param data_size Size of the data type.
 * @param pos Position to insert the element (0-based index).
 */
void insert(List *list, void *val, size_t data_size, size_t pos);

/**
 * @brief Get the size of the list.
 * 
 * @param list Pointer to the list.
 * @return Number of elements in the list.
 */
size_t size_list(List *list);

/**
 * @brief Check if the list is empty.
 * 
 * @param list Pointer to the list.
 * @return 1 if the list is empty, 0 otherwise.
 */
int is_empty(List *list);

/**
 * @brief Erase an element at a specific position in the list.
 * 
 * @param list Pointer to the list.
 * @param index Position of the element to erase (0-based index).
 */
void erase(List *list, size_t index);

/**
 * @brief Clear all elements from the list.
 * 
 * @param list Pointer to the list.
 */
void clear(List *list);

/**
 * @brief Free the memory used by the list.
 * 
 * @param list Pointer to the list.
 */
void free_list(List *list);

#endif // LIST_H
