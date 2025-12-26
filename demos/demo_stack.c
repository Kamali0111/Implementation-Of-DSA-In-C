#include "../include/dsa.h"

extern Stack* stack_new();
extern void stack_push(Stack* s, int v);
extern int stack_pop(Stack* s);
extern bool stack_is_empty(Stack* s);
extern void stack_free(Stack** s);

int main(void) {
    Stack* s = stack_new();
    stack_push(s, 1); stack_push(s, 2); stack_push(s, 3);
    while (!stack_is_empty(s)) {
        printf("pop: %d\n", stack_pop(s));
    }
    stack_free(&s);
    return 0;
}
