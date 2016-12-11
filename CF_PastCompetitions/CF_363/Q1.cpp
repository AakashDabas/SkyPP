#include<iostream>
#include<cmath>
#include<climits>

typedef long long int lli;

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    lli n;
    cin >> n;
    string str;
    cin >> str;
    lli loc[n], mn = INT_MAX;
    for(int i = 0; i < n; i++)
        cin >> loc[i];
    for(int i = 0; i < n; i++)
        if(i > 0 && str[i] == 'L' && str[i - 1] == 'R')
            mn = min(mn, loc[i] - loc[i - 1]);
    if(mn == INT_MAX)
        mn = -1;
    else
        mn /= 2;
    cout << mn << "\n";
    return 0;
}
