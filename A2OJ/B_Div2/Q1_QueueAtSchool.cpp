#include<iostream>
#include<vector>

using namespace std;

void shift(char *arr, int n){
    vector<char> tmp(n, 'G');
    for(int i = 0; i < n; i++)
        tmp[i] = arr[i];
    for(int i = 0; i < n - 1; i++)
        if(arr[i] == 'B' && arr[i + 1] == 'G'){
            tmp[i + 1] = 'B';
            tmp[i] = 'G';
        }
    for(int i = 0; i < n; i++)
        arr[i] = tmp[i];
}

int main(){
    int n, t;
    cin >> n >> t;

    char arr[n];
    cin >> arr;

    for(int i = 0; i < t; i++)
        shift(arr, n);
    for(int i = 0; i < n; i++)  cout << arr[i];
    return 0;
}
