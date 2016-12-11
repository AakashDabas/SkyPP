#include<iostream>

typedef long long int lli;

using namespace std;

lli fib(lli n){
    if(n == 1)
        return 1;
    else if(n == 0)
        return 0;
    else if(n % 2 == 0)
        return (2 * fib(n / 2 - 1) + fib(n / 2)) * fib(n / 2);
    else{
        lli k = (n + 1) / 2;
        return fib(k) * fib(k) + fib(k - 1) * fib(k - 1);
    } 
}

int main(){
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        int n;
        cin >> n;
        cout << (1 << n) - fib(n + 2) << "\n";
    }
    return 0;
}
