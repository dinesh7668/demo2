#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create_node(int val)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

void traversal(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->next;
    }
}

void insert(node *last, int val)
{
    node *new_node;
    new_node = create_node(val);

    last->next = new_node;
}

int main()
{
    node *head, *last, *first_node, *second_node, *third_node, *fourth_node;

    first_node = create_node(10);
    second_node = create_node(20);
    third_node = create_node(30);
    fourth_node = create_node(40);

    head = first_node;
    last = head;

    head->next = second_node;
    last = last->next;

    second_node->next = third_node;
    last = last->next;

    third_node->next = fourth_node;
    last = last->next;

   printf("linked list before insertion");
    traversal(head);

    insert(last,50);

   printf("\ninked list after insertion at end");
    traversal(head);
    return 0;
}
