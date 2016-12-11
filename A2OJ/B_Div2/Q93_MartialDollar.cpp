#include<iostream>
#include<deque>

using namespace std;

struct node{
    int s, l;
};

int main(){
    cout << "hello";
    int n, coins;
    cin >> n >> coins;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int coinsMx = coins;
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++){
            int nC = coins / arr[i];
            int coinsTmp = coins % arr[i];
            coinsTmp += nC * arr[j];
            if(coinsTmp > coinsMx)
                coinsMx = coinsTmp;
        }
    cout << coinsMx;
    return 0;
}
