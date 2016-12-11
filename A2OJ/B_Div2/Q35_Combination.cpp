#include<iostream>
#include<algorithm>

using namespace std;

struct node{
    int a, b;
};

bool comp(node t1, node t2){
    if(t1.b > t2.b)    return true;
    else if(t1.b == t2.b && t1.a > t2.a)    return true;
    else return false;
}

int main(){
    int n;
    cin >> n;
    node arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i].a >> arr[i].b;
    sort(arr, arr + n, comp);
    int cnt = 1, scr = 0, i = 0;
    while(cnt && i < n){
        cnt--;
        cnt += arr[i].b;
        scr += arr[i].a;
        i++;
    }
    cout << scr;
    return 0;
}
