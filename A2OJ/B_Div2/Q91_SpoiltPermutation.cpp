#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int l = -1, r = n;
    int cnt = 0, lst = arr[0];
    bool flag = false;
    for(int i = 1; i < n; i++){
        if(lst > arr[i] && !flag){
            flag = true;
            cnt++;
            if(cnt == 1)
                l = i -1;
        }
        if(flag && arr[i] > lst){
            flag = false;
            if(cnt == 1)
                r = i - 1;
        }
        lst = arr[i];
    }
    if(r == n)  r--;
    if(cnt != 1)
        cout << "0 0";
    else{
        if(r != n - 1 && arr[l] > arr[r + 1])
            cout << "0 0";
        else if(l != 0 && arr[r] < arr[l - 1])
            cout << "0 0";
        else 
            cout << l + 1 << " " << r + 1;
    }
    return 0;
}
