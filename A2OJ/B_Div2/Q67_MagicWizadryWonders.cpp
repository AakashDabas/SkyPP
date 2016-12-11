#include<iostream>
#include<deque>

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    int n, d, l;
    cin >> n >> d >> l;
    deque<int> seq;
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            seq.push_back(d);
            if(d < 1 || d > l){
                cout << "-1";
                return 0;
            }
        }
        else if(d <= 0){
            seq.push_back(1);
            d = 1 - d;
        }
        else{
            seq.push_back(l);
            d = l - d;
        }
    }
    while(!seq.empty()){
        cout << seq.front() << " ";
        seq.pop_front();
    }
    return 0;
}
