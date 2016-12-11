#include<iostream>

using namespace std;

int main(){
    int n, d, cntMx = 0, cntC = 0;
    cin >> n >> d;
    for(int i = 0; i < d; i++){
        int cntT = 0;
        for(int j = 0; j < n; j++){
            char ch;
            cin >> ch;
            if(ch == '1')
                cntT++;
        }
        if(cntT < n)
            cntC++;
        else
            cntC = 0;
        if(cntC > cntMx)
            cntMx = cntC;
    }
    cout << cntMx;
    return 0;
}
