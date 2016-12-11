#include<iostream>
#include<cmath>
#include<climits>

#define check(nu, de) abs(a * de - b * nu)

using namespace std;

int main(){
    long long int x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    double delta = INT_MAX;
    long long int aF = 0, bF = 1;
    for(int i = 1; i <= n; i++){
        int a = 0, b = i;
        int l = b * x / i;
        if(check(l, i) <= check(l + 1, i))
            a = l;
        if(abs(a / b - x / y) < delta){
            delta = abs(a / b - x / y);
            aF = a;
            bF = b;
        }
    }
    cout << aF << "/" << bF;
    return 0;
}
