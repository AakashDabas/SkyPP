#include<iostream>

typedef long long int lli;

#define mod 1000000007

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string str;
        cin >> str;
        int lstPos[26];
        for(int i = 0; i < 26; i++)
            lstPos[i] = -1;
        lli dp[str.length()] = {0}, cnt = 1;
        for(int i = 0; i < str.length(); i++){
            lli pos = lstPos[str[i] - 'a'] - 1;
            lli val = 0;
            if(pos == -2)
                val = 0;
            else if(pos == -1)
                val = 1;
            else
                val = dp[pos];
            cnt = 2 * cnt - val;
            cnt %= mod;
            if(cnt < 0)
                cnt = mod + cnt;
            dp[i] = cnt;
            lstPos[str[i] - 'a'] = i;
        }
        cout << cnt << endl;
    }
    return 0;
}
