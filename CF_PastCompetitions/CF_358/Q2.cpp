#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int idx = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] >= idx)
            idx++;
    }
    cout << idx;
    return 0;
}
