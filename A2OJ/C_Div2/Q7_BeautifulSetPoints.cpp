#include<iostream>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int mn = min(n, m);
    cout << mn + 1 << "\n";
    for(int i = 0; i <= mn; i++)
        cout << i << " " << mn - i << "\n";
    return 0;
}
