#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *first = dummy;
    ListNode *second = dummy;


    for (int i = 0; i < n + 1; i++)
    {
        if (first != nullptr)
            first = first->next;
    }
    while (first != nullptr)
    {
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;

    return dummy->next;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    ListNode *result = removeNthFromEnd(head, n);

    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }
}