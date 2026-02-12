#include <iostream>
#include <vector>
using namespace std;

int findFirst(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    int ans = -1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(nums[mid] == target) {
            ans = mid;
            end = mid - 1;
        }
        else if(nums[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

int findLast(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    int ans = -1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(nums[mid] == target) {
            ans = mid;
            start = mid + 1;
        }
        else if(nums[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    int first = findFirst(nums, target);
    int last = findLast(nums, target);

    cout << "First Position: " << first << endl;
    cout << "Last Position: " << last << endl;

    return 0;
}
