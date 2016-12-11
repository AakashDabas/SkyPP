#include<iostream>

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
        for(int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;
            arr[i] = max(arr[i], tmp);
        }
        int dp[n] = {0};
        dp[0] = arr[0];
        dp[1] = arr[1];
        for(int i = 2; i < n; i++){
            int mx = dp[i - 2];
            if(i > 2 && dp[i - 3] > mx)
                mx = dp[i - 3];
            dp[i] += mx + arr[i];
        }
        cout << max(dp[n - 1], dp[n - 2]) << "\n";
    }
    return 0;
}
