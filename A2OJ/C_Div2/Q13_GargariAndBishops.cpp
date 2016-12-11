#include<iostream>
#include<vector>
#include<climits>
#include<stdio.h>


typedef long long int lli;

using namespace std;

void Compute(vector<vector<lli> > mat, vector<vector<int> > &mark, int n, vector<lli> &dp, bool flag)
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

void GetCoordinates(vector<vector<lli> > mat, vector<lli> dpRt, vector<lli> dpLt, vector<vector<int> > markRt, vector<vector<int> > markLt, int n)
{
    lli mxB, mxW, x1, y1, x2, y2;
    mxB = mxW = INT_MIN;
    lli cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            lli sum = 0;
            sum += dpRt[markRt[i][j]];
            sum += dpLt[markLt[i][j]];
            sum -= mat[i][j];
            if(cnt % 2 == 0 && sum > mxB){
                mxB = sum;
                x1 = i;
                y1 = j;
            }
            else if(cnt % 2 == 1 && sum > mxW){
                mxW = sum;
                x2 = i;
                y2 = j;
            }
            cnt++;
        }
        if(n % 2 == 0)
            cnt++;
    }
    cout << mxB + mxW << "\n" << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1;
}

int main(){
    int n;
    cin >> n;
    vector<vector<lli> > mat(n, vector<lli>(n, 0));
    vector<vector<int> > markRt(n, vector<int>(n, 0)), markLt(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            mat[i][j] = tmp;
        }
    vector<lli> dpRt(2 * n - 1, 0), dpLt(2 * n - 1, 0);
    Compute(mat, markRt, n, dpRt, 1);
    Compute(mat, markLt, n, dpLt, 0);
    GetCoordinates(mat, dpRt, dpLt, markRt, markLt, n);
    return 0;
}
