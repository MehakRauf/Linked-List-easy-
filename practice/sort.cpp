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

void sort()
{
    struct List *curr1 = start;
    while (curr1 != NULL)
    {
        struct List *curr2 = curr1->next;
        while (curr2 != NULL)
        {
            if(curr1->data>curr2->data){
                swap(curr1->data,curr2->data);
            }
            curr2=curr2->next;
        }
        curr1=curr1->next;
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
    insert(2);
    insert(2);
    insert(1);
    insert(0);
    insert(0);
    insert(1);
    insert(1);
    print();
    sort();
    print();
}