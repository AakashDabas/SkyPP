#include<iostream>
#include<map>
#include<string>
#include<set>

#define ifOn(n, idx) (n & (1 << idx))

using namespace std;

int power(int b, int p){
    if(p == 0)
        return 1;
    return power(b, p - 1) * b;
}

int main(){
    ios :: sync_with_stdio(false);
    int n, m, idx = 0, mx = 0, ans = 0;
    cin >> n >> m;
    int arr[m][2];
    map<int, string> mappy;
    map<string, int> invMappy;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        mappy[idx] = str;
        invMappy[str] = idx;
        idx++;
    }
    for(int i = 0; i < m; i++){
        string str1, str2; 
        cin >> str1 >> str2;
        arr[i][0] = invMappy[str1];
        arr[i][1] = invMappy[str2];
    }
    for(int i = 0; i < power(2, n);){
        int cnt = 0;
        for(int j = 0; j < m; j++)
            if(ifOn(i, arr[j][1]) && ifOn(i, arr[j][0]))
                goto endLoop;
        for(int j = 0; j < 16; j++)
            if(ifOn(i, j))
                cnt++;
        if(cnt > mx){
            ans = i;
            mx = cnt;
        }
endLoop:
        i++;
    }

    set<string> seq;
    seq.clear();
    for(int i = 0; i < 16; i++)
        if(ifOn(ans, i)){
            seq.insert(mappy[i]);
        }

    cout << seq.size() << "\n";
    for(set<string> :: iterator itr = seq.begin(); itr != seq.end(); itr++)
        cout << *itr << "\n";
    return 0;
}
