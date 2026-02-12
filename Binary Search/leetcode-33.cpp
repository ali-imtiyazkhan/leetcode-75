#include <iostream>
#include <vector>
using namespace std;

int searchRotated(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(nums[mid] == target) {
            return mid;
        }

        if(nums[start] <= nums[mid]) {

            if(nums[start] <= target && target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        else {

            if(nums[mid] < target && target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter rotated sorted elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    int index = searchRotated(nums, target);

    if(index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}
