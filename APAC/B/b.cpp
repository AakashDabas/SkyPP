#include<iostream>
#include<map>
#include<cmath>

using namespace std;

typedef long long int lli;

map<int, int> mappyI, mappyJ;

lli expM(lli n, lli p, lli k){
    lli res = 1;
    n %= k;
    while(p){
        if(p & 1)
            res = (res * n) % k;
        p /= 2;
        n *= n;
        n %= k;
    }
    return res % k;
}

lli modu(lli a, lli b){
    if(a >= 0)
        return a % b;
    else 
        return b + a;
}

int main(){
    int t;
    lli m = 1000000007;
    cin >> t;
    for(int itrS = 1; itrS <= t; itrS++){
        lli a, b, n, k;
        cin >> a >> b >> n >> k;
        lli ref = min(n, k);
        lli cntRep = 0;
        mappyI.clear();
        mappyJ.clear();
        for(int i = 1; i <= ref; i++){
            int rI, rJ;
            rI = expM(i, a, k);
            rJ = expM(i, b, k);
            int inc = n / k;
            bool flag = false;
            if(n - k * (n / k))
                flag = true;
            if(i <= n % k || (n % k == 0 && i % k == 0) && flag)
                inc++;
            mappyI[rI] += inc;
            mappyJ[rJ] += inc;
            if((rI + rJ) % k == 0){
                cntRep += inc;
                cntRep %= m;
            }
        }

        lli cnt = 0;
        map<int, int> :: iterator itr = mappyI.begin();
        while(itr != mappyI.end()){
            int idx = (k - itr->first) % k;
            if(mappyJ[idx]){
                cnt += (itr->second * mappyJ[idx]) % m;
                cnt %= m;
            }
            itr++;
        }

        cout << "Case #" << itrS << ": " << modu(cnt - cntRep, m) << "\n";
    }
    return 0;
}
