#include<iostream>
using namespace std;

int main(){
    int n, target;
    cin >> n >> target;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int left = 0, right = n-1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == target){
            cout << left << " " << right << endl;
            return 0;
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }
    cout << "No pair found" << endl;
    return 0;
}