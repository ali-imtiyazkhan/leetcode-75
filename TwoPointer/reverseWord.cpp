#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s) {
    int n = s.size();
    int start = 0;

    for (int i = 0; i <= n; i++) {

        if (i == n || s[i] == ' ') {

            // Reverse the word from index 'start' to 'i - 1'
            int left = start;
            int right = i - 1;

            while (left < right) {
                // Swap characters at 'left' and 'right' indices
                swap(s[left], s[right]);
                left++;
                right--;
            }

            start = i + 1;
        }
    }

    return s;
}

int main() {
    string s;

    cout << "Enter a sentence: ";
    getline(cin, s);

    string result = reverseWords(s);

    cout << "Reversed words string: " << result << endl;

    return 0;
}