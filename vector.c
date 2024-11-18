#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Định nghĩa tạm thời cho SIZE_MAX nếu chưa có
#ifndef SIZE_MAX
    #if defined(__x86_64__) || defined(_M_X64) || defined(__aarch64__) // Kiến trúc 64-bit
        #define SIZE_MAX 18446744073709551615ULL // 2^64 - 1
    #else // Kiến trúc 32-bit
        #define SIZE_MAX 4294967295U // 2^32 - 1
    #endif
#endif
/**
 * Struct: Vector
 * ----------------------------
 * data: Pointer to data.
 * size: Current element number.
 * capacity: Current capacity.
 */
typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void move_data(int *source, int *destination, int size);

void init_vector(Vector *v, int capacity) {
    v->data = (int *)malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void push_back(Vector *v, int value) {
    if (v->size == v->capacity) {
        // Double the capacity if full
        v->capacity *= 2;
        int *new_data = (int *)malloc(v->capacity * sizeof(int));
        move_data(v->data, new_data, v->size);
        free(v->data);
        v->data = new_data;
    }
    v->data[v->size++] = value;
}

void pop_back(Vector *v) {
    if (v->size > 0) {
        v->size --;
    } else {
        printf("Error: Vector empty.\n");
    }
}

int* begin(Vector *v) {
    return v->data;
}

int* back(Vector *v) {
    if (v->size == 0) {
        return NULL;
    }
    return &v->data[v->size - 1]; // (return v->data + v->size);
}

void assign(Vector *v, int value, int count) {
    if (v->capacity < count) {
        v->data = (int *)realloc(v->data, count * sizeof(int));
        v->capacity = count;
    }
    for (int i = 0; i < count; i++) {
        v->data[i] = value;
    }
    v->size = count;
}

void reserve(Vector *v, int new_capacity) {
    if (new_capacity > v->capacity) {
        int *new_data = (int *)malloc(new_capacity * sizeof(int));
        for (int i = 0; i < v->size; i++) {
            new_data[i] = v->data[i];
        }
        free(v->data);
        v->data = new_data;
        v->capacity = new_capacity;
    }
}

void resize(Vector *v, int new_size) {
    if (new_size > v->capacity) {
        reserve(v, new_size);
    }
    if(new_size > v->size) {
        v->data = (int *)realloc(v->data, new_size * sizeof(int));
        for(int i = v->size - 1; i < new_size - 1; ++i) {
            v->data[i] = 0;
        }
    }
    v->size = new_size;
}

int size(Vector *v) {
    return v->size;
}

size_t max_size() {
    return SIZE_MAX / sizeof(int);
}

void free_vector(Vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void move_data(int *source, int *destination, int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

int main() {
    Vector v;
    init_vector(&v, 6);
    push_back(&v, 10);
    push_back(&v, 20);
    push_back(&v, 30);
    push_back(&v, 40);

    printf("Size: %zu", max_size());
    
    free_vector(&v);

    return 0;
}
