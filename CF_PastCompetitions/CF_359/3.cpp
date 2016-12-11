#include<iostream>

typedef long long int lli;

using namespace std;

bool chk(){
}

lli convD7(lli n, int &d){
    lli ans = 0, prod = 1;
    d = 0;
    while(n){
        ans += (n % 7) * prod;
        prod *= 10;
        n /= 7;
        d++;
    }
    return ans;
}

int main(){
    lli n, m;
    cin >> n >> m;
    int d1, d2;
    lli hr = convD7(n, d1);
    lli mn = convD7(m, d2);
    if(d1 + d2 > 7)
        cout << 0;
    else{

    }
    return 0;
}
