#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

ListNode* doubleIt(ListNode* head) {
    head = reverse(head);

    ListNode* temp = head;
    int carry = 0;

    while (temp) {
        int sum = temp->val * 2 + carry;
        temp->val = sum % 10;
        carry = sum / 10;

        if (!temp->next && carry) {
            temp->next = new ListNode(carry);
            carry = 0;
        }

        temp = temp->next;
    }

    return reverse(head);
}


ListNode* createList(vector<int> v) {
    ListNode* head = new ListNode(v[0]);
    ListNode* temp = head;

    for (int i = 1; i < v.size(); i++) {
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> v = {9, 9, 9}; 

    ListNode* head = createList(v);

    cout << "Original: ";
    printList(head);

    head = doubleIt(head);

    cout << "Doubled: ";
    printList(head);

    return 0;
}