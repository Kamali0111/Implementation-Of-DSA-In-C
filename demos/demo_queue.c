#include "../include/dsa.h"

extern CircQueue* cq_new(size_t cap);
extern bool cq_enqueue(CircQueue* q, int v);
extern bool cq_dequeue(CircQueue* q, int *out);
extern void cq_free(CircQueue** q);

int main(void) {
    CircQueue* q = cq_new(4);
    cq_enqueue(q, 1); cq_enqueue(q, 2); cq_enqueue(q, 3);
    int v;
    while (cq_dequeue(q, &v)) printf("deq: %d\n", v);
    cq_free(&q);
    return 0;
}
