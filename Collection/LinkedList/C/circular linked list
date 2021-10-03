#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int list_len(struct node* head) {
    struct node* curr;
    int len = 0;
    if (head == NULL) {
        return len;
    }
    curr = head;
    do {
        curr = curr->next;
        ++len;
    } while (curr->next != head);
    return ++len;
}

void create(struct node** head, int len) {
    struct node* curr;
    struct node* ptr;
    int i;

    // accepting values
    for (i = 0; i < len; ++i) {
        curr = (struct node*)malloc(sizeof(struct node));
        curr->data = random() % 20;
        curr->next = NULL;
        if (*head == NULL) {
            *head = curr;
            ptr = curr;
            curr->next = curr;
        } else {
            curr->next = *head;
            ptr->next = curr;
            ptr = curr;
        }
    }
}

void display(struct node* head) {
    struct node* curr;
    if (head == NULL) {
        return;
    }
    for (curr = head; curr->next != head; curr = curr->next) {
        printf("%d ", curr->data);
    }
    printf("%d", curr->data);  // last node
    printf("\n");
}

void insert(struct node** head, int val, int pos) {
    struct node* curr;
    struct node* ptr;
    curr = (struct node*)malloc(sizeof(struct node));
    curr->data = val;
    curr->next = NULL;
    if (*head == NULL) {
        *head = curr;
        curr->next = curr;
    } else if (pos == 0) {
        for (ptr = *head; ptr->next != *head; ptr = ptr->next)
            ;
        curr->next = (*head);
        ptr->next = curr;
        *head = curr;
    } else {
        ptr = *head;
        pos = pos % list_len(*head);
        int i = 0;
        while (i < pos) {
            ptr = ptr->next;
            ++i;
        }
        curr->next = ptr->next;
        ptr->next = curr;
    }
}

void search(struct node* head, int val) {
    struct node* ptr;
    if (head == NULL) {
        printf("Empty");
    } else {
        ptr = head;
        while (ptr->next != head) {
            if (ptr->data == val) {
                printf("Value found.\n");
                return;
            }
            ptr = ptr->next;
        }
    }
    printf("Value not found.\n");
}

void delete (struct node** head, int pos) {
    struct node* ptr;
    struct node* prv;
    if (*head == NULL) {
        printf("Empty\n");
    } else if (*head == (*head)->next) {
        *head = NULL;
        free(ptr);
    } else {
        ptr = *head;
        pos = pos % list_len(*head);
        int i = 0;
        while (i < pos && ptr->next != *head) {
            prv = ptr;
            ptr = ptr->next;
            ++i;
        }
        if (pos == 0) {
            printf("here\n");
            for (prv = *head; prv->next != *head; prv = prv->next)
                ;
            *head = (*head)->next;
            prv->next = *head;
            free(ptr);
        } else {
            prv->next = ptr->next;
            free(ptr);
        }
    }
}

void reverse(struct node** head) {
    struct node* ptr1 = *head;
    struct node* ptr2;
    while (ptr1->next != ptr1) {
        ptr2 = ptr1->next;
        ptr1->next = ptr2->next;
        ptr2->next = *head;
        *head = ptr2;
    }
    ptr1->next = ptr2;
}

int main(int argc, char* argv[]) {
    int len = atoi(argv[1]);
    struct node* head = NULL;
    create(&head, len);
    display(head);
    /*insert(&head, 30, 7);
    display(head);
    //search(head, 30);
    delete (&head, 0);*/
    reverse(&head);
    display(head);
    return 0;
}