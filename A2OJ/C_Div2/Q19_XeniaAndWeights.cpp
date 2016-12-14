#include<iostream>
#include<vector>

using namespace std;

bool arr[10] = {0};
int m;
vector<int> list;

bool Find(int diff, int lst, int cnt){
    if(cnt == m){
        cout << "YES\n";
        for(int i = 0; i < list.size(); i++)
            cout << list[i] + 1 << " ";
        return true;
    }
    for(int i = diff; i < 10; i++){
        if(arr[i] && i != lst){
            list.push_back(i);
            if(Find(i + 1 - diff, i, cnt + 1))
                return true;
            list.pop_back();
        }
    }
    return false;
}

int main(){
    for(int i = 0; i < 10; i++){
        char tmp;
        cin >> tmp;
        if(tmp == '1')
            arr[i] = true;
    }
    cin >> m;
    if(!Find(0, -1, 0))  
        cout << "NO";
    return 0;
}
