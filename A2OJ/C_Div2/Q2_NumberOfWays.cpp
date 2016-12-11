#include<iostream>

typedef long long int lli;

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    lli n;
    cin >> n;
    lli arr[n];
    lli cnt[n] = {0};
    bool flag = true;
    lli sM = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sM += arr[i];
    }
    if(sM % 3){
        cout << "0";
        return 0;
    }
    sM /= 3;
    lli sum = 0;
    for(int i = n - 1; i >= 0; i--){
        sum += arr[i];
        if(sum == sM)
            cnt[i] = 1;
    }
    for(int i = n - 2; i >= 0; i--)
        cnt[i] += cnt[i + 1];
    lli ans = 0;
    sum = 0;
    for(int i = 0; i < n - 2; i++){
        sum += arr[i];
        if(sum == sM)
            ans += cnt[i + 2];
    }
    cout << ans;
    return 0;
}
