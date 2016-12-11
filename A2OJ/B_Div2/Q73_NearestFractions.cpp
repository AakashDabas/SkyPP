#include<iostream>
#include<stdio.h>
#include<climits>
#include<cmath>

typedef long long int lli;

using namespace std;

double delta = INT_MAX;
lli aF = 0, bF = 1;
double x, y, n;

void check(double a, double b){
    double deltaTmp = abs(a / b - x / y);
    if(deltaTmp <= delta || abs(deltaTmp - delta) < 0.0000000000000001){
        if(abs(deltaTmp - delta) < pow(10, -15)){
            if(b < bF){
                aF = a;
                bF = b;
            }
            if(b == bF)
                if(a < aF){
                    aF = a;
                    bF = b;
                }
        }
        else if(abs(deltaTmp - delta) > pow(10, -15)){
            delta = deltaTmp;
            aF = a;
            bF = b;
            //cout << aF << "/" << bF << endl;
        }
    }
}

int main(){
    ios :: sync_with_stdio(false);
    delta = INT_MAX;
    aF = 0;
    bF = 1;
    cin >> x >> y >> n;
    for(double i = 1; i <= n; i++){
        lli a = 0, b = (x / y) + 1;
        b *= i;
        //cout << b << "->" ;
        //To find the minimum for given denominator
        lli mid = (a + b) / 2;
        while(a <= b && mid / i != x / y){
            //cout << a << " " << b << " " << mid << endl;
            check(a, i);
            check(b, i);
            check(mid, i);
            if( mid / i > x / y)
                b = mid - 1;
            else
                a = mid + 1;
            mid = (a + b) / 2;
        }
        check(a, i);
        check(b, i);
        check(mid, i);
        //cout << a << "~" << b << endl;
        //cout << mid << "/" << i << endl;
    }
    cout << aF << "/" << bF << endl;
    return 0;
}
