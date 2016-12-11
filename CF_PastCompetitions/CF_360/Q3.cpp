#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<deque>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    set<int> sA, sB;
    map<int, vector<int> > mappy;
    bool flag = true;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        mappy[a].push_back(b);
        mappy[b].push_back(a);
    }
    vector<bool> visited(n, false);
    for(int i = 1; i <= n && flag; i++){
        if(visited[i])
            continue;
        deque<int> buffer, parent, loop;
        buffer.push_front(i);
        parent.push_front(0);
        loop.push_front(0);
        visited[i] = true;
        while(!buffer.empty() && flag){
            int curr = buffer.front();
            int currP = parent.front();
            int currL = loop.front();
            buffer.pop_front();
            parent.pop_front();
            loop.pop_front();
            for(int j = 0; j < mappy[curr].size(); j++){
                if(!visited[mappy[curr][j]]){
                    visited[mappy[curr][j]] = true;
                    buffer.push_front(mappy[curr][j]);
                    parent.push_front(curr);
                    loop.push_front(currL + 1);
                    if(sA.count(curr))
                        sB.insert(mappy[curr][j]);
                    else{
                        if(sB.count(curr) == 0)
                            sB.insert(curr);
                        if(sA.count(mappy[curr][j]) == 0)
                        sA.insert(mappy[curr][j]);
                    }
                }
                else if(currP != mappy[curr][j] && currL % 2 == 1)
                    flag = false;
            }
        }
    }
    if(flag){
        cout << sA.size() << "\n";
        set<int> :: iterator itr = sA.begin();
        while(itr != sA.end()){
            cout << *itr << " ";
            itr++;
        }
        cout << "\n" << sB.size() << "\n";
        itr = sB.begin();
        while(itr != sB.end()){
            cout << *itr << " ";
            itr++;
        }
    }
    else
        cout << -1;
    return 0;
}
