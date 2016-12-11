#include<iostream>
#include<vector>

using namespace std;

int main(){
    int d, sum;
    cin >> d >> sum;
    int arr[d][2];
    vector<int> sch(d, 0);
    int sL = 0;

    for(int i = 0; i < d; i++)
        cin >> arr[i][0] >> arr[i][1];

    for(int i = 0; i < d; i++){
        sch[i] = arr[i][0];
        sL += sch[i];
    }

    if(sL > sum){
        cout << "NO";
        return 0;
    }

    for(int i = 0; i < d && sL < sum; i++){
        int tmp = arr[i][1] - sch[i];
        if(tmp <= sum - sL){
            sch[i] = arr[i][1];
            sL += tmp;
        }
        else{
            sch[i] += sum - sL;
            sL = sum;
            break;
        }
    }

    if(sL == sum){
        cout << "YES\n";
        for(int i = 0; i < d; i++)
            cout << sch[i] << " ";
    }
    else    
        cout << "NO";
    return 0;
}
