#include<iostream>

#define check(p) (arr[itr][1] > p || arr[itr][2] < p)

enum direction{
    LEFT,
    RIGHT
};

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    long long int arr[m][3];
    for(int i = 0; i < m; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    int currT = 1, currP = s;
    int itr = 0;
    direction dir;
    if(s > f)
        dir = LEFT;
    else
        dir = RIGHT;
    while(1){
        bool flag = true;
        if(itr < m && arr[itr][0] == currT){
            if(check(currP)){
                if(dir == LEFT && check(currP - 1))
                    currP--,flag = false, cout << "L";
                else if(dir == RIGHT && check(currP + 1))
                    currP++, flag = false, cout << "R";
            }
            itr++;
        }
        else{
            flag = false;
            if(dir == LEFT)
                currP--, cout << "L";
            else
                currP++, cout << "R";
        }

        if(flag)
            cout << "X";
        currT++;
        if(currP == f)
            break;
    }
    return 0;
}
