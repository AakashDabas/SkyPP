#include<iostream>
#include<cmath>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    long long int n, d;
    cin >> n >> d;
    int cmp = n - d;
    int len = 0;
    long long int tmp1 = n, tmp2 = n - d;
    int arr[2][20] = {0};
    while(tmp1){
        arr[0][len] = tmp1 % 10;
        arr[1][len] = tmp2 % 10;
        len++;
        tmp1 /= 10;
        tmp2 /= 10;
    }
    int ref = -1;
    for(int i = len - 1; i > 0 && ref == -1; i--){
        if(arr[0][i] != arr[1][i])
            ref = i;
    }
    bool flag = false;
    for(int i = ref - 1; i >= 0; i--)
        if(arr[0][i] != 9)
            flag = true;
    if(!flag)
        ref = -1;
    for(int i = len - 1; i >= 0; i--)
        if(i < ref)
            cout << 9;
        else if(i == ref){
           if(arr[0][ref] != 1 || i != len - 1)
            cout << arr[0][ref] - 1;
        }
        else
            cout << arr[0][i];
    return 0;
}
