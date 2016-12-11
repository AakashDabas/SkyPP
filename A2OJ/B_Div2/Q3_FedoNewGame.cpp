#include<iostream>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int arr[m + 1];
    for(int i = 0; i <= m; i++)
        cin >> arr[i];

    int frnd = 0;
    for(int i = 0; i < m; i++){
        int tmp = arr[m];
        tmp ^= arr[i];
        //cout << "@" << arr[i] << arr[m] << endl;
        int cnt = 0;
        while(tmp){
            if(tmp & 1) cnt++;
            tmp /= 2;
        }
        if(cnt <= k)    frnd++;
    }
    cout << frnd;
    return 0;
}
