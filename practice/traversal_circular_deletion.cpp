#include <iostream>
using namespace std;

struct List
{
    int data;
    struct List *next;
};

struct List *start = NULL;

void insert(int value)
{
    struct List *temp = new List();
    temp->data = value;
    temp->next = NULL;

    if (start == NULL)
    {
        start = temp;
        start->next = start;
    }
    else
    {
        struct List *curr = start;
        while (curr->next != start)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = start;
    }
}

void delete_node(int val)
{
    if (start == NULL)
    {
        return;
    }

    struct List *curr = start;
    struct List *prev;

    // If the node to be deleted is head
    while (curr->next != start && curr->data != val)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == val)
    {
        if (curr->next == start)
        {
            start = NULL;
        }
        else
        {
            prev->next = curr->next;
            start = curr->next;
        }
        free(curr);
    }
}

void print()
{
    if (start == NULL)
    {
        return;
    }

    struct List *temp = start;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != start);

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

    delete_node(12);

    print();

    return 0;
}