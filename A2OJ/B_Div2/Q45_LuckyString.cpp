#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int k = 0;
    for(int i = 0; i < n; i++){
        cout << (char)('a' + k);
        k++;
        k %= 4;
    }
    return 0;
}
