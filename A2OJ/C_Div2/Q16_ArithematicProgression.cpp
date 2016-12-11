#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    if(n == 1)
        cout << -1;
    else{
        int d = min(arr[1] - arr[0], arr[n - 1] - arr[n - 2]), idx = -1;
        bool flag = true;
        for(int i = 1; i < n; i++)
            if(d != arr[i] - arr[i - 1]){
                flag = false;
                if(idx != -1){
                    cout << 0;
                    return 0;
                }
                idx = i;
            }
        set<int> choice;
        if(flag){
            choice.insert(arr[0] - d);
            if(n == 2 && d % 2 == 0)
                choice.insert(arr[0] + d / 2);
            choice.insert(arr[n - 1] + d);
        }
        else if(arr[idx] - arr[idx - 1] == 2 * d)
            choice.insert(arr[idx] - d);
        cout << choice.size() << endl;
        for(set<int> :: iterator itr = choice.begin(); itr != choice.end(); itr++)
            cout << *itr << " ";
    }
        
    return 0;
}
