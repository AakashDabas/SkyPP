#include<iostream>
#include<cmath>
#include<climits>

typedef long long int lli;

using namespace std;

lli GetLucky(int N, bool flag = true){
    lli lucky = 0;
    for(int i = 0; i < N; i++)
        if(i < N / 2){
            lucky *= 10;
            if(flag)
                lucky += 7;
            else
                lucky += 4;
        }
        else{
            lucky *= 10;
            if(flag)
                lucky += 4;
            else
                lucky += 7;
        }
    return lucky;
}

lli mn = INT_MAX;

void GenLucky(int cnt4, int cnt7, int cnt, lli curr, lli n){
    if(!cnt4 && !cnt7){
        //cout << curr << endl;
        if(curr >= n && curr < mn)
            mn = curr;
        return;
    }
    if(cnt4)
        GenLucky(cnt4 - 1, cnt7, cnt + 1, curr + 4 * pow(10, cnt), n);
    if(cnt7)
        GenLucky(cnt4, cnt7 - 1, cnt + 1, curr + 7 * pow(10, cnt), n);
}

int main(){
    ios::sync_with_stdio(0);
    lli n;
    cin >> n;
    int len = 0;
    for(lli tmp = n; tmp; tmp /= 10, len++);
    if(len % 2 != 0)
        cout << GetLucky(len + 1, false);
    else if(GetLucky(len, true) < n)
        cout << GetLucky(len + 2, false);
    else{
        GenLucky(len / 2, len / 2, 0, 0, n);
        cout << mn;
    }
    return 0;
}
