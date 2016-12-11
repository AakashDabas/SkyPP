#include<iostream>

using namespace std;

int cnt(long long int n){
    ios :: sync_with_stdio(false);
    int ans = 0;
    while(n){
        n = n & (n - 1);
        ans++;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        long long int n;
        cin >> n;
        bool flag = true;
        for(int j = 1; j <= 31 && flag; j++){
            if(n - j > 0 && n - j + cnt(n - j) == n)
                flag = false;
        }
        if(flag)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
