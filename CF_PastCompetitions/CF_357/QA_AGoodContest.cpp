#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    cin >> n;
    bool flag = false;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        int a, b;
        cin >> a >> b;
        if(a >= 2400 && b > a)
            flag = true;
    }
    if(flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
