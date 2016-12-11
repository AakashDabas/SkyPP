#include<iostream>
#include<deque>

typedef long long int lli;

using namespace std;

lli arr[50] = {0}, len = 0;
deque<int> seq;

lli seqSearch(lli val){
    lli ans = -1;
    for(int i = 0; i <= len && arr[i] <= val; i++)
        ans = arr[i];
    return ans;
}

int findSeq(lli s, bool flag = false){
    if(s == 0){
        return 1;
    }
    int val = seqSearch(s);
    if(val == s && flag){
        seq.push_front(0);
        seq.push_front(val);
        return 1;
    }
    if(findSeq(s - val) == 1){
        seq.push_front(val);
        return 1;
    }
    else{
        val = seqSearch(val - 1);
        if(val == -1)
            return -1;
        if(findSeq(s - val) == 1){
            seq.push_front(val);
            return 1;
        }
        else
            return -1;
    }
}

int main(){
    ios :: sync_with_stdio(false);
    lli s, k;
    cin >> s >> k;
    arr[0] = 1;
    lli sum = 0;
    for(int i = 0; arr[i - 1] < s; i++){
        for(int j = 1; j <= k && i - j >= 0; j++)
            arr[i] += arr[i - j];
        //cout << i <<  " " << arr[i] << " " << sum << endl;
        sum += arr[i];
        len = i;
    }
    findSeq(s, true);
    cout << seq.size() << "\n";
    while(!seq.empty()){
        cout << seq.front() << " ";
        seq.pop_front();
    }
    return 0;
}
