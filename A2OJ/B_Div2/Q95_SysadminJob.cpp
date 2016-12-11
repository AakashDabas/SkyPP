#include <iostream>
#include <string>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    string str;
    cin >> str;
    bool flag[str.length()] = {0};
    int cnt = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '@'){
            cnt++;
            bool flag2 = false;
            if(i == 0 || i == str.length() - 1)
                flag2 = 1;
            if(flag[i - 1])
                flag2 = 1;
            flag[i - 1] = flag[i + 1] = flag[i] = true;
            if(flag2){
                cout << "No solution";
                return 0;
            }
        }
    }
    if(cnt){
        for(int i = 0; i < str.length(); i++){
            cout << str[i];
            if(str[i] == '@' && cnt > 1){
                cout << str[i + 1] << ",";
                i++;
                cnt--;
            }
        }
    }
    else
        cout << "No solution";
        return 0;
}
