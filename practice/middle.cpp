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
        struct List *curr=start;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
        temp->prev=curr;
    }
}

void middle_element(){
    struct List *curr=start;
    struct List *runner=start;
    while(runner!=NULL && runner->next!=NULL){
        curr=curr->next;
        runner=runner->next->next;
    }    
    if(runner==NULL){
        cout<<"The middle elements are: "<<endl;
        cout<<curr->data<<" "<<curr->prev->data;
    }
    else{
        cout<<"The middle element is: "<<endl;
        cout<<curr->data;
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
    middle_element();
}