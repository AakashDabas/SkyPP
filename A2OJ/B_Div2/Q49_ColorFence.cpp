#include<iostream>
#include<map>
#include<set>

using namespace std;

int main(){
    int v;
    cin >> v;
    int arr[9];
    map<int, set<int> > mappy;
    for(int i = 0; i < 9; i++){
        cin >> arr[i];
        mappy[arr[i]].insert(i + 1);
    }
    map<int, set<int> > :: iterator itr = mappy.begin();
    int len = v / itr->first;
    set<int> :: iterator itr2 = itr->second.end();
    itr2--;
    int counts[9] = {0};
    //cout << "Length: " << itr->first<< endl;
    for(int i = 8; i >= 0; i--){
        int val = 1;
        while(v - val * arr[i] >= (len - val) * itr->first && val <= len){
            val++;
        }
        counts[i] = val - 1;
        len -= val - 1;
        v -= arr[i] * counts[i];
    }
    bool flag = true;
    for(int i = 8; i >= 0; i--)
        for(int j = 0; j < counts[i]; j++){
            cout << i + 1;
            flag = false;
        }
    if(flag)
        cout << "-1";
    return 0;
}
