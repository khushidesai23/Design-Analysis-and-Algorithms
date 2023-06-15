//KHUSHI DESAI

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the linked list
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// Function to print the linked list
void printList(struct Node* head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to reverse the linked list
struct Node* reverse(struct Node* head)
{
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

// Function to add two linked lists
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    struct Node* res = NULL;
    struct Node** lastPtrRef = &res;
    int carry = 0;
    while (first != NULL || second != NULL) {
        int sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = sum / 10;
        push(lastPtrRef, sum % 10);
        lastPtrRef = &((*lastPtrRef)->next);
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry)
        push(lastPtrRef, carry);
    return res;
}

int main()
{
    struct Node* res = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    while (num1 > 0) {
        push(&first, num1 % 10);
        num1 /= 10;
    }
    while (num2 > 0) {
        push(&second, num2 % 10);
        num2 /= 10;
    }
    res = addTwoLists(first, second);
    res = reverse(res);
    printf("Result: ");
    printList(res);
   
}
