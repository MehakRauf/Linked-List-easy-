#include <iostream>
#include <stdlib.h>
using namespace std;

struct List
{
    int data;
    struct List *prev;
    struct List *next;
};
struct List *start = NULL;

void insert(int value)
{
    struct List *temp = (struct List *)malloc(sizeof(struct List));
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
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
        temp->prev = curr;
    }
}


void delete_last_occurence(int val)
{
    struct List *x = NULL;
    struct List *curr = start;
    while (curr != NULL)
    {
        if (curr->data == val)
        {
            x = curr;
        }
        curr = curr->next;
    }
    if (x != NULL)
    {
        if (x == start)
        {
            start=start->next;
            free(x);
        }
        else {
            x->prev->next=x->next;
            free(x);
        }
    }
}
void print()
{
    struct List *curr = start;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
int main()
{
    insert(4);
    insert(14);
    insert(5);
    insert(49);
    insert(10);
    insert(9);
    insert(40);
    insert(8);
    delete_last_occurence(4);
    print();
}