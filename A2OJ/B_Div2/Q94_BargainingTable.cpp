#include <iostream>
#include<cmath>

using namespace std;

int main(){
    int n, m, mx = 0;
    cin >> n >> m;
    int arr[n + 1][m + 1] = {0};
    int cnt[n + 1][m + 1];
    for(int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++) {
            cnt[i][j] = 0;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            char tmp;
            cin >> tmp;
            if(tmp == '0'){
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = 1;
                cnt[i][j] = 1;
            }
            cnt[i][j] += cnt[i][j - 1] + cnt[i - 1][j] - cnt[i - 1][j - 1];
        }
    for(int i = 1; i < n + 1 && 0; i++){
        for (int j = 1; j < m + 1; j++)
            cout << cnt[i][j] << " ";
        cout << endl;
    }
    for (int i1 = 1; i1 <= n; i1++) {
        for (int j1 = 1; j1 <= m; j1++) {
            for (int i2 = i1; i2 <= n; i2++) {
                for (int j2 = j1; j2 <= m; j2++) {
                    int len = abs(i1 - i2);
                    int wid = abs(j1 - j2);
                    int peri = 0;
                    if(arr[i1][j1] == 0)
                    if(cnt[i2][j2] - cnt[i2][j1 - 1] - cnt[i1 - 1][j2] + cnt[i1 - 1][j1 - 1]== 0)
                        peri = 2 * (len + wid) + 4;
                    if(peri > mx){
                        mx = peri;
                        //cout << "i1 :"  << i1 << " j1: " << j1 << " i2: " << i2 << " j2: " << j2 << " l: " << len << " w: " << wid << " " << peri << endl;
                    }
                }
            }
        }
    }
    cout << mx;
    return 0;
}
