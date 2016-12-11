#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        int n;
        cin >> n;
        int dp[n + 1] = {0};
        for(int i = 0; i <= 6; i++)
            dp[i] = i;
        for(int i = 7; i <= n; i++)
            for(int j = 1; j <= i - 3; j++)
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
        cout << dp[n] << "\n";
    }
    return 0;
}
