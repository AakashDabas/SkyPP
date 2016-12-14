#include<iostream>
#include<set>
#include<map>

using namespace std;

int main(){
    int n;
    cin >> n;
    set<int> wt;
    int mappy[101] = {0};
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        wt.insert(tmp);
        mappy[tmp]++;
    }
    int cnt = 0;
    while(wt.size()){
        set<int> ToBeDeleted;
        for(set<int> :: iterator itr = wt.begin(); itr != wt.end(); ++itr){
            mappy[*itr]--;
            if(mappy[*itr] == 0)
                ToBeDeleted.insert(*itr);
        }
        for(set<int> :: iterator itr = ToBeDeleted.begin(); itr != ToBeDeleted.end(); ++itr)
            wt.erase(*itr);
        cnt++;
    }
    cout << cnt;
    return 0;
}
