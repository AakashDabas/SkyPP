#include<iostream>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin >> n;
    long long int ans = 0;
    for(int i = 0; i < n; i++){
        long long int tmp;
        cin >> tmp;
        ans += tmp + i * (tmp - 1);
    }
    cout << ans;
    return 0;
}
