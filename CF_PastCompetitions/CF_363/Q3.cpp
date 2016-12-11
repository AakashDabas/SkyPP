#include<iostream>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n], lst = 0, rest = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(arr[i] == 0)
            rest++, lst = 0;
        else if(arr[i] == lst){
            rest++;
            lst = 0;
        }
        else if(arr[i] == 3){
            if(lst == 1)
                lst = 2;
            else if(lst == 2)
                lst = 1;
        }
        else
            lst = arr[i];
    }
    cout << rest << endl;
    return 0;
}
