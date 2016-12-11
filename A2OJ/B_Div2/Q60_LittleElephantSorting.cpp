#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    long long int turns = 0, ref = 0, lst = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] < lst){
            if(lst - arr[i] > ref){
                turns += lst - arr[i];
                turns -= ref;
            }
            ref = lst - arr[i];
        }
        else{
            lst = arr[i];
            ref = 0;
        }
    }
    cout << turns;
    return 0;
}
