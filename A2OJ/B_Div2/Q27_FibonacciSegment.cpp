#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int cnt = 2;
    int mx = 2;

    for(int i = n - 1; i >= 2; i--){
        if(arr[i] == arr[i - 1] + arr[i - 2])   cnt++;
        else    cnt = 2;
        if(cnt > mx)    mx = cnt;
    }

    if(n >= 2)
        cout << mx;
    else    cout << 1;
    return 0;
}
