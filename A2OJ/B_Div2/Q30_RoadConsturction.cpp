#include<iostream>
#include<vector>

using namespace std;

struct node{
    int x, y;
};

int main(){
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<bool> arr(n + 1, true);
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        arr[tmp] = false;
        cin >> tmp;
        arr[tmp] = false;
    }
    cout << n - 1 << endl;
    for(int i = 1; i <= n; i++)
        if(arr[i]){
            for(int j = 1; j <=n; j++)
                if(j != i)
                    cout << i << " " << j << endl;
            break;
        }
    return 0;
}
