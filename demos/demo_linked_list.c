#include "../include/dsa.h"

extern Node* ll_create_node(int val);
extern void ll_push_front(Node** head, int val);
extern void ll_push_back(Node** head, int val);
extern bool ll_remove(Node** head, int val);
extern void ll_print(Node* head);
extern Node* ll_search(Node* head, int val);
extern void ll_free(Node** head);

int main(void) {
    Node* head = NULL;
    ll_push_back(&head, 10);
    ll_push_front(&head, 5);
    ll_push_back(&head, 20);
    printf("List: "); ll_print(head);
    printf("Removing 10\n"); ll_remove(&head, 10);
    printf("List: "); ll_print(head);
    Node* s = ll_search(head, 20);
    printf("Search 20: %s\n", s?"found":"not found");
    ll_free(&head);
    return 0;
}
