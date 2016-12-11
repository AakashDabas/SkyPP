#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    string str;
    cin >> str;
    vector<int> arr(26, 0);
    for(int i = 0; i < str.length(); i++)
        arr[str.at(i) - 'a']++;

    int cnt = 0;
    for(int i = 0; i < 26; i++)
        if(arr[i] % 2 == 1) cnt++;
    if(cnt > 0)
        cnt--;
    if(cnt % 2 == 0)    cout << "First";
    else    cout << "Second";
    return 0;
}
