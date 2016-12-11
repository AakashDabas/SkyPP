#include<iostream>
#include<vector>
#include<map>
#include<cmath>

typedef long long int lli;

using namespace std;

vector<vector<vector<lli> > > adj;
vector<lli> mrk, val;
vector<bool> flag;
vector<int> child;
int ans = 0;

int dfsChk(int idx, lli wt){
    if(flag[idx])
        return 0;
    flag[idx] = true;
    for(int i = 0; i < adj[idx][0].size(); i++){
        if(flag[adj[idx][0][i]])
            continue;
        mrk[adj[idx][0][i]] = max((lli)0, wt + adj[idx][1][i]);
        child[idx] += dfsChk(adj[idx][0][i], mrk[adj[idx][0][i]]);
    }
    return child[idx] + 1;
}

void dfsMrk(int idx){
    //cout << idx <<"\n";
    if(flag[idx])
        return;
    //cout << idx << " : " << mrk[idx] << " : " << val[idx] << endl;
    flag[idx] = true;
    if(mrk[idx] > val[idx]){
        ans += child[idx] + 1;
        return;
    }
    for(int i = 0; i < adj[idx][0].size(); i++){
        if(!flag[adj[idx][0][i]])
            dfsMrk(adj[idx][0][i]);
    }
}

int main(){
    int n;
    cin >> n;
    flag.clear();
    flag.resize(n + 1, false);
    mrk.clear();
    mrk.resize(n + 1, 0);
    child.clear();
    child.resize(n + 1, 0);
    val.clear();
    val.resize(n + 1, 0);
    adj.resize(n + 1, vector<vector<lli> >(2));
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    //Input
    for(int i = 2; i <= n; i++){
        lli tmp, tmp2;
        cin >> tmp >> tmp2;
        adj[i][0].push_back(tmp);
        adj[tmp][0].push_back(i);
        adj[i][1].push_back(tmp2);
        adj[tmp][1].push_back(tmp2);
    }
    dfsChk(1, 0);
    flag.clear();
    flag.resize(n + 1, false);
    dfsMrk(1);
    cout << ans;
    return 0;
}
