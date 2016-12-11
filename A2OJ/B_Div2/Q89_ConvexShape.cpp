#include<iostream>
#include<vector>

using namespace std;

int n, m;
int arr[50][50], flag[50][50] = {0};

void markNodes(int i, int j, int dir = 0, int cnt = 3){
    if(i < 0 || j < 0 || i == n || j == m || cnt == 0)
        return;
    if(!arr[i][j])
        return;
    flag[i][j] = true;
    if(dir == 1)
        markNodes(i - 1, j, 1, cnt);
    else
        markNodes(i - 1, j, 1, cnt - 1);
    if(dir == 2)
        markNodes(i + 1, j, 2, cnt);
    else
        markNodes(i + 1, j, 2, cnt - 1);
    if(dir == 3)
        markNodes(i, j - 1, 3, cnt);
    else
        markNodes(i, j - 1, 3, cnt - 1);
    if(dir == 4)
        markNodes(i, j + 1, 4, cnt);
    else
        markNodes(i, j + 1, 4, cnt - 1);

}

int main(){
    ios :: sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            char ch;
            cin >> ch;
            if(ch == 'B')
                arr[i][j] = 1;
            else
                arr[i][j]= 0;
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(arr[i][j]){
                for(int k = 0; k < n; k++)
                    for(int l = 0; l < m; l++)
                        flag[k][l] = false;
                markNodes(i, j);
                for(int k = 0; k < n; k++)
                    for(int l = 0; l < m; l++)
                        if(arr[k][l] && !flag[k][l]){
                            cout << "NO";
                            return 0;
                        }
            }
        }
    cout << "YES";
    return 0;
}
