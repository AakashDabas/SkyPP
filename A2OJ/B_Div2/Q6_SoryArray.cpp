#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n], tmp[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        tmp[i] = arr[i];
    }
    sort(tmp, tmp + n);
    int f = 0, l = 0;
    bool flag = true;
    for(int i = 0; i < n; i++){
        //cout << arr[i] << " $ " << tmp[i]<<endl;
        if(arr[i] != tmp[i]){
            if(flag) f = i, flag = false;
            else    l = i;
        }
    }
    for(int i = f, j = l; i <= l; i++, j--){
        //cout << arr[i] << " # " << tmp[j] << endl;
        if(arr[i] != tmp[j]){
            cout << "no";
            return 0;
        }
    }
    cout << "yes\n" << f + 1 << " " << l + 1;
    return 0;
}
