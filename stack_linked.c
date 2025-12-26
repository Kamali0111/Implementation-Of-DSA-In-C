#include "../include/dsa.h"

typedef struct LNode {
    int val;
    struct LNode* next;
} LNode;

typedef struct Stack {
    LNode* top;
    size_t size;
} Stack;

Stack* stack_new() {
    Stack* s = malloc(sizeof(Stack));
    if (!s) return NULL;
    s->top = NULL; s->size = 0;
    return s;
}

void stack_push(Stack* s, int v) {
    LNode* n = malloc(sizeof(LNode));
    n->val = v; n->next = s->top; s->top = n; s->size++;
}

bool stack_is_empty(Stack* s) { return s->size == 0; }

int stack_pop(Stack* s) {
    if (!s || s->top == NULL) return 0; // caller should check
    LNode* t = s->top; int v = t->val;
    s->top = t->next; free(t); s->size--;
    return v;
}

int stack_peek(Stack* s) {
    if (!s || s->top == NULL) return 0;
    return s->top->val;
}

void stack_free(Stack** s) {
    if (!s || !*s) return;
    LNode* cur = (*s)->top;
    while (cur) {
        LNode* tmp = cur; cur = cur->next; free(tmp);
    }
    free(*s); *s = NULL;
}
