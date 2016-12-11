#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string getStr(string str){
    string out;
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            out += str[i];
        else if(str[i] >= 'A' && str[i] <= 'Z')
            out += str[i] - 'A' + 'a';
    }
    return out;
}

bool cmp(string a, string b){
    return a.length() > b.length();
}

int main(){
    ios :: sync_with_stdio(false);
    string str[3];
    cin >> str[0] >> str[1] >> str[2];
    str[0] = getStr(str[0]);
    str[1] = getStr(str[1]);
    str[2] = getStr(str[2]);
    sort(str, str + 3, cmp); // To rule out the probability of substring
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string test;
        cin >> test;
        test = getStr(test);
        bool flag[3] = {false};
        int ref = 0;
        for(int i = 0; i < 3; i++){
            bool flag2 = false;
            for(int j = 0; j < 3; j++){
                bool chk = true;
                for(int k = 0; k < str[j].length() && !flag[j]; k++){
                    if(ref + k == test.length()){
                        chk = false;
                        break;
                    }
                    if(str[j][k] != test[ref + k]){
                        chk = false;
                        break;
                    }
                }
                if(chk && !flag[j]){
                    ref += str[j].length();
                    flag[j] = true;
                    flag2 = true;
                    //cout << str[j] << " " << ref << endl;
                    break;
                }
            }
            if(!flag2){
                cout << "WA";
                goto end;
            }
        }
        if(ref != test.length())
            cout << "WA";
        else
            cout << "ACC";
end:
        cout << endl;
    }
    return 0;
}
