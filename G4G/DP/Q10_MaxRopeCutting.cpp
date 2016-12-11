#include<iostream>
#include<cmath>

using namespace std;

typedef long long int lli;

int main(){
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        int n;
        cin >> n;
        lli dp[n + 1] = {0};
        dp[0] = 1;
        for(lli i = 3; i <= n; i++){
                dp[i] += dp[i - 3];
        }
        for(lli i = 5; i <= n; i++){
                dp[i] += dp[i - 5];
        }
        for(lli i = 10; i <= n; i++){
                dp[i] += dp[i - 10];
        }
        cout << dp[n] << "\n";
    }
    return 0;
}
