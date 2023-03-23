#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data[100];
    struct node *link;
} *LIST;

LIST insert(LIST head, char data[]) {
    LIST temp = (LIST) malloc(sizeof(struct node));
    strcpy(temp->data, data);
    temp->link = NULL;
    if (head == NULL || strcmp(head->data, data) > 0) {
        temp->link = head;
        head = temp;
    } else {
        LIST trav = head;
        while (trav->link != NULL && strcmp(trav->link->data, data) < 0) {
            trav = trav->link;
        }
        temp->link = trav->link;
        trav->link = temp;
    }
    return head;
}

LIST deleteElem(LIST head, char data[]) {
    if (head == NULL) {
        return NULL;
    }
    if (strcmp(head->data, data) == 0) {
        LIST temp = head;
        head = head->link;
        free(temp);
        return head;
    }
    LIST trav = head;
    while (trav->link != NULL && strcmp(trav->link->data, data) != 0) {
        trav = trav->link;
    }
    if (trav->link != NULL) {
        LIST temp = trav->link;
        trav->link = trav->link->link;
        free(temp);
    }
    return head;
}

void display(LIST head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        printf("List contains: ");
        while (head != NULL) {
            printf("%s ", head->data);
            head = head->link;
        }
        printf("\n");
    }
}

LIST update(LIST head, char old_data[], char new_data[]) {
    head = deleteElem(head, old_data);
    head = insert(head, new_data);
    return head;
}

int main() {
    LIST head = NULL;
    head = insert(head, "apple");
    head = insert(head, "banana");
    head = insert(head, "cherry");
    display(head);
    head = deleteElem(head, "banana");
    display(head);
    return 0;
}
