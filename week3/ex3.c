#include <stdio.h>
#include <stdlib.h>


struct node {
    struct node* prev;
    struct node* next;
    int val;
};

struct list {
    struct node* head;
    struct node* tail;
};

void create_list(struct list* lst) {
    struct node *_head = malloc(sizeof (struct node)),
            *_tail = malloc(sizeof (struct node));
    _head->next = _tail;
    _tail->prev = _head;
    lst->head = _head;
    lst->tail = _tail;
}

void insert_node(struct list* lst, struct node* nd, struct node* before) {
    struct node *d = lst->head;
    while (d != 0) {
        if (d == before) {
            struct node* prev = d->prev;
            (*d).prev = nd;
            (*nd).next = d;
            (*prev).next = nd;
            (*nd).prev = prev;
            break;
        }
        d = d->next;
    }
}
void print_list(struct list* lst) {
    struct node *nd = lst->head;
    while (nd != lst->tail) {
        if (nd != lst->head) {
            printf("%d ", nd->val);
        }
        nd = nd->next;
    }
}

void remove_from_list(struct list* lst, int pos) {
    int p = -1;
    struct node* nd = lst->head;
    while (nd != lst->tail) {
        if (p == pos) {
            (*nd).prev->next = (*nd).next;
            (*nd).next->prev = (*nd).prev;
            break;
        }
        ++p;
    }
}
void free_list(struct list* lst) {
    struct node* nd = lst->head;
    while (nd != lst->tail) {
        struct node temp = *nd->next;
        free(nd);
        nd = temp.next;
    }
    free(nd);
}

int main() {
    struct list *lst = malloc(sizeof (struct list));
    create_list(lst);
    printf("Input the array size:\n");
    int size = 0;
    scanf("%d", &size);
    if (size < 0) {
        printf("Invalid size");
        return 0;
    }
    printf("Input the array elements separated by a space\n");
    for (int i = 0; i < size; ++i) {
        struct node* nd = malloc(sizeof (struct node));
        scanf("%d", &nd->val);
        insert_node(lst, nd, lst->tail);
    }
    remove_from_list(lst, 4);
    print_list(lst);
    free_list(lst);

}

