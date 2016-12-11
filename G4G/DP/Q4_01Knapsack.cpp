#include<iostream>
#include<cmath>

using namespace std;

typedef long long int lli;

int main(){
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        lli n, w;
        cin >> n >> w;
        lli wt[n], val[n];
        for(int i = 0; i < n; i++)
            cin >> val[i];
        for(int i = 0; i < n; i++)
            cin >> wt[i];
        lli dp[n + 1][w + 1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= w; j++){
                if(i == 0 || w == 0)
                    dp[i][j] = 0;
                else if(j - wt[i - 1] >= 0){
                    //cout << val[i - 1] + dp[i - 1][j - wt[j - 1]] << " " << dp[i - 1][j] << endl;
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
    }
        cout << dp[n][w] << endl;
    }
    return 0;
}
