#include<iostream>

using namespace std;

int main(){
    string str;
    cin >> str;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < str.length(); i++)
        if(str.at(i) == '4')    cnt1++;
        else if(str.at(i) == '7')    cnt2++;
    if(cnt1 >= cnt2 && cnt1)    cout << "4";
    else if(cnt2 >= cnt1 && cnt2)   cout << "7";
    else    cout << "-1";
    return 0;
}
