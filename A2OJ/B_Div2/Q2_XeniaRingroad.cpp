#include<iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    long long int arr[m];
    long long int pos = 1;
    long long int t = 0;
    for(int i = 0; i < m; i++){
        int val;
        cin >> val;
        if( val >= pos) t += val - pos;
        else   t += n - pos + val;
        pos = val;
    }
    cout << t;
    return 0;
}
