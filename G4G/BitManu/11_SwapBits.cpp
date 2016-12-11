#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        int x, p1, p2, n;
        cin >> x >> p1 >> p2 >> n;
        int c1 = x, c2 = x;
        c1 >>= p1;
        c1 <<= 31 - n;
        c1 >>= 31 - p2 - n;
        c2 >>= p2;
        c2 <<= 31 - n;
        c2 >>= 31 - p1 - n;
        x &= (!0 ^ 1 << (p1 + n)) | (1 << (p1 - 1));
        x |= c2;
        cout << x << "\n";
    }
    return 0;
}

