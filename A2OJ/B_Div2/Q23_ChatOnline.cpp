#include<iostream>
#include<vector>

using namespace std;

int main(){
    int p, q, l, r, cnt = 0;
    cin >> p >> q >> l >> r;
    vector<int> arr1(1001, 0), arr2(1001, 0);

    for(int i = 0; i < p; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        for(int j = tmp1; j <= tmp2; j++)
            arr1[j] = 1;
    }

    for(int i = 0; i < q; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        for(int j = tmp1; j <= tmp2; j++)
            arr2[j] = 1;
    }

    for(int i = l; i <= r; i++){
        for(int j = 0; j <= 1000 - i; j++)
            if(arr2[j] && arr1[i + j]){
                cnt++;
                break;
            }
    }
    cout << cnt;

    return 0;
}
