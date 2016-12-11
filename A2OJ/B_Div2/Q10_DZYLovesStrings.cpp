#include<iostream>

using namespace std;

int main(){
    string str;
    cin >> str;
    int k;
    cin >> k;
    int arr[26], max = -1, val = 0;
    for(int i = 0; i < 26; i++){
        cin >> arr[i];
        if(arr[i] > max)    max = arr[i];
    }
    for(int i = 0; i < str.length(); i++){
        val += arr[str.at(i) - 'a'] * (i + 1);
    }
    int n = str.length();
    val += max * ((n + k) * (n + k + 1) / 2 - n * ( n + 1) / 2);
    cout << val;
    return 0;
}
