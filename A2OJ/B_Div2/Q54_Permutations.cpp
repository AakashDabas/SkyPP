#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < 2 * n; i++){
        if(i < 2 * k){
            cout << i + 2 << " " << i + 1 << " ";
            i++;
        }
        else
            cout << i + 1 << " ";
    }
    return 0;
}
