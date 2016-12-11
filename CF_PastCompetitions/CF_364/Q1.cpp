#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n];
    map<int, vector<int> > mappy;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mappy[arr[i]].push_back(i);
    }
    sort(arr, arr + n);
    for(int i = 0; i < n / 2; i++){
        cout << mappy[arr[i]].back() + 1 << " ";
        mappy[arr[i]].pop_back();
        cout << mappy[arr[n - i - 1]].back() + 1 << "\n";
        mappy[arr[n - 1 - i]].pop_back();
    }
    return 0;
}
