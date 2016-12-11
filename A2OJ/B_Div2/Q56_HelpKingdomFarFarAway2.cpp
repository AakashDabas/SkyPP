#include<iostream>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    string str;
    cin >> str;
    int pD = 0;
    bool flag = false;
    for(pD = 0; pD < str.length() && str[pD] != '.'; pD++);
    if(str[0] == '-')
        flag = true;
    if(flag)
        cout << "(";
    cout << "$";
    for(int i = 0; i < pD; i++){
        if(str[i] != '-'){
            cout << str[i];
            if(pD - i - 1 != 0 && (pD - i - 1) % 3 == 0)
                cout << ",";
        }
    }
    cout << ".";
    for(int i = 1; i <= 2; i++)
        if(pD + i < str.length())
            cout << str[pD + i];
        else
            cout << "0";
    if(flag)
        cout << ")";
    return 0;
}
