#include<iostream>
#include<map>
#include<deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n; 
    cin >> n;
    map<int, deque<int> > buffer;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        buffer[tmp].push_back(i);
    }
    map<int, deque<int> > :: iterator itr = buffer.begin();
    map<int, int> out;
    int cnt = 0;
    while(itr != buffer.end()){
        if(itr->second.size() == 1) out[itr->first] = 0, cnt++;
        else{
            deque<int> :: iterator itrQ = itr->second.begin();
            int diff = *(itrQ + 1) - *itrQ;
            bool flag = true;
            itrQ++;
            while(itrQ != itr->second.end() - 1){
                int tmp = *(itrQ + 1) - *itrQ;
                if(tmp != diff){
                   flag = false;
                   break;
                }
                itrQ++;
            }
            if(flag)    out[itr->first] = diff, cnt++;
        }
        itr++;
    }
    map<int, int> :: iterator itrOut = out.begin();
    cout << cnt << endl;
    while(itrOut != out.end()){
        cout << itrOut->first << " " << itrOut->second << endl;
        itrOut++;
    }
    return 0;
}
