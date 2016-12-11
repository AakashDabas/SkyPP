#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n, p;
    cin >> n >> p;
    char *str = new char[n];
    int cnt = 0, f = -1, l = -1;
    for(int i = 0; i < n; i++)
        cin >> str[i];
    for(int i = 0; i < n / 2; i++){
        int cnv = abs(str[i] - str[n - 1 - i]);
        cnt += min(cnv, 26 - cnv);
        if(cnv)
            l = i;
        if(f == -1 && cnt)
            f = i;
    }
    p--;
    if(f == -1){
        cout << "0\n";
        return 0;
    }
    if(p >= n / 2)
        p = n - 1 - p;
    if(p == f || p == l)
        cnt += abs(f - l);
    else
        cnt += l - f + min(abs(p - f), abs(p - l));
    cout << cnt << endl;
    return 0;
}
