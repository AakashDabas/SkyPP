#include<iostream>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        bool flag = false;
        int s = 0, l = 8;
        int mid = 4;
        while(s <= l){
            if(1 << mid == n){
                cout << mid + 1 << "\n";
                flag = true;
                break;
            }
            else if(1 << mid > n)
                l = mid - 1;
            else
                s = mid + 1;
            mid = (s + l) / 2;
        }
        if(!flag)
            cout << "-1\n";
    }
    return 0;
}
