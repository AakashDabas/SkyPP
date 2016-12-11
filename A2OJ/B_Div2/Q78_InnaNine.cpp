#include<iostream>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    char ch;
    int lst = 0, cnt = 1;
    unsigned long long int num = 1;
    while(cin >> ch){
        int d = ch - '0';
        if(lst + d == 9)
            cnt++;
        else if(cnt > 1){
            if(cnt % 2 == 1)
                num *= (cnt + 1) / 2;
            cnt = 1;
        }
        lst = d;
    }
    if(cnt > 1){
        if(cnt % 2 == 1)
            num *= (cnt + 1) / 2;
        cnt = 1;
    }
    cout << num;
    return 0;
}
