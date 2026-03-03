#include <iostream>
#include <string>
using namespace std;

// Helper function to check palindrome in given range
bool isPalindrome(string s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

bool validPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            // Skip either left or right character
            return isPalindrome(s, i + 1, j) ||
                   isPalindrome(s, i, j - 1);
        }
        i++;
        j--;
    }

    return true;
}

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    if (validPalindrome(s))
        cout << "True (Valid Palindrome with at most one deletion)" << endl;
    else
        cout << "False (Not possible even after one deletion)" << endl;

    return 0;
}