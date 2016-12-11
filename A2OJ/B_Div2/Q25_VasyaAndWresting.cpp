#include<iostream>
#include<deque>

using namespace std;

int chkOrder(deque<long long int> first, deque<long long int> second){
    while(!first.empty() && !second.empty()){
        if(first.front() > second.front())  return 1;
        else if(second.front() > first.front()) return -1;
        first.pop_front();
        second.pop_front();
    }
    if(!first.empty())  return 1;
    if(!second.empty()) return -1;
    return 0;
}

int main(){
    int n;
    cin >> n;
    deque<long long int> first, second;
    long long int scrFirst = 0, scrSecond = 0;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        if(tmp > 0) first.push_back(tmp), scrFirst += tmp;
        else    second.push_back(-tmp), scrSecond -= tmp;
    }
    if(scrFirst > scrSecond)    cout << "first";
    if(scrSecond > scrFirst)    cout << "second";
    if(scrFirst == scrSecond){
        int val = chkOrder(first, second);
        if(val == 1)    cout << "first";
        else if(val == -1)  cout << "second";
        else if(tmp > 0)    cout << "first";
        else    cout << "second";
    }
    return 0;
}
