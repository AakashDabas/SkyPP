#include<iostream>
#include<map>

using namespace std;

int main(){
    string str1, str2;
    int ans = 0;
    cin >> str1 >> str2;
    map<char, int> base;
    for(int i = 0; i < str1.length(); i++)
        base[str1[i]]++;
    for(int i = 0; i < str2.length(); i++){
        if(base.find(str2[i]) == base.end()){
            cout << "-1";
            return 0;
        }
        else if(base[str2[i]] > 0){
            ans++;
            base[str2[i]]--;
        }
    }
    cout << ans;
    return 0;
}
