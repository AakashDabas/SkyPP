#include<iostream>

#define inRange(i, j)   (i >= 0 && i < n && j >= 0 && j < m)

using namespace std;

int main(){
    int n, m, cnt = 0;
    cin >> n >> m;
    char arr[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(arr[i][j] != 'W')    continue;
            i--;
            if(inRange(i, j) && arr[i][j] == 'P'){
                cnt++;
                i++;
                continue;
            }
            i += 2;
            if(inRange(i, j) && arr[i][j] == 'P'){
                cnt++;
                i--;
                continue;
            }
            i--;
            j--;
            if(inRange(i, j) && arr[i][j] == 'P'){
                cnt++;
                j++;
                continue;
            }
            j += 2;
            if(inRange(i, j) && arr[i][j] == 'P'){
                cnt++;
                j--;
                continue;
            }
            j--;
        }
    cout << cnt;
    return 0;
}
