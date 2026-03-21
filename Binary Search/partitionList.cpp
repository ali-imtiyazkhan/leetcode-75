#include<iostream>
using namespace std;

// Definition for singly-linked list.
class Node {
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* partition(Node* head, int x) {
    if (head == nullptr) return nullptr;

    Node* beforeHead = new Node(0); // Dummy node for the 'before' list
    Node* before = beforeHead; // Pointer to the last node in the 'before' list
    Node* afterHead = new Node(0); // Dummy node for the 'after' list
    Node* after = afterHead; // Pointer to the last node in the 'after' list

    while (head != nullptr) {
        if (head->val < x) {
            before->next = head; // Add to 'before' list
            before = before->next;
        } else {
            after->next = head; // Add to 'after' list
            after = after->next;
        }
        head = head->next; // Move to the next node
    }

    after->next = nullptr; // Terminate the 'after' list
    before->next = afterHead->next; // Connect 'before' list to 'after' list

    Node* newHead = beforeHead->next; // The new head of the partitioned list
    delete beforeHead; // Clean up dummy node
    delete afterHead; // Clean up dummy node

    return newHead;
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}   

int main() {
    // Create a linked list: 1 -> 4 -> 3 -> 2 -> 5 -> 2
    Node* head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(2);

    cout << "Original list: ";
    printList(head);

    int x = 3;
    Node* partitionedHead = partition(head, x);

    cout << "Partitioned list around " << x << ": ";
    printList(partitionedHead);

    return 0;
}