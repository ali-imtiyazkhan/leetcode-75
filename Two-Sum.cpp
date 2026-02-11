#include <iostream>
#include <vector>
#include <unordered_map>
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

    int target;
    cout << "Enter target: ";
    cin >> target;

    unordered_map<int, int> mp; // value -> index

    for (int i = 0; i < n; i++)
    {
        int complement = target - nums[i];

        if (mp.find(complement) != mp.end())
        {
            cout << "Indices: " << mp[complement] << " and " << i << endl;
            return 0;
        }

        mp[nums[i]] = i;
    }

    cout << "No solution found." << endl;

    return 0;
}
