#include<iostream>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        if(n & n >> 1)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}
