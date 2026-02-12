#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

bool hasCycle(ListNode* head) {

    if(head == NULL || head->next == NULL)
        return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL) {

        slow = slow->next;     
        fast = fast->next->next;   

        if(slow == fast)
            return true;
    }

    return false;
}

int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if(n == 0) return 0;

    int value;
    cin >> value;

    ListNode* head = new ListNode(value);
    ListNode* temp = head;

    for(int i = 1; i < n; i++) {
        cin >> value;
        temp->next = new ListNode(value);
        temp = temp->next;
    }

    int pos;
    cout << "Enter position to create cycle (-1 for no cycle): ";
    cin >> pos;

    if(pos != -1) {
        ListNode* cycleNode = head;
        for(int i = 0; i < pos; i++) {
            cycleNode = cycleNode->next;
        }
        temp->next = cycleNode; 
    }

    if(hasCycle(head))
        cout << "Cycle detected!" << endl;
    else
        cout << "No cycle." << endl;

    return 0;
}
