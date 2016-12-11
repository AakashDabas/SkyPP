#include<iostream>
#include<map>

using namespace std;

int main(){
    int n;
    cin >> n;
    int h[n], aw[n];
    map<int, int> mappy;
    for(int i = 0; i < n; i++){
        cin >> h[i] >> aw[i];
        mappy[h[i]]++;
    }
    for(int i = 0; i < n; i++){
        cout << n - 1 + mappy[aw[i]] << " " << n - 1 - mappy[aw[i]];
        cout << endl;
    }
    return 0;
}
