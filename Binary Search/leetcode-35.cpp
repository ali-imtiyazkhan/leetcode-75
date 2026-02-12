#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int target)
{
    int i = 0;
    int j = nums.size() - 1;

    while (i <= j)
    {
        int mid = i + (j - i) / 2;

        if (nums[mid] == target)
        {
            return mid;
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

    return i;
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

    int index = binarySearch(nums, target);

    cout << "Position: " << index << endl;

    return 0;
}
