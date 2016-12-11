#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    long long int t = 0;
    cin>>t;
    for(long long int itrS = 0; itrS < t; itrS++){
        long long int m, n;
        cin>>m>>n;
        if( m == 1 || n == 1)
            if( m == 2 || n == 2)   cout<<"Yes";
            else    cout<<"No";
        else if( m %2 == 0 || n % 2 == 0 )  cout<<"Yes";
        else    cout<<"No";
        cout<<endl;
    }
    return 0;
}
