#include<iostream>

using namespace std;

int main(){
    int m;
    cin >> m;
    bool arr[5][5] = {0};
    for(int i = 0; i < m ; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        arr[a][b] = arr[b][a] = true;
    }

    //To brute force
    for(int i = 0; i < 5; i++)
        for(int j = i + 1; j < 5; j++)
            for(int k = j + 1; k < 5; k++)
                if((arr[i][j] && arr[j][k] && arr[k][i]) || (!arr[i][j] && !arr[j][k] && !arr[k][i])){
                    cout << "WIN";
                    return 0;
                }
    cout << "FAIL";
    return 0;
}
