#include<iostream>
#include<string>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    string str;
    cin >> str;
    cout << str;
    for(int i = str.length() - 1; i >= 0; i--)
        cout << str[i];
    return 0;
}
