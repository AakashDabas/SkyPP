#include<iostream>

using namespace std;

int GetReverse(int n){
    int ans = 0;
    while(n){
        ans *= 10;
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int rev = GetReverse(n);
    
    //To get the maximum binary number
    int bin = 0;
    bool flag = false;
    while(rev){
        bin *= 10;
        if(!flag){
            if(rev % 10 == 0 || rev % 10 == 1)
                bin += rev % 10;
            else
                flag = true;
        }
        if(flag)
            bin += 1;
        rev /= 10;
    }
    while(n % 10 == 0){
        bin *= 10;
        if(flag)
            bin += 1;
        n /= 10;
    }

    int cnt = 0;
    int pwr = 1;
    while(bin){
        if(bin % 10 == 1)
            cnt += pwr;
        bin /= 10;
        pwr *= 2;
    }
    cout << cnt;
    return 0;
}
