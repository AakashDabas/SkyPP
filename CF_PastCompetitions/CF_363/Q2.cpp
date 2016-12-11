#include<iostream>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n, m, cnt = 0;
    cin >> n >> m;
    char mat[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
           cin >> mat[i][j]; 
           if(mat[i][j] == '*')
               cnt++;
        }
    if(cnt > n + m){
        cout << "NO\n";
        return 0;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == '*'){
                int cntT = 0;
                for(int iT = 0; iT < n; iT++)
                    if(mat[iT][j] == '*')
                        cntT++;
                for(int jT = 0; jT < m; jT++)
                    if(mat[i][jT] == '*')
                        cntT++;
                if(cntT == cnt + 1){
                    cout << "YES\n" << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
    cout << "NO\n";
    return 0;
}
