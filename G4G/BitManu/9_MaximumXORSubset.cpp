#include<iostream>

using namespace std;

int msb(int n){
    for(int i = 29; i >= 0; i--)
        if(n >= (2 << i))
            return i;
    return 0;
}

int main(){
    ios :: sync_with_stdio(false);
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        int n;
        cin >> n;
        int arr[31] = {0}, in[n];
        for(int i = 0; i < n; i++)
            cin >> in[i];
        for(int idx = 29; i >= 0; i--){
            
        int ans = 0; 
        for(int i = 0; i <= 31; i++)
            ans ^= arr[i], cout << arr[i] << " ";
        cout << ans << "\n";
    }
    return 0;
}
