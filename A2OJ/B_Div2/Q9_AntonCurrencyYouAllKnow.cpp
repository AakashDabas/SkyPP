#include<iostream>
#include<string>

using namespace std;

int main(){
    int arr[100000], cnt = 0;
    char ch = 'a';
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++)
        arr[i] = str.at(i) - '0';
    cnt = str.length();
    int ref1 = -1, ref = -1;
    for(int i = cnt - 1; i >= 0; i--){
        if(arr[i] % 2 == 0 && ref1 == -1) ref1 = i;
        if(arr[i] % 2 == 0 && arr[i] < arr[cnt - 1])    ref = i;
    }
    if(ref1 == -1){
        cout << "-1";
        return 0;
    }
    if(ref == -1)   ref = ref1;
    
    int tmp = arr[cnt - 1];
    arr[cnt - 1] = arr[ref];
    arr[ref] = tmp;

    for(int i = 0; i < cnt; i++)    cout << arr[i];
    return 0;
}
