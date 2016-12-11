#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    int l = 0;
    long long int t = -1;
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        t += abs(v - l) + 1;
        l = v;
    }
    t += n;
    cout << t;
    return 0;
}
