#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node* node;
} Node;

int get_value_of_child_node(Node* n)
{
    Node child = *n;
    int value = child.value;

    return value;
}

int traverse_linked_list(Node* head)
{
    Node current = *head;
    int counter = 1;
    
    while (1)
    {
        printf("%d node's value: %d\n", counter, current.value);
        counter++;
        if (current.node != NULL)
        {
            current = *current.node;
        }
        else
        {
            break;
        }
    }
    
}

int get_length_linked_list(Node* head)
{
    Node current = *head;
    int length = 1;

    while (1)
    {
        if (current.node != NULL)
        {
            current = *current.node;
            length++;
        }
        else
        {
            break;
        }
    }
    
    return length;
}

void get_values_linked_list(Node* head, int* values)
{
    Node current = *head;
    int counter = 0;
    
    while (1)
    {
        values[counter] = current.value;

        if (current.node != NULL)
        {
            current = *current.node;
            counter++;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    Node n1 = {10};

    Node n2 = {20};
    n1.node = &n2;

    Node n3 = {30};
    n2.node = &n3;
    
    Node n4 = {40};
    n3.node = &n4;

    printf("Traverse linked list: \n");
    traverse_linked_list(&n1);

    printf("Return values from linked list: \n");
    int linked_list_length = get_length_linked_list(&n1);
    int values [linked_list_length];
    get_values_linked_list(&n1, values);
    for (int i = 0; i < linked_list_length; i++)
    {
        printf("%d-cell's value: %d\n", i, values[i]);
    }

    return 0;
}
