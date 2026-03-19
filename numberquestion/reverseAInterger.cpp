#include <iostream>
#include <climits>
using namespace std;

int reverseInteger(int x)
{
    int rev = 0;
    while (x != 0)
    {
        int pop = x % 10;
        x /= 10;

        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
            return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
            return 0;

        rev = rev * 10 + pop;
    }
    return rev;
}

int main()
{
    int x = 123;
    cout << reverseInteger(x) << endl;

    x = -123;
    cout << reverseInteger(x) << endl; 
    x = 120;
    cout << reverseInteger(x) << endl;
    x = 0;
    cout << reverseInteger(x) << endl;

    return 0;
}