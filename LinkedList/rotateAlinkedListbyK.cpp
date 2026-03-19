#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* rotateRight(Node* head, int k) {
    if (!head || !head->next || k == 0)
        return head;

    Node* last = head;
    int length = 1;
    while (last->next) {
        last = last->next;
        length++;
    }

    last->next = head;

    k = k % length;
    Node* newTail = head;
    for (int i = 0; i < length - k - 1; i++) {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;


    newTail->next = nullptr;

    return newHead;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;
    Node* newHead = rotateRight(head, k);

    // Print the rotated list
    Node* current = newHead;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
}