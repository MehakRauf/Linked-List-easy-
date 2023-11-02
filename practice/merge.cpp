#include <iostream>
#include <stdlib.h>
using namespace std;

struct List
{
    int data;
    struct List *next;
};
struct List *start = NULL;

struct List *insert(int value)
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
    return start;
}
struct List* merge(struct List *p, struct List *q)
{
    struct List *p_next, *q_next ;
    struct List *pc=p;
    struct List *qc=q;
    while(pc!=NULL && qc!=NULL){
        p_next=pc->next;
        q_next=qc->next;
        qc->next=p_next;
        pc->next=qc;
        pc=p_next;
        qc=q_next;
    }
    q=qc;
    return q;
}
void print(struct List *start)
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
    struct List *p = insert(3);
    insert(2);
    insert(1);

    start = NULL;
    struct List *q = insert(6);
    insert(7);
    insert(8);
    insert(31);
    print(p);
    print(q);
    q=merge(p,q);
    print(p);
    print(q);
}
