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

void delete_N_after_M(int M, int N)
{
    struct List *curr = start;

    while (curr != NULL)
    {
        for (int i = 1; i < M && curr!=NULL; i++)
        {
            curr = curr->next;
        }
        if (curr == NULL)
        {
            return;
        }
        struct List *t = curr->next;
        for (int i = 1; i <= N && curr!=NULL; i++)
        {
            struct List *temp=t;
            t=t->next;
            free(temp);
        }
        curr->next=t;
        curr=curr->next;
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
    cout<<endl;
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

    delete_N_after_M(1,2);
    print();
}