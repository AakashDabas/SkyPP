#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n], l[n] = {0}, r[n] = {0};
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int cnt = 0;
    int ref = arr[0];
    l[0] = 0;
    for(int i = 1; i < n; i++)
        if(arr[i] >= ref){
            cnt++;
            l[i] = cnt;
            ref = arr[i];
        }
        else{
            cnt = 0;
            ref = arr[i];
        }

    cnt = 0;
    ref = arr[n - 1];
    r[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--)
        if(arr[i] >= ref){
            cnt++;
            r[i] = cnt;
            ref = arr[i];
        }
        else{
            cnt = 0;
            ref = arr[i];
        }

    /*for(int i = 0; i < n; i++)
        cout << l[i] << " ";
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << r[i] << " ";*/
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(ans < l[i] + r[i])
            ans = l[i] + r[i];
    cout << ans + 1;
    return 0;
}
