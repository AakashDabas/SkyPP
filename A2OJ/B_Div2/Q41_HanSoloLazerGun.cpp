#include<iostream>
#include<map>

using namespace std;

int main(){
    int n, x, y, dxz = 0;
    cin >> n >> x >> y;
    map<double, bool> flag;
    for(int i = 0; i < n; i++){
        int xT, yT;
        cin >> xT >> yT;
        double dx = xT - x, dy = yT - y;
        if(dx != 0){
            flag[dy / dx] = true;
            //cout << dy << " -> " << dx << " : " << xT << " , " << yT << endl;
        }
        else
            dxz = 1;
    }
    cout << flag.size() + dxz;
    return 0;
}
