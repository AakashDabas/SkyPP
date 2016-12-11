#include<iostream>
#include<map>
#include<set>
#include<deque>

typedef long long int lli;

using namespace std;

struct node{
    lli a, b;
};

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin >> n;
    map<int, node> mappy;
    map<int, set<int> > mapped;
    int idx = 1;
    for(int i = 0; i < n; i++){
start:
        if(i >= n)
            break;
        int mode;
        lli a, b;
        cin >> mode >> a >> b;
        if(mode == 2){
            deque<int> buffer;
            buffer.push_back(a);
            bool flag[idx + 1] = {0};
            flag[a] = true;
            while(buffer.empty() == false){
                set<int> :: iterator itr = mapped[buffer.front()].begin();
                while(itr != mapped[buffer.front()].end()){
                    if(*itr == b){
                        cout << "YES\n";
                        i++;
                        goto start;
                    }
                    if(!flag[*itr]){
                        buffer.push_back(*itr);
                        flag[*itr] = true;
                    }
                    itr++;
                }
                buffer.pop_front();
            }
            cout << "NO\n";
        }
        else{
            //To map and iterate again
            node tmp;
            tmp.a = a;
            tmp.b = b;
            mappy[idx] = tmp;
            for(map<int, node> :: iterator itr = mappy.begin(); itr != mappy.end(); itr++){
                if((itr->second.a < a && a < itr->second.b) || (itr->second.a < b && b < itr->second.b))
                    mapped[idx].insert(itr->first);
                if((a < itr->second.a && itr->second.a < b) || (a < itr->second.b && itr->second.b < b))
                    mapped[itr->first].insert(idx);
            }
            idx++;
        }
    }
    return 0;
}
