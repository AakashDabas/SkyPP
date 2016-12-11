#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

#define print(number, times)    for(int itrL = 0; itrL < times; itrL++) cout << number << " ";

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++)  cin >> arr[i];
    vector<vector<int> > buffer(n, vector<int>(k, 0));
    int c = 0;
    while(1){
        bool key = false;
        for(int i = 0; i < n; i++)
            if(arr[i] > 0)  buffer[i][c]++, arr[i]--, key = true;
        if(!key)    break;
        c = (c + 1) % k;
    }

    for(int i = 0; i < k; i++){
        int mn = INT_MAX, mx = INT_MIN;
        for(int j = 0; j < n; j++){
            int tmp = buffer[j][i];
            mn = min(tmp, mn);
            mx = max(tmp, mx);
        }
        if(mx - mn > 1){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++)
            if(buffer[i][j])    print(j + 1, buffer[i][j]);
        cout << endl;
    }
    return 0;
}
