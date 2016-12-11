#include<iostream>
#include<cmath>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    if(n - m > 1 || m - 2 * n > 2){
        cout << -1;
        return 0;
    }
    while(n || m){
        if(m - n - 2 >= 0){
            cout << "11";
            m -= 2;
        }
        else if(abs(m - n - 1) <= 1){
            cout << "1";
            m--;
        }
        if(n){
            cout << 0;
            n--;
        }
    }
    return 0;
}
