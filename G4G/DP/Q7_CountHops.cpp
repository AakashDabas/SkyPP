#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        int n;
        cin >> n;
        long long int n1 = 4, n2 = 2, n3 = 1;
        for(int i = 4; i <= n; i++){
            long long int tmp = n1 + n2 + n3;
            n3 = n2;
            n2 = n1;
            n1 = tmp;
        }
        if(n > 2)
            cout << n1 << endl;
        else
            cout << n << endl;
    }
    return 0;
}
