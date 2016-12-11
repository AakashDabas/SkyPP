#include<iostream>
#include <iomanip>
#include <cmath>

#define eql(a, b, epsi) (abs(a - b) < epsi)
#define di

using namespace std;

inline double dist(double p1[2], double p2[2]){
    return sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]));
}

inline double areaTri(double p1[2], double p2[2], double p3[2]){
    double d1 = dist(p1, p2), d2 = dist(p2, p3), d3 = dist(p3, p1);
    double s = (d1 + d2 + d3) / 2;
    return sqrt(s * (s - d1) * (s - d2) * (s - d3));
}

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin >> n;
    double arr[n][2];
    for (int i = 0; i < n; i++) 
        cin >> arr[i][0] >> arr[i][1];
    double mx = 0;
    for (int i1 = 0; i1 < n; i1++)
        for (int i2 = i1 + 1; i2 < n; i2++){
            double m, b, a1 = 0, a2 = 0;
            bool flag = false;
            if(arr[i1][0] - arr[i2][0] != 0){
                m = (arr[i1][1] - arr[i2][1]) / (arr[i1][0] - arr[i2][0]);
                b = arr[i1][1] - m * arr[i1][0];
                m *= -1;
                b *= -1;
            }
            else
                flag = true;
            for(int j = 0; j < n; j++){
                if(j != i1 && j != i2){
                    double aT = areaTri(arr[i1], arr[i2], arr[j]);
                    if(!flag && (arr[j][1] + m * arr[j][0] + b > 0))
                        a1 = max(a1, aT);
                    else if(!flag && (arr[j][1] + m * arr[j][0] + b < 0))
                        a2 = max(a2, aT);
                    else if(flag && arr[j][0] < arr[i1][0])
                        a1 = max(a1, aT);
                    else if(flag && arr[j][0] > arr[i1][0])
                        a2 = max(a2, aT);
                }
            }
            if(a1 != 0 && a2 != 0)
                mx = max(mx, a1 + a2);
        }

    cout << fixed << setprecision(30) << mx;
    return 0;
}
