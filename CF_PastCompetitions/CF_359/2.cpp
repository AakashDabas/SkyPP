#include<iostream>

typedef long long int lli;

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin >> n;
    lli arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    while(1){
        bool flag = false;
        int ref1 = -1, ref2 = -1;
        for(int i = 1; i < n; i += 1 + flag){
            if(arr[i] < arr[i - 1] || (arr[i] == arr[i - 1] && flag)){
                if(!flag)
                    ref1 = i - 1;
                ref2 = i;
                flag = true;
                lli tmp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = tmp;
            }
            else if(flag)
                break;
        }
        if(flag)
            cout << ref1 + 1 << " " << ref2 + 1 << "\n";
        else
            break;
    }
    return 0;
}
