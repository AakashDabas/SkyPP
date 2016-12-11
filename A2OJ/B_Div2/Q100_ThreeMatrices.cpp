#include<iostream>
#include <iomanip>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<double> > arr(n, vector<double>(n));
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    vector<vector<double> > arrT(n, vector<double>(n));
    arrT = arr;
    for(int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            double tmp = arrT[i][j];
            arrT[i][j] = arrT[j][i];
            arrT[j][i] = tmp;
        }
    vector<vector<double> > sym(n, vector<double>(n)), sksym(n, vector<double>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            sym[i][j] = 0.5 * (arr[i][j] + arrT[i][j]);
            sksym[i][j] = 0.5 * (arr[i][j] - arrT[i][j]);
        }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << fixed << setprecision(20) << sym[i][j] << " ";
        cout << "\n";
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << fixed << setprecision(20) << sksym[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
