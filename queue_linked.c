#include "../include/dsa.h"

typedef struct QNode {
    int val; struct QNode* next;
} QNode;

typedef struct LQueue {
    QNode* head; QNode* tail; size_t size;
} LQueue;

LQueue* lq_new() {
    LQueue* q = malloc(sizeof(LQueue)); q->head = q->tail = NULL; q->size = 0; return q;
}

void lq_enqueue(LQueue* q, int v) {
    QNode* n = malloc(sizeof(QNode)); n->val = v; n->next = NULL;
    if (q->tail) q->tail->next = n; else q->head = n;
    q->tail = n; q->size++;
}

bool lq_dequeue(LQueue* q, int *out) {
    if (!q->head) return false;
    QNode* n = q->head; *out = n->val;
    q->head = n->next; if (q->head == NULL) q->tail = NULL;
    free(n); q->size--;
    return true;
}

void lq_free(LQueue** q) {
    if (!q || !*q) return;
    QNode* cur = (*q)->head;
    while (cur) { QNode* t = cur; cur = cur->next; free(t); }
    free(*q); *q = NULL;
}
