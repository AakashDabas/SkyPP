#include<iostream>
#include<climits>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int minSum = INT_MAX, idx = 0;
    for(int i = 0; i < k; i++){
        int sum = 0;
        for(int j = i; j < n; j += k)
            sum += arr[j];
        if(sum < minSum){
            minSum = sum;
            idx = i;
        }
    }

    cout << idx + 1;

    return 0;
}
