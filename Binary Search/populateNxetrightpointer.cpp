#include <iostream>
using namespace std;

// Definition for a Node
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;

        Node* current = root;

        while (current->left != NULL) {
            Node* temp = current;

            while (temp != NULL) {
                temp->left->next = temp->right;

                if (temp->next != NULL) {
                    temp->right->next = temp->next->left;
                }

                temp = temp->next;
            }

            current = current->left;
        }

        return root;
    }
};

// Helper to print level order using next pointers
void printLevels(Node* root) {
    Node* level = root;

    while (level != NULL) {
        Node* temp = level;

        while (temp != NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;

        level = level->left;
    }
}

int main() {
    /*
        Perfect Binary Tree:
                1
              /   \
             2     3
            / \   / \
           4  5  6  7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    sol.connect(root);

    printLevels(root);

    return 0;
}