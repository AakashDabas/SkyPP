#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n];
    map<int, int> mappy;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mappy[arr[i]] = i;
    }
    sort(arr, arr + n);
    if(n >= 2){
        if(n == 2){
            if((arr[0] + arr[1]) % 2 != 0){
                cout << "Unrecoverable configuration.";
                return 0;
            }
        }
        else if((arr[0] + arr[n - 1]) / 2 != arr[1]){
            cout << "Unrecoverable configuration.";
            return 0;
        }
        for(int i = 1; i < n - 2; i++)
            if(arr[i] != arr[i + 1]){
                cout << "Unrecoverable configuration.";
                return 0;
            }
        if((arr[0] + arr[n - 1]) % 2 != 0){
            cout << "Unrecoverable configuration.";
            return 0;
        }
        if(arr[0] == arr[1])
            cout << "Exemplary pages.";
        else
            cout <<( arr[n - 1] - arr[0]) / 2 << " ml. from cup #" << mappy[arr[0]] + 1 << " to cup #"<< mappy[arr[n - 1]] + 1 << ".";
        return 0;
    }
    if(n == 1)
        cout << "Exemplary pages.";
    return 0;
}
