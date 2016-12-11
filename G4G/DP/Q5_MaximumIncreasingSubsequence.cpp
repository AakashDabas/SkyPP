#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        int dp[n] = {0};
        for(int i = 0; i < n; i++){
            dp[i] = arr[i];
            for(int j = i; j >= 0; j--){
                if(arr[j] < arr[i])
                    dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        int mx = 0;
        for(int i = 0; i < n; i++)
            mx = max(mx, dp[i]);
        cout << mx << endl;
    }
    return 0;
}
