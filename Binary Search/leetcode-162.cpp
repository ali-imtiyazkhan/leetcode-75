#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] > nums[mid + 1])
        {
            end = mid;
        }

        else
        {
            start = mid + 1;
        }
    }
    return start;
}

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

    int peakIndex = findPeakElement(nums);

    cout << "Peak element index: " << peakIndex << endl;
    cout << "Peak element value: " << nums[peakIndex] << endl;

    return 0;
}
