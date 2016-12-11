#include <iostream> 
#include<map>
#include<vector>

typedef long long int lli;

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin >> n;
    map<lli, lli> mappy;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        mappy[tmp]++;
    }
    lli ans = 0, val = 0, lst1 = 0, lst2 = 0, lst = -9;
    for(map<lli, lli> :: iterator itr = mappy.begin(); itr != mappy.end(); itr++){
        if(itr->first - lst > 1){
            ans += max(lst1, lst2);
            val = 0;
            lst1 = itr->first * itr->second;
            lst2 = 0;
        }
        else{
            lli cur = max(lst1, lst2 + itr->first * itr->second);
            lst2 = lst1;
            lst1 = cur;
        }
        lst = itr->first;
    }
        ans += max(lst1, lst2);
    cout << ans;
    return 0;
}
