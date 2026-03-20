#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *mergeNodes(Node *head)
{
    Node *dummy = new Node(0);
    Node *tail = dummy;
    int sum = 0;

    while (head)
    {
        if (head->data == 0)
        {
            if (sum > 0)
            {
                tail->next = new Node(sum);
                tail = tail->next;
                sum = 0;
            }
        }
        else
        {
            sum += head->data;
        }
        head = head->next;
    }

    return dummy->next;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(0);

    cout << "Original List: ";
    printList(head);

    Node *mergedHead = mergeNodes(head);

    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}