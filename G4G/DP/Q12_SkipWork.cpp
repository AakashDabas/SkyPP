#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        int n;
        cin >> n;
        int arr[n], sum = 0, dp[n + 1] = {0}, Max = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        dp[0] = arr[0];
        if(n == 1){
            cout << "0\n";
            continue;
        }
        dp[1] = arr[1];
        Max = max(dp[0], dp[1]);
        for(int i = 2; i < n; i++){
            int mx = dp[i - 2];
            if(i > 2)
                mx = max(dp[i - 2], dp[i - 3]);
            dp[i] = arr[i] + mx;
            Max = max(Max, dp[i]);
        }
        cout << sum - Max << "\n";
    }
    return 0;
}
