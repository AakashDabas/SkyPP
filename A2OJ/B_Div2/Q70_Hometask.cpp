#include<iostream>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin >> n;
    int cnt[10] = {0};
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }
    if(cnt[0] == 0)
        cout << "-1";
    else{
        int s = 0;
        for(int i = 0; i <= 9; i++)
            s += cnt[i] * i;
        int m = s % 3;
        for(int k = 1; s % 3 != 0 && k <= 4; k++)
            for(int i = 1; i <= 9 && s % 3 != 0; i++){
                if((k == 1 || k == 2) && 
                        (i * k) % 3 == m && cnt[i] >= k)
                    s -= i * k, cnt[i] -= k;
                else if(k == 3 && i % 3 == 1 && cnt[i] >= 1)
                        s -= i, cnt[i]--, i = 1;
                else if(k == 4 && i % 3 == 2 && cnt[i] >= 1)
                    s -= i, cnt[i]--, i = 1;

            }

        if(s % 3 != 0){
            if(cnt[0])
                cout << 0;
            else
                cout << -1;
            return 0;
        }
        bool flag = false;

        for(int i = 9; i >= 0; i--)
            for(int j = 0; j < cnt[i] && (i != 0 ||flag); j++)
                flag = true, cout << i;
        if(!flag)
            cout << "0";
    }
    return 0;
}
