//#357 Div 2 C
#include<iostream>
#include<string>
#include<map>
#include<deque>

typedef long long int lli;

using namespace std;

struct node{
    string str;
    lli n;
    bool flag = false;
};

int main(){
    map<lli, int> mappy;
    int n;
    cin >> n;
    lli arr[n] = {0};
    deque<string> commands;
    deque<node> cList, oList;
    deque<lli> nList;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        node tmp;
        tmp.str = str;
        if(str == "insert" || str == "getMin"){
            lli n;
            cin >> n;
            tmp.n = n;
        }
        cList.push_back(tmp);
    }

    while(!cList.empty()){
        node tmp = cList.front();
        if(tmp.str == "insert"){
            mappy[tmp.n]++;
            oList.push_back(tmp);
        }
        else if(tmp.str == "removeMin"){
            if(mappy.size() > 0){
                lli ref = mappy.begin()->first;
                mappy[ref]--;
                if(mappy[ref] == 0)
                    mappy.erase(ref);
                oList.push_back(tmp);
            }
            else{
                node tmp2 ;
                tmp2.str = "insert";
                tmp2.n = 10;
                oList.push_back(tmp2);
                oList.push_back(tmp);
            }
        }
        else if(tmp.str == "getMin"){
            node tmp2;
            tmp2.str = "removeMin";
            map<lli, int> :: iterator itr = mappy.begin();
            while(itr->first < tmp.n && itr != mappy.end()){
                for(int j = 0; j < itr->second; j++)
                    oList.push_back(tmp2);
                mappy.erase(itr->first);
                itr++;
            }
            if(mappy.begin()->first != tmp.n){
                tmp2.str = "insert";
                tmp2.flag = true;
                oList.push_back(tmp2);
                nList.push_back(tmp.n);
            }
            oList.push_back(tmp);
        }
        cList.pop_front();
    }
    cout << oList.size() << endl;
    while(!oList.empty()){
        node tmp = oList.front();
        if(tmp.str != "insert"){
            if(tmp.str == "removeMin")
                cout << "removeMin\n";
            else
                cout << "getMin " << tmp.n << "\n";
        }
        else{
            cout << "insert ";
            if(tmp.flag){
                if(!nList.empty()){
                    cout << nList.front() << "\n";
                    nList.pop_front();
                }
                else
                    cout << "10\n";
            }
            else
                cout << tmp.n << "\n";
        }
        oList.pop_front();
    }
    return 0;
}
