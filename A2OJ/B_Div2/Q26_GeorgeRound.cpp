#include<iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++)  cin >> arr[i];
    int itr = 0;
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        if(arr[itr] <= tmp && itr < n) itr++;
    }
    cout << n - itr;
    return 0;
}
