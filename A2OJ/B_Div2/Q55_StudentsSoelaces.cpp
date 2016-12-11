#include<iostream>
#include<map>
#include<deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    map<int, deque<int> > mappy;
    int del[101] = {0};

    //Reads the input
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        mappy[a].push_back(b);
        mappy[b].push_back(a);
    }

    //Performs the brute force
    bool flag = true;
    int cnt = 0;
    while(flag){
        flag = false;
        map<int, deque<int> > :: iterator itr = mappy.begin();
        int delTmp[101];
        for(int i = 0; i < 101; i++)
            delTmp[i] = del[i];
        while(itr != mappy.end()){
            if(itr->second.size() - del[itr->first] == 1){
                delTmp[itr->first]++;
                flag = true;
                deque<int> :: iterator itrTmp = itr->second.begin();
                while(itrTmp != itr->second.end()){
                    delTmp[*itrTmp]++;
                    itrTmp++;
                }
            }
            itr++;
        }
        for(int i = 0; i < 101; i++)
            del[i] = delTmp[i];
        if(flag)
            cnt++;
    }
    cout << cnt;
    return 0;
}
