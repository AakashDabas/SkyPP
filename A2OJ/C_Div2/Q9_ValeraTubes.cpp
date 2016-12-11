#include<iostream>
#include<string>

using namespace std;

int main(){
    int n, m, k;
    cin >> m >> n >> k;
    int cnt = 1, total = n * m, allocated = 0;
    int i = 1, j = 1, dir = 1;
    while(1){
        if(!allocated){
            if(cnt < k)
                allocated = 2, cout << "\n2 ";
            else
                allocated = total, cout << "\n" << total << " ";
            cnt++;
        }
        cout << i << " " << j << " ";
        if(j == n && dir == 1 && i != m){
            dir = -1;
            i++;
            j++;
        }
        else if(j == 1 && dir == -1 && i != m){
            dir = 1;
            i++;
            j--;
        }
        allocated--;
        total--;
        j += dir;
        if(!total)
            break;
    }
    return 0;
}
