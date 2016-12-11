#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double r, x, y, _x, _y;
    cin >> r >> x >> y >> _x >> _y;
    double dist = sqrt((_x - x) * (_x - x) + (_y - y) * (_y - y));
    if(dist == 0){
        cout << "0";
        return 0;
    }
    int n = dist / (2 * r);
    dist -= n * 2 * r;
    if(dist <= 0)   cout << n;
    else cout << n + 1;
    return 0;
}
