#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<vector<int> > mat1, mat2;
    int m, n;
    cin >> m >> n;
    mat1.resize(m, vector<int>(n, 1));
    mat2.resize(m, vector<int>(n, 1));
    for(int i =0; i < m; i++)
        for(int j = 0; j < n; j++){
            cin >> mat1[i][j];
            if(mat1[i][j] == 0){
                for(int k = 0; k < m; k++)
                    mat2[k][j] = 0;
                for(int k = 0; k < n; k++)
                    mat2[i][k] = 0;
            }
        }
    for(int i =0; i < m ; i++)
        for(int j = 0; j < n; j++){
            if(mat1[i][j] == 1){
                bool flag = false;
                for(int k = 0; k < m; k++)
                    if(mat2[k][j] == 1) flag = true;
                for(int k = 0; k < n; k++)
                    if(mat2[i][k] == 1) flag = true;
                if(!flag){
                    cout << "NO";
                    return 0;
                }
            }
        }
    cout << "YES\n";
    for(int i =0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout << mat2[i][j] << " ";
        cout << endl;
    }
    return 0;
}
