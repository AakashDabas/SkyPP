#include<iostream>

typedef long long int lli;

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin >> n;
    lli ans = 0;
    int cnt = 1;
    lli lst;
    lli in;
    cin >> in;
    lst = in;
    for(int i = 1; i < n; i++){
        cin >> in;
        if(in == lst)
            cnt++;
        else{
            ans += (cnt - 1) * cnt / 2;
            cnt = 1;
        }
        lst = in;
    }
    if(cnt > 1)
        ans += (cnt - 1) * cnt / 2;
    cout << ans + n;
    return 0;
}
