#include<iostream>

using namespace std;

typedef long long int lli;

int main(){
    lli n, k, d;
    cin >> n >> k >> d;
    lli cntD[n + 1], cntWD[n + 1];
    cntWD[0] = 1;
    cntD[0] = 0;
    for(int a = 0; a <= n; a++)
        for(int i = 1; i <= k; i++){
            if(a - i <= 0)
                continue;
            if(i < d)
                cntWD[a] += cntWD[a - i];
            else
                cntD[a] += cntWD[a - i];
            cntD[a] += cntD[a - i];
        }
    for(int i = 0; i < n; i++)
        cout << cntWD[i] << " ";
    cout << cntD[n] << "\n";
    return 0;
}

