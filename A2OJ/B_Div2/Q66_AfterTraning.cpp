#include<iostream>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int mid = m % 2 == 0? m / 2: m / 2 + 1, curr = mid;
    for(int i = 0; i < n; i++){
        cout << curr << "\n";
        if(m == 1)
            curr = 1;
        else if(curr == mid){
            if(m % 2 == 0)
                curr = mid + 1;
            else
                curr = mid - 1;
        }
        else if(curr == m)
            curr = mid;
        else if(curr < mid)
            curr = m - curr + 1;
        else
            curr = m - curr;
    }
    return 0;
}
