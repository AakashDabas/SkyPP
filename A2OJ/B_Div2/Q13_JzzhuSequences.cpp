#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

#define lim 1000000007

inline long long int modulo(long long int x){
    if(x >= 0)   return x % lim;
    else    return lim + x % lim;
}
int main(){
    long long int n, arr[6];
    cin >> arr[0] >> arr[1] >> n;
    for(int i = 2; i < 6; i++)
        arr[i] = modulo(arr[i - 1] - arr[i - 2]);
    long long int ans = arr[(n - 1) % 6];
    cout << fixed << setprecision(0) << modulo(ans);
    return 0;
}
