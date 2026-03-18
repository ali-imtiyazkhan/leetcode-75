#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int carry = 0;
    int sum[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int s = a[i] + b[i] + carry;
        sum[i] = s % 10;
        carry = s / 10;
    }

    if (carry)
        cout << carry << " ";
    for (int i = 0; i < n; i++)
        cout << sum[i] << " ";
}