#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)  cin >> arr[i];
    bool flag = false;
    int ref = n - 1;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1] && !flag){
            if(arr[i + 1] > arr[0]){
                cout << "-1";
                return 0;
            }
            flag  = true;
            ref = i;
            //cout <<"#";
        }
        else if(flag){
            //cout <<"@";
            if(arr[i] <= arr[i + 1] && arr[i] <= arr[0] && arr[i + 1] <= arr[0]);
            else{
                cout << "-1";
                return 0;
            }
        }
    }
    cout << n - ref - 1;
    return 0;
}
