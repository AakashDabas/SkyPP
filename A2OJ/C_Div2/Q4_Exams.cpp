#include<iostream>
#include<algorithm>

typedef long long int lli;

using namespace std;

struct node{
    lli a, b;
};

bool cmp(node &a, node &b){
    if(a.a != b.a)
        return a.a < b.a;
    else
        return a.b < b.b;
}

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin >> n;
    node arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i].a >> arr[i].b;
    sort(arr, arr + n, cmp);
    lli ref = -1;
    for(int i = 0; i < n; i++)
        if(arr[i].b >= ref)
            ref = arr[i].b;
        else
            ref = arr[i].a;
    cout << ref;
    return 0;
}
