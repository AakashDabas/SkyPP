#include<iostream>
#include<cmath>

using namespace std;

long long int n;

long long int root(int i){
    double d = sqrt(i * i + 4 * n);
    double r1 = (-i + d) / 2;
    if(abs(r1 - (int)r1) < 0.000000000000001){
        long long int r2 = r1;
        int sum = 0;
        while(r2){
            sum += r2 % 10;
            r2 /= 10;
        }
        if(sum != i)
            return -1;
        else
            return r1;
    }
    else
        return -1;
}

int main(){
    cin >> n;
    for(int i = 1; i <= 90; i++){
        long long int val = root(i);
        if(val > 0){
            cout << val;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
