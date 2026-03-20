#include<iostream>
using namespace std;

// Definition for singly-linked list.
class Node {
public:
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};


Node *reorder(Node *head){
    if(head == NULL || head->next == NULL) return head;

    // Step 1: Find the middle of the linked list
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the linked list
    Node *prev = NULL, *curr = slow, *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Step 3: Merge the two halves
    Node *first = head, *second = prev;
    while(second != NULL){
        Node *temp1 = first->next, *temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }

    return head;
}

// Helper function to print the linked list
void printList(Node *head) {
    Node *temp = head;
    while(temp != NULL){
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    head = reorder(head);

    cout << "Reordered List: ";
    printList(head);

    return 0;
}