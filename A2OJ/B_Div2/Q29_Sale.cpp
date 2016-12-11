#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int sum = 0, itr = 0;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < n && itr < m; i++)
        if(arr[i] < 0)  sum -= arr[i], itr++;
    cout << sum;
    return 0;
}
