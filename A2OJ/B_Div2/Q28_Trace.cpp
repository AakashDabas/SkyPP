#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    double area, rad[n], pi;
    pi = 4 * atan(1.0);
    for(int i = 0; i < n; i++)  cin >> rad[i];
    sort(rad, rad + n);
    for(int i = n - 1; i >= 0; i -= 2){
        if(i > 0)   area += pi * (rad[i] * rad[i] - rad[i - 1]*rad[i - 1]);
        else    area += pi * rad[i] * rad[i];
    }
    cout << setprecision(20) << area;
    return 0;
}
