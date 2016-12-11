#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(){
    ios :: sync_with_stdio(false);
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double d = dist(x1, y1, x2, y2);
    double r = d - r1 - r2;
    if(r < 0)
        r = max(r1, r2) - d - min(r1, r2);
    if(r < 0)
        cout << 0;
    else
        cout << fixed << setprecision(20) << r / 2;
    return 0;
}
