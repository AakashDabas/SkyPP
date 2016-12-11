#include<iostream>
#include<algorithm>

typedef long long int lli;

using namespace std;

int main(){
    lli arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    lli ans = 0;
    lli t1 = max(arr[2], arr[1] + arr[0]) - min(arr[2], arr[1] + arr[0]);
    lli t2 = min(arr[2], arr[1] + arr[0]);
    if(t1 <= t2){
        ans += t1;
        t2 -= ans;
    }
    else{
        ans += t2;
        t2 = 0;
    }
    lli t3 = t2 * 2 / 3;
    t2 -= t3 * 3;
    ans += t3;
    //cout << t2 << endl;
    if(t2 % 3 == 2)
        ans++;
    cout << ans;
    return 0;
}
