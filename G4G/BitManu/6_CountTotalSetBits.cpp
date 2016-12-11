#include<iostream>

using namespace std;

int fact[10];

int main(){
    fact[0] = 1;
    for(int i = 1; i <= 10; i++)
        fact[i] = fact[i - 1] * i;
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        int n;
        cin >> n;
        int dig = 0;
        long long int ans = 0;
        for(int tmp = n; tmp; tmp /= 2, dig++);
        int uL = 0;
        for(int i = 1; i < dig; i++){
            ans += i * fact[dig - 1] / (fact[i] * fact[dig - 1 - i]);
            uL = uL << 1;
            uL++;
        }
        while(uL < n){
            uL++;
            int tmp = uL;
            while(tmp){
                tmp = tmp & (tmp - 1);
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
