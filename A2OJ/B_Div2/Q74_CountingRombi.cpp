#include<iostream>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int w, h;
    cin >> w >> h;
    long long int cnt = 0;
    for(int i = 2; i <= w; i += 2)
        for(int j = 2; j <= h; j += 2)
            cnt += (w - i + 1) * (h - j + 1);
    cout << cnt;
    return 0;
}
