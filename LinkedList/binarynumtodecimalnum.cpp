#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
int binaryLinkedListToDecimal(ListNode* head) {
    int num = 0;
    while (head != nullptr) {
        num = num * 2 + head->val;
        head = head->next;
    }
    return num;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    cout << binaryLinkedListToDecimal(head);
}