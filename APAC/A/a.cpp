#include<iostream>
#include<cmath>

typedef long long int lli;

lli c(lli n){
    return n * (n - 1) / 2;
}

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        cout << "Case #" << itrS + 1 << ": ";
        lli l, r;
        cin >> l >> r;
        lli n = min(l, r);
        if(n == 1)
            cout << "1\n";
        else
            cout << c(n) + n << "\n";
    }
    return 0;
}
