#include<iostream>
#include<stdio.h>
#include<string>

typedef long long int lli;

using namespace std;

int main(){
    string str;
    lli a, b;
    cin >> str >> a >> b;
    int len = str.length();
    lli r = 0, factor = 1;
    bool flag[len] = {0};
    for(int i = len - 1; i >= 0; i--){
        r = (str[i] - '0') * factor + r;
        r %= b;
        if(r == 0)
            flag[i] = true;
        factor *= 10;
        factor %= b;
    }

    r = 0;
    for(int i = 0; i < len - 1; i++){
        r = r * 10 + str[i] - '0';
        r %= a;
        if(r == 0 && str[i + 1] != '0' && flag[i + 1]){
            cout << "YES\n";
            for(int j = 0; j < len; j++){
                cout << str[j];
                if(j == i)
                    cout << endl;
            }
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
