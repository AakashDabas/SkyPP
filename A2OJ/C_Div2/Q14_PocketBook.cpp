#include<iostream>
#include<vector>

#define mod 1000000007

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    char mat[n][m];
    vector<int> choice(m, false);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];

    for(int j = 0; j < m; j++){
        bool dp[26] = {0};
        for(int i = 0; i < n; i++){
            if(!dp[mat[i][j] - 'A']){
                dp[mat[i][j] - 'A'] = true;
                choice[j]++;
            }
        }
    }

    long long int ans = 1;
    for(int i = 0; i < m; i++)
        ans = (ans * choice[i]) % mod;
    cout << ans;

    return 0;
}
