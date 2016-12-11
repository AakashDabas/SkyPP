#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    long long int n, m;
    cin >> n >> m;
    long long int arr[m];
    for(int i = 0; i < m; i++)  cin >> arr[i];
    sort(arr, arr + m);
    long long int cnt = 0;
    for(int i = 0; i < m - 1; i++){
        if(arr[i] + 1 == arr[i + 1])    cnt++;
        else    cnt = 0;
        if(cnt == 2 || arr[i] == 1 || arr[i] == n){
            cout << "NO";
            return 0;
        }
    }
    if(arr[m - 1] == 1 || arr[m - 1] == n){
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}
