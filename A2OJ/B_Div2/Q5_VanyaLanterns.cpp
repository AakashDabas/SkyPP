#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    long double l;
    int n;
    cin >> n >> l;
    int arr[n];
    for(int i = 0; i < n; i++)  cin >> arr[i];
    sort(arr, arr + n);
    long double d = 0;
    for(int i = 0; i < n - 1; i++)
        if(arr[i + 1] - arr[i] > d) d = arr[i + 1] - arr[i];
    d /= 2;
    if(arr[0] > d)  d = arr[0];
    if(l - arr[n - 1] > d)  d = l - arr[n-1];
    cout << fixed << d;
    return 0;
}
