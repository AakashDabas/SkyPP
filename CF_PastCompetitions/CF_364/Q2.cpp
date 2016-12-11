#include<iostream>
#include<vector>

typedef long long int lli;

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    lli n, m;
    cin >> n >> m;
    vector<bool> col(n, false), row(n, false);
    lli rNet = n, cNet = n;
    for(int i = 0; i < m; i++){
        int c, r;
        cin >> r >> c;
        r--;
        c--;
        if(!row[r]){
            row[r] = true;
            rNet--;
        }
        if(!col[c]){
            col[c] = true;
            cNet--;
        }
        cout << rNet * cNet << " ";
    }
    return 0;
}
