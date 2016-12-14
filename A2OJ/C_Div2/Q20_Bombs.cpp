#include<iostream>
#include<utility>
#include<algorithm>
#include<cmath>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b){
    if(abs(a.second) < abs(b.second))
        return true;
    else if(abs(a.second) == abs(b.second)){
        if(abs(a.first) < abs(b.first))
            return true;
        else
            return false;
    }
    else
        return false;
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    pair<int, int> elts[n];
    for(int i = 0; i < n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        elts[i] = make_pair(tmp1, tmp2);
    }
    sort(elts, elts + n, Compare);

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(elts[i].second == 0 || elts[i].first == 0)
            cnt +=  4;
        else
            cnt += 6;
    }
    cout << cnt;
    for(int i = 0; i < n; i++){
        if(elts[i].first != 0){
            cout << "\n1 ";
            cout << abs(elts[i].first);
            if(elts[i].first > 0)
                cout << " R";
            else
                cout << " L";
        }
        if(elts[i].second != 0){
            cout << "\n1 ";
            cout << abs(elts[i].second);
            if(elts[i].second > 0)
                cout << " U";
            else
                cout << " D";
        }
        cout << "\n2";
        if(elts[i].second != 0){
            cout << "\n1 ";
            cout << abs(elts[i].second);
            if(elts[i].second > 0)
                cout << " D";
            else
                cout << " U";
        }
        if(elts[i].first != 0){
            cout << "\n1 ";
            cout << abs(elts[i].first);
            if(elts[i].first > 0)
                cout << " L";
            else
                cout << " R";
        }
        cout << "\n3";
    }
    return 0;
}
