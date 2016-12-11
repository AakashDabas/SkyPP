#include<iostream>
#include<map>
#include<deque>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    map<int, deque<int> > graph;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int flag[n + 1] = {0};
    for(map<int, deque<int> > :: iterator itr = graph.begin(); itr != graph.end(); itr++){
        if(!flag[itr->first]){
            //Do the dfs
            deque<int> buffer;
            deque<int> fSeq;
            buffer.push_front(itr->first);
            fSeq.push_front(1);
            while(!buffer.empty()){
                int idx = buffer.front();
                int f = fSeq.front();
                buffer.pop_front();
                fSeq.pop_front();
                if(flag[idx] == 0){
                    flag[idx] = f + 1;
                    f = (f + 1) % 2;
                    deque<int> :: iterator itrT = graph[idx].begin();
                    for(; itrT != graph[idx].end(); itrT++)
                        if(flag[*itrT] == 0){
                            buffer.push_front(*itrT);
                            fSeq.push_front(f);
                        }
                }
            }
        }
    }

    int faulty = 0;

    for(map<int, deque<int> > :: iterator itr = graph.begin(); itr != graph.end(); itr++){
        deque<int> :: iterator itrT = itr->second.begin();
        while(itrT != itr->second.end()){
            if(flag[*itrT] == flag[itr->first])
                faulty++;
            itrT++;
        }
    }

    faulty /= 2;
    if( (n - faulty) % 2 == 1)
        faulty++;
    cout << faulty;
    return 0;
}
