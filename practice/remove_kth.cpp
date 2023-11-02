#include <iostream>
#include <stdlib.h>
using namespace std;

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

void delete_kth(int k)
{
    if (start == NULL || k <= 0)
    {
        return;
    }

    struct List *curr = start;
    struct List *prev = NULL;
    int count = 1;

    while (curr != NULL)
    {
        if (count % k == 0)
        {
            if (prev == NULL) // If the first node needs to be deleted
            {
                start = curr->next;
                free(curr);
                curr = start;
            }
            else
            {
                prev->next = curr->next;
                struct List *temp = curr;
                curr = curr->next;
                free(temp);
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }   
        count++;
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

    delete_kth(3);
    print();
}