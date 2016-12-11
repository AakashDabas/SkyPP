#include<iostream>
#include <cmath>

typedef long long int lli;

using namespace std;

lli assign(double d){
    lli ans = d;
    if(abs(abs(d - ans) - 1) < 0.00000000001)
        return ans + 1;
    return ans;
}

lli power(lli b, lli n){
    lli ans = 1;
    for(int  i = 0; i < n; i++)
        ans *= b;
    return ans;
}

int main(){
    ios :: sync_with_stdio(false);
    lli h, w;
    cin >> h >> w;
    lli mxH = 0, mxW = 0;
    lli area = 0;
    for (int i = 0; power(2, i) <= h; i++) {
        lli hT = power(2, i);
        double w1, w2;
        lli  wF;
        w1 = hT / 0.8;
        w2 = hT / 1.25;
        if(w1 <= w && w2 <= w)
            wF = assign(w1);
        else if(w2 <= w && w1 > w)
            wF = assign(w);
        else
            continue;
        if((area < hT * wF) || (area == hT * wF && hT > mxH)){
            area = hT * wF;
            mxH = hT;
            mxW = wF;
        }
    }
    for (int i = 0; power(2, i) <= w && 1; i++) {
        lli wT = power(2, i);
        double h1, h2;
        lli  hF;
        h2 = wT * 0.8;
        h1 = wT * 1.25;
        if(h1 <= h && h2 <= h)
            hF = assign(h1);
        else if(h2 <= h && h1 > h)
            hF = assign(h);
        else
            continue;
        if((area < wT * hF) || (area == hF * wT && hF > mxH)){
            mxH = hF;
            mxW = wT;
        }
    }
    cout << mxH << " " << mxW;
    return 0;
}
