#include <iostream>
using namespace std;

int main()
{

    string str;
    cin >> str;

    int left = 0, right = str.length() - 1;
    bool isPalindrome = true;
    while (left < right)
    {
        if (str[left] != str[right])
        {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}