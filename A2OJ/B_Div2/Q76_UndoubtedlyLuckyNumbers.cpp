#include<iostream>
#include<deque>
#include<cmath>

typedef long long int lli;

using namespace std;

lli power(lli b, lli n){
    lli ans = 1;
    for(int i = 0; i < n; i++)
        ans *= b;
    return ans;
}

lli getLen(lli n){
    int len = 0;
    while(n){
        len++;
        n /= 10;
    }
    return len;
}

lli formMaxNum(int d1, int d2, lli ref){
    lli ans = 0;
    int len = 0;
    while(len < 10){
        ans *= 10;
        ans += d2;
        len++;
        if(ans > ref){
            ans /= 10;
            len--;
            break;
        }
    }
    //cout << ans << endl;
    for(int i = len - 1; i >= 0; i--){
        lli tmp = ans + (d1 - d2) * power(10, i);
        if(tmp <= ref)
            ans = tmp;
        //cout << tmp << endl;
    }
    return ans;
}

lli getCount(lli n, int d1, int d2){
    int idx = 0;
    int cnt = 0;
    while(n){
        if(!d2 && !(n / 10))
            break;
        if(n % 10 == d1)
            cnt += power(2, idx);
        n /= 10;
        idx++;
    }
    return cnt + 1;
}

int main(){
    ios :: sync_with_stdio(false);
    lli n;
    cin >> n;
    lli cnt = 0;
    for(int i = 0; i <= 8; i++)
        for(int j = i + 1; j <= 9; j++){
            lli mx = formMaxNum(j, i, n);
            if(mx == 0)
                continue;
            cnt += getCount(mx, j, i);
            //cout << j << " " << i << " " << mx << " " << cnt << " ";
            for(int k = getLen(mx) - 1; k > 0; k--){
                if(i != 0)
                    cnt += power(2, k) - 2;
                else if(k)
                    cnt += power(2, k - 1) - 1;
            }
            if(i != 0){
                lli mxTmp = formMaxNum(j, j, n);
                cnt -= ((getLen(mxTmp) == getLen(mx)) && (mxTmp <= mx))? 2 : 1;
            }
            else{
                lli mxTmp = formMaxNum(j, j, n);
                cnt -= ((getLen(mxTmp) == getLen(mx)) && (mxTmp <= mx))? 1 : 0;
            }
            //cout << cnt << endl;
        }
    //cout << cnt << endl;
    for(int i = 1; i <= 9; i++){
        int x = getLen(formMaxNum(i, i, n));
        //cout << x << " ";
        cnt += getLen(formMaxNum(i, i, n));
    }
    cout << cnt;
    return 0;
}
