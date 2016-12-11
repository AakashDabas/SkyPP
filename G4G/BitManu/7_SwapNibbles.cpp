#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        int n;
        cin >> n;
        int ans = 0, f = 1;
        for(int i = 0; i < 4; i++){
            if(n & 1)
                ans += f;
            n /= 2;
            f *= 2;
        }
        ans = ans << 4;
        ans += n;
        cout << ans << "\n";
    }
    return 0;
}
