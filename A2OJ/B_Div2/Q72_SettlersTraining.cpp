#include<iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int cnt[k + 1] = {0}, cntNon = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
        if(tmp != k)
            cntNon++;
    }

    int coins = 0;
    while(cntNon){
        bool mrk[k + 1] = {false};
        for(int i = 1; i < k; i++)
            if(cnt[i]){
                cnt[i]--;
                mrk[i + 1] = true;
                if(i == k - 1)
                    cntNon--;
            }
        for(int i = 1; i <= k; i++)
            if(mrk[i])
                cnt[i]++;
        for(int i = 1; i <= k && 0; i++)
            cout << cnt[i] << " ";
        //cout << endl;
        coins++;
    }

    cout << coins;

    return 0;
}
