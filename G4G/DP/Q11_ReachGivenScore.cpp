#include<iostream>

using namespace std;

int main(){
    int t; 
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        int n;
        cin >> n;
        int dp[n + 1] = {0};
        for(int i = 1; i <= n; i++){
            if(i > 3)
                dp[i] = dp[i - 3] + 1;
            if(i > 5)
                dp[i] += dp[i - 5] + 1;
            if(i > 10)
                dp[i] += dp[i - 10] + 1;
        }
        cout << dp[n] << "\n";
    }
    return 0;
}
