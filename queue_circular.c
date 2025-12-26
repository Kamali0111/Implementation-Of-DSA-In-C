#include "../include/dsa.h"

typedef struct CircQueue {
    int *buf;
    size_t capacity; // actual buffer size
    size_t head; // index to read
    size_t tail; // index to write
    size_t count;
} CircQueue;

CircQueue* cq_new(size_t cap) {
    CircQueue* q = malloc(sizeof(CircQueue));
    q->buf = malloc(sizeof(int)*cap);
    q->capacity = cap; q->head = q->tail = q->count = 0; return q;
}

bool cq_enqueue(CircQueue* q, int v) {
    if (q->count == q->capacity) return false;
    q->buf[q->tail] = v;
    q->tail = (q->tail + 1) % q->capacity;
    q->count++;
    return true;
}

bool cq_dequeue(CircQueue* q, int *out) {
    if (q->count == 0) return false;
    *out = q->buf[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->count--;
    return true;
}

void cq_free(CircQueue** q) {
    if (!q || !*q) return;
    free((*q)->buf); free(*q); *q = NULL;
}
