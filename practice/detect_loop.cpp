#include <iostream>
#include <stdlib.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};

struct ListNode *insert(int value)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->val = value;
    temp->next = NULL;
    return temp;
}
bool hasCycle(ListNode *head)
{
    if (head == NULL)
        return false;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    // Example usage

    // Create a linked list with a loop
    ListNode *head = insert(1);
    ListNode *node2 = insert(2);
    ListNode *node3 = insert(3);
    ListNode *node4 = insert(4);
    ListNode *node5 = insert(5);
    head->next = node2;
    node2->next = node3;
    node3->next = node2;
    node4->next = node5;
    node5->next = NULL; // create a loop pointing back to node3

    bool hasLoop = hasCycle(head);
    if (hasLoop)
    {
        std::cout << "The linked list has a loop." << std::endl;
    }
    else
    {
        std::cout << "The linked list does not have a loop." << std::endl;
    }

    return 0;
}