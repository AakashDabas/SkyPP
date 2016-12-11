#include<iostream>
#include<vector>
#include<climits>

typedef long long int lli;

using namespace std;

void Compute(vector<vector<int> > mat, vector<vector<int> > &mark, int n, vector<lli> &dp, bool flag)
{
    int i = 0, j = 0, cnt = 0;
    if(!flag)
        i = n - 1;
    while(true){
        if(i == n || j == n || i < 0 || j < 0)
            break;
        if(j == n)
            break;
        for(int i1 = i, i2 = j; i1 >= 0 && i2 <= n - 1 && i1 <= n - 1 && i2 >= 0;){
            dp[cnt] += mat[i1][i2];
            mark[i1][i2] = cnt;
            i1--;
            if(flag)
                i2++;
            else
                i2--;
        }
        cnt++;
        if(flag){
            if(i < n - 1)
                i++;
            else
                j++;
        }
        else{
            if(j < n - 1)
                j++;
            else
                i--;
        }
    }
}

void GetCoordinates(vector<lli> dpRt, vector<lli> dpLt, vector<vector<int> > markRt, vector<vector<int> > markLt, int n)
{
    lli mxW = INT_MIN, mxB = INT_MIN, xW, yW, xB, yB;
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            lli sum = 0;
            sum += dpRt[markRt[i][j]];
            sum += dpLt[markLt[i][j]];
            if(cnt % 2 == 0 && sum > mxB){
                xB = i;
                yB = j;
                mxB = sum;
            }
            else if(sum > mxW){
                xW = i;
                yW = j;
                mxW = sum;
            }
            cnt++;
        }
    cout << mxB << " " << mxW << endl;
    cout << xB + 1 << " " << yB + 1 << " " << xW + 1 << " " << yW + 1;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int> > mat(n, vector<int>(n, 0)), markRt(n, vector<int>(n, 0)), markLt(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    vector<lli> dpRt(2 * n - 1, 0), dpLt(2 * n - 1, 0);
    Compute(mat, markRt, n, dpRt, 1);
    Compute(mat, markLt, n, dpLt, 0);
    for(int i = 0; i < n; i++){
        cout << endl;
        for(int j = 0; j < n; j++)
            cout << markRt[i][j] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << endl;
        for(int j = 0; j < n; j++)
            cout << markLt[i][j] << " ";
    }
    cout <<"\n\nRight:\n";
    for(int i = 0; i < 2 * n - 1; i++)
        cout << i << " " << dpRt[i] << endl;
    cout <<"\n\nLeft:\n";
    for(int i = 0; i < 2 * n - 1; i++)
        cout << i << " " << dpLt[i] << endl;
    GetCoordinates(dpRt, dpLt, markRt, markLt, n);
    return 0;
}
