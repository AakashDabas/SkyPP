#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double ans = 0;
    double prod = a / b;
    while(prod * (1 - c / d) * (1 - a / b)  > 0.000000000000000000005){
        //cout << fixed << setprecision(20) << prod << endl;
        ans += prod;
        prod *= (1 - c / d) * (1 - a / b) ;
    }
    cout << fixed << setprecision(20) << ans;
    return 0;
}
