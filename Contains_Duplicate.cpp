#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    unordered_set<int> s;

    for (int i = 0; i < n; i++)
    {
        if (s.find(nums[i]) != s.end())
        {
            cout << "True (Duplicate found)" << endl;
            return 0;
        }
        s.insert(nums[i]);
    }

    cout << "False (No duplicate)" << endl;

    return 0;
}
