#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    if (n == 0)
    {
        cout << "Maximum Profit: 0" << endl;
        return 0;
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++)
    {
        if (prices[i] < minPrice)
        {
            minPrice = prices[i]; // Update minimum price
        }
        else
        {
            int profit = prices[i] - minPrice;
            if (profit > maxProfit)
            {
                maxProfit = profit; // Update max profit
            }
        }
    }

    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
