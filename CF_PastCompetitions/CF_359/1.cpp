#include<iostream>

typedef long long int lli;

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    lli n, x;
    cin >> n >> x;
    lli cnt = 0;
    for(int i = 0; i < n; i++){
        char ch;
        lli val;
        cin >> ch >> val;
        if(ch == '+')
            x += val;
        else if(ch == '-'){
            if(x >= val)
                x -= val;
            else
                cnt++;
        }
    }
    cout << x << " " << cnt;
    return 0;
}
