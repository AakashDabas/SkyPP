#include<iostream>
#include<map>
#include<deque>

using namespace std;

int main(){
    int n; 
    cin >> n;
    map<int, deque<int> > mappy;
    int arr[n + 1] = {0};
    for(int i = 0; i < n * (n - 1) / 2 - 1; i++){
        int a, b;
        cin >> a >> b;
        mappy[b].push_back(a);
        arr[a]++;
        arr[b]++;
    }
    int a = 0, b = 0;
    for(int i = 1; i <= n; i++){
        if(arr[i] != n - 1){
            if(!a)
                a = i;
            else{
                b = i;
                break;
            }
        }
    }
    // do the dfs
    bool flag[n + 1] = {0};
    deque<int> buffer;
    buffer.push_back(a);
    while(!buffer.empty()){
        int idx = buffer.front();
        buffer.pop_front();
        if(idx == b){
            cout << b << " " << a;
            return 0;
        }
        deque<int> :: iterator itr = mappy[idx].begin();
        while(itr != mappy[idx].end()){
            if(!flag[*itr]){
                flag[*itr] = 1;
                buffer.push_front(*itr);
            }
            itr++;
        }
    }
    cout << a << " " << b;
    return 0;
}
