#include<iostream>
#include<map>

using namespace std;

int main(){
    int n, s, t;
    cin >> n >> s >> t;
    map<int, int> mappy;
    for(int i = 1; i <= n; i++)
        cin >> mappy[i];
    int cnt = 0;
    int pos = s;
    while(pos != t && cnt < n){
        pos = mappy[pos];
        cnt++;
    }
    if(cnt == n)    cout << "-1";
    else    cout << cnt;
    return 0;
}
