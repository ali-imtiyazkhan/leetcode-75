#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    if (s.size() < p.size())
        return res;

    int m = p.size();
    int n = s.size();

    vector<int> Pcout(26, 0);
    vector<int> window(26, 0);

    for (char c : p)
    {
        Pcout[c - 'a']++;
    }

    for (int i = 0; i < m; i++)
    {
        window[s[i] - 'a']++;
    }

    if (window == Pcout)
        res.push_back(0);

    for (int i = m; i < n; i++)
    {

        window[s[i - m] - 'a']--;

        window[s[i] - 'a']++;

        if (window == Pcout)
            res.push_back(i - m + 1);
    }

    return res;
}

int main()
{
    string s, p;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string p: ";
    cin >> p;

    vector<int> result = findAnagrams(s, p);

    if (result.empty())
    {
        cout << "No anagrams found." << endl;
    }
    else
    {
        cout << "Anagram starting indices: ";
        for (int index : result)
        {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}
