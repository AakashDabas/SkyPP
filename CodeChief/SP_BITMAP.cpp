#include<iostream>
#include<vector>

#define ifOk(i, j)  (i >= 0 && i < m && j >= 0 && j < n && mat[i][j] == 0)
using namespace std;

struct point{
    int x, y;
    int flag = 2;
};

int cnt;

int main()
{
    int t;
    cin>>t;
    for(int itrS = 0; itrS < t; itrS++)
    {
        vector<point> buffer;
        cnt = 0;
        int n, m;
        cin>>m>>n;
        vector< vector<int> > mat(m, vector<int>(n));
        for(int i = 0; i < m; i++)
            for(int j =0; j < n; j++)
            {
                char ch;
                cin>>ch;
                if(ch == '0')   mat[i][j] = 0;
                else    mat[i][j] = 1;
                point pt;
                pt.x = i;
                pt.y = j;
                if(mat[i][j] == 1)
                    buffer.push_back(pt), cnt++;
            }
        int itr = 0;
        while(cnt < n*m)
        {
            point pt = buffer[itr];
            itr++;
            pt.x--;
            pt.flag++;
            if( ifOk(pt.x, pt.y) )   mat[pt.x][pt.y] = pt.flag - 1, buffer.push_back(pt), cnt++;
            //else    cout<<"F UP\n";
            pt.x += 2;
            if( ifOk(pt.x, pt.y) )   mat[pt.x][pt.y] = pt.flag - 1, buffer.push_back(pt), cnt++;
            //else    cout<<"F DOWN\n";
            pt.x--;
            pt.y--;
            if( ifOk(pt.x, pt.y) )   mat[pt.x][pt.y] = pt.flag - 1, buffer.push_back(pt), cnt++;
            //else    cout<<"F LEFT\n";
            pt.y += 2;
            if( ifOk(pt.x, pt.y) )   mat[pt.x][pt.y] = pt.flag - 1, buffer.push_back(pt), cnt++;
            //else    cout<<"F RIGHT\n";
        }
        for(int i = 0; i < m; i++){
            for(int j =0; j < n; j++)
                cout<<mat[i][j] - 1<<" ";
            cout<<endl;
        }
    }
    return 0;
}
