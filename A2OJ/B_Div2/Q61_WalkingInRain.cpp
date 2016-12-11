#include<iostream>
#include<cmath>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int mx = 1001;
    for(int i = n - 2; i > 1; i--){
        mx = min(mx, max(arr[i], arr[i - 1]));
    }
    cout << min(min(arr[0], arr[n - 1]), mx);
    return 0;
}
