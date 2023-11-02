#include <iostream>
#include <stdlib.h>
using namespace std;

struct List
{
    struct List *next;
    int data;
};
struct List *start = NULL;

void insert(int value)
{
    struct List *temp = (struct List *)malloc(sizeof(struct List));
    temp->data = value;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct List *curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}
List* reverseInGroups(List* head, int size) {
    List* current = head;
    List* prev = nullptr;
    List* next = nullptr;

    int count = 0;
    // Reverse the first 'size' nodes of the linked list
    while (count < size && current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Recursively call the function for remaining nodes
    if (next != nullptr) {
        List* rest = reverseInGroups(next, size);
        head->next = rest;
    }

    return prev;
}
void print()
{
    struct List *curr = start;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    insert(1);
    insert(0);
    insert(12);
    insert(2);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(31);
    print();
    start=reverseInGroups(start,4);
    print();
}