#include<iostream>

using namespace std;

typedef long long int lli;

#define cmbnsn( x )    ( ((x) * ( x - 1 )) / 2 );

int main(){
    lli n, m;
    cin >> n >> m;
    lli max, min;
    max = cmbnsn(n - m + 1);
    lli f = n/m;
    min = (m - n % m) * cmbnsn(n / m);
    min += (n % m) * cmbnsn(1 + n / m);
    cout << min << " " << max;
    return 0;
}
