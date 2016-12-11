#include<iostream>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int m, s;
    cin >> m >> s;
    if(m * 9 < s || (s == 0 && m > 1)){
        cout << -1 << " " << -1;
        return 0;
    }
    int sT = s, nT = m, ref = 1;
    while(nT){
        if(nT == 1){
            cout << sT;
            break;
        }
        else
            for(int i = ref; i <= 9; i++){
                if((nT - 1) * 9 >= sT - i){
                    cout << i;
                    nT--;
                    sT -= i;
                    break;
                } 
            }
        if(ref)    ref = 0;
    }
    cout << " ";
    sT = s, nT = m, ref = 1;
    while(nT){
        if(nT == 1){
            cout << sT;
            nT--;
        }
        else
            for(int i = 9; i >= ref; i--){
                if((nT - 1) * 9 >= sT - i && sT - i >= 0){
                    cout << i;
                    nT--;
                    sT -= i;
                    break;
                } 
            }
        if(ref)    ref = 0;
    }
    return 0;
}
