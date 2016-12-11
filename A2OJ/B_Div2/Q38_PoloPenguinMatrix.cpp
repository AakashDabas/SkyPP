#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int n, m, d;
    cin >> n >> m >> d;

    int len = n * m;
    int arr[len], arrSrtd[len];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i * m + j];

    sort(arr, arr + len);
    int cnt = 0;

    if(len % 2 == 1 || 1){
        int ref = arr[len / 2];
        for(int i = 0; i <= (len - 1) / 2; i++){
            if((ref - arr[i]) % d == 0){
                cnt += (ref - arr[i]) / d;
                //cout << i << "Even : cnt : " << (ref - arr[i]) / d << endl;
            }
            else{
                cout << "-1";
                return 0;
            }
            if((ref - arr[len - i - 1]) % d == 0){
                cnt += (arr[len - i - 1] - ref) / d;
                //cout << len - i - 1 << " Element is : " << arr[len - i - 1] << "  Odd : cnt : " << (arr[len - i - 1] - ref) / d << endl;
            }
            else{
                cout << "-1";
                return 0;
            }
        }
    }
    cout << cnt;

    return 0;
}
