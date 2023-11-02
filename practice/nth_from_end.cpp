#include <iostream>
#include <stdlib.h>
using namespace std;

struct List
{
    int data;
    struct List *next;
};
struct List *start = NULL;
int length_list = 0;

void insert(int value)
{
    struct List *temp = (struct List *)malloc(sizeof(struct List));
    temp->data = value;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
        length_list++;
    }
    else
    {
        struct List *curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        length_list++;
    }
}
void print_nth(int n)
{
    struct List *curr = start;
    for (int i = 1; i < (length_list - n + 1); i++)
    {
        curr = curr->next;
    }
    if (curr != NULL)
    {
        cout << curr->data << endl;
    }
    else
    {
        cout << "The index is invalid" << endl;
    }
}
int main()
{
    insert(4);
    insert(14);
    insert(5);
    insert(7);
    insert(10);
    insert(9);
    insert(3);
    insert(8);
    cout << length_list;
    print_nth(3);
}