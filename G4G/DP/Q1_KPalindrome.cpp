#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cmath>

using namespace std;

int main(){
    string str1, str2;
    cin >> str1;
    for(int i = str1.length() - 1; i >= 0; i--)
        str2 += str1[i];
    str2 += '\0';
    cout << str2 << endl;
    int dp[str1.length() + 1][str2.length() + 1];
    memset(dp, 0, sizeof(int) * (str1.length() + 1) * (str2.length() + 1));
    for(int i = 1; i <= str1.length(); i++){
        for(int j = 1; j <= str2.length(); j++){
            if(str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[str1.length()][str2.length()];
    return 0;
}
