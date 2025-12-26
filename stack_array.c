#include "../include/dsa.h"

typedef struct ArrStack {
    int *arr;
    size_t capacity;
    size_t top; // index of next push
} ArrStack;

ArrStack* arrstack_new(size_t cap) {
    ArrStack* s = malloc(sizeof(ArrStack));
    s->arr = malloc(sizeof(int)*cap);
    s->capacity = cap; s->top = 0; return s;
}

bool arrstack_push(ArrStack* s, int v) {
    if (s->top >= s->capacity) return false;
    s->arr[s->top++] = v; return true;
}

int arrstack_pop(ArrStack* s) {
    if (s->top == 0) return 0;
    return s->arr[--s->top];
}

bool arrstack_is_empty(ArrStack* s) { return s->top == 0; }

void arrstack_free(ArrStack** s) {
    if (!s || !*s) return;
    free((*s)->arr); free(*s); *s = NULL;
}
