#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    double l, d, v, g, r;
    cin >> l >> d >> v >> g >> r;
    double t = d / v;
    t -= (int)(t / (g + r)) * (g + r);
    if(t < g)
        cout << fixed << setprecision(20) << l / v;
    else
        cout << fixed << setprecision(20) << l / v + g - t + r;
    return 0;
}
