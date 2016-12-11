#include<iostream>

#define house 1234567
#define cars 123456
#define computer 1234

typedef long long int lli;

using namespace std;

int main(){
    ios :: sync_with_stdio(false);
    lli n;
    cin >> n;
    for(lli a = 0; a * house <= n; a++)
        for(lli b = 0; b * cars <= n; b++){
            lli req = n - a * house - b * cars;
            lli s = 0, l = req / computer;
            lli mid = (s + l) / 2;
            while(s <= l){
                if(mid * computer == req){
                    cout << "YES";
                    return 0;
                }
                if(mid * computer < req)
                    s = mid + 1;
                else
                    l = mid - 1;
                mid = (s + l) / 2;
            }
        }
    cout << "NO";
    return 0;
}
