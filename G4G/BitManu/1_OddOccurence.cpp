#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int tmp, idx = 0;
            cin >> tmp;
            ans ^= tmp;
        }
        cout << ans << "\n";
    }
    return 0;
}
