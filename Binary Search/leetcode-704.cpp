#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<int> &nums, int target)
{
    int i = 0;
    int j = nums.size() - 1;

    while (i <= j)
    {
        int mid = i + (j - i) / 2;

        if (nums[mid] == target)
        {
            return true;
        }
        else if (nums[mid] > target)
        {
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter total number in an array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements in sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    if (binarySearch(nums, target))
    {
        cout << "Target is present in array";
    }
    else
    {
        cout << "Target is not present in array";
    }

    return 0;
}
