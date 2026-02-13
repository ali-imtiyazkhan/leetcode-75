#include <iostream>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    int freq[26] = {0};

    for (char c : s) {
        freq[c - 'a']++;
    }

    for (int i = 0; i < s.length(); i++) {
        if (freq[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    int result = firstUniqChar(s);

    if (result != -1)
        cout << "First unique character index: " << result << endl;
    else
        cout << "No unique character found." << endl;

    return 0;
}
