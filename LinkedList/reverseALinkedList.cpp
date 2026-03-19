#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* reversedHead = reverseList(head);

    // Print the reversed list
    Node* current = reversedHead;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    return 0;
}