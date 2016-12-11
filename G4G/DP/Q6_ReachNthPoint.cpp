#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        int n;
        cin >> n;
        long long int n1 = 0, n2 = 1;
        for(int i = 0; i <= n; i++){
            long long int tmp = n1 + n2;
            n2 = n1;
            n1 = tmp;
        }
        cout << n1 << endl;

    }
    return 0;
}
