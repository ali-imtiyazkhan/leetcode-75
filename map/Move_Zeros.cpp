#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n;
    cout << "Enter number of elements in an array : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements in an array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int index = 0; // position of next non zero

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[index]);
            index++;
        }
    }

    cout << "Array after moving zeroes: ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}