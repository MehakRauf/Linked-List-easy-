#include <iostream>
#include <stdlib.h>
using namespace std;

struct List
{
    int data;
    struct List *next;
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
void pairwise_swap()
{
    struct List *curr = start;
    while (curr != NULL && curr->next !=NULL)
    {
        swap(curr->data,curr->next->data);
        curr=curr->next->next;
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
    pairwise_swap();
    print();
}