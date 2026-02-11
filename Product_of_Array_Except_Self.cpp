#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "enter number of element in an array : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the element in the array";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> answer(n, 1);

    // prefix producte
    int prefix = 1;
    for (int i = 0; i < n; i++)
    {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    // Suffix products
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    cout << "Product array: ";
    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}