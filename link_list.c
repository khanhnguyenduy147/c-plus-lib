#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    size_t size;
} List;

Node *get_end_node(List *list) {
    if (list->head == NULL) return NULL;
    Node *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current;
}

List *init_empty_list() {
    List *list = (List *)malloc(sizeof(List));
    if (list == NULL) {
        perror("Cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

List *init_value_list(size_t n, void *val, size_t data_size) {
    List *list = init_empty_list();
    for (int i = 0; i < n; ++i) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL) {
            perror("Cannot allocate memory\n");
            exit(EXIT_FAILURE);
        }
        new_node->data = malloc(data_size);
        if (new_node->data == NULL) {
            perror("Cannot allocate memory\n");
            exit(EXIT_FAILURE);
        }
        memcpy(new_node->data, val, data_size);
        new_node->next = list->head;
        list->head = new_node;
        list->size++;
    }
    return list;
}

void *assign_from_range(List *list, void *array, size_t n, size_t data_size) {
    for (int i = 0; i < n; ++i) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL) {
            perror("Cannot allocate memory\n");
            exit(EXIT_FAILURE);
        }
        new_node->data = malloc(data_size);
        if(new_node->data == NULL) {
            perror("Cannot allocate memory\n");
            exit(EXIT_FAILURE);
        }
        memcpy(new_node->data, (char *)array + i*data_size, data_size);
        new_node->next = list->head;
        list->head = new_node;
        list->size++;
    }
}

void *front(List *list) {
    if (list->head == NULL) {
        printf("Link List Empty.\n");
        return NULL;
    }
    return list->head->data;
}

void *back(List *list) {
    if (list->head == NULL) {
        printf("Link List Empty.\n");
        return NULL;
    }
    Node *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    return current->data;
}

void push_front(List *list, void* val, size_t data_size) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("Cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = malloc(data_size);
    if (new_node->data == NULL) {
        perror("Cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }
    memcpy(new_node->data, val, data_size);
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void push_back(List *list, void* val, size_t data_size) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("Cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = malloc(data_size);
    if(new_node->data == NULL) {
        perror("Cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }
    new_node->next = NULL;
    memcpy(new_node->data, val, data_size);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *last_node = get_end_node(list);
        last_node->next = new_node;
    }
    list->size++;
}

void sort(List *list) {
    if (list->head == NULL || list->head->next == NULL) return;

    for (Node *i = list->head; i != NULL; i = i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (*(int *)i->data > *(int *)j->data) {
                int temp = *(int *)i->data;
                *(int *)i->data = *(int *)j->data;
                *(int *)j->data = temp;
            }
        }
    }
}

void reverse(List *list) {
    if (list->head == NULL || list->head->next == NULL) return;

    Node *prev = NULL, *current = list->head, *next = NULL;
    while (current != NULL) {
        next = current->next; // Lưu con trỏ tiếp theo
        current->next = prev; // Đảo ngược con trỏ
        prev = current;       // Dịch con trỏ `prev` lên một bước
        current = next;       // Dịch con trỏ `current` lên một bước
    }
    list->head = prev;
}

void insert(List *list, void *val, size_t data_size, size_t pos) {
    if (pos > list->size) {
        printf("Position out of range\n");
        return;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("Cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = malloc(data_size);
    if (new_node->data == NULL) {
        perror("Cannot allocate memory\n");
        exit(EXIT_FAILURE);
    }
    memcpy(new_node->data, val, data_size);

    if (pos == 0) { // Insert at the beginning
        new_node->next = list->head;
        list->head = new_node;
    } else {
        Node * current = list->head;
        for (size_t i = 0; i < pos - 1; ++i) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    list->size++;
}

size_t size_list(List *list) {
    return list->size;
}

int is_empty(List *list) {
    return list->size == 0;
}

void erase(List *list, size_t index) {
    if (list == NULL || index >= list->size || list->head == NULL) {
        printf("Invalid index or empty list.\n");
        return;
    }

    Node *current = list->head;
    Node *prev = NULL;

    if (index == 0) {
        list->head = current->next;
        free(current->data);
        free(current);
    } else {
        for (size_t i = 0; i < index; ++i) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        free(current->data);
        free(current);
    }
    list->size--;
}

void clear(List *list) {
    if (list == NULL) return;

    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    list->head = NULL;
    list->size = 0;
}

void free_list(List *list) {
    if (list == NULL) return;

    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    list->head = NULL;
    list->size = 0;
    free(list);
}

int main() {
    // Test assign
    int size = 12;
    int a[12];
    List *list = init_empty_list();
    for (int i = 0; i < 12; i++) {
        a[i] = i;
    }
    assign_from_range(list, a, size, sizeof(int));
    Node *current = list->head;
    while (current != NULL) {
        printf("Value: %d\n", *(int *)current->data);
        current = current->next;
    }
    // Test front and back
    int *front_val = front(list);
    int *back_val = back(list);
    printf("Front: %d\n", *front_val);
    printf("Back: %d\n", *back_val);
    // Test push_back and push_front
    int val_back = -1;
    push_back(list, &val_back, sizeof(int));
    int val_front = 12;
    push_front(list, &val_front, sizeof(int));

    current = list->head;
    while (current != NULL) {
        printf("Value: %d\n", *(int *)current->data);
        current = current->next;
    }

    front_val = front(list);
    back_val = back(list);
    printf("Front: %d\n", *front_val);
    printf("Back: %d\n", *back_val);

    // Test size
    printf("Size: %u\n", size_list(list));

    free_list(list);
    return 0;
}
