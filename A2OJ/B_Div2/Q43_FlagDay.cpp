#include<iostream>
#include<set>
#include<map>
#include<deque>
#include<vector>

using namespace std;
int n, m;
vector<vector<int> > arr;
vector<int> val;

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m;

    val.resize(n, 0);
    arr.resize(m, vector<int>(3, 0));

    for(int i = 0; i < m; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }


    for(int i = 0; i < m; i++){
        set<int> current;
        current.insert(1);
        current.insert(2);
        current.insert(3);
        for(int j = 0; j < 3; j++)
            if(val[arr[i][j] - 1] != 0)
                current.erase(val[arr[i][j] - 1]);
        for(int j = 0; j < 3; j++)
            if(val[arr[i][j] - 1] == 0){
                val[arr[i][j] - 1] = *(current.begin());
                current.erase(val[arr[i][j] - 1]);
            }
    }

    for(int i = 0; i < n; i++)
        cout << val[i] << " ";

    return 0;
}
