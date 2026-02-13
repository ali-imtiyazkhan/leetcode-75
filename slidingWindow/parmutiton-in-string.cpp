#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;

    vector<int> freq1(26, 0);
    vector<int> window(26, 0);

    int n = s2.size();
    int m = s1.size();

    // Count frequency of s1
    for (char c : s1) {
        freq1[c - 'a']++;
    }

    // First window in s2
    for (int i = 0; i < m; i++) {
        window[s2[i] - 'a']++;
    }

    if (window == freq1) return true;

    // Slide window
    for (int i = m; i < n; i++) {
        // Remove left character
        window[s2[i - m] - 'a']--;

        // Add new right character
        window[s2[i] - 'a']++;

        if (window == freq1)
            return true;
    }

    return false;
}

int main() {
    string s1, s2;

    cout << "Enter string s1: ";
    cin >> s1;

    cout << "Enter string s2: ";
    cin >> s2;

    if (checkInclusion(s1, s2))
        cout << "Permutation exists in s2." << endl;
    else
        cout << "No permutation found." << endl;

    return 0;
}
