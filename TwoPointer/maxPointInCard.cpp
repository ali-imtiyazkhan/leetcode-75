#include <iostream>
#include <vector>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    
    int totalSum = 0;
    for(int x : cardPoints) totalSum += x;

    int windowSize = n - k;

    if(windowSize == 0) return totalSum;

    int windowSum = 0;

    for(int i = 0; i < windowSize; i++)
        windowSum += cardPoints[i];

    int minSum = windowSum;

    for(int i = windowSize; i < n; i++){
        windowSum += cardPoints[i];
        windowSum -= cardPoints[i - windowSize];
        minSum = min(minSum, windowSum);
    }

    return totalSum - minSum;
}

int main() {
    vector<int> cards = {1,2,3,4,5,6,1};
    int k = 3;

    cout << maxScore(cards, k);
}