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
        if(n <= 4){
            int tmp = arr[0];
            for(int i = 0; i < n; i++)
                tmp = min(tmp, arr[i]);
            cout << tmp << endl;
            continue;
        }
        int dp[n];
        dp[0] = arr[0];
        dp[1] = arr[1];
        dp[2] = arr[2];
        dp[3] = arr[3];
        for(int i = 4; i < n; i++){
            dp[i] = arr[i] + min(dp[i - 1], min(dp[i - 2], min(dp[i - 3], dp[i - 4])));
        }

        int tmp = min(dp[n - 1], min(dp[n - 2], min(dp[n - 3], dp[n - 4])));
        cout << tmp << endl;
    }
    return 0;
}
