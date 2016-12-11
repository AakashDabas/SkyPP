#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int> > arr(m + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <=n; j++)
            cin >> arr[i][j];

    for(int j = 1; j <= n; j++)
        for(int i = 1; i <= m; i++){
            arr[i][j] += max(arr[i - 1][j], arr[i][j -1]);
        }

    for(int i = 1; i <= m; i++)
        cout << arr[i][n] << " ";
    return 0;
}
