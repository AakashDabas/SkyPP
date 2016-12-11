#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin >> n;
    double vb, vs;
    cin >> vb >> vs;
    double tmp;
    cin >> tmp;
    double arr[n - 1];
    for(int i = 0; i < n - 1; i++){
        cin >> arr[i];
    }
    double mnT = INT_MAX, mnD = INT_MAX;
    double x, y;
    int idx = 0;
    cin >> x >> y;
    for(int i = 0; i < n - 1; i++){
        double t = arr[i] / vb;
        double dist = sqrt((x - arr[i]) * (x - arr[i]) + y * y);
        t += dist / vs;
        if(t < mnT){
            mnT = t;
            mnD = dist;
            idx = i;
        }
        else if(t == mnT && mnD > dist){
            mnT = t;
            mnD = dist;
            idx = i;
        }
    }
    cout << idx + 2;
    return 0;
}
