#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if(n == 0) {
        cout << "Maximum Subarray Sum: 0" << endl;
        return 0;
    }

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int currentSum = nums[0];
    int maxSum = nums[0];

    for(int i = 1; i < n; i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;

    return 0;
}
