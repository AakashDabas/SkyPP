#include<iostream>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        long long int l, r, ans = 0;
        cin >> l >> r;
        for(int i = 31; i >= 0; i--){
            if((l & 1 << i) == (r & 1 << i))
                ans |= l & 1 << i;
            else
                break;
        }
        cout << ans << "\n";
    }
    return 0;
}
