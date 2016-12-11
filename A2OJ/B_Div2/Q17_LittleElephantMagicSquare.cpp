#include<iostream>

using namespace std;

int main(){
    float mat[3][3];
    float arr[3];
    arr[0] = arr[1] = arr[2] = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            cin >> mat[i][j];
            arr[i] += mat[i][j];
        }
    mat[0][0] = (arr[1] + arr[2] - arr[0]) / 2;
    mat[1][1] = (arr[0] + arr[2] - arr[1]) / 2;
    mat[2][2] = (arr[0] + arr[1] - arr[2]) / 2;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}
