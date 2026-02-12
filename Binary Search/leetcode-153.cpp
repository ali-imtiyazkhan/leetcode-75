#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &nums)
{
    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
        int mid = i + (j - i) / 2;

        if (nums[mid] > nums[j])
        {
            i = mid + 1;
        }
        else
        {
            j = mid;  
        }
    }

    return nums[i];
}

int main()
{
    int n;
    cout << "Enter total number in an array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements in rotated sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int num = findMin(nums);

    cout << "Minimum number in array: " << num << endl;

    return 0;
}
