#include<iostream>

typedef long long int lli;

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int n4 = n, n7 = n;
    bool flag = false;

    n4 = n / 4;
    n7 = 0;
    int r = n % 4;
    while(r % 7 != 0 && n4){
        r += 4;
        n4--;
    }
    if(r % 7 != 0){
        cout << -1;
        return 0;
    }
    else flag = true;
    n7 += r / 7;
    int q = n4 / 7;
    n4 = n4 % 7;
    n7 += q * 4;

    for(int i = 0; i < n4; i++)
        cout << 4;
    for(int i = 0; i < n7; i++)
        cout << 7;
    return 0;
}
