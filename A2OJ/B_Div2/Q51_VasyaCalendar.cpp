#include<iostream>

using namespace std;

int main(){
    int d;
    cin >> d;
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(i != n - 1)
            ans += d - tmp;
    }
    cout << ans;
    return 0;
}
