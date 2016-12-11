#include<iostream>
#include<map>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    map<string, string> mappy;
    for(int i = 0; i < m; i++){
        string str1, str2;
        cin >> str1 >> str2;
        if(str1.length() > str2.length())   mappy[str1] = str2;
        else    mappy[str1] = str1;
    }
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        cout << mappy[tmp] << " ";
    }
    return 0;
}
