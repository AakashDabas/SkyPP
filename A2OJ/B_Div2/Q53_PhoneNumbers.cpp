#include<iostream>
#include<string>
#include<deque>

using namespace std;

struct node{
    string name;
    int val[3] = {0};
};

int main(){
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    deque<node> que;
    int mV[3] = {0};
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        node data;
        cin >> data.name;
        for(int j = 0; j < k; j++){
            string num;
            cin >> num;
            if(num[0] == num[1] &&
                    num[1] == num[3] &&
                    num[3] == num[4] &&
                    num[4] == num[6] && 
                    num[6] == num[7])
                data.val[0]++;
            else if(num[0] > num[1] &&
                    num[1] > num[3] &&
                    num[3] > num[4] &&
                    num[4] > num[6] && 
                    num[6] > num[7])
                data.val[1]++;
            else
                data.val[2]++;
        }
        if(data.val[0] > mV[0])
            mV[0] = data.val[0];
        if(data.val[1] > mV[1])
            mV[1] = data.val[1];
        if(data.val[2] > mV[2])
            mV[2] = data.val[2];
        que.push_back(data);
    }
    for(int i = 0; i < 3; i++){
        deque<node> :: iterator itr = que.begin();
        bool flag = false;
        switch(i){
            case 0:
                cout << "If you want to call a taxi, you should call: ";
                break;
            case 1:
                cout << "If you want to order a pizza, you should call: ";
                break;
            case 2:
                cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
                break;
        }
        while(itr != que.end()){
            if((*itr).val[i] == mV[i]){
                if(flag)
                    cout << ", ";
                cout << (*itr).name;
                flag = true;
            }
            itr++;
        }
        cout << ".\n";
    }
    return 0;
}
