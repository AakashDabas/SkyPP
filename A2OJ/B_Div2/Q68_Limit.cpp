#include<iostream>
#include<cmath>

using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    ios :: sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int arr1[n + 1], arr2[m + 1];
    for(int i = 0; i < n + 1; i++)
        cin >> arr1[i];
    for(int i = 0; i < m + 1; i++)
        cin >> arr2[i];
    if(m > n)
        cout << "0/1";
    else if(n > m){
        if((float)arr1[0] / arr2[0] > 0)
            cout << "Infinity";
        else
            cout << "-Infinity";
    }
    else{
        int f = gcd(arr1[0], arr2[0]);
        if((float)arr1[0] / arr2[0] < 0)
            cout << "-";
        cout << abs(arr1[0] / f) << "/" << abs(arr2[0] / f);
    }
    return 0;
}
