#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int itrS = 0; itrS < t; itrS++){
        int n;
        cin >> n;
        long long int arrTmp[n], arr[n], cnt = 0;
        for(int i = 0; i < n; i++){
            cin >> arrTmp[i];
            if(i > 0)
                arr[i] = arrTmp[i] - arrTmp[i - 1];
            else
                arr[i] = arrTmp[i];
        }
        for(int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;
            if(tmp <= arr[i])
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
