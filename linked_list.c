#include "../include/dsa.h"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* ll_create_node(int val) {
    Node* n = malloc(sizeof(Node));
    if (!n) return NULL;
    n->data = val;
    n->next = NULL;
    return n;
}

void ll_push_front(Node** head, int val) {
    Node* n = ll_create_node(val);
    n->next = *head;
    *head = n;
}

void ll_push_back(Node** head, int val) {
    Node* n = ll_create_node(val);
    if (*head == NULL) {
        *head = n; return;
    }
    Node* cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

bool ll_remove(Node** head, int val) {
    Node* cur = *head;
    Node* prev = NULL;
    while (cur) {
        if (cur->data == val) {
            if (prev) prev->next = cur->next;
            else *head = cur->next;
            free(cur);
            return true;
        }
        prev = cur; cur = cur->next;
    }
    return false;
}

Node* ll_search(Node* head, int val) {
    Node* cur = head;
    while (cur) {
        if (cur->data == val) return cur;
        cur = cur->next;
    }
    return NULL;
}

void ll_print(Node* head) {
    Node* cur = head;
    while (cur) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void ll_free(Node** head) {
    Node* cur = *head;
    while (cur) {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    *head = NULL;
}
