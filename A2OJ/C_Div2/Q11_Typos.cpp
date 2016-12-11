#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    char *arr = new char[200001];
    scanf("%s", arr);
    bool flag = false;
    char lst = '0';
    int cnt = 1;
    for(int i = 0; arr[i] != '\0'; i++){
        if(lst == arr[i])
            cnt++;
        else if(cnt > 1 && !flag)
            cnt = 1, flag = true;
        else 
            flag = false, cnt = 1;
        if(flag && cnt == 1)
            cout << arr[i];
        if(cnt <= 2 && !flag)
            cout << arr[i];
        lst = arr[i];
    }
    return 0;
}
