#include<iostream>
#include<deque>

using namespace std;

int main(){
    int sum, limit;
    cin >> sum >> limit;
    int len = 0;
    deque<int> seq;
    for(int tmp = limit; tmp; tmp /= 2, len++);
    while(len && sum){
        int itr = 1;
        while(sum && (itr << (len - 1)) <= limit && sum - (1 << (len - 1)) >= 0){
            sum -= 1 << (len - 1);
            seq.push_back(itr << (len - 1));
            itr += 2;
        }
        len--;
    }

    if(sum == 0){
        cout << seq.size() << "\n";
        for(deque<int>::iterator itr = seq.begin(); itr < seq.end(); itr++)
            cout << *itr << " ";
    }
    else
        cout << "-1";
    return 0;
}
