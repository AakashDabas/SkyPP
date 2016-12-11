#include<iostream>

using namespace std;

int main(){
    int na, ma, nb, mb;
    cin >> na >> ma;
    long long int arr1[na][ma];
    for(int i = 0; i < na; i++){
        char in[ma];
        cin >> in;
        for(int j = 0; j < ma; j++)
            arr1[i][j] = in[j] - '0';
    }
    cin >> nb >> mb;
    long long int arr2[nb][mb];
    for(int i = 0; i < nb; i++){
        char in[mb];
        cin >> in;
        for(int j = 0; j < mb; j++)
            arr2[i][j] = in[j] - '0';
    }

    int mx = 0;
    int x = 0, y = 0;
    for(int i = -na; i <= na || i <= nb; i++){
        for(int j = -ma; j <= ma || j <= mb; j++){
            int cnt = 0;
            for(int i1 = 0; i1 < na; i1++){
                for(int i2 = 0; i2 < ma; i2++){
                    if(i1 + i >= 0 && i2 + j >= 0 && i1 + i < nb && i2 + j < mb){
                        if(arr1[i1][i2] && arr2[i1 + i][i2 + j])
                            cnt ++;
                    }
                }
            }
            if(cnt > mx){
                mx = cnt;
                x = i;
                y = j;
            }
        }
    }
    cout << x << " " << y;
    return 0;
}
