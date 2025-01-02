#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node of the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue
typedef struct Queue {
    Node *front;    // First element
    Node *rear;     // Last element
    int size;       // Number of elements
} Queue;

// Init function
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void push(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->rear = q->front = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

void pop(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    Node* temp = q->front;
    q->front = q->front->next;

    // Queue have 1 element
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
}

int back(Queue* q) {
    if (q->rear == NULL) {
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    return q->rear->data;
}

bool empty(Queue* q) {
    return q->size == 0;
}

int size(Queue* q) {
    return q->size;
}

void swap(Queue* q1, Queue* q2) {
    Node* tempFront = q1->front;
    Node* tempRear = q1->rear;
    int tempSize = q1->size;

    q1->front = q2->front;
    q1->rear = q2->rear;
    q1->size = q2->size;

    q2->front = tempFront;
    q2->rear = tempRear;
    q2->size = tempSize;
}


void print(Queue* q) {
    Node* currentNode = q->front;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    push(q, 10);
    push(q, 20);
    push(q, 30);
    pop(q);
    print(q);
    printf("Back value: %d\n", back(q));
    return 0;
}