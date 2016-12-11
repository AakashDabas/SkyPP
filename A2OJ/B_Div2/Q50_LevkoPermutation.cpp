#include<iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int ans[n];
    for(int i = 1; i < k + 1; i++){
        ans[i] = i + 1;
        if(i == n){
            cout << "-1";
            return 0;
        }
    }
    for(int i = k + 1; i < n; i++)
        ans[i] = (i + 1) % n + 1;
    if(k == n - 1)
        ans[0] = 1;
    else
        ans[0] = k + 2;
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}
