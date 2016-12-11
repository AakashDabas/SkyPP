#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

struct node{
    char ch;
    int cnt = 0;
};

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin >> n;
    vector<node> arr;
    char lst = '0';
    set<char> refU;
    for(int i = 0; i < n; i++){
        char tmp;
        cin >> tmp;
        refU.insert(tmp);
        if(tmp == lst)
            arr.back().cnt++;
        else{
            node t;
            t.ch = tmp;
            t.cnt = 1;
            arr.push_back(t);
        }
        lst = tmp;
    }
    int mn = n;
    for(int i = 0; i < arr.size(); i++){
        set<char> ref;
        map<char, int> mappy;
        int len = arr[i].cnt;;
        ref.insert(arr[i].ch);
        mappy[arr[i].ch]++;
        int j = i + 1;
        for(; j < arr.size(); j++){
            len += arr[j].cnt;
            ref.insert(arr[j].ch);
            mappy[arr[j].ch]++;
            if(ref.size() == refU.size()){
                len++;
                len -= arr[j].cnt;
                break;
            }
        }
        if(ref.size() == refU.size()){
            for(int k = i; k < j; k++, i++){
                if(mappy[arr[k].ch] > 1){
                    mappy[arr[k].ch]--;
                    len -= arr[k].cnt;
                }
                else{
                    len++;
                    len -= arr[k].cnt;
                    break;
                }
            }
            if(len < mn)
                mn = len;
            i++;
        }
        else
            break;
    }
    cout << mn;
    return 0;
}
