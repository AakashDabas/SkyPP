#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<long long int> cnt1(5, 0), cnt2(5, 0);
    for(int i = 1; i <= n; i++)
        cnt1[i % 5]++;
    for(int j = 1; j <= m; j++)
        cnt2[j % 5]++;
    long long int ans = 0;
    ans += cnt1[0] * cnt2[0];
    ans += cnt1[1] * cnt2[4];
    ans += cnt1[4] * cnt2[1];
    ans += cnt1[2] * cnt2[3];
    ans += cnt1[3] * cnt2[2];
    cout << ans;
    return 0;
}
