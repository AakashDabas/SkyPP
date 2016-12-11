#include<iostream>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        int a, b;
        cin >> a >> b;
        int ab = a ^ b;
        int cnt = 0;
        while(ab){
            ab = ab & (ab - 1);
            cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
